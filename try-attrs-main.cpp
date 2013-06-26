/*
 * attr/try-attrs-main.cpp
 * 
 * sample code work with the attribute feature
 *
 * Copyright (c) 2013 Zex Li <top_zlynch@yahoo.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option) 
 * any later version.
 */
#include "try-attrs.h"

int main( int argc, char* argv[] )
{
	std::cout << "------enter main()-------\n";
//	int8_t BIT8_DATA c_8bit = 130; // be directive ignored, since it's on Intel CPU
	int c = 73;

	pr_name();
//	dont_call_me();
	std::cout << "a = " << a << '\n'; // a = 100
	std::cout << "b = " << b << '\n'; // b = 1999

//	std::cout << "c_8bit = " << c_8bit << " @ " << &c_8bit << '\n'; // c_8bit = 73
//	std::cout << "c = " << c << " @ " << &c << '\n'; // c = 73

	try
	{
		throw std::runtime_error("RUNTIME ERROR !!");
	} catch (...) {
		std::cout << "Error caught !!\n";
	}

//	non_interrupt_func();
	display_time();

//	AbiTaggedClass atc;
	try_pure();
//	try_return_twice();

	std::cout << "------leave main()-------\n";	
	return 0;
}
