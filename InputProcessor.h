/*
 * InputProcessor.h
 *
 *  Created on: 25 sep. 2018
 *      Author: mdkoning
 */
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include "Job.h"
#include "Task.h"

#ifndef INPUTPROCESSOR_H_
#define INPUTPROCESSOR_H_

class InputProcessor
{
public:
	InputProcessor(std::string fileName);
	virtual ~InputProcessor();

	void processInput(std::string fileName);
	void print();

	const std::vector<Job>& getJobList() const;
	unsigned long getTJobs() const;
	unsigned long getTMachines() const;

private:
	void initProcessor(std::string str);
	Job jobProcessor(std::string jobStr, unsigned short jobID);
	Task taskProcessor(std::string str);

	std::string fileName;
	std::vector<Job> jobList;

	unsigned long tMachines;
	unsigned long tJobs;
};

#endif /* INPUTPROCESSOR_H_ */
