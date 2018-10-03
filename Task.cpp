/*
 * Task.cpp
 *
 *  Created on: 20 sep. 2018
 *      Author: mdkon
 */

#include "Task.h"

Task::Task(unsigned long machineID, unsigned long duration) :
		machineID(machineID), duration(duration)
{
	// TODO Auto-generated constructor stub

}

Task::~Task()
{
	// TODO Auto-generated destructor stub
}

Task::Task(const Task& task){
	this->machineID = task.machineID;
	this->duration = task.duration;
}

unsigned long Task::getDuration() const
{
	return duration;
}

unsigned long Task::getMachineId() const
{
	return machineID;
}
