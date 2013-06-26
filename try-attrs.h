/*
 * attr/try-attrs.h
 *
 * sample function, class and variable using the attribute feature
 *
 * Copyright (c) 2013 Zex Li <top_zlynch@yahoo.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option) 
 * any later version.
 */
#ifndef TRY_ATTRS_H_
#define TRY_ATTRS_H_

#include <iostream>
#include <system_error>
#include <unistd.h>

#include "attrs.h"

extern int a;
extern int b;

extern void CTOR setup();
extern void CTOR_PRI(120) setup_again();
extern void CTOR_PRI(101) setup_over_again();

extern void DTOR clear();
extern void WARN_TODO("print a name") pr_name();

//void ERROR_NOT_IMP dont_call_me();
//void EXCP_HANDLER handler();
//void NON_INTR non_interrupt_func();

extern void FM_TIME pr_time ( char *time_str, size_t str_s, const char* fm_str, struct tm *tm );
// be directive ignored, since we are working on Intel
//void FUNC_VEC display_time();
extern void display_time();

class A
{
	int num_;
public:
	A( int num ) : num_( num )
	{ printf( "big foot %d in A !!\n", num_ ); }
};

//class ABI_TAG AbiTaggedClass
//{
//public:
//	AbiTaggedClass(){}
//
//};

extern int LEAF return_sid();
extern int PURE return_num( int i );
extern int PURE recursive_num( int i );

//extern int RET_TWICE recursive_num_ret2( int i );

extern void try_pure();
//extern void try_return_twice();

#endif /* TRY_ATTRS_H_ */
