//programing language lava
#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
#include "PROGRAM.cpp"


int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cout << "il compilatore lava- v0.3.0a" << std::endl;
		std::cout << "\nUsage: lava <source file>.lava";
	} else {
		load(argv[1]);
	}
}

void load(const std::string& file)
{
    std::ifstream code;

	code.open(file);

    if (!code) {
        std::cout << "Error! '" << file << "' doesn\'t exist" << std::endl;
        exit(-1);
    }

    std::string text;
    while(!code.eof()) 
    {
        std::getline(code, text);
        if (text.rfind("//", 0) == 0)
            continue;
        else 
            std::cout << text << "\n";
    }

    code.close();
}