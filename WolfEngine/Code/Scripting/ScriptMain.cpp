#include "ScriptMain.h"

#ifdef SQUNICODE 
#define scvprintf vwprintf 
#else 
#define scvprintf vprintf 
#endif 

void printfunc(HSQUIRRELVM v, const SQChar *s, ...)
{
	va_list arglist;
	va_start(arglist, s);
	scvprintf(s, arglist);
	va_end(arglist);
}


void call_foo(HSQUIRRELVM v)
{
	int top = sq_gettop(v); //saves the stack size before the call
	sq_pushroottable(v); //pushes the global table
	sq_pushstring(v, _SC("foo"), -1);
	if (SQ_SUCCEEDED(sq_get(v, -2))) { //gets the field 'foo' from the global table
		sq_pushroottable(v); //push the 'this' (in this case is the global table)
		sq_call(v, 1, 0, 1); //calls the function 
	}
	sq_settop(v, top); //restores the original stack size
}

void ScriptMain()
{
	HSQUIRRELVM v;
	v = sq_open(1024); // creates a VM with initial stack size 1024 

	sqstd_seterrorhandlers(v);

	sq_setprintfunc(v, printfunc, 0); //sets the print function

	sq_pushroottable(v); //push the root table(were the globals of the script will be stored)
	if (SQ_SUCCEEDED(sqstd_dofile(v, _SC("../Scripts/test.nut"), 0, 1))) // also prints syntax errors if any 
	{
		call_foo(v);
	}


	sq_pop(v, 1); //pops the root table
	sq_close(v);
}