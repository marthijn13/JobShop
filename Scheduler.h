/*
 * Scheduler.h
 *
 *  Created on: 23 sep. 2018
 *      Author: mdkon
 */
#include <vector>
#include "Machine.h"
#include "Task.h"
#include "Job.h"
#include <iostream>
#include <algorithm>

#ifndef JOBSHOP_SCHEDULER_H_
#define JOBSHOP_SCHEDULER_H_

class Scheduler
{
public:
	Scheduler(std::vector<Job> jobList, unsigned short totalMachines, unsigned short totalJobs);
	virtual ~Scheduler();

	void update();
	void calcEF();
	void assignTask();
	void print();
	bool isFinished() const;

private:
	std::vector<Machine> machineList;
	std::vector<Job> jobList;
	unsigned short totalMachines;
	unsigned short totalJobs;

	unsigned long currentTime = 0;
	unsigned long latestFinish = 0;

	bool finished = false;
};

#endif /* JOBSHOP_SCHEDULER_H_ */
