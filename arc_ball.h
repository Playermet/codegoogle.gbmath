/** \file  
  \brief class To rotate the camera

*/

#pragma once

#ifdef WIN32  // only for windows platform

namespace gbmath
{


class arc_ball  {
public:
    arc_ball(bool cameraLeftHandle=true);

    // Functions to change behavior
    void reset(); 
    void setTranslationRadius( float fRadiusTranslation ) 
	{ 
		m_fRadiusTranslation = fRadiusTranslation; 
	}

	void setWindow( INT nWidth, INT nHeight, float fRadius = 0.9f ) 
	{ 
		m_nWidth = nWidth; 
		m_nHeight = nHeight; 
		m_fRadius = fRadius; 
		m_vCenter = vec2(m_nWidth/2.0f,m_nHeight/2.0f); 
	}

    void setOffset( INT nX, INT nY ) 
	{ 
		m_Offset.x = nX; 
		m_Offset.y = nY; 
	}

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

    const mat44& getTranslationMatrix() const          
	{ 
		return m_mTranslation; 
	}

	const mat44& getTranslationDeltaMatrix() const     
	{ 
		return m_mTranslationDelta; 
	}

    bool        isBeingDragged() const 
	{ 
		return m_bDrag; 
	}

    Quaternion getQuatNow() const  
	{ 
		return m_qNow; 
	}

    void        setQuatNow( Quaternion q ) 
	{ 
		m_qNow = q; 
	}

    static Quaternion quatFromBallPoints( const vec3 &vFrom, 
												const vec3 &vTo, bool leftHandle=true );


protected:

	const bool m_bArcBallLeftHandle;


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

}

#endif  // win32
