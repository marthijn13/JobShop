/*
 * Machine.h
 *
 *  Created on: 25 sep. 2018
 *      Author: mdkoning
 */
#include "Task.h"

#ifndef MACHINE_H_
#define MACHINE_H_

class Machine
{
public:
	Machine(unsigned short machineID);
	virtual ~Machine();

	void update(unsigned long currentTime);
	void assignTask(const Task& newTask, unsigned long currentTime);
	bool isActive() const;
	unsigned long getEndTime() const;
	unsigned short getMachineId() const;

private:
	bool active = false;

	unsigned short machineID;
	unsigned long endTime = 0;
};

#endif /* MACHINE_H_ */
