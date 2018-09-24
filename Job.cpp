/*
 * Job.cpp
 *
 *  Created on: Sep 24, 2018
 *      Author: marthijn
 */

#include "Job.h"

Job::Job(std::vector<Task> taskList, unsigned short jobID) :
		taskList(taskList), jobID(jobID)
{

}

Job::~Job()
{

}

void Job::update(unsigned long currentTime)
{
	active = currentTime < endTime;

	if (taskList.size() == 0) done = true;
//	std::cout << "Active======== " << active << std::endl;
}

void Job::startTask(unsigned long currentTime)
{
	endTime = currentTime + taskList[0].getDuration() + endTime;
	active = true;
//	std::cout << "Tasklist duration ------------------------- "
//			<< taskList[0].getDuration() << std::endl;
//	std::cout << "EndTime------------------------- " << endTime << std::endl;
}

void Job::taskDone()
{
	taskList.erase(taskList.begin());
}

bool Job::operator==(const Job& other) const
{
	return jobID == other.jobID;
}

Task Job::getFirstTask() const
{
	return taskList[0];
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

long Job::getStartTime() const
{
	return startTime;
}

void Job::setStartTime(long startTime)
{
	this->startTime = startTime;
}

std::vector<Task> Job::getTaskList() const
{
	return taskList;
}

void Job::setTasklist(std::vector<Task> taskList)
{
	this->taskList = taskList;
}

bool Job::isActive() const
{
	return active;
}

unsigned short Job::getJobId() const
{
	return jobID;
}

bool Job::isDone() const
{
	return done;
}
