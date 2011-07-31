
//#include "pch.h"
//#include "d3d9pch.h"
//#include "stdafx.h"

//#include <gb/Config.h>
#include "devcamera.h"

#ifdef WIN32



#if 1

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

#endif

#include "assert.h"

//======================================================

namespace gbmath {
 

/*****************************************
HMONITOR MYUTMonitorFromWindow( HWND hWnd, DWORD dwFlags )
{

 assert(false && "no valid function" );
  return 0;
};

    typedef struct tagMYMONITORINFO
    {
        DWORD   cbSize;
        RECT    rcMonitor;
        RECT    rcWork;
        DWORD   dwFlags;
    } MYMONITORINFO, *LPMYMONITORINFO; // MONITORINFO


BOOL  MYUTGetMonitorInfo( HMONITOR hMonitor, LPMYMONITORINFO lpMonitorInfo )
{
 	assert(false && "no valid function" );
 return  FALSE;
};
 
double MYUTGetTime() 
{  
	assert(false && "no valid function" );
    return 0.0;
};
********************************************************/

 
//=========================================================================
arc_ball::arc_ball()
{
    reset();
    m_vDownPt = vec3(0,0,0);
    m_vCurrentPt = vec3(0,0,0);
    m_Offset.x = m_Offset.y = 0;

    RECT rc;
    GetClientRect( GetForegroundWindow(), &rc );
    setWindow( rc.right, rc.bottom );
}





//=========================================================================
void arc_ball::reset()
{
    m_qDown.reset(); // D 3DX QuaternionIdentity( m_qDown );
    m_qNow.reset();// D 3DX QuaternionIdentity( m_qNow );
    m_mRotation.reset();//  D 3DX MatrixIdentity( m_mRotation );
    m_mTranslation.reset(); //D 3DX MatrixIdentity( m_mTranslation );
    m_mTranslationDelta.reset(); //  D 3DX MatrixIdentity( m_mTranslationDelta );
    m_bDrag = FALSE;
    m_fRadiusTranslation = 1.0f;
    m_fRadius = 1.0f;
}




//=========================================================================
vec3 arc_ball::screenToVector( float fScreenPtX, float fScreenPtY )
{
    // Scale to screen
    float x   = -(fScreenPtX - m_Offset.x - m_nWidth/2)  / (m_fRadius*m_nWidth/2);
    float y   =  (fScreenPtY - m_Offset.y - m_nHeight/2) / (m_fRadius*m_nHeight/2);

    float z   = 0.0f;
    float mag = x*x + y*y;

    if( mag > 1.0f )
    {
        float scale = 1.0f/sqrtf(mag);
        x *= scale;
        y *= scale;
    }
    else
        z = sqrtf( 1.0f - mag );

    // Return vector
    return vec3( x, y, z );
}




//=========================================================================
Quaternion arc_ball::quatFromBallPoints(const vec3 &vFrom, const vec3 &vTo)
{
    vec3 vPart;

    float fDot = vFrom.dot(vTo);//  D 3DX Vec3Dot(vFrom, vTo);

     // D 3DX Vec3Cross(vPart, vFrom, vTo);
	   vPart = vFrom.cross(vTo);

    return Quaternion(vPart.x, vPart.y, vPart.z, fDot);
}



//=========================================================================
void arc_ball::onBegin( int nX, int nY )
{
    // Only enter the drag state if the click falls
    // inside the click rectangle.
    if( nX >= m_Offset.x &&
        nX < m_Offset.x + m_nWidth &&
        nY >= m_Offset.y &&
        nY < m_Offset.y + m_nHeight )
    {
        m_bDrag = true;
        m_qDown = m_qNow;
        m_vDownPt = screenToVector( (float)nX, (float)nY );
    }
}


//=========================================================================
void arc_ball::onMove( int nX, int nY )
{
    if (m_bDrag) 
    { 
        m_vCurrentPt = screenToVector( (float)nX, (float)nY );
        m_qNow = m_qDown * quatFromBallPoints( m_vDownPt, m_vCurrentPt );
    }
}




//=========================================================================
void arc_ball::onEnd()
{
    m_bDrag = false;
}


//=========================================================================
LRESULT arc_ball::handleMessages( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    // Current mouse position
    int iMouseX = (short)LOWORD(lParam);
    int iMouseY = (short)HIWORD(lParam);

	switch( uMsg )
	{
	case WM_LBUTTONDOWN:
	case WM_LBUTTONDBLCLK:
		SetCapture( hWnd );
		onBegin( iMouseX, iMouseY );
		return TRUE;

	case WM_LBUTTONUP:
		ReleaseCapture();
		onEnd();
		return TRUE;

	case WM_CAPTURECHANGED:
		if( (HWND)lParam != hWnd )
		{
			ReleaseCapture();
			onEnd();
		}
		return TRUE;

	case WM_RBUTTONDOWN:
	case WM_RBUTTONDBLCLK:
	case WM_MBUTTONDOWN:
	case WM_MBUTTONDBLCLK:
		SetCapture( hWnd );
		// Store off the position of the cursor when the button is pressed
		m_ptLastMouse.x = iMouseX;
		m_ptLastMouse.y = iMouseY;
		return TRUE;

	case WM_RBUTTONUP:
	case WM_MBUTTONUP:
		ReleaseCapture();
		return TRUE;

	case WM_MOUSEMOVE:
		if( MK_LBUTTON & wParam )
		{
			onMove( iMouseX, iMouseY );
		}
		else if( (MK_RBUTTON & wParam) || (MK_MBUTTON & wParam) )
		{
			// Normalize based on size of window and bounding sphere radius
			float fDeltaX = ( m_ptLastMouse.x-iMouseX ) * m_fRadiusTranslation / m_nWidth;
			float fDeltaY = ( m_ptLastMouse.y-iMouseY ) * m_fRadiusTranslation / m_nHeight;

			if( wParam & MK_RBUTTON )
			{
				//D 3DXMatrixTranslation( m_mTranslationDelta, -2 * fDeltaX, 2 * fDeltaY, 0.0f );
					m_mTranslationDelta.setTranslation       ( -2 * fDeltaX, 2 * fDeltaY, 0.0f );

				//D 3DXMatrixMultiply( m_mTranslation, m_mTranslation, m_mTranslationDelta );
				 m_mTranslation =m_mTranslation	* m_mTranslationDelta;
			}
			else  // wParam & MK_MBUTTON
			{
				//D 3DXMatrixTranslation( m_mTranslationDelta, 0.0f, 0.0f, 5 * fDeltaY );
				 m_mTranslationDelta.setTranslation( 0.0f, 0.0f, 5 * fDeltaY  );

				//D 3DXMatrixMultiply( m_mTranslation, m_mTranslation, m_mTranslationDelta );
				  m_mTranslation = m_mTranslation * m_mTranslationDelta;
			}

			// Store mouse coordinate
			m_ptLastMouse.x = iMouseX;
			m_ptLastMouse.y = iMouseY;
		}
		return TRUE;
	}

    return FALSE;
}


//========================================================================
BaseCamera::BaseCamera()
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
void BaseCamera::setViewParams( const vec3& pvEyePt, const vec3& pvLookatPt )
{
   
	//if( NULL == pvEyePt || NULL == pvLookatPt )
    //    return;

    m_vDefaultEye = m_vEye = pvEyePt;
    m_vDefaultLookAt = m_vLookAt = pvLookatPt;

    // Calc the view matrix
    vec3 vUp(0,1,0);
    // D 3DXMatrixLookAtLH( m_mView, pvEyePt, pvLookatPt, vUp );
	  m_mView.setViewLookAtLH(pvEyePt, pvLookatPt, vUp );

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
void BaseCamera::setProjParams( float fFOV, float fAspect, float fNearPlane,
                                   float fFarPlane )
{
    // Set attributes for the projection matrix
    m_fFOV        = fFOV;
    m_fAspect     = fAspect;
    m_fNearPlane  = fNearPlane;
    m_fFarPlane   = fFarPlane;

   // D 3DXMatrixPerspectiveFovLH( m_mProj, fFOV, fAspect, fNearPlane, fFarPlane );
	          m_mProj.setPerspectiveFovLH( fFOV, fAspect, fNearPlane, fFarPlane  );
}




//========================================================================
// Call this from your message proc so this class can handle window messages
//========================================================================
LRESULT BaseCamera::handleMessages( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
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
			};
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
                { m_bMouseLButtonDown = true; m_nCurrentButtonMask |= MOUSE_LEFT_BUTTON; }
            if( ( uMsg == WM_MBUTTONDOWN || uMsg == WM_MBUTTONDBLCLK ) && PtInRect( &m_rcDrag, ptCursor ) )
                { m_bMouseMButtonDown = true; m_nCurrentButtonMask |= MOUSE_MIDDLE_BUTTON; }
            if( ( uMsg == WM_RBUTTONDOWN || uMsg == WM_RBUTTONDBLCLK ) && PtInRect( &m_rcDrag, ptCursor ) )
                { m_bMouseRButtonDown = true; m_nCurrentButtonMask |= MOUSE_RIGHT_BUTTON; }

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
            if( uMsg == WM_LBUTTONUP ) { m_bMouseLButtonDown = false; m_nCurrentButtonMask &= ~MOUSE_LEFT_BUTTON; }
            if( uMsg == WM_MBUTTONUP ) { m_bMouseMButtonDown = false; m_nCurrentButtonMask &= ~MOUSE_MIDDLE_BUTTON; }
            if( uMsg == WM_RBUTTONUP ) { m_bMouseRButtonDown = false; m_nCurrentButtonMask &= ~MOUSE_RIGHT_BUTTON; }

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
void BaseCamera::getInput( bool bGetKeyboardInput, bool bGetMouseInput, 
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
void BaseCamera::updateVelocity( float fElapsedTime )
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
        if( vAccel.lengthSq() > 0 )
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
void BaseCamera::constrainToBoundary( vec3* pV )
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
D3DUtil_CameraKeys BaseCamera::mapKey( UINT nKey )
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
void BaseCamera::reset()
{
    setViewParams( m_vDefaultEye, m_vDefaultLookAt );
}






//========================================================================
// Constructor
//========================================================================
FirstPersonCamera::FirstPersonCamera() :
    m_nActiveButtonMask( 0x07 )
{
    m_bRotateWithoutButtonDown = false;
}




//========================================================================
// Update the view matrix based on user input & elapsed time
//========================================================================
void FirstPersonCamera::frameMove( float fElapsedTime )
{

#pragma message("ks777 gb::devhelp::FirstPersonCamera::framemove  ПРОВЕРИТЬ МЕТОД!  "  __FILE__)
  //  if( MYUTGetGlobalTimer()->IsStopped() )
	//{
  //      fElapsedTime = 1.0f / MYUTGetFPS();
	//}



    if( isKeyDown(m_aKeys[CAM_RESET]) )
        reset();

    // Get keyboard/mouse/gamepad input
    getInput( m_bEnablePositionMovement, (m_nActiveButtonMask & m_nCurrentButtonMask) || m_bRotateWithoutButtonDown, true, m_bResetCursorAfterMove );

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
		 vWorldUp.transformCoord(mCameraRot);

   // D 3DX Vec3TransformCoord( vWorldAhead, vLocalAhead, mCameraRot );
	 vWorldAhead = vLocalAhead;
	  vWorldAhead.transformCoord(mCameraRot);



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
	 vPosDeltaWorld.transformCoord(mCameraRot);


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
void FirstPersonCamera::setRotateButtons( bool bLeft, bool bMiddle, bool bRight, bool bRotateWithoutButtonDown )
{
    m_nActiveButtonMask = ( bLeft ? MOUSE_LEFT_BUTTON : 0 ) |
                          ( bMiddle ? MOUSE_MIDDLE_BUTTON : 0 ) |
                          ( bRight ? MOUSE_RIGHT_BUTTON : 0 );
    m_bRotateWithoutButtonDown = bRotateWithoutButtonDown;
}


//========================================================================
ModelViewerCamera::ModelViewerCamera()
{
    m_mWorld.reset(); // D 3 D X MatrixIdentity( m_mWorld );
    m_mModelRot.reset(); //  D 3 D X MatrixIdentity( m_mModelRot );
    m_mModelLastRot.reset(); // D 3 D X MatrixIdentity( m_mModelLastRot );    
    m_mCameraRotLast.reset(); // D 3 D X MatrixIdentity( m_mCameraRotLast );    
    m_vModelCenter = vec3(0,0,0);
    m_fRadius    = 5.0f;
    m_fDefaultRadius = 5.0f;
    m_fMinRadius = 1.0f;
    m_fMaxRadius = FLT_MAX;
    m_bLimitPitch = false;
    m_bEnablePositionMovement = false;
    m_bAttachCameraToModel = false;

    m_nRotateModelButtonMask  = MOUSE_LEFT_BUTTON;
    m_nZoomButtonMask         = MOUSE_WHEEL;
    m_nRotateCameraButtonMask = MOUSE_RIGHT_BUTTON;
    m_bDragSinceLastUpdate    = true;
}




//========================================================================
// Update the view matrix & the model's world matrix based 
//       on user input & elapsed time
//========================================================================
void ModelViewerCamera::frameMove( float fElapsedTime )
{
    if( isKeyDown(m_aKeys[CAM_RESET]) )
        reset();

    // If no dragged has happend since last time FrameMove is called,
    // and no camera key is held down, then no need to handle again.
    if( !m_bDragSinceLastUpdate && 0 == m_cKeysDown )
        return;
    m_bDragSinceLastUpdate = false;

    // Get keyboard/mouse/gamepad input
    getInput( m_bEnablePositionMovement, m_nCurrentButtonMask != 0, true, false );

    // Get amount of velocity based on the keyboard input and drag (if any)
    updateVelocity( fElapsedTime );

    // Simple euler method to calculate position delta
    vec3 vPosDelta = m_vVelocity * fElapsedTime;

    // Change the radius from the camera to the model based on wheel scrolling
    if( m_nMouseWheelDelta && m_nZoomButtonMask == MOUSE_WHEEL )
        m_fRadius -= m_nMouseWheelDelta * m_fRadius * 0.1f;
    m_fRadius = __min( m_fMaxRadius, m_fRadius );
    m_fRadius = __max( m_fMinRadius, m_fRadius );
    m_nMouseWheelDelta = 0;

    // Get the inverse of the arcball's rotation matrix
    mat44 mCameraRot;
    //D 3DXMatrixInverse( mCameraRot, NULL, m_ViewArcBall.getRotationMatrix() );
	 mCameraRot = m_ViewArcBall.getRotationMatrix().inverted();


    // Transform vectors based on camera's rotation matrix
    vec3 vWorldUp, vWorldAhead;
    vec3 vLocalUp    = vec3(0,1,0);
    vec3 vLocalAhead = vec3(0,0,1);


   // D 3DX Vec3TransformCoord( vWorldUp, vLocalUp, mCameraRot );
	 vWorldUp = vLocalUp;
	 vWorldUp.transformCoord(mCameraRot);


   // D 3DX Vec3TransformCoord( vWorldAhead, vLocalAhead, mCameraRot );
		vWorldAhead =   vLocalAhead;
		vWorldAhead.transformCoord(mCameraRot);



    // Transform the position delta by the camera's rotation 
    vec3 vPosDeltaWorld;
    //D 3DX Vec3TransformCoord( vPosDeltaWorld, vPosDelta, mCameraRot );
		vPosDeltaWorld = vPosDelta;
		vPosDeltaWorld.transformCoord(mCameraRot);



    // Move the lookAt position 
    m_vLookAt += vPosDeltaWorld;
    if( m_bClipToBoundary )
        constrainToBoundary( &m_vLookAt );

    // Update the eye point based on a radius away from the lookAt position
    m_vEye = m_vLookAt - vWorldAhead * m_fRadius;

    // Update the view matrix
    //D 3DXMatrixLookAtLH( m_mView, m_vEye, m_vLookAt, vWorldUp );
	 m_mView.setViewLookAtLH(m_vEye, m_vLookAt, vWorldUp);


    mat44 mInvView;
    //D 3DXMatrixInverse( mInvView, NULL, m_mView );
		mInvView = m_mView.inverted();

    mInvView._41 = mInvView._42 = mInvView._43 = 0;


    mat44 mModelLastRotInv;
    //D 3DXMatrixInverse(mModelLastRotInv, NULL, m_mModelLastRot);
		mModelLastRotInv =	m_mModelLastRot.inverted();

    // Accumulate the delta of the arcball's rotation in view space.
    // Note that per-frame delta rotations could be problematic over long periods of time.
    mat44 mModelRot;
    mModelRot = m_WorldArcBall.getRotationMatrix();
    m_mModelRot *= m_mView * mModelLastRotInv * mModelRot * mInvView;

    if( m_ViewArcBall.isBeingDragged() && m_bAttachCameraToModel && !isKeyDown(m_aKeys[CAM_CONTROLDOWN]) )
    {

        // Attach camera to model by inverse of the model rotation
        mat44 mCameraLastRotInv;
        //D 3DXMatrixInverse(mCameraLastRotInv, NULL, m_mCameraRotLast);
		  mCameraLastRotInv = m_mCameraRotLast.inverted();

        mat44 mCameraRotDelta = mCameraLastRotInv * mCameraRot; // local to world matrix
        m_mModelRot *= mCameraRotDelta;
    }
    m_mCameraRotLast = mCameraRot; 

    m_mModelLastRot = mModelRot;

    // Since we're accumulating delta rotations, we need to orthonormalize 
    // the matrix to prevent eventual matrix skew
    vec3* pXBasis = (vec3*) &m_mModelRot._11;
    vec3* pYBasis = (vec3*) &m_mModelRot._21;
    vec3* pZBasis = (vec3*) &m_mModelRot._31;

    //D 3DX Vec3Normalize( *pXBasis, *pXBasis );
	 pXBasis->normalize();

//    D 3DX Vec3Cross( *pYBasis, *pZBasis, *pXBasis );
	 *pYBasis = pZBasis->cross(*pXBasis);

    // D 3DX Vec3Normalize( *pYBasis, *pYBasis );
	  pYBasis->normalize();

  //  D 3DX Vec3Cross( *pZBasis, *pXBasis, *pYBasis );
    *pZBasis = pXBasis->cross(  *pYBasis  );


    // Translate the rotation matrix to the same position as the lookAt position
    m_mModelRot._41 = m_vLookAt.x;
    m_mModelRot._42 = m_vLookAt.y;
    m_mModelRot._43 = m_vLookAt.z;

    // Translate world matrix so its at the center of the model
    mat44 mTrans;
    //D 3DXMatrixTranslation( mTrans, -m_vModelCenter.x, -m_vModelCenter.y, -m_vModelCenter.z );
	 mTrans.setTranslation( -m_vModelCenter.x, -m_vModelCenter.y, -m_vModelCenter.z   );

    m_mWorld = mTrans * m_mModelRot;
}


void ModelViewerCamera::setDragRect( RECT &rc )
{
    BaseCamera::setDragRect( rc );

    m_WorldArcBall.setOffset( rc.left, rc.top );
    m_ViewArcBall.setOffset( rc.left, rc.top );
    setWindow( rc.right - rc.left, rc.bottom - rc.top );
}


//========================================================================
// Reset the camera's position back to the default
//========================================================================
void ModelViewerCamera::reset()
{
    BaseCamera::reset();

  m_mWorld.reset(); //  D 3 DXMatrixIdentity( m_mWorld );
  m_mModelRot.reset(); //  D 3 DXMatrixIdentity( m_mModelRot );
  m_mModelLastRot.reset(); //  D 3 DXMatrixIdentity( m_mModelLastRot );    
  m_mCameraRotLast.reset(); //  D 3 DXMatrixIdentity( m_mCameraRotLast );    

    m_fRadius = m_fDefaultRadius;
    m_WorldArcBall.reset();
    m_ViewArcBall.reset();
}


//========================================================================
// Override for setting the view parameters
//========================================================================
void ModelViewerCamera::setViewParams( const vec3& pvEyePt, const vec3& pvLookatPt )
{
    BaseCamera::setViewParams( pvEyePt, pvLookatPt );

    // Propogate changes to the member arcball
    Quaternion quat;
    mat44 mRotation;
    vec3 vUp(0,1,0);
    //D 3DXMatrixLookAtLH( mRotation, pvEyePt, pvLookatPt, vUp );
		 mRotation.setViewLookAtLH(  pvEyePt, pvLookatPt, vUp    );

   // D 3DX QuaternionRotationMatrix( quat, mRotation );
  quat.setRotationMatrix(mRotation);

    m_ViewArcBall.setQuatNow( quat );

    // Set the radius according to the distance
    vec3 vEyeToPoint;
    //D 3DXVec3Subtract( vEyeToPoint, pvLookatPt, pvEyePt );
//#pragma message("ks777::devhelp::ModelViewerCamera::setViewParams  ВОЗМОЖНО НЕПРАВИЛЬНО"   __FILE__)
	  vEyeToPoint =  pvEyePt -   pvLookatPt;

	  //D 3DX Vec3Length( vEyeToPoint   );
    setRadius( vEyeToPoint.length()  );   

    // View information changed. FrameMove should be called.
    m_bDragSinceLastUpdate = true;
}



//========================================================================
// Call this from your message proc so this class can handle window messages
//========================================================================
LRESULT ModelViewerCamera::handleMessages( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    BaseCamera::handleMessages( hWnd, uMsg, wParam, lParam );

    if( ( (uMsg == WM_LBUTTONDOWN || uMsg == WM_LBUTTONDBLCLK ) && m_nRotateModelButtonMask & MOUSE_LEFT_BUTTON) ||
        ( (uMsg == WM_MBUTTONDOWN || uMsg == WM_MBUTTONDBLCLK ) && m_nRotateModelButtonMask & MOUSE_MIDDLE_BUTTON) ||
        ( (uMsg == WM_RBUTTONDOWN || uMsg == WM_RBUTTONDBLCLK ) && m_nRotateModelButtonMask & MOUSE_RIGHT_BUTTON) )
    {
        int iMouseX = (short)LOWORD(lParam);
        int iMouseY = (short)HIWORD(lParam);
        m_WorldArcBall.onBegin( iMouseX, iMouseY );
    }

    if( ( (uMsg == WM_LBUTTONDOWN || uMsg == WM_LBUTTONDBLCLK ) && m_nRotateCameraButtonMask & MOUSE_LEFT_BUTTON) ||
        ( (uMsg == WM_MBUTTONDOWN || uMsg == WM_MBUTTONDBLCLK ) && m_nRotateCameraButtonMask & MOUSE_MIDDLE_BUTTON) ||
        ( (uMsg == WM_RBUTTONDOWN || uMsg == WM_RBUTTONDBLCLK ) && m_nRotateCameraButtonMask & MOUSE_RIGHT_BUTTON) )
    {
        int iMouseX = (short)LOWORD(lParam);
        int iMouseY = (short)HIWORD(lParam);
        m_ViewArcBall.onBegin( iMouseX, iMouseY );
    }

    if( uMsg == WM_MOUSEMOVE )
    {
        int iMouseX = (short)LOWORD(lParam);
        int iMouseY = (short)HIWORD(lParam);
        m_WorldArcBall.onMove( iMouseX, iMouseY );
        m_ViewArcBall.onMove( iMouseX, iMouseY );
    }

    if( (uMsg == WM_LBUTTONUP && m_nRotateModelButtonMask & MOUSE_LEFT_BUTTON) ||
        (uMsg == WM_MBUTTONUP && m_nRotateModelButtonMask & MOUSE_MIDDLE_BUTTON) ||
        (uMsg == WM_RBUTTONUP && m_nRotateModelButtonMask & MOUSE_RIGHT_BUTTON) )
    {
        m_WorldArcBall.onEnd();
    }

    if( (uMsg == WM_LBUTTONUP && m_nRotateCameraButtonMask & MOUSE_LEFT_BUTTON) ||
        (uMsg == WM_MBUTTONUP && m_nRotateCameraButtonMask & MOUSE_MIDDLE_BUTTON) ||
        (uMsg == WM_RBUTTONUP && m_nRotateCameraButtonMask & MOUSE_RIGHT_BUTTON) )
    {
        m_ViewArcBall.onEnd();
    }

    if( uMsg == WM_CAPTURECHANGED )
    {
        if( (HWND)lParam != hWnd )
        {
            if( (m_nRotateModelButtonMask & MOUSE_LEFT_BUTTON) ||
                (m_nRotateModelButtonMask & MOUSE_MIDDLE_BUTTON) ||
                (m_nRotateModelButtonMask & MOUSE_RIGHT_BUTTON) )
            {
                m_WorldArcBall.onEnd();
            }
        
            if( (m_nRotateCameraButtonMask & MOUSE_LEFT_BUTTON) ||
                (m_nRotateCameraButtonMask & MOUSE_MIDDLE_BUTTON) ||
                (m_nRotateCameraButtonMask & MOUSE_RIGHT_BUTTON) )
            {
                m_ViewArcBall.onEnd();
            }
        }
    }

    if( uMsg == WM_LBUTTONDOWN ||
        uMsg == WM_LBUTTONDBLCLK ||
        uMsg == WM_MBUTTONDOWN ||
        uMsg == WM_MBUTTONDBLCLK ||
        uMsg == WM_RBUTTONDOWN ||
        uMsg == WM_RBUTTONDBLCLK ||
        uMsg == WM_LBUTTONUP ||
        uMsg == WM_MBUTTONUP ||
        uMsg == WM_RBUTTONUP ||
        uMsg == WM_MOUSEWHEEL ||
        uMsg == WM_MOUSEMOVE )
    {
        m_bDragSinceLastUpdate = true;
    }

    return FALSE;
}

 
}// end namespace

#endif // #ifdef WIN32
