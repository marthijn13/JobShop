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
	Task(unsigned long machineID, unsigned long duration);
	virtual ~Task();
	Task(const Task& task);

	unsigned long getDuration() const;
	unsigned long getMachineId() const;

private:
	unsigned long machineID;
	unsigned long duration;
};

#endif /* JOBSHOP_TASK_H_ */
