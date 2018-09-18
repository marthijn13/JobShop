/*
 * Main.cpp
 *
 *  Created on: Sep 14, 2018
 *      Author: marthijn
 */
#include <iostream>
#include <fstream>
#include <string>
#include "InputReader.h"

int main(int argc, char **argv) {
	std::ifstream istrm ("test.txt");

//	istrm.open("test.txt", std::ifstream::in);

	std::string c;// = istrm.get();

	if (istrm.is_open()){
		while (getline (istrm, c)){
			std::cout << c << std::endl;
		}
	} else {
		std::cout << "ERROR ERROR ERROR" << std::endl;
	}

//	while(istrm.is_open()){
//		std::cout << "NODDFSDFSDF" << std::endl;
//		std::cout << c;
//		c = istrm.get();
//	}

	std::cout << "xxxxxx" << std::endl;

	istrm.close();
	return 0;
}
