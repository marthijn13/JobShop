/*
 * InputReader.cpp
 *
 *  Created on: Sep 18, 2018
 *      Author: marthijn
 */
#include "InputReader.h"

InputReader::InputReader(std::string fileName) :
		fileName(fileName)
{
	readInput(fileName);
}

InputReader::InputReader(const InputReader& obj) :
		fileName(obj.fileName)
{
	//copy constructor
}

InputReader::~InputReader()
{
}

void InputReader::readInput(std::string fileName)
{
	std::ifstream istrm(fileName);
	std::string c;

//	std::vector<std::vector<Task>> taskList =
//	{
//	{ } };

	if (istrm.is_open())
	{
		getline(istrm, c);

		char space = c.find(' ');
		std::string::size_type stringSize;

		totalJobs = std::stoi(c.substr(0, space), &stringSize);
		std::cout << "Number of jobs: " << totalJobs << std::endl;

		totalMachines = std::stoi(c.substr(space, (c.size() - space)), &stringSize);
		std::cout << "Number of machines: " << totalMachines << std::endl;
		taskList.resize(totalJobs * totalMachines);
		auto k = 0;
		for (int l = 0; l < totalJobs; ++l)
		{
			getline(istrm, c);
			for (int i = 0; i < totalMachines - 1; ++i)
			{
				auto j = c.find(' ');
				unsigned short machine = std::stoi(c.substr(k, j));
				c.erase(k, j + 1);
				j = c.find(' ');
				unsigned short duration = std::stoi(c.substr(k, j));
				c.erase(k, j + 1);
				Task a(machine, duration);
//				std::cout << "___Job_" << l << "___" << std::endl;
//				std::cout << "M:" << machine << std::endl;
//				std::cout << "D:" << duration << std::endl;
//				std::cout << std::endl;
				taskList[l].push_back(a);
			}
			auto j = c.find(' ');
			unsigned short machine = std::stoi(c.substr(k, j));
			c.erase(k, j + 1);
			short duration = std::stoi(c.substr(k, c.size()));
			Task a(machine, duration);
//			std::cout << "M:" << machine << std::endl;
//			std::cout << "D:" << duration << std::endl;
//			std::cout << "-----------------------------------------" << std::endl;

		}
	}
	else
	{
		std::cout << "Bestand niet gevonden." << std::endl;
	}
//	std::cout << taskList[1].at(1).getDuration() << std::endl;

	istrm.close();
}

const std::string& InputReader::getFileName() const
{
	return fileName;
}

void InputReader::setFileName(const std::string& fileName)
{
	this->fileName = fileName;
}

const std::vector<std::vector<Task> >& InputReader::getTaskList() const
{
	return taskList;
}

unsigned short InputReader::getTotalJobs() const
{
	return totalJobs;
}

unsigned short InputReader::getTotalMachines() const
{
	return totalMachines;
}
