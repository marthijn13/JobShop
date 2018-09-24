/*
 * Scheduler.cpp
 *
 *  Created on: 23 sep. 2018
 *      Author: mdkon
 */

#include "Scheduler.h"

Scheduler::Scheduler(std::vector<std::vector<Task>> taskList,
		unsigned short totalMachines, unsigned short totalJobs) :
		taskList(taskList), totalMachines(totalMachines), totalJobs(totalJobs)
{

}

Scheduler::~Scheduler()
{
	// TODO Auto-generated destructor stub
}

