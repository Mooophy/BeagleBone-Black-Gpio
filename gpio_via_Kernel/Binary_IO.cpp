//!	 @Alan 
//!	
//!	file name: Binary_IO.cpp
//!
#include "Binary_IO.h"
#include <fstream>
#include <iostream>

//! config gpio via export file
void Binary_IO::config() const
{
  //!export input:
  for(auto  i : inputList){
      std::ofstream stream( path + "export" );
      stream << i;
    }
	
  //!export output
  for(auto  o : outputList){
      std::ofstream stream( path + "export" );
      stream << o;
    }	
}

//! write string "out" into corresponding files
void Binary_IO::direction_handle() const
{
    for(auto  o : outputList){
      std::string file_name = path + "gpio" + std::to_string(o) + "/direction";
      std::ofstream stream( file_name);
      stream << "out";
    }
}

//! return input signals
//! format of signale : 0x00010001 where 1 is on , 0 off.
unsigned Binary_IO::inputRead() const
{
	unsigned ret = 0;
	std::size_t bit = 0;
	for(auto i : inputList)	
	{
		std::ifstream fin(path + "gpio" + std::to_string(i) + "/value");	
		std::string input;
		fin >> input;
		ret += (std::stoi(input) <<  bit);
		
		bit += 4;
	}
	return ret;
}

//! write output signals
void Binary_IO::outputWrite(unsigned cmd)const
{
	std::size_t bit = 0;
	for (auto o : outputList)
	{
		std::ofstream fout(path + "gpio" + std::to_string(o) + "/value");
		fout << ((cmd >> bit) & 0x1);

		bit += 4;
	}
}

