
/***************************************************************************
 *  @file       IO_driver_viaMmap/IO_MANAGER.cpp
 *  @author     Alan.W
 *  @date       2014
 *  @remark     This code access gpio register via virtual memory,i.e.mmap()
 *  @note	Tested.
 ***************************************************************************/


#ifndef IO_MANAGER
#define IO_MANAGER


#include "IO.h"
#include <vector>

//! this class config input and ouput via mmap
class IO_Manager
{
public:
	IO_Manager() 
	{
		config();
		direction_handle();
	}

	unsigned readInput() const;
	void writeOutput(unsigned cmd) const;

private:
	std::vector<unsigned> input_vec  = { 30,31,60,61, 2, 3,14,15 };
	std::vector<unsigned> output_vec = { 22,23,26,27,48,49,50,51 };
	IO io = IO();
	
	//utilities
	void config() const;
	void direction_handle() const;

};

#endif	//IO_MANAGER

