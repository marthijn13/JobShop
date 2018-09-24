/*
 * Task.h
 *
 *  Created on: 20 sep. 2018
 *      Author: Maurice
 */

#ifndef JOBSHOP_TASK_H_
#define JOBSHOP_TASK_H_

class Task
{
public:
	Task(unsigned short machineID, unsigned short duration);
	virtual ~Task();
	unsigned short getDuration() const;
	unsigned short getMachineId() const;

private:
	unsigned short machineID;
	unsigned short duration;
};

#endif /* JOBSHOP_TASK_H_ */
