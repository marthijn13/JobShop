/*
 * main.cpp
 *
 *  Created on: 25 sep. 2018
 *      Author: mdkoning
 */
#include <iostream>
#include <regex>
#include "InputProcessor.h"
#include "Scheduler.h"

int main(int argc, char **argv)
{
	if (argc > 0)
	{
		InputProcessor input(argv[1]);
		//	input.print();

		Scheduler mrSchedule(input.getJobList(), input.getTMachines(),
				input.getTJobs());

		while (!mrSchedule.isFinished())
		{
			mrSchedule.update();
		}

		mrSchedule.print();
	}

	return 0;
}
