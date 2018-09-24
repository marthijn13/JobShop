/*
 * Scheduler.cpp
 *
 *  Created on: 23 sep. 2018
 *      Author: mdkon
 */

#include "Scheduler.h"

Scheduler::Scheduler(std::vector<Job> jobList,
		unsigned short totalMachines, unsigned short totalJobs) :
		jobList(jobList), totalMachines(totalMachines), totalJobs(totalJobs)
{

}

Scheduler::~Scheduler()
{

}

void Scheduler::update()
{
	machineList.reserve(totalMachines);
	for (unsigned short i = 0; i < totalMachines; ++i){
		Machine a(i);
		machineList.push_back(a);
	}
}

void Scheduler::calcEF()
{

}

void Scheduler::calcSlack()
{

}

bool Scheduler::isFinished() const
{
	return finished;
}
