/** \file 
 \brief Камеры для наблюдения, отладки, создания утилит и т.д.
 Выдраны из DXUT с небольшими исправлениями и удалением ненужного.


 \todo поправить код-стиль
 
 \todo Удалить MONITORINFO

 <br><br>
СДЕЛАНО: <br>
 - Удалить лишние геймпадовые типы. <br>
 -  Избавиться от зависимости от d3dx-математики. <br>

 <br>

*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


#ifdef WIN32 // только для windows

//#include <stdexcept>

#include <windows.h>
#include <zmouse.h>

//#include <gb/Config.h>
//#include <gb/base/Types.h>
//#include <gbmath/_gbmath.h>
 

//using namespace gb::fmath;
//using namespace gb::fmath::geom3d;

 

namespace gbmath {
 

#define KEY_WAS_DOWN_MASK 0x80
#define KEY_IS_DOWN_MASK  0x01

#define MOUSE_LEFT_BUTTON   0x01
#define MOUSE_MIDDLE_BUTTON 0x02
#define MOUSE_RIGHT_BUTTON  0x04
#define MOUSE_WHEEL         0x08



enum D3DUtil_CameraKeys
{
    CAM_STRAFE_LEFT = 0,
    CAM_STRAFE_RIGHT,
    CAM_MOVE_FORWARD,
    CAM_MOVE_BACKWARD,
    CAM_MOVE_UP,
    CAM_MOVE_DOWN,
    CAM_RESET,
    CAM_CONTROLDOWN,
    CAM_MAX_KEYS,
    CAM_UNKNOWN = 0xFF
};
  

class arc_ball  {
public:
    arc_ball();

    // Functions to change behavior
    void reset(); 
    void setTranslationRadius( float fRadiusTranslation ) { m_fRadiusTranslation = fRadiusTranslation; }
    void setWindow( INT nWidth, INT nHeight, float fRadius = 0.9f ) { m_nWidth = nWidth; m_nHeight = nHeight; m_fRadius = fRadius; m_vCenter = vec2(m_nWidth/2.0f,m_nHeight/2.0f); }
    void setOffset( INT nX, INT nY ) { m_Offset.x = nX; m_Offset.y = nY; }

    //! \brief  Call these from client and use GetRotationMatrix() to read new rotation matrix
    void onBegin( int nX, int nY );  // start the rotation (pass current mouse position)
    void onMove( int nX, int nY );   // continue the rotation (pass current mouse position)
    void onEnd();                    // end the rotation 

    //! \brief  Or call this to automatically handle left, middle, right buttons
    LRESULT     handleMessages( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

    // Functions to get/set state
    const mat44& getRotationMatrix()                   
	{ 
		  //D 3DX MatrixRotationQuaternion(m_mRotation, m_qNow); 
		  m_mRotation.setRotationQuaternion(m_qNow);
		  return m_mRotation;
	}

    const mat44& getTranslationMatrix() const          { return m_mTranslation; }
    const mat44& getTranslationDeltaMatrix() const     { return m_mTranslationDelta; }

    bool        isBeingDragged() const                      { return m_bDrag; }
    Quaternion getQuatNow() const                       { return m_qNow; }
    void        setQuatNow( Quaternion q ) { m_qNow = q; }

    static Quaternion quatFromBallPoints( const vec3 &vFrom, const vec3 &vTo );


protected:
    mat44  m_mRotation;         ///< Matrix for arc ball's orientation
    mat44  m_mTranslation;      ///< Matrix for arc ball's position
    mat44  m_mTranslationDelta; ///< Matrix for arc ball's position

    POINT          m_Offset;   ///< window offset, or upper-left corner of window
    INT            m_nWidth;   ///< arc ball's window width
    INT            m_nHeight;  ///< arc ball's window height
    vec2    m_vCenter;  ///< center of arc ball 
    float          m_fRadius;  ///< arc ball's radius in screen coords
    float          m_fRadiusTranslation; ///< arc ball's radius for translating the target

    Quaternion m_qDown;             ///< Quaternion before button down
    Quaternion m_qNow;              ///< Composite quaternion for current drag
    bool           m_bDrag;             ///< Whether user is dragging arc ball

    POINT          m_ptLastMouse;      ///< position of last mouse point
    vec3    m_vDownPt;           ///< starting point of rotation arc
    vec3    m_vCurrentPt;        ///< current point of rotation arc

    vec3    screenToVector( float fScreenPtX, float fScreenPtY );
};



class BaseCamera {
public:
			  BaseCamera();
	virtual  ~BaseCamera() {}

	// //! \brief Сделать камеру текущей
	//virtual HRESULT makeCurrent(IDirect3DDevice9* pDevice) = 0; 

    // Call these from client and use Get*Matrix() to read new matrices
    virtual LRESULT handleMessages( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
    virtual void    frameMove( float fElapsedTime ) = 0;

    // Functions to change camera matrices

    virtual void reset(); 
    virtual void setViewParams( const vec3& pvEyePt, const vec3& pvLookatPt );
    virtual void setProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane );

    // Functions to change behavior

    virtual void setDragRect( RECT &rc ) { m_rcDrag = rc; }
    void setInvertPitch( bool bInvertPitch ) { m_bInvertPitch = bInvertPitch; }
    void setDrag( bool bMovementDrag, float fTotalDragTimeToZero = 0.25f ) { m_bMovementDrag = bMovementDrag; m_fTotalDragTimeToZero = fTotalDragTimeToZero; }
    void setEnableYAxisMovement( bool bEnableYAxisMovement ) { m_bEnableYAxisMovement = bEnableYAxisMovement; }
    void setEnablePositionMovement( bool bEnablePositionMovement ) { m_bEnablePositionMovement = bEnablePositionMovement; }
    void setClipToBoundary( bool bClipToBoundary, vec3* pvMinBoundary, vec3* pvMaxBoundary ) { m_bClipToBoundary = bClipToBoundary; if( pvMinBoundary ) m_vMinBoundary = *pvMinBoundary; if( pvMaxBoundary ) m_vMaxBoundary = *pvMaxBoundary; }
    void setScalers( float fRotationScaler = 0.01f, float fMoveScaler = 5.0f )  { m_fRotationScaler = fRotationScaler; m_fMoveScaler = fMoveScaler; }
    void setNumberOfFramesToSmoothMouseData( int nFrames ) { if( nFrames > 0 ) m_fFramesToSmoothMouseData = (float)nFrames; }

    // Functions to get state
    const mat44&  getViewMatrix() const { return m_mView; }
    const mat44&  getProjMatrix() const { return m_mProj; }
    const vec3& getEyePoint() const      { return m_vEye; }
    const vec3& getLookAtPoint() const   { return m_vLookAt; }
    float getNearClipPlane() const { return m_fNearPlane; }
    float getFarClipPlane() const { return m_fFarPlane; }

    bool isBeingDragged() const         { return (m_bMouseLButtonDown || m_bMouseMButtonDown || m_bMouseRButtonDown); }
    bool isMouseLButtonDown() const     { return m_bMouseLButtonDown; } 
    bool isMouseMButtonDown() const     { return m_bMouseMButtonDown; } 
    bool isMouseRButtonDown() const     { return m_bMouseRButtonDown; } 



protected:
    // Functions to map a WM_KEYDOWN key to a D3DUtil_CameraKeys enum
    // >>>>  old  : virtual 
		static D3DUtil_CameraKeys mapKey( UINT nKey );  

    bool isKeyDown( BYTE key ) const { return( (key & KEY_IS_DOWN_MASK) == KEY_IS_DOWN_MASK ); }
    bool wasKeyDown( BYTE key ) const { return( (key & KEY_WAS_DOWN_MASK) == KEY_WAS_DOWN_MASK ); }

    void constrainToBoundary( vec3* pV );
    void updateVelocity( float fElapsedTime );
    void getInput( bool bGetKeyboardInput, bool bGetMouseInput, bool bGetGamepadInput, bool bResetCursorAfterMove );
 

    mat44            m_mView;              ///< View matrix 
    mat44            m_mProj;              ///< Projection matrix
 
    vec3           m_vGamePadLeftThumb;
    vec3           m_vGamePadRightThumb;
 
    int                   m_cKeysDown;            ///< Number of camera keys that are down.
    BYTE                  m_aKeys[CAM_MAX_KEYS];  ///< State of input - KEY_WAS_DOWN_MASK|KEY_IS_DOWN_MASK
    vec3           m_vKeyboardDirection;   ///< Direction vector of keyboard input
    POINT                 m_ptLastMousePosition;  ///< Last absolute position of mouse cursor
    bool                  m_bMouseLButtonDown;    ///< True if left button is down 
    bool                  m_bMouseMButtonDown;    ///< True if middle button is down 
    bool                  m_bMouseRButtonDown;    ///< True if right button is down 
    int                   m_nCurrentButtonMask;   ///< mask of which buttons are down
    int                   m_nMouseWheelDelta;     ///< Amount of middle wheel scroll (+/-) 
    vec2           m_vMouseDelta;          ///< Mouse relative delta smoothed over a few frames
    float                 m_fFramesToSmoothMouseData; ///< Number of frames to smooth mouse data over

    vec3           m_vDefaultEye;          ///< Default camera eye position
    vec3           m_vDefaultLookAt;       ///< Default LookAt position
    vec3           m_vEye;                 ///< Camera eye position
    vec3           m_vLookAt;              ///< LookAt position
    float                 m_fCameraYawAngle;      ///< Yaw angle of camera
    float                 m_fCameraPitchAngle;    ///< Pitch angle of camera

    RECT                  m_rcDrag;               ///< Rectangle within which a drag can be initiated.
    vec3           m_vVelocity;            ///< Velocity of camera
    bool                  m_bMovementDrag;        ///< If true, then camera movement will slow to a stop otherwise movement is instant
    vec3           m_vVelocityDrag;        ///< Velocity drag force
    float                 m_fDragTimer;           ///< Countdown timer to apply drag
    float                 m_fTotalDragTimeToZero; ///< Time it takes for velocity to go from full to 0
    vec2           m_vRotVelocity;         ///< Velocity of camera

    float                 m_fFOV;                 ///< Field of view
    float                 m_fAspect;              ///< Aspect ratio
    float                 m_fNearPlane;           ///< Near plane
    float                 m_fFarPlane;            ///< Far plane

    float                 m_fRotationScaler;      ///< Scaler for rotation
    float                 m_fMoveScaler;          ///< Scaler for movement

    bool                  m_bInvertPitch;         ///< Invert the pitch axis
    bool                  m_bEnablePositionMovement; ///< If true, then the user can translate the camera/model 
    bool                  m_bEnableYAxisMovement; ///< If true, then camera can move in the y-axis

    bool                  m_bClipToBoundary;      ///< If true, then the camera will be clipped to the boundary
    vec3           m_vMinBoundary;         ///< Min point in clip boundary
    vec3           m_vMaxBoundary;         ///< Max point in clip boundary

	HWND m_hwnd;
};
// end class


/** \brief Камера от первого лица. 
   Использует сообщения окну для чтения клавиатуры: вперёд,назад,влево,вправо,вверх,вниз  */
