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



//-------------------------------------------------------------------------
 
}
// end namespace

#endif // #ifdef WIN32
 