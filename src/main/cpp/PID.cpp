#include <PID.h>

void PID::set_pid(float percent_output){
	if (percent_output == 10)
	{
		talon_left->Config_kF(0, 1.62, 10);
		talon_left->Config_kP(0, 5.5, 10);
		talon_left->Config_kI(0, 0, 10);
		talon_left->Config_kD(0, 0, 10);

		talon_right->Config_kF(0, 3.2, 10);
		talon_right->Config_kP(0, 5.5, 10);
		talon_right->Config_kI(0, 0, 10);
		talon_right->Config_kD(0, 0, 10);
	}
	if (percent_output == 20)
	{
		talon_left->Config_kF(0, 1.62, 10);
		talon_left->Config_kP(0, 5.5, 10);
		talon_left->Config_kI(0, 0, 10);
		talon_left->Config_kD(0, 0, 10);

		talon_right->Config_kF(0, 2.75, 10);
		talon_right->Config_kP(0, 5.5, 10);
		talon_right->Config_kI(0, 0, 10);
		talon_right->Config_kD(0, 0, 10);
	}
	if (percent_output == 30)
	{
		talon_left->Config_kF(0, 1.62, 10);
		talon_left->Config_kP(0, 5.5, 10);
		talon_left->Config_kI(0, 0, 10);
		talon_left->Config_kD(0, 0, 10);

		talon_right->Config_kF(0, 2.5, 10);
		talon_right->Config_kP(0, 5.5, 10);
		talon_right->Config_kI(0, 0, 10);
		talon_right->Config_kD(0, 0, 10);
	}
	if (percent_output == 40)
	{
		talon_left->Config_kF(0, 1.62, 10);
		talon_left->Config_kP(0, 5.5, 10);
		talon_left->Config_kI(0, 0, 10);
		talon_left->Config_kD(0, 0, 10);

		talon_right->Config_kF(0, 2.18, 10);
		talon_right->Config_kP(0, 5.5, 10);
		talon_right->Config_kI(0, 0, 10);
		talon_right->Config_kD(0, 0, 10);
	}
	if (percent_output == 60) //inches per second
	{
		talon_left->Config_kF(0, 1.6, 10);
		talon_left->Config_kP(0, 3.2, 10);
		talon_left->Config_kI(0, 0, 10);
		talon_left->Config_kD(0, 0, 10);

		talon_right->Config_kF(0, 2.6, 10);
		talon_right->Config_kP(0, 3, 10);
		talon_right->Config_kI(0, 0, 10);
		talon_right->Config_kD(0, 0, 10);	
	}
}