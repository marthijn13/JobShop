/*
 * Scheduler.cpp
 *
 *  Created on: 25 sep. 2018
 *      Author: mdkoning
 */

#include "Scheduler.h"

Scheduler::Scheduler(std::vector<Job> jobList, unsigned long totalMachines,
		unsigned long totalJobs) :
		jobList(jobList), totalMachines(totalMachines), totalJobs(totalJobs) {
	machineList.reserve(totalMachines);
	for (unsigned short i = 0; i < totalMachines; ++i) {
		Machine a(i);
		machineList.push_back(a);
	}
}

Scheduler::~Scheduler() {

}

void Scheduler::update() {
	bool done = true;
	for (auto& job : jobList) {
		job.update(currentTime);
		if (!job.isDone())
			done = false;
	}
	if (done)
		finished = true;

	for (auto& machine : machineList) {
		machine.update(currentTime);
//		std::cout << "MachineActive: " << machine.isActive() << std::endl;
	}

//	std::cout << "Time: " << currentTime << std::endl;

	calcEF();
	assignTask();
//	print();
//	std::cout << currentTime << " | ";
	++currentTime;
}

void Scheduler::calcEF() {
	unsigned long earliestFinish = 0;
	for (auto& job : jobList) {
		if (!job.isActive()) {
			for (auto& task : job.getTaskList()) {
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

void Scheduler::assignTask() {
	auto sortEF = [](Job a, Job b)
	{
		if(a.getEarliestFinish() == b.getEarliestFinish()){
			return a.getJobId() < b.getJobId();
		} else {
			return a.getEarliestFinish() > b.getEarliestFinish();
		}
	};
	std::sort(jobList.begin(), jobList.end(), sortEF);

	for (auto& job : jobList) {
		if (!job.isActive() && !job.isDone()
				&& !(machineList[job.getFirstTask().getMachineId()].isActive())) {
			if (job.getStartTime() < 0) {
				job.setStartTime(currentTime);
			}
			machineList[job.getFirstTask().getMachineId()].assignTask(
					job.getFirstTask(), currentTime);
			job.startTask(currentTime);
			job.taskDone();
			jobCounter++;
		}
	}
}

void Scheduler::print() {
	auto greater = [](Job a, Job b)
	{
		return a.getJobId() < b.getJobId();
	};
	std::sort(jobList.begin(), jobList.end(), greater);
	for (auto& job : jobList) {
		std::cout << job.getJobId() << " " << job.getStartTime() << " "
				<< job.getEndTime() << std::endl;
	}
	std::cout << "Task count: " << jobCounter << std::endl;
}

bool Scheduler::isFinished() const {
	return finished;
}
