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
	Task();
	virtual ~Task();

	unsigned short getDuration() const
	{
		return duration;
	}

	unsigned short getMachine() const
	{
		return machine;
	}

private:
	unsigned short machine;
	unsigned short duration;
};

#endif /* JOBSHOP_TASK_H_ */
