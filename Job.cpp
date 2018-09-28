/*
 * Job.cpp
 *
 *  Created on: 25 sep. 2018
 *      Author: mdkon
 */

#include "Job.h"

Job::Job(std::vector<Task> taskList, unsigned short jobID) :
		taskList(taskList), jobID(jobID)
{
}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

void Job::update(unsigned long currentTime)
{
	active = currentTime < endTime;

//	if (taskList.size() == 0) done = true;
}

Task& Job::getFirstTask()
{
	return taskList[0];
}

void Job::startTask(unsigned long currentTime)
{
	endTime = currentTime + taskList[0].getDuration();
	active = true;
}

void Job::taskDone()
{
	taskList.erase(taskList.begin());
}

bool Job::isDone()
{
	return !(taskList.size());
}

const std::vector<Task>& Job::getTaskList() const
{
	return taskList;
}

bool Job::isActive() const
{
	return active;
}

unsigned long Job::getEarliestFinish() const
{
	return earliestFinish;
}

void Job::setEarliestFinish(unsigned long earliestFinish)
{
	this->earliestFinish = earliestFinish;
}

long Job::getStartTime() const
{
	return startTime;
}

void Job::setStartTime(long startTime)
{
	this->startTime = startTime;
}

unsigned long Job::getEndTime() const
{
	return endTime;
}

unsigned short Job::getJobId() const
{
	return jobID;
}
