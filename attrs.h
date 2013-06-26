/*
 * attr/attr.h
 *
 * Header for using the attribute feature of gxx compiler
 *
 * NOTICE:
 * Most of the following comments are quoted from GCC manual.
 *
 * SEE ALSO:
 * The GNU Compiler Collection Manual
 * en.Wikipidia.org
 *
 * Copyright (c) 2013 Zex Li <top_zlynch@yahoo.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option) 
 * any later version.
 */
#ifndef ATTRS_H_
#define ATTRS_H_

#include <stdio.h>
#include <time.h>

/*
 * The constructor attribute causes the function to be called 
 * automatically before execution enters main (). Similarly, 
 * the destructor attribute causes the function to be called 
 * automatically after main () has completed or exit () has been 
 * called. Functions with these attributes are useful for initializing 
 * data that will be used implicitly during the execution of the program.
 * These attributes are not currently implemented for Objective-C. 
 *
 * since gcc 2.7
 *
 * NOTE: constructor priorities from 0 to 100 are reserved for the
 * implementation.
 */
#define CTOR __attribute__ ((constructor))
#define DTOR __attribute__ ((destructor))
#define CTOR_PRI(n) __attribute__ ((constructor (n)))
#define DTOR_PRI(n) __attribute__ ((destructor (n)))
/*
 * The deprecated attribute results in a warning if the function is used
 * anywhere in the source file. This is useful when identifying functions that
 * are expected to be removed in a future version of a program. The warning also
 * includes the location of the declaration of the deprecated function, to
 * enable users to easily find further information about why the function is
 * deprecated, or what they should do instead. Note that the warnings only
 * occurs for uses
 */
#define DEPR __attribute__ ((deprecated))
/*
 * On Microsoft Windows and Symbian OS targets, the dllimport attribute causes
 * the compiler to reference a function or variable via a global pointer to a
 * pointer that is set up by the DLL exporting the symbol. The attribute implies
 * extern. On Microsoft Windows targets, the pointer name is formed by combining
 * _imp__ and the function or variable name.
 *
 * You can use __declspec(dllimport) as a synonym for __attribute__
 * ((dllimport)) for compatibility with other compilers.
 *
 * On systems that support the visibility attribute, this attribute also implies
 * “default” visibility. It is an error to explicitly specify any other
 * visibility.
 *
 * Currently, the attribute is ignored for inlined functions. If the attribute
 * is applied to a symbol definition, an error is reported. If a symbol
 * previously declared dllimport is later defined, the attribute is ignored in
 * subsequent references, and a warning is emitted. The attribute is also
 * overridden by a subsequent declaration as dllexport.
 *
 * When applied to C++ classes, the attribute marks non-inlined member functions
 * and static data members as imports. However, the attribute is ignored for
 * virtual methods to allow creation of vtables using thunks.
 *
 * On the SH Symbian OS target the dllimport attribute also has another
 * affect—it can cause the vtable and run-time type information for a class to
 * be exported. This happens when the class has a dllimport'ed constructor or a
 * non-inline, non-pure virtual function and, for either of those two
 * conditions, the class also has an inline constructor or destructor and has a
 * key function that is defined in the current translation unit.
 *
 * For Microsoft Windows based targets the use of the dllimport attribute on
 * functions is not necessary, but provides a small performance benefit by
 * eliminating a thunk in the DLL. The use of the dllimport attribute on
 * imported variables was required on older versions of the GNU linker, but can
 * now be avoided by passing the --enable-auto-import switch to the GNU linker.
 * As with functions, using the attribute for a variable eliminates a thunk in
 * the DLL.
 *
 * One drawback to using this attribute is that a pointer to a variable marked
 * as dllimport cannot be used as a constant address. However, a pointer to a
 * function with the dllimport attribute can be used as a constant initializer;
 * in this case, the address of a stub function in the import lib is referenced.
 * On Microsoft Windows targets, the attribute can be disabled for functions by
 * setting the -mnop-fun-dllimport flag. 
 */
