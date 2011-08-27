/**  \file
 \brief The target chamber, which can be set objective observation

*/

#pragma once

namespace gbmath
{

	//! \brief The target chamber, which can be set objective observation
	class TargetCamera {
	public:

		TargetCamera() 
		{ 
			m_pvTarget=NULL; m_bNeedUpdateView=true; 
			m_vEyePt = vec3(5.0f , 0.0f , -0.0f);
			m_vUp   = vec3( 0.0f , 1.0f , 0.0f );
		}

	 //! \brief  Set a target cell, or NULL if no goal.
	 void setViewTarget( vec3* pvTarget ) 
	 { 
		 m_pvTarget=pvTarget; 
		 m_bNeedUpdateView=true; 
	 }
	 
	 void setViewPosition( const vec3& vPos )
	 { 
		 m_vEyePt=vPos; 
		 m_bNeedUpdateView=true; 
	 }

	 void setViewUp( const vec3& vUp ) 
	 { 
		 m_vUp=vUp; 
		 m_bNeedUpdateView=true; 
	 }

	 void setProjParams( float fFOV, float fAspect, float fNearPlane, float fFarPlane )
	 {
	   //D 3DX MatrixPerspectiveFovLH(m_mProj, fFOV, fAspect, fNearPlane, fFarPlane );
		m_mProj.setPerspectiveFovLH( fFOV, fAspect, fNearPlane, fFarPlane );

	 }

		   mat44& getViewMatrix()       { return m_mView; }
	 const mat44& getViewMatrix() const { return m_mView; }

		   mat44& getProjMatrix()       { return m_mProj; }
	 const mat44& getProjMatrix() const { return m_mProj; }

	 //! \brief  Update. Call before rendering the frame. Or more, if the target has moved.
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
		mat44     m_mView;  ///< View matrix 
		mat44     m_mProj;  ///< Projection matrix

		vec3  m_vEyePt;
		vec3  m_vUp;

		bool m_bNeedUpdateView;
	};


}
