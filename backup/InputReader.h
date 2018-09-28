/*
 * InputReader.h
 *
 * Created on: Sep 18, 2018
 * Author: marthijn
 */

#ifndef JOBSHOP_INPUTREADER_H_
#define JOBSHOP_INPUTREADER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Task.h"
#include "Job.h"

class InputReader
{
public:
	InputReader(std::string fileName);
	virtual ~InputReader();

	void readInput(std::string fileName);
	auto searchWhitespace(std::string s);

	const std::string& getFileName() const;
	void setFileName(const std::string& fileName);
	const std::vector<Job>& getJobList() const;
	unsigned short getTotalJobs() const;
	unsigned short getTotalMachines() const;

private:
	std::vector<Job> jobList;
	std::vector<Task> taskList;

	unsigned short totalJobs;
	unsigned short totalMachines;
	std::string fileName;
};

#endif /* JOBSHOP_INPUTREADER_H_ */