#define DLLIMP __attribute__ ((dllimport))
/*
 * On Microsoft Windows targets and Symbian OS targets the dllexport attribute
 * causes the compiler to provide a global pointer to a pointer in a DLL, so
 * that it can be referenced with the dllimport attribute. On Microsoft Windows
 * targets, the pointer name is formed by combining _imp__ and the function or
 * variable name.
 *
 * You can use __declspec(dllexport) as a synonym for __attribute__
 * ((dllexport)) for compatibility with other compilers.
 *
 * On systems that support the visibility attribute, this attribute also implies
 * “default” visibility. It is an error to explicitly specify any other
 * visibility.
 *
 * In previous versions of GCC, the dllexport attribute was ignored for inlined
 * functions, unless the -fkeep-inline-functions flag had been used. The default
 * behaviour now is to emit all dllexported inline functions; however, this can
 * cause object file-size bloat, in which case the old behaviour can be restored
 * by using -fno-keep-inline-dllexport.
 *
 * The attribute is also ignored for undefined symbols.
 *
 * When applied to C++ classes, the attribute marks defined non-inlined member
 * functions and static data members as exports. Static consts initialized
 * in-class are not marked unless they are also defined out-of-class.
 *
 * For Microsoft Windows targets there are alternative methods for including the
 * symbol in the DLL's export table such as using a .def file with an EXPORTS
 * section or, with GNU ld, using the --export-all linker flag. 
 */
#define DLLEXP __attribute__ ((dllexport))
//#define ALIAS __attribute__ (())

/*
 * This attribute specifies a minimum alignment for the function, measured in
 * bytes.
 *
 * You cannot use this attribute to decrease the alignment of a function, only
 * to increase it. However, when you explicitly specify a function alignment
 * this will override the effect of the -falign-functions (see Optimize Options)
 * option for this function.
 *
 * Note that the effectiveness of aligned attributes may be limited by inherent
 * limitations in your linker. On many systems, the linker is only able to
 * arrange for functions to be aligned up to a certain maximum alignment. (For
 * some linkers, the maximum supported alignment may be very very small.) See
 * your linker documentation for further information.
 *
 * The aligned attribute can also be used for variables and fields (see Variable
 * Attributes.) 
 */
#define ALIGNED __attribute__ ((aligned ()))
#define WARN_TODO(s) __attribute__ ((warning ("TODO: "#s)))
#define WARN_NEED_CONFIRM(s) __attribute__ ((warning ("TOCONFIRM: "#s)))
#define ERROR_NOT_IMP __attribute__((error ("Not implemented!!")))

/*
 * Use this attribute on the H8/300, H8/300H, and H8S to indicate that the
 * specified variable should be placed into the eight bit data section. The
 * compiler will generate more efficient code for certain operations on data in
 * the eight bit data area. Note the eight bit data area is limited to 256 bytes of data.
 * You must use GAS and GLD from GNU binutils version 2.7 or later for this attribute
 * to work correctly. 
 *
 * NOTE:
 * H8/300, 8-bit high-speed central processing unit with a Hitachi-original RISC-like architecture
 *
 * SEE ALSO:
 * H8 Programming Manual
 */
#define BIT8_DATA __attribute__ ((eightbit_data))
/*
 * Use this attribute on the Blackfin to indicate that the specified function is
 * an exception handler. The compiler will generate function entry and exit
 * sequences suitable for use in an exception handler when this attribute is
 * present. 
 */
#define EXCP_HANDLER __attribute__ ((exception_handler))
/*
 * On Epiphany and MeP targets, this attribute causes the compiler to emit
 * instructions to disable interrupts for the duration of the given function. 
 *
 * NOTE:
 * Media embedded Processor (MeP), a CPU design from Toshiba Semiconductor
 */
