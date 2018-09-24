/*
 * InputReader.cpp
 *
 * Created on: Sep 18, 2018
 * Author: marthijn
 */
#include "InputReader.h"

InputReader::InputReader(std::string fileName) :
		fileName(fileName)
{
	readInput(fileName);
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

InputReader::~InputReader()
{
}

void InputReader::readInput(std::string fileName)
{
	std::ifstream istrm(fileName);
	std::string c;

	if (istrm.is_open())
	{
		getline(istrm, c);
		getline(istrm, c);

		char space = c.find(' ');
		std::string::size_type stringSize;

		totalJobs = std::stoi(c.substr(0, space), &stringSize);
		std::cout << "Number of jobs: " << totalJobs << std::endl;

		totalMachines = std::stoi(c.substr(space, (c.size() - space)),
				&stringSize);
		std::cout << "Number of machines: " << totalMachines << std::endl;
		taskList.reserve(totalMachines);

		auto stringStart = 0;

		for (int j = 0; j < totalJobs; ++j)
		{
			getline(istrm, c);
			for (int m = 0; m < totalMachines - 1; ++m)
			{
				auto stringEnd = c.find(' ');
				unsigned short machine = std::stoi(
						c.substr(stringStart, stringEnd));
				c.erase(stringStart, stringEnd + 1);
				stringEnd = c.find(' ');
				unsigned short duration = std::stoi(
						c.substr(stringStart, stringEnd));
				c.erase(stringStart, stringEnd + 1);
				Task a(machine, duration);
				taskList.push_back(a);
			}
			auto stringEnd = c.find(' ');
			unsigned short machine = std::stoi(
					c.substr(stringStart, stringEnd));
			c.erase(stringStart, stringEnd + 1);
			short duration = std::stoi(c.substr(stringStart, c.size()));
			Task a(machine, duration);
			taskList.push_back(a);
			Job job(taskList);
			jobList.push_back(job);
		}
	}
	else
	{
		std::cout << "Bestand niet gevonden." << std::endl;
	}

	istrm.close();
}

auto searchWhitespace(std::string s)
{
	auto a = s.find(' ');
	auto b = s.find('\t');
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

const std::string& InputReader::getFileName() const
{
	return fileName;
}

void InputReader::setFileName(const std::string& fileName)
{
	this->fileName = fileName;
}

const std::vector<Job>& InputReader::getJobList() const
{
	return jobList;
}

unsigned short InputReader::getTotalJobs() const
{
	return totalJobs;
}

unsigned short InputReader::getTotalMachines() const
{
	return totalMachines;
}
