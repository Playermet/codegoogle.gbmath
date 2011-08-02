/** \file  */

#pragma once
#include "base_camera.h"

namespace gbmath
{







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




}
