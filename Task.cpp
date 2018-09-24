/*
 * Task.cpp
 *
 *  Created on: 20 sep. 2018
 *      Author: mdkon
 */

#include "Task.h"

Task::Task(unsigned short machineID, unsigned short duration) :
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

unsigned short Task::getDuration() const
{
	return duration;
}

unsigned short Task::getMachineId() const
{
	return machineID;
}
