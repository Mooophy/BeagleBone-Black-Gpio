/***************************************************************************
 *  @file       IO_driver_viaMmap/io.cpp
 *  @author     Alan.W
 *  @date       2014
 *  @remark     This code access gpio register via virtual memory,i.e.mmap()
 *  @note	Tested.
 ***************************************************************************/

#include "IO.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>

const unsigned  GPIO_DATAIN 	 = 0x138 >> 2 ;
const unsigned  GPIO_DATAOUT 	 = 0x13c >> 2 ; 

const unsigned  GPIO0_START_ADDR = 0x44E07000 ;
const unsigned  GPIO0_END_ADDR   = 0x44E08FFF ;
const unsigned  GPIO0_SIZE       = GPIO0_END_ADDR - GPIO0_START_ADDR ;

const unsigned  GPIO1_START_ADDR = 0x4804C000 ;	
const unsigned  GPIO1_END_ADDR 	 = 0x4804DFFF ;
const unsigned  GPIO1_SIZE	 = GPIO1_END_ADDR - GPIO1_START_ADDR ;


//! default constructor
IO::IO()
{
	fd = open("/dev/mem", O_RDWR);
        void* p0  = mmap(0, GPIO0_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO0_START_ADDR);
	void* p1  = mmap(0, GPIO1_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO1_START_ADDR);
	
	gpio_0 = static_cast<Register>(p0);
	gpio_1 = static_cast<Register>(p1);
}

//! return GPIO_DATAIN register of GPIO[0]
IO::Register IO::getDI_0() const
{
	return gpio_0 + GPIO_DATAIN;
}

//! return GPIO_DATAOUT register of GPIO[0]
IO::Register IO::getDO_0() const
{
	return gpio_0 + GPIO_DATAOUT;
}

//! return GPIO_DATAIN register of GPIO[1]
IO::Register IO::getDI_1() const
{
	return gpio_1 + GPIO_DATAIN;
}

//! return GPIO_DATAOUT register of GPIO[1]
IO::Register IO::getDO_1() const
{
	return gpio_1 + GPIO_DATAOUT;
}

