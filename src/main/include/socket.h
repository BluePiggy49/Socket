#ifndef SOCKET_H
#define SOCKET_H

#include "Robot.h"
#include "ctre/Phoenix.h"
#include "frc/WPILib.h"
#include <frc/Joystick.h>
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

class Socket {
	public:
		Socket() {};

		std::string update();
		float angle_one(std::string buffer_string);
		float distance(std::string buffer_string);
		float angle_two(std::string buffer_string);
		float left_depth(std::string buffer_string);
		float right_depth(std::string buffer_string);

	private:
		//update():
		int my_socket = -1;
		int connect_socket = -1;
		int mode = 1;
		int connect_mode = 1;
		struct sockaddr_in my_address;
		struct sockaddr_in serv_addr;
		int flags;
		char buffer[265] = {0};
		int loop = 0;
		std::string buffer_string = "";

		//angle_one():
		
};

#endif