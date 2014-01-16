/** \file  
 \brief  First-person camera. windows only

*/

#pragma once

#ifdef WIN32

namespace gbmath
{



	//! \brief First-person camera.  windows only.  Uses window messages for reading keyboard: forward, backward, left, right, up, down  
	class first_person_camera : public base_camera 
	{
	public:

				  first_person_camera();
		virtual  ~first_person_camera() {}

	#ifdef _D3D9_H_
		//! \brief Make the current camera
		virtual HRESULT makeCurrent(IDirect3DDevice9* pDevice) 
		{
		  HRESULT hr =0;
		   // hr |= pDevice->SetTransform( D3DTS_WORLD ,  GetWorldMatrix() );
		   hr |= pDevice->SetTransform(D3DTS_VIEW ,  getViewMatrix() );
		   hr |= pDevice->SetTransform(D3DTS_PROJECTION ,  getProjMatrix() );

		  return hr;
		}
	#endif

		//! \brief Call these from client and use Get*Matrix()  to read new matrices
		virtual void frameMove( float fElapsedTime );

		//  Functions to change behavior
		void setRotateButtons( bool bLeft, bool bMiddle, bool bRight, bool bRotateWithoutButtonDown = false );

		void setResetCursorAfterMove( bool bResetCursorAfterMove ) 
		{ 
			m_bResetCursorAfterMove = bResetCursorAfterMove; 
		}

		   // Functions to get state

		mat44&  getWorldMatrix()           
		{ 
			return m_mCameraWorld; 
		}

	   const mat44&  getWorldMatrix() const 
	   { 
		   return m_mCameraWorld; 
	   }


		const vec3* getWorldRight() const 
		{ 
			return (vec3*)&m_mCameraWorld._11; 
		}

		const vec3* getWorldUp() const   
		{ 
			return (vec3*)&m_mCameraWorld._21; 
		}

		const vec3* getWorldAhead() const 
		{ 
			return (vec3*)&m_mCameraWorld._31; 
		}

		const vec3* getEyePoint() const     
		{ 
			return (vec3*)&m_mCameraWorld._41; 
		}

	protected:

		mat44   m_mCameraWorld;       ///< World matrix of the camera (inverse of the view matrix)

		int        m_nActiveButtonMask;  ///< Mask to determine which button to enable for rotation
		bool       m_bRotateWithoutButtonDown;

		bool       m_bResetCursorAfterMove; ///< If true, the class will reset the cursor position so that the cursor always has space to move 

	};
	 
}

#endif 
