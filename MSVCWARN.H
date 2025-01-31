#ifndef MSVCWARN_H
#define MSVCWARN_H

#ifdef D7_VERBOSE_FILENAME
	#pragma message("  "__FILE__)
#endif

#define MSVCWARN_H_NEW
#ifdef MSVCWARN_H_NEW

// NEW
#pragma warning(disable: 4100) /* unref param */
//#pragma warning(disable: 4101) /* unref var */
#pragma warning(disable: 4102) /* unref label */

#pragma warning(error: 4297) // 'function' : function assumed not to throw an exception but does
#pragma warning(error: 4047) // 'function' : 'char **' differs in levels of indirection from 'char [128]'
#pragma warning(error: 4081) // expected ')'; found 'newline'
#pragma warning(error: 4002) // too many actual parameters for macro 
#pragma warning(error: 4013) // 'function' undefined; assuming extern returning int
#pragma warning(error: 4024) // 'function' : different types for formal and actual parameter 'number'
#pragma warning(error: 4022) // 'function' : pointer mismatch for actual parameter 'number'
#pragma warning(error: 4020) // The number of actual parameters in a function call exceeds the number of formal parameters in the function prototype or definition.
#pragma warning(error: 4098) // warning C4098: 'void' function returning a value
#pragma warning(error: 4133) // 'type' : incompatible types - from 'type1' to 'type2'
#pragma warning(error: 4716) // 'function' must return a value
#pragma warning(error: 4028) // formal parameter 'number' different from declaration
#pragma warning(error: 4700) // uninitialized local variable 'name' used
#pragma warning(error: 4701) // Potentially uninitialized local variable 'name' used
#pragma warning(error: 4715) // 'function' : not all control paths return a value
#pragma warning(error: 4717) // 'function' : recursive on all control paths, function will cause runtime stack overflow
#pragma warning(error: 4407) // cast between different pointer to member representations, compiler may generate incorrect code
	// 4407 leads to errors usually...
#pragma warning(error: 4150) // deletion of pointer to incomplete type 'CSOMECLASS'; no destructor called	q:\program files (x86)\microsoft visual studio 9.0\vc\include\memory	1551	testREFCOUNT
#pragma warning(error: 4307) // integral constant overflow
#pragma warning(error: 4789) // destination of memory copy is too small
#pragma warning(error: 4129) // unrecognized character escape sequence
 
#else // #ifdef MSVCWARN_H_NEW

// OLD
#pragma warning(3 : 4100 4101 4701 4702 4704 4705 4706)

#endif // #ifdef MSVCWARN_H_NEW

#endif // #ifndef MSVCWARN_H

