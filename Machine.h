/*
 * Machine.h
 *
 *  Created on: 23 sep. 2018
 *      Author: mdkon
 */
#include "task.h"

#ifndef JOBSHOP_MACHINE_H_
#define JOBSHOP_MACHINE_H_

class Machine
{
public:
	Machine();
	virtual ~Machine();

	void giveTask(Task newTask);

private:
	bool active;
	Task activeTask;

	unsigned short startTime;
	unsigned long endTime;
};

#endif /* JOBSHOP_MACHINE_H_ */
