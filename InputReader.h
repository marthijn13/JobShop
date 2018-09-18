/*
 * InputReader.h
 *
 *  Created on: Sep 18, 2018
 *      Author: marthijn
 */

#ifndef JOBSHOP_INPUTREADER_H_
#define JOBSHOP_INPUTREADER_H_

#include <iostream>
#include <fstream>
#include <string>

class InputReader {
public:
	InputReader();
	virtual ~InputReader();
	void readInput();
};

#endif /* JOBSHOP_INPUTREADER_H_ */
