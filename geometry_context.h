/**  \file
 \brief   яяяяячччччч


 * \todo УБрать FAILED SUCC и все виндовские макросы.
 * \todo Подружить с не windows ....

*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif



namespace gbmath
{




		//! \brief Геометрический контекст.
		class geometry_context  {
		public:
		             geometry_context() {}
		   virtual  ~geometry_context() {}


		  long  setMatrices(const  mat44 *mWorld,
						    const  mat44 *mView,
						    const  mat44 *mProj );

		  /** \brief Для перекрытия пользователем.  При изменении матриц.
					 Если матрица не меняется тогда параметр NULL.
					 возвращает результат установки матрицы.  */
		  virtual long onNewMatrices(const  mat44 *mWorld,
									 const  mat44 *mView,
									 const  mat44 *mProj )
		  {
		     return 0;
		  }

			inline long  set_matrix_World(const mat44 *m)
			{
			  return setMatrices(m, NULL, NULL);
			}

			inline long set_matrix_View(const mat44 *m)
			{
			  return setMatrices(NULL, m, NULL);
			}

			inline long set_matrix_Proj(const mat44 *m)
			{
			  return setMatrices(NULL, NULL, m);
			}


		  const mat44 *get_matrix_World()const
		  {
		    return  &m_mWorld;
		  }

		  const mat44 *get_matrix_View()const
		  {
		    return  &m_mView;
		  }

		  const mat44 *get_matrix_Proj()const
		  {
		    return  &m_mProj;
		  }


		  const mat44 *get_matrix_ViewProjection()const;
		  const mat44 *get_matrix_ViewProjectionInverse()const;
		  const mat44 *get_matrix_ViewProjectionInverseTranspone()const;
		  const mat44 *get_matrix_ViewProjectionTranspone()const;
		  const mat44 *get_matrix_ViewTranspone()const;
		  const mat44 *get_matrix_ViewInverse()const;
		  const mat44 *get_matrix_ViewInverseTranspone()const;

		  const mat44 *get_matrix_ProjectionInverse()const;
		  const mat44 *get_matrix_ProjectionTranspone()const;
		  const mat44 *get_matrix_ProjectionInverseTranspone()const;

		  const mat44 *get_matrix_WorldViewProjection()const;
		  const mat44 *get_matrix_WorldViewProjectionTranspone()const;
		  const mat44 *get_matrix_WorldViewProjectionInverse()const;
		  const mat44 *get_matrix_WorldViewProjectionInverseTranspone()const;
		  const mat44 *get_matrix_WorldTranspone()const;
		  const mat44 *get_matrix_WorldInverse()const;
		  const mat44 *get_matrix_WorldInverseTranspone()const;
		  const mat44 *get_matrix_WorldView()const;
		  const mat44 *get_matrix_WorldViewTranspone()const;
		  const mat44 *get_matrix_WorldViewInverse()const;
		  const mat44 *get_matrix_WorldViewInverseTranspone()const;



		  const vec3 *get_vector3_VewPos()const;
		  const vec3 *get_vector3_ViewDir()const;
		  const vec3 *get_vector3_ViewUp()const;
		  const vec3 *get_vector3_ViewSide()const;

		  const vec4 *get_vector4_ViewPos()const;
		  const vec4 *get_vector4_ViewDir()const;
		  const vec4 *get_vector4_ViewUp()const;
		  const vec4 *get_vector4_ViewSide()const;


		  const mat44 *get_matrix_by_context_type(const matrix4x4_context_type_e::e) const;
		  const vec4 *get_vector4_by_context_type(const vector_context_type_e::e) const;


		//  const vec3 *get_vector3_Unproject(const  ViewportZ *vp, const  POINT *pntCoord)const;

		 // const vec3 *GetMouseCoordCameraUnproject(const ViewportZ *vp, const POINT *pntMouseCoord)const;
		 // const vec3 *GetMouseCoordCameraUnproject()const;

		  const perspective_projection_data *get_projection_Data()const;

		  float get_projection_Fov()const
		  {
		    const perspective_projection_data *prj = get_projection_Data();
		    return prj->fovy;
		  }

		  float get_projection_Aspect()const
		  {
		    const perspective_projection_data *prj = get_projection_Data();
		    return prj->aspect;
		  }

		  float get_projection_ZNear()const
		  {
		    const perspective_projection_data *prj = get_projection_Data();
		    return prj->zn;
		  }

		  float get_projection_ZFar()const
		  {
		    const perspective_projection_data *prj = get_projection_Data();
		    return prj->zf;
		  }

		   /* ****************************************
		  int  PushMatrixWorld()const;
		  int  PushMatrixView()const;
		  int  PushMatrixProj()const;

		  int  PushMatrices(BOOLFLAG bWorld, BOOLFLAG bView, BOOLFLAG bProj)const;
		  inline int  PushAllMatrices()const
		  {
		    PushMatrices(1, 1, 1);
		  }

		  int  PopMatrixWorld()const;
		  int  PopMatrixView()const;
		  int  PopMatrixProj()const;


		  int  PopMatrices(BOOLFLAG bWorld, BOOLFLAG bView, BOOLFLAG bProj)const;
		  int  PopAllMatrices()const;

		    int  set_matrix_World(const mat44 *m)const;
		    int  set_matrix_View(const mat44 *m)const;
		    int  set_matrix_Proj(const mat44 *m)const;

			***************************************************/



		   eyedata getViewParams()const;
		    const eyedata *getViewParamsPtr()const;


		    int  setViewParams(const  vec3 *eye, const  vec3 *at, const  vec3 *up) ;
		    int  setViewParams(const eyedata *pvp) ;

		    int  setViewEye(const vec3 *eye) ;
		    int  setViewAt(const vec3 *at) ;
		    int  setViewUp(const vec3 *up) ;

		    int  setProjectionParams(float fFov, float fAsp, float fZNear, float fZFar) ;
			int  setProjectionParams(const perspective_projection_data *proj) ;
		    int  setProjectionFov(float fFov) ;
		    int  setProjectionAsp(float fAsp) ;
		    int  setProjectionZNear(float fZNear) ;
		    int  setProjectionZFar(float fZFar) ;
		    int  setProjectionZNearZFar(float fZNear, float fZFar) ;

		  //-----------------------------------------------------------------------


		    TransformData  getWorldTransformData()const;
		    const TransformData  *getWorldTransformDataPtr()const;

		    vec3 getWorldScaling()const;


		    axies_angle getWorldRotationAxiesAngle()const;

		    Quaternion getWorldRotationQuaternion()const;


		    vec3 getWorldPosition()const;

		    int  setWorldTransformData(const TransformData  *pTr) ;

		    int  setWorldPositionVal(float x, float y, float z) ;
		    int  setWorldPositionVec(const vec3 *pos) ;

		    int  setWorldRotationYawPitchRoll(float yaw, float pitch, float roll) ;
		//    int  setWorldRotationVal(float axX, float axY, float axZ, float angle) ;
		    int  setWorldRotationQuaternion(const Quaternion *q) ;
		    int  setWorldRotationAxiesAngle(const vec3 *vAx, float angle) ;

		    int  setWorldScaling(float val) ;
		    int  setWorldScaling(float x, float y, float z) ;
		    int  setWorldScalingVec(const vec3 *vSc) ;

		    int  setWorldScalingTranslation(float fScale, const vec3 *vTrnsl) ;
		    int  setWorldScalingTranslation(float fScale, float x, float y, float z) ;

			int  setWorldIdentity()
			{
			   mat44 mident(1.0f);
				return setMatrices(&mident, NULL, NULL);
			}


			/*
		    UINT get_matrix_WorldStackSize()const
		  {
		    return (UINT)m_MatrixStackWorld.size();
		  };
		    UINT get_matrix_ViewStackSize()const
		  {
		    return (UINT)m_MatrixStackView.size();
		  };
		    UINT get_matrix_ProjStackSize()const
		  {
		    return (UINT)m_MatrixStackProj.size();
		  };
		     */


			//gbmath::perspective_projection_data

		protected:
		   void __checkViewVectors() const;


		private:
			typedef unsigned long BOOLFLAG;

		  //  /** \brief Сборка для класса MatricesContext */
		  struct matrixStore_s
		  {
		    mat44 matrix;
		    BOOLFLAG bChangeFlag;
		  };

		  //    /** \brief Структура Вспомогательная сборка матриц для класса MatricesContext */
		  struct MatricesStore
		  {
		    matrixStore_s

			mViewProjection,
			mViewProjectionInverse,
			mViewProjectionInverseTranspone,
			mViewProjectionTranspone,
		    mViewTranspone,
			mViewInverse,
			mViewInverseTranspone,
		    mProjectionInverse,
			mProjectionTranspone,
			mProjectionInverseTranspone,
		    mWorldViewProjection,
			mWorldViewProjectionTranspone,
			mWorldViewProjectionInverse,
			mWorldViewProjectionInverseTranspone,
		    mWorldTranspone,
			mWorldInverse,
			mWorldInverseTranspone,
			mWorldView,
			mWorldViewTranspone,
			mWorldViewInverse,
			mWorldViewInverseTranspone;

		  };



		  //     /** \brief Вспомогательная структура для класса MatricesContext  */
		  struct BoolChangedMainMatrisec
		  {
		    BOOLFLAG bViewChange, bWorldChange, bProjChange;
		  };


		    mat44 m_mWorld, m_mView, m_mProj; ///< основные матрицы


		  mutable mat44 m_temp;
		  mutable mat44 m_temp2; ///< для временных вычислений

		  mutable MatricesStore m_matr;
		  mutable BoolChangedMainMatrisec m_BoolChangedMatr;

		  mutable vec3 m_VewPos;
		  mutable vec3 m_ViewDir;
		  mutable vec3 m_ViewUp;
		  mutable vec3 m_vec3Temp;

		  mutable vec4 m_vec4Temp;

		  //*  показывает изменился ли вектор MouseCoordCameraUnproject
		  mutable bool m_bMouseCoordCameraUnproject_change;
		  //* последний пересчитаный вектор MouseCoordCameraUnproject
		  mutable vec3 m_vec3_MouseCoordCameraUnproject;

		  //* изменилимь ли данные проекции
		  mutable BOOLFLAG m_bChangeProjectionData;
		  //* данные проекции
		  mutable perspective_projection_data m_PerspectiveProjData;

		  //* изменились ли вью параметры
		  mutable BOOLFLAG m_bIsParameter_EyeData_changed;

		  //* вью параметры
		  mutable eyedata m_EyeData;

		 // fmathEyeData


			/******************************
		  mutable CFixedMatrixStack m_MatrixStackWorld;
		  mutable CFixedMatrixStack m_MatrixStackView;
		  mutable CFixedMatrixStack m_MatrixStackProj;
		    *********************************/

		  mutable bool m_bTransfDataChange;
		  mutable TransformData  m_TransformData;

		  // временно исключено !
		 // mutable Quaternion m_qRotation;


		};
		// end class





}