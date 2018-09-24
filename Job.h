/*
 * Job.h
 *
 *  Created on: Sep 24, 2018
 *      Author: marthijn
 */
#include <vector>
#include "Task.h"
#include <iostream>

#ifndef JOBSHOP_JOB_H_
#define JOBSHOP_JOB_H_

class Job
{
public:
	Job(std::vector<Task> taskList, unsigned short jobID);
	~Job();

	void update(unsigned long currentTime);
	void startTask(unsigned long currentTime);
	void taskDone();

	bool operator==(const Job& other) const;

	Task getFirstTask() const;
	unsigned long getEarliestFinish() const;
	void setEarliestFinish(unsigned long earliestFinish);
	unsigned long getEndTime() const;
	void setEndTime(unsigned long endTime);
	unsigned long getSlack() const;
	void setSlack(unsigned long slack);
	long getStartTime() const;
	void setStartTime(long startTime);
	std::vector<Task> getTaskList() const;
	void setTasklist(std::vector<Task> tasklist);
	bool isActive() const;
	unsigned short getJobId() const;
	bool isDone() const;

private:
	std::vector<Task> taskList;
	long startTime = -1;
	unsigned long endTime = 0;
	unsigned long earliestFinish;
	unsigned long slack;

	unsigned short jobID;
	bool active = false;
	bool done = false;
};

#endif /* JOBSHOP_JOB_H_ */