#define NON_INTR __attribute__ ((disinterrupt))
/*
 * The format attribute specifies that a function takes printf, scanf, strftime
 * or strfmon style arguments which should be type-checked against a format
 * string.
 *
 * causes the compiler to check the arguments in calls to my_printf for
 * consistency with the printf style format string argument my_format.
 *
 * The parameter archetype determines how the format string is interpreted, and
 * should be printf, scanf, strftime, gnu_printf, gnu_scanf, gnu_strftime or
 * strfmon. (You can also use __printf__, __scanf__, __strftime__ or
 * __strfmon__.) On MinGW targets, ms_printf, ms_scanf, and ms_strftime are also
 * present. archtype values such as printf refer to the formats accepted by the
 * system's C run-time library, while gnu_ values always refer to the formats
 * accepted by the GNU C Library. On Microsoft Windows targets, ms_ values refer
 * to the formats accepted by the msvcrt.dll library. The parameter string-index
 * specifies which argument is the format string argument (starting from 1),
 * while first-to-check is the number of the first argument to check against the
 * format string. For functions where the arguments are not available to be
 * checked (such as vprintf), specify the third parameter as zero. In this case
 * the compiler only checks the format string for consistency. For strftime
 * formats, the third parameter is required to be zero. Since non-static C++
 * methods have an implicit this argument, the arguments of such methods should
 * be counted from two, not one, when giving values for string-index and
 * first-to-check.
 *
 * In the example above, the format string (my_format) is the second argument of
 * the function my_print, and the arguments to check start with the third
 * argument, so the correct parameters for the format attribute are 2 and 3.
 *
 * The format attribute allows you to identify your own functions which take
 * format strings as arguments, so that GCC can check the calls to these
 * functions for errors. The compiler always (unless -ffreestanding or
 * -fno-builtin is used) checks formats for the standard library functions
 *  printf, fprintf, sprintf, scanf, fscanf, sscanf, strftime, vprintf, vfprintf
 *  and vsprintf whenever such warnings are requested (using -Wformat), so there
 *  is no need to modify the header file stdio.h. In C99 mode, the functions
 *  snprintf, vsnprintf, vscanf, vfscanf and vsscanf are also checked. Except in
 *  strictly conforming C standard modes, the X/Open function strfmon is also
 *  checked as are printf_unlocked and fprintf_unlocked. See Options Controlling
 *  C Dialect.
 *
 *  For Objective-C dialects, NSString (or __NSString__) is recognized in the
 *  same context. Declarations including these format attributes will be parsed
 *  for correct syntax, however the result of checking of such format strings is
 *  not yet defined, and will not be carried out by this version of the
 *  compiler.
 */
#define FM_PRINTF __attribute__ ((format (printf, 2, 3)))
#define FM_TIME __attribute__ ((format (strftime, 3, 0)))
/*
 * Use this attribute on the H8/300, H8/300H, and H8S to indicate that the
 * specified function should be called through the function vector. Calling a
 * function through the function vector will reduce code size, however; the
 * function vector has a limited size (maximum 128 entries on the H8/300 and 64
 * entries on the H8/300H and H8S) and shares space with the interrupt vector.
 *
 * In SH2A target, this attribute declares a function to be called using the TBR
 * relative addressing mode. The argument to this attribute is the entry number
 * of the same function in a vector table containing all the TBR relative
 * addressable functions. For the successful jump, register TBR should contain
 * the start address of this TBR relative vector table. In the startup routine
 * of the user application, user needs to care of this TBR register
 * initialization. The TBR relative vector table can have at max 256 function
 * entries. The jumps to these functions will be generated using a SH2A
 * specific, non delayed branch instruction JSR/N @(disp8,TBR). You must use GAS
 * and GLD from GNU binutils version 2.7 or later for this attribute to work
 * correctly.
 *
 * Please refer the example of M16C target, to see the use of this attribute
 * while declaring a function,
 *
 * In an application, for a function being called once, this attribute will save
 * at least 8 bytes of code; and if other successive calls are being made to the
 * same function, it will save 2 bytes of code per each of these calls.
 *
 * On M16C/M32C targets, the function_vector attribute declares a special page
 * subroutine call function. Use of this attribute reduces the code size by 2
 * bytes for each call generated to the subroutine. The argument to the
 * attribute is the vector number entry from the special page vector table which
 * contains the 16 low-order bits of the subroutine's entry address. Each vector
 * table has special page number (18 to 255) which are used in jsrs instruction.
 * Jump addresses of the routines are generated by adding 0x0F0000 (in case of
 * M16C targets) or 0xFF0000 (in case of M32C targets), to the 2 byte addresses
 * set in the vector table. Therefore you need to ensure that all the special
 * page vector routines should get mapped within the address range 0x0F0000 to
 * 0x0FFFFF (for M16C) and 0xFF0000 to 0xFFFFFF (for M32C).
 */
