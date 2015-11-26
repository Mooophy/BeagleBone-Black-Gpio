/***************************************************************************
 *  @file       IO_driver_viaMmap/IO_Manager.cpp
 *  @author     Alan.W
 *  @date       2014
 *  @remark     This code access gpio register via virtual memory,i.e.mmap()
 *  @note	
 ***************************************************************************/
#include "IO_Manager.h"
#include <fstream>
#include <string>

//! the path used to config gpio through kernel.
const std::string  PATH = "/sys/class/gpio/";

//! config gpio via export file
void IO_Manager::config() const
{
  //!export input:
  for(auto  i : input_vec){
      std::ofstream stream( PATH + "export" );
      stream << i;
    }
	
  //!export output
  for(auto  o : output_vec){
      std::ofstream stream( PATH + "export" );
      stream << o;
    }	
}

//! write string "out" into corresponding files
void IO_Manager::direction_handle() const
{
    for(auto  o : output_vec){
      std::string file_name = PATH + "gpio" + std::to_string(o) + "/direction";
      std::ofstream stream( file_name);
      stream << "out";
    }
}

//! decode corresponding gpio DATAIN registers and encode input signal.
unsigned IO_Manager::readInput() const
{
	unsigned ret = 0 , bit = 0;
	for(auto i : input_vec)
	{
		if ( i < 32 )	ret += 	(0x1 & (*io.getDI_0() >>  i    ))	<< bit;
		else		ret += 	(0x1 & (*io.getDI_1() >> (i-32)))	<< bit;
		//!note			^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^	^~~~~^
		//!			decode registers.			encode result.						
		bit += 4;
	}
	return ret;
}

//! decode corresponding gpio DATAOUT registers and encode output signal.
void IO_Manager::writeOutput( unsigned cmd ) const
{
	unsigned bit = 0;
	for (auto o : output_vec)
	{
		//! fetch the current bit from cmd
		unsigned cmd_bit = 0x1 & (cmd >> bit);
		if (o < 32)
		{
			//! fetch the value of bits that should keep untouched.
			unsigned untouched_bits = *io.getDO_0()   &   (0xffffffff - (1 <<  o     )); 
			//! plus the cmd bit and write into this DATAOUT register.
			*io.getDO_0() = untouched_bits  +  (cmd_bit <<  o    ) ;  
		}
		else
		{
			unsigned untouched_bits = *io.getDO_1()   &   (0xffffffff - (1 << (o-32) ));
			*io.getDO_1() = untouched_bits  +  (cmd_bit << (o-32)) ;
		}						//!note	 ^^^ don't forget -32.
		
		bit += 4;
	}
}

















