/*
 * Machine.h
 *
 *  Created on: 23 sep. 2018
 *      Author: mdkon
 */
#include "Task.h"

#ifndef JOBSHOP_MACHINE_H_
#define JOBSHOP_MACHINE_H_

class Machine
{
public:
	Machine(unsigned short machineID);
	virtual ~Machine();

	void update(unsigned long currentTime);
	void giveTask(const Task& newTask, unsigned long currentTime);

	bool isActive() const;
	unsigned long getEndTime() const;
	unsigned short getMachineId() const;
	unsigned short getStartTime() const;
	void setActive(bool active);
	void setEndTime(unsigned long endTime);
	void setMachineId(unsigned short machineId);
	void setStartTime(unsigned long startTime);

private:
	bool active;

	unsigned short machineID;
	unsigned long endTime = 0;
};

#endif /* JOBSHOP_MACHINE_H_ */
