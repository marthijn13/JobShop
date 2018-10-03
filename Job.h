/*
 * Job.h
 *
 *  Created on: 25 sep. 2018
 *      Author: mdkon
 */
#include <vector>
#include "Task.h"

#ifndef JOB_H_
#define JOB_H_

class Job
{
public:
	Job(std::vector<Task> taskList, unsigned long jobID);
	~Job();

	void update(unsigned long currentTime);
	Task& getFirstTask();
	void startTask(unsigned long currentTime);
	void taskDone();
	bool isDone();

	bool operator==(const Job& other) const;
	const std::vector<Task>& getTaskList() const;
	bool isActive() const;
	unsigned long getEarliestFinish() const;
	void setEarliestFinish(unsigned long earliestFinish);
	long getStartTime() const;
	void setStartTime(long startTime = -1);
	unsigned long getEndTime() const;
	unsigned long getJobId() const;

private:
	std::vector<Task> taskList;
	long startTime = -1;
	unsigned long endTime = 0;
	unsigned long earliestFinish = 0;

	unsigned long jobID;
	bool active = false;
	bool done = false;
};

#endif /* JOB_H_ */
