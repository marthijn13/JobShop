/*
 * Job.h
 *
 *  Created on: Sep 24, 2018
 *      Author: marthijn
 */
#include <vector>
#include "Task.h"

#ifndef JOBSHOP_JOB_H_
#define JOBSHOP_JOB_H_

class Job
{
public:
	Job(std::vector<Task> taskList);
	~Job();

	void updateTaskList();
	void assignTask();

	unsigned long getEarliestFinish() const;
	void setEarliestFinish(unsigned long earliestFinish);
	unsigned long getEndTime() const;
	void setEndTime(unsigned long endTime);
	unsigned long getSlack() const;
	void setSlack(unsigned long slack);
	unsigned long getStartTime() const;
	void setStartTime(unsigned long startTime);
	std::vector<Task> getTasklist() const;
	void setTasklist(std::vector<Task> tasklist);

private:
	std::vector<Task> taskList;
	unsigned long startTime;
	unsigned long endTime;
	unsigned long earliestFinish;
	unsigned long slack;
};

#endif /* JOBSHOP_JOB_H_ */
