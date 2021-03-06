/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
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
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

class Robot : public frc::TimedRobot {
	public:
		void RobotInit() override;
		void RobotPeriodic() override;
		void AutonomousInit() override;
		void AutonomousPeriodic() override;
		void TeleopInit() override;
		void TeleopPeriodic() override;
		void TestPeriodic() override;

	private:
		frc::SendableChooser<std::string> m_chooser;
		const std::string kAutoNameDefault = "Default";
		const std::string kAutoNameCustom = "My Auto";
		std::string m_autoSelected;
};
