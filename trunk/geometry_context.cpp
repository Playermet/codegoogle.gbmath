#pragma once

#include "_gbmath.h"


namespace gbmath
{

	// constants ...

		static const char* CSTR_VIEWPROJECTION = "VIEWPROJECTION";
		static const char* CSTR_VIEWPROJECTIONINVERSE = "VIEWPROJECTIONINVERSE";
		static const char* CSTR_VIEWPROJECTIONINVERSETRANSPONE = "VIEWPROJECTIONINVERSETRANSPONE";
		static const char* CSTR_VIEWPROJECTIONTRANSPONE = "VIEWPROJECTIONTRANSPONE";
		static const char* CSTR_VIEW = "VIEW";
		static const char* CSTR_VIEWTRANSPONE = "VIEWTRANSPONE";
		static const char* CSTR_VIEWINVERSE = "VIEWINVERSE";
		static const char* CSTR_VIEWINVERSETRANSPONE = "VIEWINVERSETRANSPONE";
		static const char* CSTR_PROJECTION = "PROJECTION";
		static const char* CSTR_PROJECTIONINVERSE = "PROJECTIONINVERSE";
		static const char* CSTR_PROJECTIONTRANSPONE = "PROJECTIONTRANSPONE";
		static const char* CSTR_PROJECTIONINVERSETRANSPONE = "PROJECTIONINVERSETRANSPONE";
		static const char* CSTR_WORLDVIEWPROJECTION = "WORLDVIEWPROJECTION";
		static const char* CSTR_WORLDVIEWPROJECTIONTRANSPONE = "WORLDVIEWPROJECTIONTRANSPONE";
		static const char* CSTR_WORLDVIEWPROJECTIONINVERSE = "WORLDVIEWPROJECTIONINVERSE";
		static const char* CSTR_WORLDVIEWPROJECTIONINVERSETRANSPONE = "WORLDVIEWPROJECTIONINVERSETRANSPONE";
		static const char* CSTR_WORLD = "WORLD";
		static const char* CSTR_WORLDTRANSPONE = "WORLDTRANSPONE";
		static const char* CSTR_WORLDINVERSE = "WORLDINVERSE";
		static const char* CSTR_WORLDINVERSETRANSPONE = "WORLDINVERSETRANSPONE";
		static const char* CSTR_WORLDVIEW = "WORLDVIEW";
		static const char* CSTR_WORLDVIEWTRANSPONE = "WORLDVIEWTRANSPONE";
		static const char* CSTR_WORLDVIEWINVERSE = "WORLDVIEWINVERSE";
		static const char* CSTR_WORLDVIEWINVERSETRANSPONE = "WORLDVIEWINVERSETRANSPONE";





//=========================================================================
//				geometry_context
//=========================================================================



//=========================================================================
long  geometry_context::setMatrices(const mat44 *mWorld, const mat44 *mView, const mat44 *mProj)
{
  long  hr = 0;

  if (mWorld)
  {
    m_mWorld =  *mWorld;
    m_BoolChangedMatr.bWorldChange = true;
    m_bMouseCoordCameraUnproject_change = true;


    m_matr.mWorldViewProjection.bChangeFlag = 1;
    m_matr.mWorldViewProjectionTranspone.bChangeFlag = 1;
    m_matr.mWorldViewProjectionInverse.bChangeFlag = 1;
    m_matr.mWorldViewProjectionInverseTranspone.bChangeFlag =  1 ;

    m_matr.mWorldTranspone.bChangeFlag =  1 ;
    m_matr.mWorldInverse.bChangeFlag =  1 ;
    m_matr.mWorldInverseTranspone.bChangeFlag =  1 ;
    m_matr.mWorldView.bChangeFlag =  1 ;
    m_matr.mWorldViewTranspone.bChangeFlag =  1 ;
    m_matr.mWorldViewInverse.bChangeFlag =  1 ;
    m_matr.mWorldViewInverseTranspone.bChangeFlag =  1 ;


  } // if(mWorld)

  if (mView)
  {
    m_mView =  *mView;
    m_BoolChangedMatr.bViewChange = true;
    m_bMouseCoordCameraUnproject_change = true;

    m_matr.mViewProjection.bChangeFlag =  1 ;
    m_matr.mViewProjectionInverse.bChangeFlag =  1 ;
    m_matr.mViewProjectionInverseTranspone.bChangeFlag =  1 ;
    m_matr.mViewProjectionTranspone.bChangeFlag =  1 ;

    m_matr.mViewTranspone.bChangeFlag =  1 ;
    m_matr.mViewInverse.bChangeFlag =  1 ;
    m_matr.mViewInverseTranspone.bChangeFlag =  1 ;

    m_matr.mWorldViewProjection.bChangeFlag =  1 ;
    m_matr.mWorldViewProjectionTranspone.bChangeFlag =  1 ;
    m_matr.mWorldViewProjectionInverse.bChangeFlag =  1 ;
    m_matr.mWorldViewProjectionInverseTranspone.bChangeFlag =  1 ;

    m_matr.mWorldView.bChangeFlag =  1 ;
    m_matr.mWorldViewTranspone.bChangeFlag =  1 ;
    m_matr.mWorldViewInverse.bChangeFlag =  1 ;
    m_matr.mWorldViewInverseTranspone.bChangeFlag =  1 ;

  } // if(mView)


  if (mProj)
  {
    m_bChangeProjectionData = true;
    m_mProj =  *mProj;
    m_BoolChangedMatr.bProjChange = true;
    m_bMouseCoordCameraUnproject_change = true;

    m_matr.mViewProjection.bChangeFlag =  1 ;
    m_matr.mViewProjectionInverse.bChangeFlag =  1 ;
    m_matr.mViewProjectionInverseTranspone.bChangeFlag =  1 ;
    m_matr.mViewProjectionTranspone.bChangeFlag =  1 ;

    m_matr.mProjectionInverse.bChangeFlag =  1 ;
    m_matr.mProjectionTranspone.bChangeFlag =  1 ;
    m_matr.mProjectionInverseTranspone.bChangeFlag =  1 ;

    m_matr.mWorldViewProjection.bChangeFlag =  1 ;
    m_matr.mWorldViewProjectionTranspone.bChangeFlag =  1 ;
    m_matr.mWorldViewProjectionInverse.bChangeFlag =  1 ;
    m_matr.mWorldViewProjectionInverseTranspone.bChangeFlag =  1 ;


  } // if(mProj)


   long lres =0;
   lres=onNewMatrices(mWorld, mView, mProj);


  //if (pdvc)
  //{

  //  if (mWorld)
  //  {
  //    hr |= pdvc->SetTransform(D3DTS_WORLD, &m_mWorld);
  //  };

  //  if (mView)
  //  {
  //    hr |= pdvc->SetTransform(D3DTS_VIEW, &m_mView);
  //  };

  //  if (mProj)
  //  {
  //    hr |= pdvc->SetTransform(D3DTS_PROJECTION, &m_mProj);
  //  };

  //}
  //else
  //{
  //  MONPRINT("device is NULL");
  //  hr |= S_FALSE;

  //};



  return hr;
};

//====================================================================
const mat44 *geometry_context::get_matrix_ViewProjection()const
{
  if (m_matr.mViewProjection .bChangeFlag)
  {
    //MMUL(&m_matr.mViewProjection.matrix, &m_mView, &m_mProj);
	m_matr.mViewProjection.matrix = m_mView * m_mProj;

    m_matr.mViewProjection .bChangeFlag =  0 ;
  }

  return  &m_matr.mViewProjection.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_ViewProjectionInverse()const
{
  if (m_matr.mViewProjectionInverse.bChangeFlag)
  {
    //MMUL(&m_temp, &m_mView, &m_mProj);
	m_temp = m_mView * m_mProj;

    //D3DXMatrixInverse(&m_matr.mViewProjectionInverse.matrix, NULL, &m_temp);
	m_matr.mViewProjectionInverse.matrix = m_temp.inverted();

    m_matr.mViewProjectionInverse.bChangeFlag =  0 ;
  }

  return  &m_matr.mViewProjectionInverse.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_ViewProjectionInverseTranspone()const
{
  if (m_matr.mViewProjectionInverseTranspone.bChangeFlag)
  {
   // MMUL(&m_temp, &m_mView, &m_mProj);
	 m_temp  = m_mView * m_mProj;

   // D3DXMatrixInverse(&m_temp2, NULL, &m_temp);
	m_temp2.invert();

    //D3DXMatrixTranspose(&m_matr.mViewProjectionInverseTranspone.matrix, &m_temp2);
	 m_matr.mViewProjectionInverseTranspone.matrix=m_temp2.transponed();


    m_matr.mViewProjectionInverseTranspone.bChangeFlag =  0 ;
  }

  return  &m_matr.mViewProjectionInverseTranspone.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_ViewProjectionTranspone()const
{
  if (m_matr.mViewProjectionTranspone.bChangeFlag)
  {
   // MMUL(&m_temp, &m_mView, &m_mProj);
	m_temp = m_mView * m_mProj;
    //D3DXMatrixTranspose(&m_matr.mViewProjectionTranspone.matrix, &m_temp);


    m_matr.mViewProjectionTranspone.bChangeFlag =  1 ;
  }

  return  &m_matr.mViewProjectionTranspone.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_ViewTranspone()const
{
  if (m_matr.mViewTranspone.bChangeFlag)
  {
   // D3DXMatrixTranspose(&m_matr.mViewTranspone.matrix, &m_mView);
   m_matr.mViewTranspone.matrix = m_mView.transponed();

    m_matr.mViewTranspone.bChangeFlag =  0 ;
  }

  return  &m_matr.mViewTranspone.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_ViewInverse()const
{
  if (m_matr.mViewInverse.bChangeFlag)
  {
   // D3DXMatrixInverse(&m_matr.mViewInverse.matrix, NULL, &m_mView);
	m_matr.mViewInverse.matrix = m_mView.inverted();

    m_matr.mViewInverse.bChangeFlag =  0 ;
  }

  return  &m_matr.mViewInverse.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_ViewInverseTranspone()const
{
  if (m_matr.mViewInverseTranspone.bChangeFlag)
  {
    //D3DXMatrixInverse(&m_temp, NULL, &m_mView);
	 m_temp = m_mView.inverted();
   // D3DXMatrixTranspose(&m_matr.mViewInverseTranspone.matrix, &m_temp);
   m_matr.mViewInverseTranspone.matrix = m_temp.transponed();

    m_matr.mViewInverseTranspone.bChangeFlag =  0 ;
  }

  return  &m_matr.mViewInverseTranspone.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_ProjectionInverse()const
{
  if (m_matr.mProjectionInverse.bChangeFlag)
  {
    //D3DXMatrixInverse(&m_matr.mProjectionInverse.matrix, NULL, &m_mProj);
	m_matr.mProjectionInverse.matrix = m_mProj.inverted();

    m_matr.mProjectionInverse.bChangeFlag =  0 ;
  }

  return  &m_matr.mProjectionInverse.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_ProjectionTranspone()const
{
  if (m_matr.mProjectionTranspone.bChangeFlag)
  {
   // D3DXMatrixTranspose(&m_matr.mProjectionTranspone.matrix, &m_mProj);
	 m_matr.mProjectionTranspone.matrix = m_mProj.transponed();

    m_matr.mProjectionTranspone.bChangeFlag =  0 ;
  }

  return  &m_matr.mProjectionTranspone.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_ProjectionInverseTranspone()const
{
  if (m_matr.mProjectionInverseTranspone.bChangeFlag)
  {
   // D3DXMatrixInverse(&m_temp, NULL, &m_mProj);
	  m_temp = m_mProj.inverted();
   // D3DXMatrixTranspose(&m_matr.mProjectionInverseTranspone.matrix, &m_temp);
	 m_matr.mProjectionInverseTranspone.matrix = m_temp.transponed();

    m_matr.mProjectionInverseTranspone.bChangeFlag =  0 ;
  }

  return  &m_matr.mProjectionInverseTranspone.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_WorldViewProjection()const
{
  if (m_matr.mWorldViewProjection.bChangeFlag)
  {
   // MMUL(&m_temp, &m_mView, &m_mProj);
   m_temp = m_mView * m_mProj;

   // MMUL(&m_matr.mWorldViewProjection.matrix, &m_mWorld, &m_temp);
   m_matr.mWorldViewProjection.matrix = m_mWorld * m_temp;

    m_matr.mWorldViewProjection.bChangeFlag =  1 ;
  }

  return  &m_matr.mWorldViewProjection.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_WorldViewProjectionTranspone()const
{
  if (m_matr.mWorldViewProjectionTranspone.bChangeFlag)
  {
    //MMUL(&m_temp, &m_mView, &m_mProj);
		  m_temp = m_mView * m_mProj;
    //MMUL(&m_temp2, &m_mWorld, &m_temp);
		  m_temp2 = m_mWorld * m_temp;

//    D3DXMatrixTranspose(&m_matr.mWorldViewProjectionTranspone.matrix, &m_temp2);
	 m_matr.mWorldViewProjectionTranspone.matrix = m_temp2.transponed();

    m_matr.mWorldViewProjectionTranspone.bChangeFlag =  0 ;
  }

  return  &m_matr.mWorldViewProjectionTranspone.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_WorldViewProjectionInverse()const
{
  if (m_matr.mWorldViewProjectionInverse.bChangeFlag)
  {
    //MMUL(&m_temp, &m_mView, &m_mProj);
		  m_temp =m_mView * m_mProj;

    //MMUL(&m_temp2, &m_mWorld, &m_temp);
		  m_temp2 =m_mWorld * m_temp;

//    D3DXMatrixInverse(&m_matr.mWorldViewProjectionInverse.matrix, NULL, &m_temp2);
	 m_matr.mWorldViewProjectionInverse.matrix = m_temp2.inverted();

    m_matr.mWorldViewProjectionInverse.bChangeFlag =  0 ;
  }

  return  &m_matr.mWorldViewProjectionInverse.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_WorldViewProjectionInverseTranspone()const
{
  mat44 temp;
  if (m_matr.mWorldViewProjectionInverseTranspone.bChangeFlag)
  {
    //MMUL(&m_temp, &m_mView, &m_mProj);
		  m_temp =m_mView * m_mProj;
    //MMUL(&m_temp2, &m_mWorld, &m_temp);
		 m_temp2 =m_mWorld * m_temp;


   // D3DXMatrixInverse(&temp, NULL, &m_temp2);
	   temp = m_temp2.inverted();

//    D3DXMatrixTranspose(&m_matr.mWorldViewProjectionInverseTranspone.matrix, &temp);
	  m_matr.mWorldViewProjectionInverseTranspone.matrix=temp.transponed();

    m_matr.mWorldViewProjectionInverseTranspone.bChangeFlag =  0 ;
  }

  return  &m_matr.mWorldViewProjectionInverseTranspone.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_WorldTranspone()const
{
  if (m_matr.mWorldTranspone.bChangeFlag)
  {
    //D3DXMatrixTranspose(&m_matr.mWorldTranspone.matrix, &m_mWorld);
	m_matr.mWorldTranspone.matrix=m_mWorld.transponed();

    m_matr.mWorldTranspone.bChangeFlag =  0 ;
  }

  return  &m_matr.mWorldTranspone.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_WorldInverse()const
{
  if (m_matr.mWorldInverse.bChangeFlag)
  {
   // D3DXMatrixInverse(&m_matr.mWorldInverse.matrix, NULL, &m_mWorld);
		m_matr.mWorldInverse.matrix = m_mWorld.inverted();

    m_matr.mWorldInverse.bChangeFlag =  0 ;
  }

  return  &m_matr.mWorldInverse.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_WorldInverseTranspone()const
{
  if (m_matr.mWorldInverseTranspone.bChangeFlag)
  {
   // D3DXMatrixInverse(&m_temp, NULL, &m_mWorld);
	 m_temp = m_mWorld.inverted();

    //D3DXMatrixTranspose(&m_matr.mWorldInverseTranspone.matrix, &m_temp);
	m_matr.mWorldInverseTranspone.matrix=m_temp.transponed();

    m_matr.mWorldInverseTranspone.bChangeFlag =  0 ;
  }

  return  &m_matr.mWorldInverseTranspone.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_WorldView()const
{
  if (m_matr.mWorldView .bChangeFlag)
  {
    //MMUL(&m_matr.mWorldView.matrix, &m_mWorld, &m_mView);
    m_matr.mWorldView.matrix * m_mWorld * m_mView;

    m_matr.mWorldView.bChangeFlag =  0 ;
  }

  return  &m_matr.mWorldView.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_WorldViewTranspone()const
{
  if (m_matr.mWorldViewTranspone.bChangeFlag)
  {
    //MMUL(&m_temp, &m_mWorld, &m_mView);
	   m_temp = m_mWorld * m_mView;

    //D3DXMatrixTranspose(&m_matr.mWorldViewTranspone.matrix, &m_temp);
	m_matr.mWorldViewTranspone.matrix=m_temp.transponed();

    m_matr.mWorldViewTranspone.bChangeFlag =  0 ;
  }

  return  &m_matr.mWorldViewTranspone.matrix;
};

//#error ДОДЕЛАТЬ ДАЛЬШЕ !!!!


//====================================================================
const mat44 *geometry_context::get_matrix_WorldViewInverse()const
{
  if (m_matr.mWorldViewInverse.bChangeFlag)
  {
    //MMUL(&m_temp, &m_mWorld, &m_mView);
	m_temp =  m_mWorld * m_mView;

    //D3DXMatrixInverse(&m_matr.mWorldViewInverse.matrix, NULL, &m_temp);
 m_matr.mWorldViewInverse.matrix = m_temp.inverted();


    m_matr.mWorldViewInverse.bChangeFlag =  0 ;
  };
  return  &m_matr.mWorldViewInverse.matrix;
};

//====================================================================
const mat44 *geometry_context::get_matrix_WorldViewInverseTranspone()const
{
  if (m_matr.mWorldViewInverseTranspone.bChangeFlag)
  {
   // MMUL(&m_temp, &m_mWorld, &m_mView);
	 m_temp = m_mWorld * m_mView;


    //D3DXMatrixInverse(&m_temp2, NULL, &m_temp);
	 m_temp2 = m_temp.inverted();

   // D3DXMatrixTranspose(&m_matr.mWorldViewInverseTranspone.matrix, &m_temp2);
   m_matr.mWorldViewInverseTranspone.matrix = m_temp2.inverted();

    m_matr.mWorldViewInverseTranspone.bChangeFlag =  0 ;
  };
  return  &m_matr.mWorldViewInverseTranspone.matrix;
};

//=====================================================================
const vec4* geometry_context::get_vector4_by_context_type(
	     const vector_context_type_e::e val) const
{
  switch(val)
  {

  case vector_context_type_e::VIEWPOSITION:
	  {
	  return get_vector4_ViewPos();
	  }
	  break;

  case vector_context_type_e::VIEWDIRECTION:
	  {
	  return get_vector4_ViewDir();
	  }
	  break;

  case vector_context_type_e::VIEWUP:
	  {
	  return get_vector4_ViewUp();
	  }
	  break;

  case vector_context_type_e::VIEWSIDE:
	  {
	  return get_vector4_ViewSide();
	  }
	  break;


  default:
	  {

	  }
  }

  assert(false && " not found ! ");
  return NULL;
};

//====================================================================
const mat44 * geometry_context::get_matrix_by_context_type(
				const matrix4x4_context_type_e::e  val
				) const
{
  switch(val)
  {

		case matrix4x4_context_type_e::VIEWPROJECTION:
			{
				return get_matrix_ViewProjection();
			}
			break;

		case matrix4x4_context_type_e::VIEWPROJECTIONINVERSE:
			{
				return get_matrix_ViewProjectionInverse();
			}
			break;

		case matrix4x4_context_type_e::VIEWPROJECTIONINVERSETRANSPONE:
			{
				return get_matrix_ViewProjectionInverseTranspone();
			}
			break;

		case matrix4x4_context_type_e::VIEWPROJECTIONTRANSPONE:
			{
				return get_matrix_ViewProjectionTranspone();
			}
			break;


		//================================


		case matrix4x4_context_type_e::VIEW:
			{
				return get_matrix_View();
			}
			break;

		case matrix4x4_context_type_e::VIEWTRANSPONE:
			{
				return get_matrix_ViewTranspone();
			}
			break;

		case matrix4x4_context_type_e::VIEWINVERSE:
			{
				return  get_matrix_ViewInverse();
			}
			break;

		case matrix4x4_context_type_e::VIEWINVERSETRANSPONE:
			{
				return  get_matrix_ViewInverseTranspone();
			}
			break;





		case matrix4x4_context_type_e::PROJECTION:
			{
				return  get_matrix_Proj();
			}
			break;

		case matrix4x4_context_type_e::PROJECTIONINVERSE:
			{
				return  get_matrix_ProjectionInverse();
			}
			break;

		case matrix4x4_context_type_e::PROJECTIONTRANSPONE:
			{
				return get_matrix_ProjectionTranspone();
			}
			break;

		case matrix4x4_context_type_e::PROJECTIONINVERSETRANSPONE:
			{
				return get_matrix_ProjectionInverseTranspone();
			}
			break;



		case matrix4x4_context_type_e::WORLDVIEWPROJECTION:
			{
				return get_matrix_WorldViewProjection();
			}
			break;

		case matrix4x4_context_type_e::WORLDVIEWPROJECTIONTRANSPONE:
			{
				return get_matrix_WorldViewProjectionTranspone();
			}
			break;

		case matrix4x4_context_type_e::WORLDVIEWPROJECTIONINVERSE:
			{
				return get_matrix_WorldViewProjectionInverse();
			}
			break;

		case matrix4x4_context_type_e::WORLDVIEWPROJECTIONINVERSETRANSPONE:
			{
				return get_matrix_WorldViewProjectionInverseTranspone();
			}
			break;

		case matrix4x4_context_type_e::WORLD:
			{
				return get_matrix_World();
			}
			break;

		case matrix4x4_context_type_e::WORLDTRANSPONE:
			{
				return get_matrix_WorldTranspone();
			}
			break;

		case matrix4x4_context_type_e::WORLDINVERSE:
			{
				return get_matrix_WorldInverse();
			}
			break;

	   //========================


		case matrix4x4_context_type_e::WORLDINVERSETRANSPONE:
			{
				return get_matrix_WorldInverseTranspone();
			}
			break;

		case matrix4x4_context_type_e::WORLDVIEW:
			{
				return get_matrix_WorldView();
			}
			break;


		case matrix4x4_context_type_e::WORLDVIEWTRANSPONE:
			{
				return get_matrix_WorldViewTranspone();
			}
			break;

		case matrix4x4_context_type_e::WORLDVIEWINVERSE:
			{
				return get_matrix_WorldViewInverse();
			}
			break;

		case matrix4x4_context_type_e::WORLDVIEWINVERSETRANSPONE:
			{
				return get_matrix_WorldViewInverseTranspone();
			}
			break;


  default:
	  {

	  }
  }


	// not found !!
  assert(false && "matrix not found");
	return NULL;
}

//====================================================================
void geometry_context::__checkViewVectors()const
{
  if (m_matr.mViewInverse.bChangeFlag)
  {
    get_matrix_ViewInverse();

    m_VewPos = *((vec3*) &m_matr.mViewInverse.matrix._41);
    m_ViewDir = *((vec3*) &m_matr.mViewInverse.matrix._31);
    m_ViewUp = *((vec3*) &m_matr.mViewInverse.matrix._21);
  };
};

//====================================================================
const vec4 *geometry_context::get_vector4_ViewPos()const
{
  __checkViewVectors();
  m_vec4Temp.x = m_VewPos.x;
  m_vec4Temp.y = m_VewPos.y;
  m_vec4Temp.z = m_VewPos.z;
  m_vec4Temp.w = 1.0f;
  return  &m_vec4Temp;
};

//====================================================================
const vec4 *geometry_context::get_vector4_ViewDir()const
{
  __checkViewVectors();
  m_vec4Temp.x = m_ViewDir.x;
  m_vec4Temp.y = m_ViewDir.y;
  m_vec4Temp.z = m_ViewDir.z;
  m_vec4Temp.w = 1.0f;
  return  &m_vec4Temp;
};

//====================================================================
const vec4 *geometry_context::get_vector4_ViewUp()const
{
  __checkViewVectors();
  m_vec4Temp.x = m_ViewUp.x;
  m_vec4Temp.y = m_ViewUp.y;
  m_vec4Temp.z = m_ViewUp.z;
  m_vec4Temp.w = 1.0f;
  return  &m_vec4Temp;
};

//====================================================================
const vec3 *geometry_context::get_vector3_ViewSide()const
{

 // D3DXVec3Cross(&m_vec3Temp, &m_ViewDir, &m_ViewUp);
  m_vec3Temp =	m_ViewDir.cross( m_ViewUp );


  return  &m_vec3Temp;
};

//====================================================================
const vec4 *geometry_context::get_vector4_ViewSide()const
{
  vec3 res =  *get_vector3_ViewUp();
  m_vec4Temp.x = res.x;
  m_vec4Temp.y = res.y;
  m_vec4Temp.z = res.z;
  m_vec4Temp.w = 1.0f;
  return  &m_vec4Temp;
};

 /************************
//==================================================================
const vec3 *geometry_context::GetMouseCoordCameraUnproject()const
{
  //ViewportZ  vp ;
  //  POINT  pntMouseCoord ;

  // get viewport and mouse coord
  const DAPLIB_RenderContext *prcontext = DAPL_GetRenderContext();

  POINT msCoord = RWnd_GetWindowCursorPosition();

  return GetMouseCoordCameraUnproject(GetViewPortPtr(), &GetPointCursorWindowPosition() // &prcontext->GetPointCursorWindowPosition();

  );
};

//==================================================================
const vec3 *geometry_context::get_vector3_Unproject(const  ViewportZ *vp, const  POINT *pntCoord)const
{
  vec3 vsrc;
  vsrc.x = (FLOAT)pntCoord->x;
  vsrc.y = (FLOAT)pntCoord->y;
  vsrc.z = 0.0f;



  ViewportZ __viewport;

  if (vp)
  {
    __viewport =  *vp;
  }
  else
  {
    //const DAPLIB_RenderContext* prcontext =  DAPL_GetRenderContext();
    // viewport = prcontext->viewport;
    __viewport =  *GetViewPortPtr();
  }


  static vec3 res[4];


  static int nCurrResult = 0;
  nCurrResult++;
  if (nCurrResult >= 4)
  {
    nCurrResult = 0;
  }

  vec3 *pResult = &res[nCurrResult];





  D3DXVec3Unproject(pResult,  // vec3 * pOut,
   &vsrc,  //CONST vec3 * pV,
   &__viewport,  //CONST ViewportZ * pViewport,
  get_matrix_Proj(),  //CONST mat44 * pProjection,
  get_matrix_View(),  //CONST mat44 * pView,
  get_matrix_World() // CONST mat44 * pWorld
  );



  return pResult;
};

//====================================================================
const vec3 *geometry_context::GetMouseCoordCameraUnproject(const ViewportZ *vp, const POINT *pntMouseCoord)const
{

  if (m_bMouseCoordCameraUnproject_change)
  {
    // compute
    vec3 vsrc;
    vsrc.x = (FLOAT)pntMouseCoord->x;
    vsrc.y = (FLOAT)pntMouseCoord->y;
    vsrc.z = 0.0f;

    D3DXVec3Unproject( &m_vec3_MouseCoordCameraUnproject,  // vec3 * pOut,
     &vsrc,  //CONST vec3 * pV,
    vp,  //CONST ViewportZ * pViewport,
    get_matrix_Proj(),  //CONST mat44 * pProjection,
    get_matrix_View(),  //CONST mat44 * pView,
    get_matrix_World() // CONST mat44 * pWorld
    );


    m_bMouseCoordCameraUnproject_change = false;
  };

  return  &m_vec3_MouseCoordCameraUnproject;
};
 ************************************/

const vec3 *geometry_context::get_vector3_VewPos()const
{
  __checkViewVectors();
  return  &m_VewPos;
};
const vec3 *geometry_context::get_vector3_ViewDir()const
{
  __checkViewVectors();
  return  &m_ViewDir;
};
const vec3 *geometry_context::get_vector3_ViewUp()const
{
  __checkViewVectors();
  return  &m_ViewUp;
};


//===============================================
const perspective_projection_data *geometry_context::get_projection_Data()const
{
  if (m_BoolChangedMatr.bProjChange)
  {

    if (m_bChangeProjectionData)
    {
    //  D3DXEX_ExtractProjPerspectLH(m_PerspectiveProjData.fFovy, m_PerspectiveProjData.fAspect, m_PerspectiveProjData.fZnear, m_PerspectiveProjData.fZfar, get_matrix_Proj());
	 m_PerspectiveProjData.extractProjPerspectLH(m_mProj);

      m_bChangeProjectionData =  0 ;

    } // if


  }; // if


  return  &m_PerspectiveProjData;
};


/****************************

//============================================================
int  geometry_context::PushMatrixWorld()const
{
  int  hr = 0;

  if (m_MatrixStackWorld.full())
    return (-1);

  try
  {
    m_MatrixStackWorld.top() =  *get_matrix_World();
    m_MatrixStackWorld.push();

  }
  catch(...)
  {
    hr |= (-1);
  };


  return hr;
};

//============================================================
int  geometry_context::PushMatrixView()const
{
  int  hr = 0;
  if (m_MatrixStackView.full())
    return (-1);

  try
  {
    m_MatrixStackView.top() =  *get_matrix_View();
    m_MatrixStackView.push();

  }
  catch(...)
  {
    hr |= (-1);
  };


  return hr;
};

//============================================================
int  geometry_context::PushMatrixProj()const
{
  int  hr = 0;

  if (m_MatrixStackProj.full())
    return (-1);

  try
  {
    m_MatrixStackProj.top() =  *get_matrix_Proj();
    m_MatrixStackProj.push();

  }
  catch(...)
  {
    hr |= (-1);
  };


  return hr;
};

//============================================================
int  geometry_context::PushMatrices(BOOLFLAG bWorld, BOOLFLAG bView, BOOLFLAG bProj)const
{
  int  hr = 0;



  //const mat44* pmw = NULL;
  if (bWorld)
  {
    if (m_MatrixStackWorld.full())
    {
      MONPRINT(" MatrixStackWorld is full");
      hr |= (-1);
    }
    else
    {
      *m_MatrixStackWorld.top_ptr() =  *get_matrix_World();
      m_MatrixStackWorld.push();
    }

  };

  //const mat44* pmv = NULL;
  if (bView)
  {
    if (m_MatrixStackView.full())
    {
      MONPRINT(" MatrixStackView is full");
      hr |= (-1);
    }
    else
    {
      *m_MatrixStackView.top_ptr() =  *get_matrix_View();
      m_MatrixStackView.push();
    }
  };

  //const mat44* pmp = NULL;
  if (bProj)
  {
    if (m_MatrixStackProj.full())
    {
      MONPRINT(" MatrixStackProj is full");
      hr |= (-1);
    }
    else
    {
      *m_MatrixStackProj.top_ptr() =  *get_matrix_Proj();
      m_MatrixStackProj.push();
    }

  };


  return hr;
};



//============================================================
int  geometry_context::PopMatrixWorld()const
{
  int  hr = 0;


  if (m_MatrixStackWorld.empty())
    return S_FALSE;

  hr |= setMatrices(m_MatrixStackWorld.top_ptr(), 0, 0);
  m_MatrixStackWorld.pop();

  return hr;
};

//============================================================
int  geometry_context::PopMatrixView()const
{
  int  hr = 0;

  if (m_MatrixStackView.empty())
    return S_FALSE;

  hr |= setMatrices(0, m_MatrixStackView.top_ptr(), 0);
  m_MatrixStackView.pop();

  return hr;
};

//============================================================
int  geometry_context::PopMatrixProj()const
{
  int  hr = 0;

  if (m_MatrixStackProj.empty())
    return S_FALSE;

  hr |= setMatrices(0, 0, m_MatrixStackProj.top_ptr());
  m_MatrixStackProj.pop();

  return hr;
};

//============================================================
int  geometry_context::PopMatrices(BOOLFLAG bWorld, BOOLFLAG bView, BOOLFLAG bProj)const
{
  int  hr = 0;



  const mat44 *pmw = NULL;
  if (bWorld)
  {
    pmw = m_MatrixStackWorld.top_ptr();
  };

  const mat44 *pmv = NULL;
  if (bView)
  {
    pmv = m_MatrixStackView.top_ptr();
  };


  const mat44 *pmp = NULL;
  if (bProj)
  {
    pmp = m_MatrixStackProj.top_ptr();
  };


  hr |= setMatrices(pmw, pmv, pmp);


  return hr;
};


//=======================================================
int  geometry_context::PopAllMatrices()const
{
  int  hr = 0;

  return PopMatrices(1, 1, 1);

};
****************************************/

//=======================================================
eyedata geometry_context::getViewParams()const
{
  eyedata res =  *getViewParamsPtr();
  return res;
};

//=======================================================
const eyedata *geometry_context::getViewParamsPtr()const
{
	assert(false);
#pragma message ( "geometry_context::getViewParamsPtr :: ПОГОНЯТЬ В ОТЛАДКЕ ЭТОТ МЕТОД  "  __FILE__ )


  const mat44 *pmViewInv = get_matrix_ViewInverse();

  if (m_bIsParameter_EyeData_changed)
  {
	 m_EyeData.decomposeInverseView(m_matr.mViewInverse.matrix);

   // #pragma message ("ПРОВЕРИТЬ ПОЛУЧЕНИЕ ВЕКТОРОВ  ВИДА ИЗ ИНВЕРСНОЙ ВИДОВОЙ МАТРИЦЫ ")
   // m_EyeData.eye_position = *((vec3*) &m_matr.mViewInverse.matrix._41);
   // vec3 vViewDir = *((vec3*) &m_matr.mViewInverse.matrix._31);
   // m_EyeData.eye_up = *((Normal3*) &m_matr.mViewInverse.matrix._21);

    #pragma message("ks777  ПРОВЕРИТЬ !!!!  " __FILE__)
      assert(false&&"NEED CKECK!! ");
   // float fDistToCenter = vViewDir.length();  // D3DXVec3Length(&vViewDir);

	/**
    m_EyeData.eye_up = m_EyeData.eye_position;
    m_EyeData.eye_up.x() += fDistToCenter;
    m_EyeData.eye_up.y() += fDistToCenter;
    m_EyeData.eye_up.z() += fDistToCenter;
	   */

    m_bIsParameter_EyeData_changed =  0 ;
  }

  return  &m_EyeData;
};



//===========================================================
int  geometry_context::setViewParams(const  vec3 *eye, const  vec3 *at, const  vec3 *up)
{
  int  hr = 0;

  eyedata vp = getViewParams();

  if (eye)
    vp.eye_position=  *eye;

  if (at)
    vp.eye_at=  *at;

  if (up)
    vp.eye_up =  *up;

  hr |= setViewParams(&vp);

  return hr;
};

//===========================================================
int  geometry_context::setViewParams(const eyedata *pvp)
{
  int  hr = 0;

  mat44 mv;
  m_EyeData =  *pvp;

//  D3DXMatrixLookAtLH(&mv, &m_EyeData.eye_position, &m_EyeData.eye_up, &m_EyeData.eye_up);

  mv.setViewLookAtLH( m_EyeData.eye_position, m_EyeData.eye_at, m_EyeData.eye_up  );


  hr |= set_matrix_View(&mv);
  m_bIsParameter_EyeData_changed =  0 ;
  return hr;
};

//===========================================================
int  geometry_context::setViewEye(const vec3 *eye)
{
  int  hr = 0;

  eyedata vp = getViewParams();
  vp.eye_position =  *eye;
  hr |= setViewParams(&vp);

  return hr;
};

//===========================================================
int  geometry_context::setViewAt(const vec3 *at)
{
  int  hr = 0;

  eyedata vp = getViewParams();
  vp.eye_at =  *at;
  hr |= setViewParams(&vp);

  return hr;
};

//===========================================================
int  geometry_context::setViewUp(const vec3 *up)
{
  int  hr = 0;

  eyedata vp = getViewParams();
  vp.eye_up =  *up;
  hr |= setViewParams(&vp);

  return hr;
};

//===========================================================




//==============================================
int  geometry_context::setProjectionParams(float fFov, float fAsp, float fZNear, float fZFar)
{
  int  hr = 0;

  perspective_projection_data pd;

  pd.fovy = fFov;
  pd.aspect = fAsp;
  pd.zn = fZNear;
  pd.zf = fZFar;

  hr |= setProjectionParams(&pd);

  return hr;
};

//===================================
int  geometry_context::setProjectionParams(const perspective_projection_data *proj)
{
  int  hr = 0;
  try
  {

    mat44 mproj;
   // D3DXMatrixPerspectiveFovLH(&mproj, proj->fFovy, proj->fAspect, proj->fZnear, proj->fZfar);
   mproj.setPerspectiveFovLH(proj->fovy, proj->aspect, proj->zn, proj->zf);


	hr |= set_matrix_Proj(&mproj);

  }
  catch(...)
  {
    hr |= (-1);
  }

  return hr;
};

//==============================================
int  geometry_context::setProjectionFov(float fFov)
{
  int  hr = 0;

  try
  {
    perspective_projection_data proj =  *get_projection_Data();
    proj.fovy = fFov;
    setProjectionParams(&proj);
  }
  catch(...)
  {
    //MONPRINT("Exception ");
    hr |= (-1);
  };

  return hr;
};

//===================================================
int  geometry_context::setProjectionAsp(float fAsp)
{
  int  hr = 0;


  try
  {
    perspective_projection_data proj =  *get_projection_Data();
    proj.aspect = fAsp;
    setProjectionParams(&proj);
  }
  catch(...)
  {
    //MONPRINT("Exception ");
    hr |= (-1);
  };


  return hr;

};

//===================================================
int  geometry_context::setProjectionZNear(float fZNear)
{
  int  hr = 0;

  try
  {
    perspective_projection_data proj =  *get_projection_Data();
    proj.zn = fZNear;
    setProjectionParams(&proj);
  }
  catch(...)
  {
//    MONPRINT("Exception ");
    hr |= (-1);
  };


  return hr;
};

//===================================================
int  geometry_context::setProjectionZFar(float fZFar)
{
  int  hr = 0;

  try
  {
    perspective_projection_data proj =  *get_projection_Data();
    proj.zf = fZFar;
    setProjectionParams(&proj);
  }
  catch(...)
  {
    hr |= -1;
  }

  return hr;
}

//=====================================================
int  geometry_context::setProjectionZNearZFar(float fZNear, float fZFar)
{
  int  hr = 0;

  try
  {
    perspective_projection_data proj =  *get_projection_Data();
    proj.zn = fZNear;
    proj.zf = fZFar;
    setProjectionParams(&proj);
  }
  catch(...)
  {
//    MONPRINT("Exception ");
    hr |= (-1);
  };

  return hr;
};

//==========================================
TransformData  geometry_context::getWorldTransformData()const
{
  TransformData  res =  *getWorldTransformDataPtr();
  return res;
};


//==========================================
const TransformData  *geometry_context::getWorldTransformDataPtr()const
{

  if (m_bTransfDataChange)
  {



    const mat44 *mw = get_matrix_World();



   /**********  OLD  CODE :  *******
    int  hrDecomp = D3DXMatrixDecompose(
		&m_TransformData.vSc,  //vec3 * pOutScale,
     &m_qRotation,  //Quaternion * pOutRotation,
     &m_TransformData.vTranslation ,  //  vec3 * pOutTranslation,
    mw  // CONST mat44 * pM
    );
	*************/

	// new
   mw->decompose(
	   m_TransformData.vScaling,  //vec3 * pOutScale,
	   m_TransformData.qRotation,  //Quaternion * pOutRotation,
	   m_TransformData.vTranslation   //  vec3 * pOutTranslation,
	   );


  //  if FAILED(hrDecomp)
  //  {
    //  throw std::runtime_error("Error decompose matrix");
   // }


   // D3DXQuaternionToAxisAngle( &m_qRotation,  // CONST Quaternion * pQ,
   //  &m_TransformData.rot.vRotAx,  //vec3 * pAxis,
   //  &m_TransformData.rot.fAngle  //  FLOAT * pAngle
  //  );


   assert(false);
   // дальше нвадо разобраццо !!

	 // NEW !!!!
	// m_qRotation.toAxiesAngle(  m_TransformData.rot.vRotAx,  m_TransformData.rot.fAngle  );





    m_bTransfDataChange =  0 ;
  }; // if


  return  &m_TransformData;
};

//==========================================
vec3 geometry_context::getWorldScaling()const
{

  vec3 res = getWorldTransformDataPtr()->vScaling;

  return res;

};

//==========================================
axies_angle geometry_context::getWorldRotationAxiesAngle() const
{
	const TransformData  *ptd = getWorldTransformDataPtr();
	Quaternion qrot =  ptd->qRotation;
	return qrot.toAxiesAngle();
};

//==========================================
Quaternion geometry_context::getWorldRotationQuaternion() const
{
  // get const to check calculate
  const TransformData  *ptr = getWorldTransformDataPtr();
 
    #pragma message("ks777   Quaternion geometry_context::getWorldRotationQuaternion() const  Need check code    "  __FILE__ )
  assert(false);
	return ptr->qRotation;

  // OLD
  //return m_qRotation;
};

//==========================================
vec3 geometry_context::getWorldPosition()const
{

  const TransformData  *ptd = getWorldTransformDataPtr();

  return ptd->vTranslation;

};


//==========================================
int  geometry_context::setWorldTransformData(const TransformData  *pTr)
{
  int  hr = 0;

  m_bTransfDataChange = true;
  m_TransformData =  *pTr;

 /*****************************
  mat44 mscale, mrotate, mtransl;

 // D3DXMatrixTranslation(&mtransl, m_TransformData.vTrnsl.x,
//			m_TransformData.vTrnsl.y,
//			m_TransformData.vTrnsl.z);

   mtransl.setTranslation(
	   m_TransformData.vTranslation.x  ,
	   m_TransformData.vTranslation.y ,
	   m_TransformData.vTranslation.z );


 // D3DXMatrixRotationAxis(&mrotate, &m_TransformData.rot.vRotAx, m_TransformData.rot.fAngle);
  mrotate.setRotationAxis(m_TransformData.rot.vRotAx, m_TransformData.rot.fAngle);


 // D3DXMatrixScaling(&mscale, m_TransformData.vSc.x,
//	  m_TransformData.vSc.y,
//	  m_TransformData.vSc.z);

 mscale.setScaling(
	  m_TransformData.vScaling.x,
	  m_TransformData.vScaling.y,
	  m_TransformData.vScaling.z );

  mat44 mworld = mtransl * mscale * mrotate;
  ******************************/

   mat44 mworld;
   mworld.setTransformation(pTr->vScaling, pTr->qRotation, pTr->vTranslation);

  hr |= setMatrices(&mworld, NULL, NULL);



  return hr;
};

//==========================================
int  geometry_context::setWorldPositionVal(float x, float y, float z)
{
  int  hr = 0;
  TransformData  trd = getWorldTransformData();


  trd.vTranslation.x = x;
  trd.vTranslation.y = y;
  trd.vTranslation.z = z;

  hr |= setWorldTransformData(&trd);

  return hr;
};

//==========================================
int  geometry_context::setWorldPositionVec(const vec3 *pos)
{
  int  hr = 0;
  vec3 vpos =  *pos;
  hr |= setWorldPositionVal(vpos.x, vpos.y, vpos.z);

  return hr;
};


//==========================================
int  geometry_context::setWorldRotationYawPitchRoll(float yaw, float pitch, float roll)
{
  int  hr = 0;
  Quaternion q;

  //D3DXQuaternionRotationYawPitchRoll(&q, yaw, pitch, roll);
   q.setRotationYawPitchRoll(  yaw, pitch, roll )  ;

  hr |= setWorldRotationQuaternion(&q);

  return hr;
};

/********************************
int  geometry_context::setWorldRotationVal(float axX, float axY, float axZ, float angle)
{
  int  hr = 0;
  TransformData  trd = getWorldTransformData();


   assert(false);

   // НАДО ПОПРАВИТЬ ЭТОТ КОД!!!
//  trd.rot.vRotAx.x = axX;
 // trd.rot.vRotAx.y = axY;
//  trd.rot.vRotAx.z = axZ;

   // БЫЛО
 // D3DXVec3Normalize(&trd.rot.vRotAx, &trd.rot.vRotAx);
  // НАДО
  //>>>>>  trd.rot.normalize();


  hr |= setWorldTransformData(&trd);

  return hr;
};
*******************************/

//==========================================
int  geometry_context::setWorldRotationQuaternion(const Quaternion *q)
{
  int  hr = 0;
  TransformData  trd = getWorldTransformData();
//  m_qRotation =  *q;


 // D3DXQuaternionToAxisAngle( &m_qRotation,  // CONST Quaternion * pQ,
//   &trd.rot.vRotAx,  // vec3 * pAxis,
//   &trd.rot.fAngle  //  FLOAT * pAngle
//  );
trd.qRotation = *q;


 // m_qRotation.setRotationAxis(trd.rot.vRotAx, trd.rot.fAngle );



  mat44 world;

  /******************
  D3DXMatrixTransformation( &world,  //mat44 * pOut,
  NULL,  //CONST vec3 * pScalingCenter,
  NULL,  //CONST Quaternion * pScalingRotation,
   &trd.vSc,  // CONST vec3 * pScaling,
  NULL,  //CONST vec3 * pRotationCenter,
   &m_qRotation,  // CONST Quaternion * pRotation,
   &trd.vTrnsl  //  CONST vec3 * pTranslation
  );
  ***************/
   world.setTransformation(trd.vScaling , trd.qRotation , trd.vTranslation);


  m_bTransfDataChange = true;




  return hr;
};

//=========================================================================
int  geometry_context::setWorldRotationAxiesAngle(const vec3 *vAx, float angle )
{
  int  hr = 0;

  TransformData  trd = getWorldTransformData();


  vec3 vax_norm = vAx->normalized();
  trd.qRotation.setRotationAxis( vax_norm, angle );
 // trd.rot.vRotAx =  *vAx;
 // trd.rot.fAngle = angle;

   // D3DXVec3Normalize(&trd.rot.vRotAx, &trd.rot.vRotAx);
   // trd.rot.vRotAx.normalize();

  hr |= setWorldTransformData(&trd);

  return hr;
};


//=========================================================================
int  geometry_context::setWorldScaling(float val)
{
  int  hr = 0;
  hr |= setWorldScaling(val, val, val);

  return hr;
};

//=========================================================================
int  geometry_context::setWorldScaling(float x, float y, float z)
{
	int  hr = 0;

	TransformData  tr = getWorldTransformData();

	tr.vScaling.x = x;
	tr.vScaling.y = y;
	tr.vScaling.z = z;

	hr |= setWorldTransformData(&tr);
	return hr;
};

//=========================================================================
int  geometry_context::setWorldScalingVec(const vec3 *vSc)
{
  int  hr = 0;
  vec3 scale =  *vSc;
  hr |= setWorldScaling(scale.x, scale.y, scale.z);

  return hr;
};

//=========================================================================
int  geometry_context::setWorldScalingTranslation(float fScale, const vec3 *vTrnsl)
{
  int  hr = 0;
  TransformData  tr = getWorldTransformData();
  tr.vScaling.x = tr.vScaling.y = tr.vScaling.z = fScale;
  tr.vTranslation =  *vTrnsl;
  hr |= setWorldTransformData(&tr);

  return hr;
};

//=========================================================================
int  geometry_context::setWorldScalingTranslation(float fScale, float x, float y, float z)
{
  int  hr = 0;
  vec3 vtr;

  vtr.x = x;
  vtr.y = y;
  vtr.z = z;

  hr |= setWorldScalingTranslation(fScale, &vtr);

  return hr;
};
//
//#pragma message("ks777: NEED DELETE MAIN()  " __FILE__ )
//int main()
//{
//	return 0;
//}
//

//=========================================================================



//=================================================================
std::string  matrix4x4_context_type_e::tostr(const matrix4x4_context_type_e::e val)
{
	std::string res;


	switch(val)
	{

	case matrix4x4_context_type_e::VIEWPROJECTION:
		{
			res =  CSTR_VIEWPROJECTION;
		}
		break;

	case matrix4x4_context_type_e::VIEWPROJECTIONINVERSE:
		{
			res = CSTR_VIEWPROJECTIONINVERSE;
		}
		break;

	case matrix4x4_context_type_e::VIEWPROJECTIONINVERSETRANSPONE:
		{
			res = CSTR_VIEWPROJECTIONINVERSETRANSPONE;
		}
		break;

	case matrix4x4_context_type_e::VIEWPROJECTIONTRANSPONE:
		{
			res = CSTR_VIEWPROJECTIONTRANSPONE;
		}
		break;

	case matrix4x4_context_type_e::VIEW:
		{
			res = CSTR_VIEW;
		}
		break;

	case matrix4x4_context_type_e::VIEWTRANSPONE:
		{
			res = CSTR_VIEWTRANSPONE;
		}
		break;

	case matrix4x4_context_type_e::VIEWINVERSE:
		{
			res = CSTR_VIEWINVERSE;
		}
		break;

	case matrix4x4_context_type_e::VIEWINVERSETRANSPONE:
		{
			res = CSTR_VIEWINVERSETRANSPONE;
		}
		break;

	case matrix4x4_context_type_e::PROJECTION:
		{
			res = CSTR_PROJECTION;
		}
		break;

	case matrix4x4_context_type_e::PROJECTIONINVERSE:
		{
			res = CSTR_PROJECTIONINVERSE;
		}
		break;

	case matrix4x4_context_type_e::PROJECTIONTRANSPONE:
		{
			res = CSTR_PROJECTIONTRANSPONE;
		}
		break;

	case matrix4x4_context_type_e::PROJECTIONINVERSETRANSPONE:
		{
			res = CSTR_PROJECTIONINVERSETRANSPONE;
		}
		break;


	case matrix4x4_context_type_e::WORLDVIEWPROJECTION:
		{
			res = CSTR_WORLDVIEWPROJECTION;
		}
		break;

	case matrix4x4_context_type_e::WORLDVIEWPROJECTIONTRANSPONE:
		{
			res = CSTR_WORLDVIEWPROJECTIONTRANSPONE;
		}
		break;

	case matrix4x4_context_type_e::WORLDVIEWPROJECTIONINVERSE:
		{
			res = CSTR_WORLDVIEWPROJECTIONINVERSE;
		}
		break;

	case matrix4x4_context_type_e::WORLDVIEWPROJECTIONINVERSETRANSPONE:
		{
			res = CSTR_WORLDVIEWPROJECTIONINVERSETRANSPONE;
		}
		break;




	case matrix4x4_context_type_e::WORLD:
		{
			res = CSTR_WORLD;
		}
		break;


	case matrix4x4_context_type_e::WORLDTRANSPONE:
		{
			res = CSTR_WORLDTRANSPONE;
		}
		break;

	case matrix4x4_context_type_e::WORLDINVERSE:
		{
			res = CSTR_WORLDINVERSE;
		}
		break;

	case matrix4x4_context_type_e::WORLDINVERSETRANSPONE:
		{
			res = CSTR_WORLDINVERSETRANSPONE;
		}
		break;

	case matrix4x4_context_type_e::WORLDVIEW:
		{
			res = CSTR_WORLDVIEW;
		}
		break;

	case matrix4x4_context_type_e::WORLDVIEWTRANSPONE:
		{
			res = CSTR_WORLDVIEWTRANSPONE;
		}
		break;

	case matrix4x4_context_type_e::WORLDVIEWINVERSE:
		{
			res = CSTR_WORLDVIEWINVERSE;
		}
		break;

	case matrix4x4_context_type_e::WORLDVIEWINVERSETRANSPONE:
		{
			res = CSTR_WORLDVIEWINVERSETRANSPONE;
		}
		break;



	default:
		{

		}

	}

	return res;
}

//=================================================================
bool  matrix4x4_context_type_e::fromstr(
								matrix4x4_context_type_e::e& valOut,
							    const char* strArg
								)
{
	assert(strArg);
	std::string str =   strArg;
	for(size_t c=0; c<str.length(); c++)
	{
		str[c] = toupper(str[c]);
	}


	if( (str == CSTR_VIEWPROJECTION)||(str=="VIEWPROJ")||(str=="VP")||(str=="VIEWPROJECTION") )
	{
		valOut = matrix4x4_context_type_e::VIEWPROJECTION;
		return true;
	}

	if( (str==CSTR_VIEWPROJECTIONINVERSE)||(str=="VIEWPROJINV")||(str=="VPI")||(str=="VIEWPROJECTIONINVERSE") )
	{
		valOut = matrix4x4_context_type_e::VIEWPROJECTIONINVERSE;
		return true;
	}

	if( (str == CSTR_VIEWPROJECTIONINVERSETRANSPONE) ||
		(str=="CSTR_VIEWPROJINVTRANSP") || (str=="VPIT") || (str=="VIEWPROJECTIONINVERSETRANSPONE") )
	{
		valOut = matrix4x4_context_type_e::VIEWPROJECTIONINVERSETRANSPONE;
		return true;
	}





	// VIEWPROJECTIONTRANSPONE

	if( (str == CSTR_VIEWPROJECTIONTRANSPONE) || (str=="VIEWPROJTRANSP")
		|| (str=="VPT") || (str=="VIEWPROJECTIONTRANSPONE") )
	{
		valOut = matrix4x4_context_type_e::VIEWPROJECTIONTRANSPONE;
		return true;
	}


	if( str == CSTR_VIEW )
	{
		valOut = matrix4x4_context_type_e::VIEW;
		return true;
	}

	if( (str == CSTR_VIEWTRANSPONE) || (str=="VIEWTRANSP") || (str=="VT")||(str=="VIEWTRANSPONE") )
	{
		valOut = matrix4x4_context_type_e::VIEWTRANSPONE;
		return true;
	}

	//	VIEWINVERSE

	if( (str == CSTR_VIEWINVERSE) || (str=="VIEWINV") || (str=="VI") )
	{
		valOut = matrix4x4_context_type_e::VIEWINVERSE;
		return true;
	}






	// VIEWINVERSETRANSPONE

	if( (str == CSTR_VIEWINVERSETRANSPONE) || ( str == "VIEWINVTRANSP" )
		|| (str=="VIT"))
	{
		valOut = matrix4x4_context_type_e::VIEWINVERSETRANSPONE;
		return true;
	}


	if( (str == CSTR_PROJECTION) || ( str == "PROJ" ) )
	{
		valOut = matrix4x4_context_type_e::PROJECTION;
		return true;
	}




	if((str==CSTR_PROJECTIONINVERSE)||(str=="PROJINV")||(str=="PI") )
	{
		valOut = matrix4x4_context_type_e::PROJECTIONINVERSE;
		return true;
	}




	if( (str==CSTR_PROJECTIONTRANSPONE)||(str=="PROJTRANSP")||(str=="PT") )
	{
		valOut = matrix4x4_context_type_e::PROJECTIONTRANSPONE;
		return true;
	}


	if( (str==CSTR_PROJECTIONINVERSETRANSPONE) || (str=="CSTR_PROJINVTRANSP")
		|| (str=="PIT") )
	{
		valOut = matrix4x4_context_type_e::PROJECTIONINVERSETRANSPONE;
		return true;
	}

	if( (str == CSTR_WORLDVIEWPROJECTION)||(str=="WORLDVIEWPROJ")||(str=="WVP") )
	{
		valOut = matrix4x4_context_type_e::WORLDVIEWPROJECTION;
		return true;
	}


	if( (str==CSTR_WORLDVIEWPROJECTIONTRANSPONE)||(str=="WORLDVIEWPROJTRANSP")
		|| (str=="WVPT") )
	{
		valOut = matrix4x4_context_type_e::WORLDVIEWPROJECTIONTRANSPONE;
		return true;
	}




	if( (str==CSTR_WORLDVIEWPROJECTIONINVERSE) || (str=="WORLDVIEWPROJINV")
		|| (str=="WVPI") )
	{
		valOut = matrix4x4_context_type_e::WORLDVIEWPROJECTIONINVERSE;
		return true;
	}


	// WORLDVIEWPROJECTIONINVERSETRANSPONE

	if( (str == CSTR_WORLDVIEWPROJECTIONINVERSETRANSPONE)
		|| (str == "WORLDVIEWPROJINVTRANSP" )
		|| (str=="WVPIT") )
	{
		valOut = matrix4x4_context_type_e::WORLDVIEWPROJECTIONINVERSETRANSPONE;
		return true;
	}





	if( str == CSTR_WORLD )
	{
		valOut = matrix4x4_context_type_e::WORLD;
		return true;
	}




	if( (str == CSTR_WORLDTRANSPONE) || (str == "WORLDTRANSP")||(str=="WT") )
	{
		valOut = matrix4x4_context_type_e::WORLDTRANSPONE;
		return true;
	}





	if( (str==CSTR_WORLDINVERSE)||(str=="WORLDINV")||(str=="WI") )
	{
		valOut = matrix4x4_context_type_e::WORLDINVERSE;
		return true;
	}



	// WORLDINVERSETRANSPONE


	if( (str==CSTR_WORLDINVERSETRANSPONE)||(str=="WORLDINVTRANSP")||(str=="WIT") )
	{
		valOut = matrix4x4_context_type_e::WORLDINVERSETRANSPONE;
		return true;
	}




	if( (str==CSTR_WORLDVIEW)||(str=="WV") )
	{
		valOut = matrix4x4_context_type_e::WORLDVIEW;
		return true;
	}


	if( (str==CSTR_WORLDVIEWTRANSPONE)||(str == "WORLDVIEWTRANSP")||(str=="WVT") )
	{
		valOut = matrix4x4_context_type_e::WORLDVIEWTRANSPONE;
		return true;
	}



	if( (str==CSTR_WORLDVIEWINVERSE)||(str=="WORLDVIEWINV")||(str=="WVI") )
	{
		valOut = matrix4x4_context_type_e::WORLDVIEWINVERSE;
		return true;
	}


	//  WORLDVIEWINVERSETRANSPONE

	if( str == CSTR_WORLDVIEWINVERSETRANSPONE )
	{
		valOut = matrix4x4_context_type_e::WORLDVIEWINVERSETRANSPONE;
		return true;
	}

	if( str == "WORLDVIEWINVTRANSP" )
	{
		valOut = matrix4x4_context_type_e::WORLDVIEWINVERSETRANSPONE;
		return true;
	}

	if(str=="WVIT")
	{
		valOut = matrix4x4_context_type_e::WORLDVIEWINVERSETRANSPONE;
		return true;
	}



	return false;
}

//=================================================================
std::string   vector_context_type_e::tostr(const vector_context_type_e::e val)
{
	std::string res;
   switch(val)
   {

   case VIEWPOSITION:
	   {
	   res = "VIEWPOSITION";
	   }
	   break;

   case VIEWDIRECTION:
	   {
	   res = "VIEWDIRECTION";
	   }
	   break;

   case VIEWUP:
	   {
	   res = "VIEWUP";
	   }
	   break;

   case VIEWSIDE:
	   {
		res = "VIEWSIDE";
	   }
	   break;

   default:
	   {

	   }
   }

  return res;
};

//=================================================================
bool   vector_context_type_e::fromstr(vector_context_type_e::e& valOut, const char* strarg)
{

	std::string str = strarg;

	//__str_touper(str);
	for(size_t c=0; c<str.length(); c++ )
	{
		str[c] = toupper( str[c] );
	}



	if( ("VIEWPOSITION" == str) || ("VIEW_POSITION" == str) || ("VIEWPOS" == str))
	{
		valOut = VIEWPOSITION;
		return true;
	}

	if( ("VIEWDIRECTION" == str) || ("VIEW_DIRECTION" == str) || ("VIEWDIR" == str)  )
	{
		valOut = VIEWDIRECTION;
		return true;
	}

	if("VIEWUP" == str)
	{
		valOut = VIEWUP;
		return true;
	}

	if("VIEWSIDE" == str)
	{
		valOut = VIEWSIDE;
		return true;
	}


  return false;
};


}