class FirstPersonCamera : public BaseCamera {
public:
    FirstPersonCamera();
	virtual ~FirstPersonCamera() {}

#ifdef _D3D9_H_
	//! \brief Сделать камеру текущей
	virtual HRESULT makeCurrent(IDirect3DDevice9* pDevice) 
	{
	  HRESULT hr =0;
       // hr |= pDevice->SetTransform( D3DTS_WORLD ,  GetWorldMatrix() );
       hr |= pDevice->SetTransform(D3DTS_VIEW ,  getViewMatrix() );
       hr |= pDevice->SetTransform(D3DTS_PROJECTION ,  getProjMatrix() );

      return hr;
	}
#endif

    //! \brief Call these from client and use Get*Matrix() to read new matrices
    virtual void frameMove( float fElapsedTime );

    //  Functions to change behavior
    void setRotateButtons( bool bLeft, bool bMiddle, bool bRight, bool bRotateWithoutButtonDown = false );

    void setResetCursorAfterMove( bool bResetCursorAfterMove ) { m_bResetCursorAfterMove = bResetCursorAfterMove; }

       // Functions to get state

         mat44&  getWorldMatrix()            { return m_mCameraWorld; }
   const mat44&  getWorldMatrix() const { return m_mCameraWorld; }


    const vec3* getWorldRight() const { return (vec3*)&m_mCameraWorld._11; } 
    const vec3* getWorldUp() const    { return (vec3*)&m_mCameraWorld._21; }
    const vec3* getWorldAhead() const { return (vec3*)&m_mCameraWorld._31; }
    const vec3* getEyePoint() const      { return (vec3*)&m_mCameraWorld._41; }

protected:
    mat44   m_mCameraWorld;       ///< World matrix of the camera (inverse of the view matrix)

