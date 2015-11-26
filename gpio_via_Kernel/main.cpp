 // @test: 	input and output signals
 // @result:	Succeeded.
 // @author:	@Yue Wang
 

#include "Binary_IO.h"
#include <iostream>
#include <fstream>

int main()
{
    Binary_IO io;

    // @test: 	input and output signals
    // @result:	Succeeded.
    // @author:	@Yue Wang
    std::cout << "Plz enter:\n";
    while (true)
    {
        static bool state = true;
        std::string s;
        std::cin >> s;
        if (s == "q")	break;
        //!	for input signals	
        std::cout << "The inputList = { 30,31,60,61, 2, 3,14,15 };\n"
            << std::hex << io.inputRead() << std::endl;
        std::cout << "plz enter:\n";
        state = !state;
    }
    return 0;
}
