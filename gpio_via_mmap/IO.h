/***************************************************************************
 *  @file       IO_driver_viaMmap/IO.h
 *  @author     Alan.W
 *  @date       2014
 *  @remark     This code access gpio register via virtual memory,i.e.mmap()
 *  @note	Tested.
 ***************************************************************************/


#ifndef IO_H
#define IO_H
#include <unistd.h>


//! manage gpio via mmap;
class IO
{
public:
	typedef volatile unsigned* Register;
	//! default constructor
	IO();
	
	//! return registers.	
	Register getDI_0() const ;
	Register getDO_0() const ;
	Register getDI_1() const ;
	Register getDO_1() const ;		

	~IO()	{ close(fd); }
private:

	int fd;	//file descriptor
	Register gpio_0;
	Register gpio_1;

};


#endif	//IO_H