    int        m_nActiveButtonMask;  ///< Mask to determine which button to enable for rotation
    bool       m_bRotateWithoutButtonDown;

    bool       m_bResetCursorAfterMove; ///< If true, the class will reset the cursor position so that the cursor always has space to move 
};
// end class



/** \brief Простая модель класс камеры , которая вращается вокруг объекта и вращает объект. */
class ModelViewerCamera : public BaseCamera
{
public:
    ModelViewerCamera();
	virtual ~ModelViewerCamera() {}

#ifdef _D3D9_H_
	//! \brief Сделать камеру текущей
	virtual HRESULT makeCurrent(IDirect3DDevice9* pDevice, bool bNeedSetWorld=true) 
	{
	  HRESULT hr =0;
	  assert(pDevice);
      if(bNeedSetWorld) hr |= pDevice->SetTransform( D3DTS_WORLD ,      getWorldMatrix()  );
       hr |= pDevice->SetTransform(D3DTS_VIEW ,        getViewMatrix()   );
       hr |= pDevice->SetTransform(D3DTS_PROJECTION ,  getProjMatrix()   );
      return hr;
	} 
#endif

    // Call these from client and use Get*Matrix() to read new matrices
    virtual LRESULT handleMessages( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
    virtual void frameMove( float fElapsedTime );

   
    // Functions to change behavior
    virtual void setDragRect( RECT &rc );
    void reset(); 
    void setViewParams( const vec3& pvEyePt, const vec3& pvLookatPt );
    void setButtonMasks( int nRotateModelButtonMask = MOUSE_LEFT_BUTTON, int nZoomButtonMask = MOUSE_WHEEL, int nRotateCameraButtonMask = MOUSE_RIGHT_BUTTON ) { m_nRotateModelButtonMask = nRotateModelButtonMask, m_nZoomButtonMask = nZoomButtonMask; m_nRotateCameraButtonMask = nRotateCameraButtonMask; }
    
    void setAttachCameraToModel( bool bEnable = false ) { m_bAttachCameraToModel = bEnable; }
    void setWindow( int nWidth, int nHeight, float fArcballRadius=0.9f ) { m_WorldArcBall.setWindow( nWidth, nHeight, fArcballRadius ); m_ViewArcBall.setWindow( nWidth, nHeight, fArcballRadius ); }
    void setRadius( float fDefaultRadius=5.0f, float fMinRadius=1.0f, float fMaxRadius=FLT_MAX  ) { m_fDefaultRadius = m_fRadius = fDefaultRadius; m_fMinRadius = fMinRadius; m_fMaxRadius = fMaxRadius; m_bDragSinceLastUpdate = true; }
    void setModelCenter( vec3 vModelCenter ) { m_vModelCenter = vModelCenter; }
    void setLimitPitch( bool bLimitPitch ) { m_bLimitPitch = bLimitPitch; }
    void setViewQuat( Quaternion q ) { m_ViewArcBall.setQuatNow( q ); m_bDragSinceLastUpdate = true; }
    void setWorldQuat( Quaternion q ) { m_WorldArcBall.setQuatNow( q ); m_bDragSinceLastUpdate = true; }

    // Functions to get state
    const mat44& getWorldMatrix() const { return m_mWorld; }
    void setWorldMatrix( mat44 &mWorld ) { m_mWorld = mWorld; m_bDragSinceLastUpdate = true; }

protected:
    arc_ball  m_WorldArcBall;
    arc_ball  m_ViewArcBall;
    vec3  m_vModelCenter;
    mat44   m_mModelLastRot;        // Last arcball rotation matrix for model 
    mat44   m_mModelRot;            // Rotation matrix of model
    mat44   m_mWorld;               // World matrix of model

    int          m_nRotateModelButtonMask;
    int          m_nZoomButtonMask;
    int          m_nRotateCameraButtonMask;

    bool         m_bAttachCameraToModel;
    bool         m_bLimitPitch;
    float        m_fRadius;              // Distance from the camera to model 
    float        m_fDefaultRadius;       // Distance from the camera to model 
    float        m_fMinRadius;           // Min radius
    float        m_fMaxRadius;           // Max radius
    bool         m_bDragSinceLastUpdate; // True if mouse drag has happened since last time FrameMove is called.

    mat44   m_mCameraRotLast;

};
// end class


//! \brief Целевая камера , которой может быть установлена точка обзора, за которой камера будет "сделить"
class TargetCamera {
public:

