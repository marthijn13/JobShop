/*
 * Machine.cpp
 *
 *  Created on: 23 sep. 2018
 *      Author: mdkon
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

void Machine::setActive(bool active)
{
	this->active = active;
}

void Machine::setEndTime(unsigned long endTime)
{
	this->endTime = endTime;
}

void Machine::setMachineId(unsigned short machineId)
{
	machineID = machineId;
}
