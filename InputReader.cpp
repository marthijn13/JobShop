/*
 * InputReader.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: marthijn
 */
#include <iostream>
#include <fstream>
#include <string>
#include "InputReader.h"

InputReader::InputReader(){
//bla
}

InputReader::~InputReader(){
//bla
}

void readInput() {
	std::string fileName = "test.txt";
	std::ifstream istrm(fileName, std::ios::binary);
	std::string s;
	if (istrm >> s) {
		std::cout << s << std::endl;
	}
}

