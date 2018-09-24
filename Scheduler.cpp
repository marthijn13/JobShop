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
	machineList.reserve(totalMachines);
	for (unsigned short i = 0; i < totalMachines; ++i)
	{
		Machine a(i);
		machineList.push_back(a);
	}
}

Scheduler::~Scheduler()
{

}

void Scheduler::update()
{
	bool done = true;
	for (auto& job : jobList)
	{
		job.update(currentTime);
		if (!job.isDone()) done = false;
//		std::cout << "JobActive: " << job.isActive() << std::endl;
//		auto result = std::find(jobList.begin(), jobList.end(), job);
//		(*result).update(currentTime);
	}
	std::cout << "Time: " << currentTime << std::endl;
	if (done) finished = true;

	for (auto& machine : machineList)
	{
		machine.update(currentTime);
//		std::cout << "MachineActive: " << machine.isActive() << std::endl;
	}
//	std::cout << "Time: " << currentTime << std::endl;
	calcEF();
	assignTask();

	++currentTime;
}

void Scheduler::calcEF()
{
	unsigned long earliestFinish = 0;
	for (auto& job : jobList)
	{
		if (!job.isActive())
		{
			for (auto& task : job.getTaskList())
			{
				earliestFinish += currentTime;
				earliestFinish += task.getDuration();
				//			std::cout << "Single: " << task.getDuration() <<" | Time: " << earliestFinish << std::endl;
			}
			//		std::cout << "Earliest finish: " << earliestFinish << std::endl;
			job.setEarliestFinish(earliestFinish);
			if (job.getEarliestFinish() > latestFinish)
				latestFinish = job.getEarliestFinish();
			earliestFinish = 0;

		}
	}
}

void Scheduler::assignTask()
{
//	std::cout << latestFinish << std::endl;
//	std::vector<Job> finishList;
//	for (auto& job : jobList)
//	{
//		finishList.push_back(job);
//	}
	auto greater = [](Job a, Job b)
	{
		return a.getEarliestFinish() > b.getEarliestFinish();
	};
	std::sort(jobList.begin(), jobList.end(), greater);

//	for (auto job : jobList) {
//		std::cout << "SORT: " << job.getJobId() << std::endl;
//	}

	for (auto& job : jobList)
	{
		if (!job.isActive()
				&& !(machineList[job.getFirstTask().getMachineId()].isActive()))
		{
//			std::cout << "Job start time: " << job.getStartTime() << std::endl;
			if (job.getStartTime() < 0)
			{
				job.setStartTime(currentTime);
			}
//			std::cout << "Job start time2: " << job.getStartTime() << std::endl;
			machineList[job.getFirstTask().getMachineId()].assignTask(
					job.getFirstTask(), currentTime);
//			std::cout << "Machine: " << job.getFirstTask().getMachineId()
//					<< " | EndTime: "
//					<< machineList[job.getFirstTask().getMachineId()].getEndTime()
//					<< std::endl;
			job.startTask(currentTime);
			job.taskDone();
//			auto result = std::find(jobList.begin(), jobList.end(), job);
//			(*result).startTask(currentTime);
//			(*result).taskDone();
		}
	}
}

void Scheduler::print()
{
	for (unsigned short i = 0; i < jobList.size(); ++i)
	{
		std::cout << jobList[i].getJobId() << " " << jobList[i].getStartTime()
				<< " " << jobList[i].getEndTime() << std::endl;
	}
}

bool Scheduler::isFinished() const
{
	return finished;
}
