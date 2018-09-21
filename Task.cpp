/*
 * Task.cpp
 *
 *  Created on: 20 sep. 2018
 *      Author: mdkon
 */

#include "Task.h"

Task::Task()
{
	// TODO Auto-generated constructor stub

}

Task::~Task()
{
	// TODO Auto-generated destructor stub
}

unsigned short Task::getDuration() const
{
	return duration;
}

unsigned short Task::getMachineId() const
{
	return machineID;
}
