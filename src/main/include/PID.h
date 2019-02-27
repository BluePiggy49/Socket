#ifndef PID_H
#define PID_H

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <cmath>

class PID {
	public:
		PID(TalonSRX* talon_left, TalonSRX* talon_right)
			:talon_left(talon_left), talon_right(talon_right) {};

		void set_pid(float percent_output);
		
	private:
		TalonSRX* talon_left;
		TalonSRX* talon_right;
		
};
#endif