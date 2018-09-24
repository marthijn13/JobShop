/*
 * Job.cpp
 *
 *  Created on: Sep 24, 2018
 *      Author: marthijn
 */

#include "Job.h"

Job::Job(std::vector<Task> taskList) :
		taskList(taskList)
{

}

Job::~Job()
{

}

void Job::updateTaskList()
{

}

void Job::assignTask()
{

}

unsigned long Job::getEarliestFinish() const
{
	return earliestFinish;
}

void Job::setEarliestFinish(unsigned long earliestFinish)
{
	this->earliestFinish = earliestFinish;
}

unsigned long Job::getEndTime() const
{
	return endTime;
}

void Job::setEndTime(unsigned long endTime)
{
	this->endTime = endTime;
}

unsigned long Job::getSlack() const
{
	return slack;
}

void Job::setSlack(unsigned long slack)
{
	this->slack = slack;
}

unsigned long Job::getStartTime() const
{
	return startTime;
}

void Job::setStartTime(unsigned long startTime)
{
	this->startTime = startTime;
}

std::vector<Task> Job::getTasklist() const
{
	return taskList;
}

void Job::setTasklist(std::vector<Task> taskList)
{
	this->taskList = taskList;
}
