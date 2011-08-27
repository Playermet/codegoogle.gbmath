#pragma once

#include "_gbmath.h"
#include "base_camera.h"

namespace gbmath
{



//========================================================================
// Constructor
//========================================================================
first_person_camera::first_person_camera() :
    m_nActiveButtonMask( 0x07 )
{
    m_bRotateWithoutButtonDown = false;
}




//========================================================================
// Update the view matrix based on user input & elapsed time
//========================================================================
void first_person_camera::frameMove( float fElapsedTime )
{

#pragma message("ks777 gb::devhelp::first_person_camera::framemove  опнбепхрэ лернд!  "  __FILE__)
  //  if( MYUTGetGlobalTimer()->IsStopped() )
	//{
  //      fElapsedTime = 1.0f / MYUTGetFPS();
	//}



    if( isKeyDown(m_aKeys[CAM_RESET]) )
        reset();

    // Get keyboard/mouse/gamepad input
    getInput( m_bEnablePositionMovement,
		(m_nActiveButtonMask & m_nCurrentButtonMask) || m_bRotateWithoutButtonDown, 
		true, m_bResetCursorAfterMove );

    // Get amount of velocity based on the keyboard input and drag (if any)
    updateVelocity( fElapsedTime );

    // Simple euler method to calculate position delta
    vec3 vPosDelta = m_vVelocity * fElapsedTime;

    // If rotating the camera 
    if( (m_nActiveButtonMask & m_nCurrentButtonMask) || 
        m_bRotateWithoutButtonDown || 
        m_vGamePadRightThumb.x != 0 || 
        m_vGamePadRightThumb.z != 0 )
    {
        // Update the pitch & yaw angle based on mouse movement
        float fYawDelta   = m_vRotVelocity.x;
        float fPitchDelta = m_vRotVelocity.y;

        // Invert pitch if requested
        if( m_bInvertPitch )
            fPitchDelta = -fPitchDelta;

        m_fCameraPitchAngle += fPitchDelta;
        m_fCameraYawAngle   += fYawDelta;

		static const float __PI_DIV2 = 3.141592654f / 2.0f;

        // Limit pitch to straight up or straight down
        m_fCameraPitchAngle = __max( -__PI_DIV2,  m_fCameraPitchAngle );
        m_fCameraPitchAngle = __min( +__PI_DIV2,  m_fCameraPitchAngle );
    }

    // Make a rotation matrix based on the camera's yaw & pitch
    mat44 mCameraRot;
    //D 3DX MatrixRotationYawPitchRoll( mCameraRot, m_fCameraYawAngle, m_fCameraPitchAngle, 0 );
	  mCameraRot.setRotationYawPitchRoll( m_fCameraYawAngle, m_fCameraPitchAngle, 0.0f  );



    // Transform vectors based on camera's rotation matrix
    vec3 vWorldUp, vWorldAhead;
    vec3 vLocalUp    = vec3(0,1,0);
    vec3 vLocalAhead = vec3(0,0,1);

   // D 3DX Vec3TransformCoord( vWorldUp, vLocalUp, mCameraRot );
	  vWorldUp = vLocalUp;
		 vWorldUp.transform_coord(mCameraRot);

   // D 3DX Vec3TransformCoord( vWorldAhead, vLocalAhead, mCameraRot );
	 vWorldAhead = vLocalAhead;
	  vWorldAhead.transform_coord(mCameraRot);



    // Transform the position delta by the camera's rotation 
    vec3 vPosDeltaWorld;
    if( !m_bEnableYAxisMovement )
    {
        // If restricting Y movement, do not include pitch
        // when transforming position delta vector.
        //D 3DX MatrixRotationYawPitchRoll( mCameraRot, m_fCameraYawAngle, 0.0f, 0.0f );
		mCameraRot.setRotationYawPitchRoll(m_fCameraYawAngle, 0.0f, 0.0f  );

    }

    //D 3DX Vec3TransformCoord( vPosDeltaWorld, vPosDelta, mCameraRot );
	 vPosDeltaWorld =   vPosDelta;
	 vPosDeltaWorld.transform_coord(mCameraRot);


    // Move the eye position 
    m_vEye += vPosDeltaWorld;
    if( m_bClipToBoundary )
        constrainToBoundary( &m_vEye );

    // Update the lookAt position based on the eye position 
    m_vLookAt = m_vEye + vWorldAhead;


    // Update the view matrix
    //D 3DX MatrixLookAtLH( m_mView, m_vEye, m_vLookAt, vWorldUp );
	m_mView.setViewLookAtLH(  m_vEye, m_vLookAt, vWorldUp  );



  //D 3DX MatrixInverse( m_mCameraWorld, NULL, m_mView );
	m_mCameraWorld = m_mView.inverted();

}


//========================================================================
// Enable or disable each of the mouse buttons for rotation drag.
//========================================================================
void first_person_camera::setRotateButtons( bool bLeft, bool bMiddle, 
										   bool bRight, 
										   bool bRotateWithoutButtonDown )
{
    m_nActiveButtonMask = ( bLeft ? MOUSE_LEFT_BUTTON : 0 ) |
                          ( bMiddle ? MOUSE_MIDDLE_BUTTON : 0 ) |
                          ( bRight ? MOUSE_RIGHT_BUTTON : 0 );
    m_bRotateWithoutButtonDown = bRotateWithoutButtonDown;
}

 

}

