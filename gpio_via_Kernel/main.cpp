#include "Binary_IO.h"
#include <iostream>
#include <fstream>

int main()
{
	Binary_IO io;
	
	// @test: 	input and output signals
	// @result:	Succeeded.
	// @author:	@Alan
	std::cout << "Plz enter:\n";
	while(true)
	{
		static bool state = true;
		std::string s;
		std::cin >> s;
		if (s=="q")	break;
	
		//!	for input signals	
		std::cout << "The inputList = { 30,31,60,61, 2, 3,14,15 };\n"
			  << std::hex << io.inputRead() << std::endl;				


		//!	for output signals
//		std::cout << "The outputList = { 22,23,26,27,48,49,50,51 } \n";
//		io.outputWrite(state ? 0x11111111 : 0x00000000);


		std::cout << "plz enter:\n";
		state = !state;
	}

	return 0;

}
