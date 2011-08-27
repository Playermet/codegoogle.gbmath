

#pragma once


#ifdef WIN32 // only windows platform


#include "_gbmath.h"

///////////////////////////////////////////////
#if 0

   #pragma comment( lib, "dxerr.lib" )
   #pragma comment( lib, "dxguid.lib" )
   
		#if defined(DEBUG) || defined(_DEBUG)

		   #pragma comment( lib, "d3dx9d.lib" )

		#else

		   #pragma comment( lib, "d3dx9.lib" )

		#endif

   #pragma comment( lib, "d3d9.lib" )
   #pragma comment( lib, "winmm.lib" )
   #pragma comment( lib, "comctl32.lib" )

#endif   // #if
////////////////////////////////////////////////

#include "assert.h"

//======================================================

namespace gbmath 
{
 
 

//========================================================================
base_camera::base_camera()
{
	m_hwnd = 0;
    m_cKeysDown = 0;
    ZeroMemory( m_aKeys, sizeof(BYTE)*CAM_MAX_KEYS );
//    ZeroMemory( m_GamePad, sizeof(MYUT_GAMEPAD)*MYUT_MAX_CONTROLLERS );

    // Set attributes for the view matrix
    vec3 vEyePt    = vec3(0.0f,0.0f,0.0f);
    vec3 vLookatPt = vec3(0.0f,0.0f,1.0f);

    // Setup the view matrix
    setViewParams( vEyePt, vLookatPt );

    // Setup the projection matrix
	static const float _PI_DIV4  =  3.141592654f / 4.0f;
    setProjParams(  _PI_DIV4  , 1.0f, 1.0f, 1000.0f );

    GetCursorPos( &m_ptLastMousePosition );
    m_bMouseLButtonDown = false;
    m_bMouseMButtonDown = false;
    m_bMouseRButtonDown = false;
    m_nCurrentButtonMask = 0;
    m_nMouseWheelDelta = 0;

    m_fCameraYawAngle = 0.0f;
    m_fCameraPitchAngle = 0.0f;

    SetRect( &m_rcDrag, LONG_MIN, LONG_MIN, LONG_MAX, LONG_MAX );
    m_vVelocity     = vec3(0,0,0);
    m_bMovementDrag = false;
    m_vVelocityDrag = vec3(0,0,0);
    m_fDragTimer    = 0.0f;
    m_fTotalDragTimeToZero = 0.25;
    m_vRotVelocity = vec2(0,0);

    m_fRotationScaler = 0.01f;           
    m_fMoveScaler = 5.0f;           

    m_bInvertPitch = false;
    m_bEnableYAxisMovement = true;
    m_bEnablePositionMovement = true;

    m_vMouseDelta   = vec2(0,0);
    m_fFramesToSmoothMouseData = 2.0f;

    m_bClipToBoundary = false;
    m_vMinBoundary = vec3(-1,-1,-1);
    m_vMaxBoundary = vec3(1,1,1);
}


//========================================================================
// Client can call this to change the position and direction of camera
//========================================================================
void base_camera::setViewParams( const vec3& pvEyePt, const vec3& pvLookatPt)
{
   
	//if( NULL == pvEyePt || NULL == pvLookatPt )
    //    return;

    m_vDefaultEye = m_vEye = pvEyePt;
    m_vDefaultLookAt = m_vLookAt = pvLookatPt;

    // Calc the view matrix
    vec3 vUp(0,1,0);
 
	if (CAMERA_LEFT_HANDLE)
	{
	 m_mView.setViewLookAtLH(pvEyePt, pvLookatPt, vUp );
	}
	else
	{
	 m_mView.setViewLookAtRH(pvEyePt, pvLookatPt, vUp );
	}




    mat44 mInvView;
   // D 3DX MatrixInverse( mInvView, NULL, m_mView );
	mInvView   =  m_mView.inverted();

    // The axis basis vectors and camera position are stored inside the 
    // position matrix in the 4 rows of the camera's world matrix.
    // To figure out the yaw/pitch of the camera, we just need the Z basis vector
    vec3* pZBasis = (vec3*) &mInvView._31;

    m_fCameraYawAngle   = atan2f( pZBasis->x, pZBasis->z );
    float fLen = sqrtf(pZBasis->z*pZBasis->z + pZBasis->x*pZBasis->x);
    m_fCameraPitchAngle = -atan2f( pZBasis->y, fLen );
}




//========================================================================
// Calculates the projection matrix based on input params
//========================================================================
void base_camera::setProjParams( float fFOV, float fAspect, 
								float fNearPlane,  float fFarPlane )
{
    // Set attributes for the projection matrix
    m_fFOV        = fFOV;
    m_fAspect     = fAspect;
    m_fNearPlane  = fNearPlane;
    m_fFarPlane   = fFarPlane;

   // D 3DXMatrixPerspectiveFovLH( m_mProj, fFOV, fAspect, fNearPlane, fFarPlane );
	// m_mProj.setPerspectiveFovLH( fFOV, fAspect, fNearPlane, fFarPlane  );


	 if (CAMERA_LEFT_HANDLE)
	 {
		 m_mProj.setPerspectiveFovLH( fFOV, fAspect, fNearPlane, fFarPlane);
	 }
	 else
	 {
		 m_mProj.setPerspectiveFovRH( fFOV, fAspect, fNearPlane, fFarPlane);
	 }
}




//========================================================================
// Call this from your message proc so this class can handle window messages
//========================================================================
LRESULT base_camera::handleMessages( HWND hWnd, UINT uMsg, WPARAM wParam, 
												LPARAM lParam )
{
	m_hwnd = hWnd;
    UNREFERENCED_PARAMETER( hWnd );
    UNREFERENCED_PARAMETER( lParam );

    switch( uMsg )
    {
        case WM_KEYDOWN:
        {
            // Map this key to a D3DUtil_CameraKeys enum and update the
            // state of m_aKeys[] by adding the KEY_WAS_DOWN_MASK|KEY_IS_DOWN_MASK mask
            // only if the key is not down
			if(wParam == 27)
			{
			  int _stop = 0;
			}

            D3DUtil_CameraKeys mappedKey = mapKey( (UINT)wParam );
            if( mappedKey != CAM_UNKNOWN )
            {
                if( FALSE == isKeyDown(m_aKeys[mappedKey]) )
                {
                    m_aKeys[ mappedKey ] = KEY_WAS_DOWN_MASK | KEY_IS_DOWN_MASK;
                    ++m_cKeysDown;
                }
            }
            break;
        }

        case WM_KEYUP:
        {
            // Map this key to a D3DUtil_CameraKeys enum and update the
            // state of m_aKeys[] by removing the KEY_IS_DOWN_MASK mask.
            D3DUtil_CameraKeys mappedKey = mapKey( (UINT)wParam );
            if( mappedKey != CAM_UNKNOWN && (DWORD)mappedKey < 8 )
            {
                m_aKeys[ mappedKey ] &= ~KEY_IS_DOWN_MASK;
                --m_cKeysDown;
            }
            break;
        }

        case WM_RBUTTONDOWN:
        case WM_MBUTTONDOWN:
        case WM_LBUTTONDOWN:
        case WM_RBUTTONDBLCLK:
        case WM_MBUTTONDBLCLK:
        case WM_LBUTTONDBLCLK:
        {
            // Compute the drag rectangle in screen coord.
            POINT ptCursor = { (short)LOWORD(lParam), (short)HIWORD(lParam) };

            // Update member var state
            if( ( uMsg == WM_LBUTTONDOWN || uMsg == WM_LBUTTONDBLCLK ) && PtInRect( &m_rcDrag, ptCursor ) )
            { 
				m_bMouseLButtonDown = true; m_nCurrentButtonMask |= MOUSE_LEFT_BUTTON; 
			}

			if( ( uMsg == WM_MBUTTONDOWN || uMsg == WM_MBUTTONDBLCLK ) && PtInRect( &m_rcDrag, ptCursor ) )
			{ 
				m_bMouseMButtonDown = true; m_nCurrentButtonMask |= MOUSE_MIDDLE_BUTTON; 
			}

			if( ( uMsg == WM_RBUTTONDOWN || uMsg == WM_RBUTTONDBLCLK ) && PtInRect( &m_rcDrag, ptCursor ) )
			{ 
				m_bMouseRButtonDown = true; m_nCurrentButtonMask |= MOUSE_RIGHT_BUTTON; 
			}

            // Capture the mouse, so if the mouse button is 
            // released outside the window, we'll get the WM_LBUTTONUP message
            SetCapture(hWnd);
            GetCursorPos( &m_ptLastMousePosition );
            return TRUE;
        }

        case WM_RBUTTONUP: 
        case WM_MBUTTONUP: 
        case WM_LBUTTONUP:   
        {
            // Update member var state
            if( uMsg == WM_LBUTTONUP ) 
			{ 
				m_bMouseLButtonDown = false; m_nCurrentButtonMask &= ~MOUSE_LEFT_BUTTON; 
			}

            if( uMsg == WM_MBUTTONUP ) 
			{ 
				m_bMouseMButtonDown = false; m_nCurrentButtonMask &= ~MOUSE_MIDDLE_BUTTON; 
			}

            if( uMsg == WM_RBUTTONUP ) 
			{ 
				m_bMouseRButtonDown = false; m_nCurrentButtonMask &= ~MOUSE_RIGHT_BUTTON; 
			}


            // Release the capture if no mouse buttons down
            if( !m_bMouseLButtonDown  && 
                !m_bMouseRButtonDown &&
                !m_bMouseMButtonDown )
            {
                ReleaseCapture();
            }
            break;
        }

        case WM_CAPTURECHANGED:
        {
            if( (HWND)lParam != hWnd )
            {
                if( (m_nCurrentButtonMask & MOUSE_LEFT_BUTTON) ||
                    (m_nCurrentButtonMask & MOUSE_MIDDLE_BUTTON) ||
                    (m_nCurrentButtonMask & MOUSE_RIGHT_BUTTON) )
                {
                    m_bMouseLButtonDown = false;
                    m_bMouseMButtonDown = false;
                    m_bMouseRButtonDown = false;
                    m_nCurrentButtonMask &= ~MOUSE_LEFT_BUTTON;
                    m_nCurrentButtonMask &= ~MOUSE_MIDDLE_BUTTON;
                    m_nCurrentButtonMask &= ~MOUSE_RIGHT_BUTTON;
                    ReleaseCapture();
                }
            }
            break;
        }

        case WM_MOUSEWHEEL: 
            // Update member var state
            m_nMouseWheelDelta = (short)HIWORD(wParam) / 120;
            break;
    }

    return FALSE;
}


//========================================================================
// Figure out the velocity based on keyboard input & drag if any
//========================================================================
void base_camera::getInput( bool bGetKeyboardInput, bool bGetMouseInput, 
						   bool bGetGamepadInput, bool bResetCursorAfterMove )
{
    m_vKeyboardDirection = vec3(0,0,0);
    if( bGetKeyboardInput )
    {
        // Update acceleration vector based on keyboard state
        if( isKeyDown(m_aKeys[CAM_MOVE_FORWARD]) )
            m_vKeyboardDirection.z += 1.0f;
        if( isKeyDown(m_aKeys[CAM_MOVE_BACKWARD]) )
            m_vKeyboardDirection.z -= 1.0f;
        if( m_bEnableYAxisMovement )
        {
            if( isKeyDown(m_aKeys[CAM_MOVE_UP]) )
                m_vKeyboardDirection.y += 1.0f;
            if( isKeyDown(m_aKeys[CAM_MOVE_DOWN]) )
                m_vKeyboardDirection.y -= 1.0f;
        }
        if( isKeyDown(m_aKeys[CAM_STRAFE_RIGHT]) )
            m_vKeyboardDirection.x += 1.0f;
        if( isKeyDown(m_aKeys[CAM_STRAFE_LEFT]) )
            m_vKeyboardDirection.x -= 1.0f;
    }

    if( bGetMouseInput )
    {
        // Get current position of mouse
        POINT ptCurMouseDelta;
        POINT ptCurMousePos;
        
        if( GetCursorPos( &ptCurMousePos ) )
        {
            // Calc how far it's moved since last frame
            ptCurMouseDelta.x = ptCurMousePos.x - m_ptLastMousePosition.x;
            ptCurMouseDelta.y = ptCurMousePos.y - m_ptLastMousePosition.y;
            
            // Record current position for next time
            m_ptLastMousePosition = ptCurMousePos;
        }
        else
        {
            // If GetCursorPos() returns false, just set delta to zero
            ptCurMouseDelta.x = 0;
            ptCurMouseDelta.y = 0;
        }

		/**************** ИСКЛЮЧЕНО ********* MONITOR INFO
        if( bResetCursorAfterMove && TRUE) // ks777 MYUTIsActive() )
        {
            // Set position of camera to center of desktop, 
            // so it always has room to move.  This is very useful
            // if the cursor is hidden.  If this isn't done and cursor is hidden, 
            // then invisible cursor will hit the edge of the screen 
            // and the user can't tell what happened
            POINT ptCenter;
			assert(m_hwnd && "m_hwnd is zero");

            // Get the center of the current monitor
            MYMONITORINFO mi;
            mi.cbSize = sizeof(MONITORINFO);
			
            MYUTGetMonitorInfo( MYUTMonitorFromWindow( m_hwnd,MONITOR_DEFAULTTONEAREST), &mi );
            ptCenter.x = (mi.rcMonitor.left + mi.rcMonitor.right) / 2;
            ptCenter.y = (mi.rcMonitor.top + mi.rcMonitor.bottom) / 2;   
            SetCursorPos( ptCenter.x, ptCenter.y );
            m_ptLastMousePosition = ptCenter;
        }
		***********************************************/


        // Smooth the relative mouse data over a few frames so it isn't 
        // jerky when moving slowly at low frame rates.
        float fPercentOfNew =  1.0f / m_fFramesToSmoothMouseData;
        float fPercentOfOld =  1.0f - fPercentOfNew;
        m_vMouseDelta.x = m_vMouseDelta.x*fPercentOfOld + ptCurMouseDelta.x*fPercentOfNew;
        m_vMouseDelta.y = m_vMouseDelta.y*fPercentOfOld + ptCurMouseDelta.y*fPercentOfNew;

    }

    if( bGetGamepadInput )
    {
        m_vGamePadLeftThumb = vec3(0,0,0);
        m_vGamePadRightThumb = vec3(0,0,0);
	  
        // Find out which controller was non-zero last
        int iMostRecentlyActive = -1;
        double fMostRecentlyActiveTime = 0.0f;
 


    }
}


//========================================================================
// Figure out the velocity based on keyboard input & drag if any
//========================================================================
void base_camera::updateVelocity( float fElapsedTime )
{
    mat44 mRotDelta;

    vec2 vGamePadRightThumb = vec2(m_vGamePadRightThumb.x, -m_vGamePadRightThumb.z);
    m_vRotVelocity = m_vMouseDelta * m_fRotationScaler + vGamePadRightThumb * 0.02f;

    vec3 vAccel = m_vKeyboardDirection + m_vGamePadLeftThumb;

    // Normalize vector so if moving 2 dirs (left & forward), 
    // the camera doesn't move faster than if moving in 1 dir

 
    //D 3DX Vec3Normalize( vAccel, vAccel );
	  vAccel.normalize();
 
 

    // Scale the acceleration vector
    vAccel *= m_fMoveScaler;

    if( m_bMovementDrag )
    {
        // Is there any acceleration this frame?
      //if( D 3DX Vec3LengthSq( vAccel ) > 0 )
        if( vAccel.length_sq() > 0 )
        {
            // If so, then this means the user has pressed a movement key\
            // so change the velocity immediately to acceleration 
            // upon keyboard input.  This isn't normal physics
            // but it will give a quick response to keyboard input
            m_vVelocity = vAccel;
            m_fDragTimer = m_fTotalDragTimeToZero;
            m_vVelocityDrag = vAccel / m_fDragTimer;
        }
        else 
        {
            // If no key being pressed, then slowly decrease velocity to 0
            if( m_fDragTimer > 0 )
            {
                // Drag until timer is <= 0
                m_vVelocity -= m_vVelocityDrag * fElapsedTime;
                m_fDragTimer -= fElapsedTime;
            }
            else
            {
                // Zero velocity
                m_vVelocity = vec3(0,0,0);
            }
        }
    }
    else
    {
        // No drag, so immediately change the velocity
        m_vVelocity = vAccel;
    }
}




//========================================================================
// Clamps pV to lie inside m_vMinBoundary & m_vMaxBoundary
//========================================================================
void base_camera::constrainToBoundary( vec3* pV )
{
    // Constrain vector to a bounding box 
    pV->x = __max(pV->x, m_vMinBoundary.x);
    pV->y = __max(pV->y, m_vMinBoundary.y);
    pV->z = __max(pV->z, m_vMinBoundary.z);

    pV->x = __min(pV->x, m_vMaxBoundary.x);
    pV->y = __min(pV->y, m_vMaxBoundary.y);
    pV->z = __min(pV->z, m_vMaxBoundary.z);
}




//========================================================================
// Maps a windows virtual key to an enum
//========================================================================
D3DUtil_CameraKeys base_camera::mapKey( UINT nKey )
{
    // This could be upgraded to a method that's user-definable but for 
    // simplicity, we'll use a hardcoded mapping.
    switch( nKey )
    {
        case VK_CONTROL:  return CAM_CONTROLDOWN;
        case VK_LEFT:  return CAM_STRAFE_LEFT;
        case VK_RIGHT: return CAM_STRAFE_RIGHT;
        case VK_UP:    return CAM_MOVE_FORWARD;
        case VK_DOWN:  return CAM_MOVE_BACKWARD;
        case VK_PRIOR: return CAM_MOVE_UP;        // pgup
        case VK_NEXT:  return CAM_MOVE_DOWN;      // pgdn

        case 'A':      return CAM_STRAFE_LEFT;
        case 'D':      return CAM_STRAFE_RIGHT;
        case 'W':      return CAM_MOVE_FORWARD;
        case 'S':      return CAM_MOVE_BACKWARD;
        case 'Q':      return CAM_MOVE_DOWN;
        case 'E':      return CAM_MOVE_UP;

        case VK_NUMPAD4: return CAM_STRAFE_LEFT;
        case VK_NUMPAD6: return CAM_STRAFE_RIGHT;
        case VK_NUMPAD8: return CAM_MOVE_FORWARD;
        case VK_NUMPAD2: return CAM_MOVE_BACKWARD;
        case VK_NUMPAD9: return CAM_MOVE_UP;        
        case VK_NUMPAD3: return CAM_MOVE_DOWN;      

        case VK_HOME:   return CAM_RESET;
    }

    return CAM_UNKNOWN;
}




//========================================================================
// Reset the camera's position back to the default
//========================================================================
void base_camera::reset()
{
    setViewParams( m_vDefaultEye, m_vDefaultLookAt );
}




 
}

#endif // #ifdef WIN32
