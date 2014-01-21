 

#include "_gbmath.h"
 
 
namespace gbmath
{
 
#ifdef _DEBUG

void gbmath_assert_failed( const char* srcfunc, const char* srcfile, const int srcline, const char* msg )
{
	std::string msg_full;	 
	msg_full += "ACCERTION FAILED: ";
	msg_full += msg;
	msg_full += "    ";
	msg_full += srcfunc;
	msg_full += "   ";

	msg_full += "(";
	msg_full += srcfile;
	msg_full += " : ";
	std::ostringstream oss;
	oss << srcline;
	msg_full += oss.str();
	msg_full += ") ";

	msg_full += "\n";

	std::cerr << msg_full;

	#ifdef WIN32
	::MessageBoxA(0,msg_full.c_str(), "gbmath assertion failed", MB_OK|MB_ICONERROR|MB_TOPMOST|MB_TASKMODAL );
	#endif

}

#endif 

}

