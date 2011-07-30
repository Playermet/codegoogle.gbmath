/** \file  */

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


namespace gmath
{

	struct orthographic_projection_data {
	
		float width, 
		float height;
		float zn;
		float zf;
	
		orthographic_projection_data()
		{
			width = height = zn = zf = 0.0f;
		}
		
		orthographic_projection_data(const orthographic_projection_data& a)
		{
			width = a.width;
			height = a.height;
			zn = a.zn;
			zf = a.zf;
		}


		friend std::ostream &operator << (std::ostream &stream, const orthographic_projection_data& a)
		{
			stream << a.width << " " << a.height << " " << a.zn << " " << a.zf;
			return stream;
		}
		
		operator std::string() const
		{
			std::ostringstream ss;
			ss << a.width << " " << a.height << " " << a.zn << " " << a.zf
			return ss.str();
		}

		void operator = (const std::string& str) throw (std::invalid_argument)
		{
			std::istringstream ss(str);
			ss >> width;
			ss >> height;
			ss >> zn;
			ss >> zf;
			if( ss.fail() ) throw std::invalid_argument("bad input string");
		}



	};


}
