/*
 * InputProcessor.cpp
 *
 *  Created on: 25 sep. 2018
 *      Author: mdkoning
 */

#include "InputProcessor.h"

InputProcessor::InputProcessor(std::string fileName) :
		fileName(fileName)
{
	processInput(fileName);

}

InputProcessor::~InputProcessor()
{
	// TODO Auto-generated destructor stub
}

void InputProcessor::processInput(std::string fileName)
{
	// \d searches nubers [0-9] for 1 nuber long {1}
	std::ifstream istrm(fileName);
	std::string str;
	if (istrm.is_open())
	{
		getline(istrm, str);
		std::regex reg("\\d[^ ]? \\d[^ ]?");
		std::smatch matches;

		while (!(std::regex_search(str, matches, reg)))
		{
			getline(istrm, str);
		}
//		std::cout << "Match: " << matches.str(0) << std::endl;

		initProcessor(matches.str(0));

		for (unsigned short j = 0; j < tJobs; ++j)
		{
			getline(istrm, str);
			std::string jobStr = "";
			for (unsigned short i = 0; i < tMachines; ++i)
			{
				std::regex_search(str, matches, reg);
				jobStr += matches.str(0);
				jobStr += " ";
				str = matches.suffix().str();

			}
//			std::cout << "Job: " << jobStr << std::endl;
			jobList.push_back(jobProcessor(jobStr, j));
		}

	}
	else
	{
		std::cout << "File not found" << std::endl;
	}
}

void InputProcessor::print(){
	std::cout << "------TASKLIST-VISUALISATION-PER-JOB------" << std::endl;
	for (auto job : jobList){
			for (auto task : job.getTaskList()){
				std::cout << "Task-M-ID: " << task.getMachineId() << std::endl;
				std::cout << "Task-D: " << task.getDuration() << std::endl;
			}
			std::cout << "------------------------------------------" << std::endl;
		}
}

void InputProcessor::initProcessor(std::string str)
{
	std::string::size_type sz;
	std::regex reg("\\d[^ ]?");
	std::smatch matches;

	short i = 0;

	while (std::regex_search(str, matches, reg) && i < 2)
	{
		if (i == 0)
		{
			tJobs = std::stol(matches.str(0), &sz);
		}
		else
		{
			tMachines = std::stol(matches.str(0), &sz);
		}
		str = matches.suffix().str();
		++i;
	}
//	std::cout << "Jobs: " << tJobs << std::endl;
//	std::cout << "Machines: " << tMachines << std::endl;
}

Job InputProcessor::jobProcessor(std::string str, unsigned short jobID)
{
	std::regex reg("\\d[^ ]? \\d[^ ]?");
	std::smatch matches;

	std::vector<Task> taskList;

	while (std::regex_search(str, matches, reg))
	{

//		std::cout << matches.str(0) << std::endl;

		taskList.push_back(taskProcessor(matches.str(0)));

		str = matches.suffix().str();
	}

	Job job(taskList, jobID);
	return job;
}

Task InputProcessor::taskProcessor(std::string str)
{
	unsigned short machineID;
	unsigned short duration;
	std::string::size_type sz;
	std::regex reg("\\d[^ ]?");
	std::smatch matches;

	short i = 0;

	while (std::regex_search(str, matches, reg) && i < 2)
	{
		if (i == 0)
		{
			machineID = std::stol(matches.str(0), &sz);
		}
		else
		{
			duration = std::stol(matches.str(0), &sz);
		}
		str = matches.suffix().str();
		++i;
	}

	Task a(machineID, duration);
	return a;
}

const std::vector<Job>& InputProcessor::getJobList() const
{
	return jobList;
}

unsigned long InputProcessor::getTJobs() const
{
	return tJobs;
}

unsigned long InputProcessor::getTMachines() const
{
	return tMachines;
}
