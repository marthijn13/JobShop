/*
 * Scheduler.cpp
 *
 *  Created on: 23 sep. 2018
 *      Author: mdkon
 */

#include "Scheduler.h"

Scheduler::Scheduler(std::vector<Job> jobList, unsigned short totalMachines,
		unsigned short totalJobs) :
		jobList(jobList), totalMachines(totalMachines), totalJobs(totalJobs)
{

}

Scheduler::~Scheduler()
{

}

void Scheduler::update()
{
	machineList.reserve(totalMachines);
	for (unsigned short i = 0; i < totalMachines; ++i)
	{
		Machine a(i);
		machineList.push_back(a);
	}

	calcEF();
}

void Scheduler::calcEF()
{
	unsigned short earliestFinish = 0;
	for (auto job : jobList)
	{
		for (auto task : job.getTaskList())
		{
			earliestFinish += currendTime;
			earliestFinish += task.getDuration();
//			std::cout << "Single: " << task.getDuration() <<" | Time: " << earliestFinish << std::endl;
		}
//		std::cout << "Earliest finish: " << earliestFinish << std::endl;
		job.setEarliestFinish(earliestFinish);
		earliestFinish = 0;
//		std::cout << job.getEarliestFinish() << std::endl;
	}
}

void Scheduler::calcSlack()
{

}

bool Scheduler::isFinished() const
{
	return finished;
}