	TargetCamera() 
	{ 
		m_pvTarget=NULL; m_bNeedUpdateView=true; 
		m_vEyePt = vec3(5.0f , 0.0f , -0.0f);
		m_vUp   = vec3( 0.0f , 1.0f , 0.0f );
	}

 //! \brief Установить цель камеры или NULL если цели нет.
 void setViewTarget( vec3* pvTarget ) { m_pvTarget=pvTarget; m_bNeedUpdateView=true; }
 void setViewPosition( const vec3& vPos ) { m_vEyePt=vPos;  m_bNeedUpdateView=true; }
 void setViewUp( const vec3& vUp ) { m_vUp=vUp; m_bNeedUpdateView=true; }

 void setProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane )
 {
   //D 3DX MatrixPerspectiveFovLH(m_mProj, fFOV, fAspect, fNearPlane, fFarPlane );
	m_mProj.setPerspectiveFovLH( fFOV, fAspect, fNearPlane, fFarPlane );

 }

       mat44& getViewMatrix()       { return m_mView; }
 const mat44& getViewMatrix() const { return m_mView; }

       mat44& getProjMatrix()       { return m_mProj; }
 const mat44& getProjMatrix() const { return m_mProj; }

 //! \brief  Обновить. Вызвать раз перед отрисовкой кадра. Или несколько, если цель переместилась.
 void updateView(float fTime) 
 {
	 // make view matrix
	 vec3 vLookAt;
	 if(m_pvTarget) 
	 { 
		 vLookAt = *m_pvTarget;  
	 }
	 else
	 {
		 vLookAt.x = vLookAt.y = vLookAt.z = 0.0f;
	 }

	// D 3DX MatrixLookAtLH( m_mView, m_vEyePt, vLookAt, m_vUp );
	 m_mView.setViewLookAtLH( m_vEyePt, vLookAt, m_vUp  );

    m_bNeedUpdateView = false;
 }


private:
    vec3*     m_pvTarget; ///< pointer to target coord
	mat44            m_mView;              ///< View matrix 
	mat44            m_mProj;              ///< Projection matrix

	vec3  m_vEyePt;
	vec3  m_vUp;

	bool m_bNeedUpdateView;
};


//-------------------------------------------------------------------------
 
}
// end namespace

#endif // #ifdef WIN32
 