/*
 * Machine.cpp
 *
 *  Created on: 25 sep. 2018
 *      Author: mdkoning
 */

#include "Machine.h"

Machine::Machine(unsigned short machineID) :
		machineID(machineID), endTime(0)
{
}

Machine::~Machine()
{
	// TODO Auto-generated destructor stub
}

void Machine::update(unsigned long currentTime)
{
	active = currentTime < endTime;
}

void Machine::assignTask(const Task& newTask, unsigned long currentTime)
{
	endTime = currentTime + newTask.getDuration();
	active = true;
}

bool Machine::isActive() const
{
	return active;
}

unsigned long Machine::getEndTime() const
{
	return endTime;
}

unsigned short Machine::getMachineId() const
{
	return machineID;
}
