/*
 * attr/try-attrs.cpp
 *
 * Copyright (c) 2013 Zex Li <top_zlynch@yahoo.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option) 
 * any later version.
 */
#include "try-attrs.h"

int a = 0;
int b = 0;

// This attribute can only on file-scope definitions of objects of class type
A INIT_PRI(299) a_50( 50 ); /* actual order: big foot 71 in A !! */
A INIT_PRI(200) a_71( 71 ); /*  			 big foot 50 in A !! */

void CTOR setup()
{
	// This shall run before main
//	std::cout << "before main!!\n"; // causes core dump
	printf( "%s(), before main !! original a = %d\n", __func__, a );
	a = 100;
}

void CTOR_PRI(120) setup_again()
{
	// This shall run before main
//	std::cout << "before main!!\n"; // causes core dump
	b = 1999;
}

void CTOR_PRI(101) setup_over_again()
{
	// This shall run before main
//	std::cout << "before main!!\n"; // causes core dump
	b = 520;
}

void DTOR clear()
{
	//This shall run after main or exit
	a = 300;
	std::cout << __func__ << "(), after main!! reset a = " << a << "\n";
}

void WARN_TODO("print a name") pr_name()
{
	// This shall causes compiling warning if called
}

//void ERROR_NOT_IMP dont_call_me()
//{
//	// This shall causes compiling error if called
//}

//void EXCP_HANDLER handler()
//{
//	// This shall be directive ignored, since it's on Linux
//	std::cerr << "Error !!\n";
//}

//void NON_INTR non_interrupt_func()
//{
//	// This shall be directive ignored, since it's not working
//	// on MeP or Epiphany processor.
//	for ( int8_t count = 0; count++ < 5; )
//	{
//		std::cout << "current [" << count << "] - uninterruptable\n";
//		sleep(1);
//	}
//}

void FM_TIME pr_time ( char *time_str, size_t str_s, const char* fm_str, struct tm *tm )
{
	strftime( time_str, str_s, fm_str, tm );
}
// be directive ignored, since we are working on Intel
//void FUNC_VEC display_time()
void display_time()
{
	char time_buf[1000];
//	struct tm tm_to_pr;
	time_t ltime = time( NULL );
	const char* fm_str;

	fm_str  = "This is the %V week of %Y%n"
		"Today is the %dth day of the %mth month of the %yth year of the %C century%n"
		"%a indicates %A%n"
		"Preferred representation: %c%n"
		"Show with slash: %D %n"
		"Show with minus sign: %F%n"
		"%%G %G, %%g %g%n"
		"%b(%%b) is short for %B(%%B)%n"
		"%H:%M:%S and %I:%M:%S %P are the same time%n"
		"Hour: %%H [%H], %%I [%I], %%k [%k], %%l [%l]%n"
		"Day: %%e [%e], %%d [%d]%n"
		"Today is the %jth day of year, the %uth day of week, which is the %Uth week of year%n"
		"%%P[%P], %%p[%p]%n"
		"%%r[%r], %%R[%R], %%T[%T]%n"
		"Seconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC): %s%n"
		"%%V[%V], %%W[%W], %%w[%w]%n"
		"%%x[%x], %%X[%X]%n"
		"Timezone:  %%z[%z], %%Z[%Z]%n"
		"Padding: %%-3d[%-3d], %%_3d[%_3d], %%03d[%03d]%n"
		"Upper/Lower case: %%#Z[%#Z], %%#B[%#B], %%^b[%^b]%n";
//		"%O %n";

	pr_time( time_buf, sizeof( time_buf ), fm_str, localtime( &ltime ) );
	std::cout << "---------[now]---------\n" << time_buf << '\n';
	std::cout << "------end of now-------\n";
}

int LEAF return_sid()
{
	return getsid ( getpid() );
}

int PURE return_num( int i )
{
	return (i%6);
}

int PURE recursive_num( int i )
{
	if ( i > 0 )
		recursive_num( --i );
	else
		return i;
}

//int RET_TWICE recursive_num_ret2( int i )
//{
//	if (i)
//		recursive_num_ret2( --i );
//}

void try_pure()
{
	std::cout << "--------[pure]-------\n";
	std::cout << "returning sid.." << return_sid() << '\n';
	for ( int i = 10; i-- > 0; )
		std::cout << "returning num.." << i << ".." << return_num( i ) << '\n';

	std::cout << "recursive num.." << 10 << ".." << return_num( 10 ) << '\n';
	std::cout << "recursive num.." << 3 << ".." << return_num( 3 ) << '\n';
	std::cout << "recursive num.." << 5 << ".." << return_num( 5 ) << '\n';
	std::cout << "recursive num.." << 6 << ".." << return_num( 6 ) << '\n';
	std::cout << "------end of pure-----\n";
}

//void try_return_twice()
//{
//	std::cout << "--------[rettwice]-------\n";
//	//for ( int i = 10; i-- > 0; )
//	if ( recursive_num_ret2( 10 ) )
//		std::cout << "returning num.." << 10 << "..1" << '\n';
//	else
//		std::cout << "returning num.." << 10 << "..2" << '\n';
//	std::cout << "------end of rettwice-----\n";
//}

