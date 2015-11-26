/***************************************************************************
 *  @file       IO_driver_viaMmap/main.cpp
 *  @author     Alan.W
 *  @date       2014
 *  @remark     This code accesses gpio register via virtual memory,i.e.mmap()
 *  @note	Tested.
 ***************************************************************************/


#include "IO_Manager.h"
#include <iostream>

int main()
{
	IO_Manager m;	
//	m.writeOutput(0x11111111);
//	std::cout << "0x"  << std::hex <<  m.readInput() << std::endl;


	//!	test for frequency 
	//!	the result == 114 kH
	bool state = true;
	while(true)
	{
		m.writeOutput(state);
		state = !state; 		
	}

	return 0;
}
