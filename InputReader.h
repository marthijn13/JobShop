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
#include <vector>
#include "Task.h"

class InputReader {
public:
	InputReader(std::string fileName);
	InputReader(const InputReader& obj);
	virtual ~InputReader();

	void readInput(std::string fileName);

	const std::string& getFileName() const;
	void setFileName(const std::string& fileName);
	const std::vector<std::vector<Task> >& getTaskList() const;
	unsigned short getTotalJobs() const;
	unsigned short getTotalMachines() const;

private:
	std::vector<std::vector<Task>> taskList;
	unsigned short totalJobs;
	unsigned short totalMachines;
	std::string fileName;
};

#endif /* JOBSHOP_INPUTREADER_H_ */
