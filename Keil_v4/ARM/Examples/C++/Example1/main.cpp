
/******************************************************************************/
/* Main.Cpp: C++ ostream + stl + exception demonstration                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2007 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <string.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stddef.h>

typedef unsigned int  U32;

extern "C" int getkey (void);



/*
 * STL Test Code
 */

typedef std::vector<int>       IntVectorType;
typedef IntVectorType::iterator IntVectorItr;
typedef std::map<int, int>     IntIntMapType;
typedef IntIntMapType::iterator IntIntMapItr;

IntVectorType v;
IntIntMapType m;
std::string str;


void stl_test (void)  {
  int   sum = 0;
	
// vector test
  sum = v.size();
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  sum = v.size();
	
  sum = 0;
  for (IntVectorItr itr = v.begin(); itr != v.end(); itr++)  {
    sum += *itr;
  }
  printf ("*** stl_test: vector sum = %d\n", sum);

// map test
  sum  = 0;
  m[1] = 1;
  m[2] = 2;
  m[3] = 3;
	
  for (IntIntMapItr itr = m.begin(); itr != m.end(); itr++)  {
    sum += itr->first * itr->second;
  }
  printf ("*** stl_test: map sum = %d\n", sum);

// Exception-test:
//  Note: execptions need to be enabled in
//   Options for Target - C/C++ - Misc controls: '--exceptions'				 
  std::cout << "Throwing an exception:" << std::endl;
  printf ("----------------------\n");

  try  {
    throw "Test exception";
  }
  catch (const char *szMessage)  {
    str = szMessage;
  }

  if (str.length() > 0)  {
    str += " - has been catched !";
  }
  std::cout << str << std::endl;
}


/*
 * Main program
 *  Note: initialization of the serial port is done in Serial.C.
 *        The function '$Sub$$__rt_entry()' does this job. Initializing
 *        it in main() is too late because the iostream library code is
 *        already initialized when entering main.
 *
 *  The following linker warning can be safely ignored:
 *  warning:  #223-D: function "$Super$$__rt_entry" declared implicitly
 *
 *  Note: the stl code requires an appropriate heap setup, otherwise it
 *        will not work. Check the settings in the Startup code 'Lpc2300.s'
 */
int main (void)  {
  U32 volatile start;

  std::cout.sync_with_stdio(false);
  std::cout << "*** Hello C++ World!" << std::endl;
  std::cout << std::endl;

  std::cout << "Enter any key to start STL test code:" << std::endl;
  start = getkey();
  stl_test();

  std::cout << "End of example." << std::endl;
  while (1);
} 

