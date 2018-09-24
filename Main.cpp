/*
 * Main.cpp
 *
 *  Created on: Sep 14, 2018
 *      Author: marthijn
 */
#include <iostream>
#include <fstream>
#include <string>
#include "InputReader.h"
#include "Scheduler.h"

int main(int argc, char **argv) {

	InputReader file("test.txt");
	Scheduler mrSchedule(file.getJobList(), file.getTotalMachines(), file.getTotalJobs());

	mrSchedule.update();




	return 0;
}
