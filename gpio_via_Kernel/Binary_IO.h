//!	@Alan 
//!	file name : Binary_IO.h
//!	note	: this file is for the fouth project by Alan
//!		: accesses gpio via kernel.		
#ifndef BINARY_IO_H
#define BINARY_IO_H

#include <vector>
#include <string>

//! the path used to config gpio through kernel.
const std::string  PATH = "/sys/class/gpio/";

//! This class configs 8 binary  I and 8 O, and provides interface to access to them.
//! This version uses kernel to access gpio register. 
class Binary_IO
{
public:
	//!default constructor
	Binary_IO(){ 
	config();
	direction_handle();	
	}

	//! return path
	std::string getPath() const{ return path; }	

	unsigned inputRead() const;
	void outputWrite( unsigned  cmd ) const;	

	~Binary_IO(){}

private:

	//gpio nubmers as used in the kernel.
	std::vector<unsigned> inputList  = { 30,31,60,61, 2, 3,14,15 };
	std::vector<unsigned> outputList = { 22,23,26,27,48,49,50,51 };
	
	const std::string path = PATH;		

	//utilities
	void config() const;
	void direction_handle() const;
};

#endif