#define FUNC_VEC __attribute__ ((function_vector))
/*
 * In Standard C++, objects defined at namespace scope are guaranteed to be
 * initialized in an order in strict accordance with that of their definitions
 * in a given translation unit. No guarantee is made for initializations across
 * translation units. However, GNU C++ allows users to control the order of
 * initialization of objects defined at namespace scope with the init_priority
 * attribute by specifying a relative priority, a constant integral expression
 * currently bounded between 101 and 65535 inclusive. Lower numbers indicate a
 * higher priority.
 */
#define INIT_PRI(n) __attribute__ ((init_priority(n)))
/*
 * abi_tag ("tag", ...)
 *     The abi_tag attribute can be applied to a function or class declaration.
 *     It modifies the mangled name of the function or class to incorporate the
 *     tag name, in order to distinguish the function or class from an earlier
 *     version with a different ABI; perhaps the class has changed size, or the
 *     function has a different return type that is not encoded in the mangled
 *     name.
 *
 *     The argument can be a list of strings of arbitrary length. The
 *     strings are sorted on output, so the order of the list is unimportant.
 *
 *     A redeclaration of a function or class must not add new ABI tags,
 *     since doing so would change the mangled name.
 *
 *     The -Wabi-tag flag enables a warning about a class which does
 *     not have all the ABI tags used by its subobjects and virtual
 *     functions; for users with code that needs to coexist with an
 *     earlier ABI, using this option can help to find all affected
 *     types that need to be tagged. 
 */
//#define ABI_TAG __attribute__ ((abi_tag ("tag1", "tag2")))
/*
 * Calls to external functions with this attribute must return to the current
 * compilation unit only by return or by exception handling. In particular, leaf
 * functions are not allowed to call callback function passed to it from the
 * current compilation unit or directly call functions exported by the unit or
 * longjmp into the unit. Leaf function might still call functions from other
 * compilation units and thus they are not necessarily leaf in the sense that
 * they contain no function calls at all.
 *
 * The attribute is intended for library functions to improve dataflow analysis.
 * The compiler takes the hint that any data not escaping the current
 * compilation unit can not be used or modified by the leaf function. For
 * example, the sin function is a leaf function, but qsort is not.
 *
 * Note that leaf functions might invoke signals and signal handlers might be
 * defined in the current compilation unit and use static variables. The only
 * compliant way to write such a signal handler is to declare such variables
 * volatile.
 *
 * The attribute has no effect on functions defined within the current
 * compilation unit. This is to allow easy merging of multiple compilation units
 * into one, for example, by using the link time optimization. For this reason
 * the attribute is not allowed on types to annotate indirect calls. 
 */
#define LEAF __attribute__ ((leaf))
#define PURE __attribute__ ((pure))

#define RET_TWICE __attribute__ ((return_twice))
/*
 * default
 * Default visibility is the normal case for the object file format. This
 * value is available for the visibility attribute to override other options
 * that may change the assumed visibility of entities.
 *
 * On ELF, default visibility means that the declaration is visible to
 * other modules and, in shared libraries, means that the declared
 * entity may be overridden.
 *
 * On Darwin, default visibility means that the declaration is
 * visible to other modules.
 *
 * Default visibility corresponds to “external linkage” in the
 * language.
 * hidden
 * Hidden visibility indicates that the entity declared will
 * have a new form of linkage, which we'll call “hidden
 * linkage”. Two declarations of an object with hidden
 * linkage refer to the same object if they are in the same
 * shared object.
 * internal
 * Internal visibility is like hidden visibility, but
 * with additional processor specific semantics. Unless
 * otherwise specified by the psABI, GCC defines
 * internal visibility to mean that a function is never
 * called from another module. Compare this with hidden
 * functions which, while they cannot be referenced
 * directly by other modules, can be referenced
 * indirectly via function pointers. By indicating that
 * a function cannot be called from outside the module,
 * GCC may for instance omit the load of a PIC register
 * since it is known that the calling function loaded
 * the correct value.
 * protected
 * Protected visibility is like default visibility
 * except that it indicates that references within
 * the defining module will bind to the definition
 * in that module. That is, the declared entity
 * cannot be overridden by another module. 
 */
#define PROTECTED __attribute__ ((visibility("protected")))
#define HIDDEN __attribute__ ((visibility("hidden")))
#define INTERNAL __attribute__ ((visibility("internal")))
#endif /* ATTRS_H_ */
