/*
 * Scheduler.h
 *
 *  Created on: 23 sep. 2018
 *      Author: mdkon
 */
#include <vector>
#include "Machine.h"
#include "Task.h"

#ifndef JOBSHOP_SCHEDULER_H_
#define JOBSHOP_SCHEDULER_H_

class Scheduler
{
public:
	Scheduler(std::vector<std::vector<Task>> taskList, unsigned short totalMachines, unsigned short totalJobs);
	virtual ~Scheduler();

	void update();
	void calcEF();
	void calcSlack();

private:
	std::vector<Machine> machineList;
	std::vector<std::vector<Task>> taskList;
	unsigned short totalMachines;
	unsigned short totalJobs;
};

#endif /* JOBSHOP_SCHEDULER_H_ */
