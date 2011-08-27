#pragma once

#ifdef WIN32

#include "_gbmath.h"



namespace gbmath
{



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
    float x   = -(fScreenPtX - m_Offset.x - m_nWidth/2)  / 
							(m_fRadius*m_nWidth/2);

    float y   =  (fScreenPtY - m_Offset.y - m_nHeight/2) / 
							(m_fRadius*m_nHeight/2);

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

	   float K_MULT = 1.0f;
		if(CAMERA_LEFT_HANDLE)
		{
		  K_MULT = 1.0f;
		}
		else
		{
	      K_MULT = - 1.0f;
		}
	 

			   /*ksacvet777 не был минус  */ 
    float fDot = K_MULT *    vFrom.dot(vTo);//  D 3DX Vec3Dot(vFrom, vTo);

     // D 3DX Vec3Cross(vPart, vFrom, vTo);
	   vPart = vFrom.cross(vTo);

							  /*ksacvet777 не был минус  */ 

    return Quaternion( K_MULT *  vPart.x,  vPart.y,  vPart.z, fDot);
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
        m_vCurrentPt = screenToVector(  (float)nX  ,  (float)nY  );
        m_qNow = m_qDown * quatFromBallPoints( m_vDownPt, m_vCurrentPt );
    }
}




//=========================================================================
void arc_ball::onEnd()
{
    m_bDrag = false;
}


//=========================================================================
LRESULT arc_ball::handleMessages( HWND hWnd, UINT uMsg, WPARAM wParam,
										LPARAM lParam )
{
    // Current mouse position
    int iMouseX =    (short)LOWORD(lParam);
    int iMouseY = (short)HIWORD(lParam);

	switch( uMsg )
	{
	case WM_LBUTTONDOWN:
	case WM_LBUTTONDBLCLK:
		SetCapture( hWnd );
		onBegin(   iMouseX , iMouseY   );
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
						   	 
			float fDeltaX = (m_ptLastMouse.x-iMouseX  ) * m_fRadiusTranslation / m_nWidth;
			float fDeltaY = ( m_ptLastMouse.y-iMouseY ) * m_fRadiusTranslation / m_nHeight;

			if( wParam & MK_RBUTTON )
			{
				//D 3DXMatrixTranslation( m_mTranslationDelta, -2 * fDeltaX, 2 * fDeltaY, 0.0f );
					m_mTranslationDelta.setTranslation ( -2 * fDeltaX, 
													2 * fDeltaY, 0.0f );

				//D 3DXMatrixMultiply( m_mTranslation, m_mTranslation, m_mTranslationDelta );
				 m_mTranslation =m_mTranslation	* m_mTranslationDelta;
			}
			else  // wParam & MK_MBUTTON
			{
				//D 3DXMatrixTranslation( m_mTranslationDelta, 0.0f, 0.0f, 5 * fDeltaY );
				 m_mTranslationDelta.setTranslation( 0.0f, 0.0f, 
													5 * fDeltaY  );

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

 

}

#endif   // win32
