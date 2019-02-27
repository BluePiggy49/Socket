#include "Robot.h"
#include "ctre/Phoenix.h"
#include "frc/WPILib.h"
#include <frc/Joystick.h>
#include <PID.h>
#include <frc/Timer.h>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>	
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h>	
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <socket.h>

using namespace frc;

Socket *client;

void Robot::RobotInit() {

	std::cout<<"Socket v. 13"<<std::endl;
	client = new Socket();

}

void Robot::RobotPeriodic() {}


void Robot::AutonomousInit() {

}
void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {
	//loop = 0;
}

void Robot::TeleopPeriodic() {
	std::string buffer_string = client->update();

	if (buffer_string == "0")
	{
		std::cout<<"Not Connected"<<std::endl;
	}else{
		float angle_one = client->angle_one(buffer_string);
		std::cout<<"Angle One: "<<angle_one<<std::endl;

		float distance = client->distance(buffer_string);
		std::cout<<"Distance: "<<distance<<std::endl;

		float angle_two = client->angle_two(buffer_string);
		std::cout<<"Angle Two: "<<angle_two<<std::endl;

		float left_depth = client->left_depth(buffer_string);
		std::cout<<"Left Depth: "<<left_depth<<std::endl;

		float right_depth = client->right_depth(buffer_string);
		std::cout<<"Right Depth: "<<right_depth<<std::endl;
	}
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS

int main() { return frc::StartRobot<Robot>(); }

#endif
