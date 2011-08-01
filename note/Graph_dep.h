


enum Dep {
 DEP_UNDEF  =  0,
 
 DEP_LINEAR,   ///<  y=x;
 DEP_LINEAR_INV,   ///<  y=1-x; 
 
 DEP_SQRT,     ///<  y=x*x; 
 DEP_SQRT_INV, ///<  y= 1 - x*x; 
 
 DEP_CUBIC,    ///< y=x*x*x;
 DEP_CUBIC_INV, ///< 1- x*x*x 
 
 
 
 
 

};




float Frmla(float x, Dep dep, bool bNeedClump) {
  float y = 0.0f;
  
  if(bNeedClump)
  {
    if(x<0.0f) { x=0.0f; };
	if(x>1.0f) { x=1.0f; };
  }

 switch(dep) {
 
   case DEP_LINEAR: { y=x;  } break;
   
   case DEP_LINEAR_INV: { y=1-x; } break;
   
   case DEP_SQRT: { y=x*x; } break;
   
   case DEP_SQRT_INV: { y=1 - x*x; } break;
  
   case DEP_CUBIC: { y=x*x*x; } break;
   case DEP_CUBIC_INV: { y=1 - x*x*x; } break;  
   
   case xxx: {  } break;   
   case xxx: {  } break;   
   case xxx: {  } break; 

   case xxx: {  } break;   
   case xxx: {  } break;   
   case xxx: {  } break; 

   case xxx: {  } break;   
   case xxx: {  } break;   
   case xxx: {  } break; 
   
   case xxx: {  } break;   
   case xxx: {  } break;   
   case xxx: {  } break;    
   
   case DEP_CUBIC: { y=x*x*x; } break;
   
   
   
   default: {   
    
    };
 };
  
  
  

  return y;
};







// end file