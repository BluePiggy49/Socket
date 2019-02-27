#include <socket.h>

std::string Socket::update(){
	if (mode == 1)
	{
		std::cout<<"I am at line 55"<<std::endl;
		my_socket = socket(AF_INET, SOCK_STREAM, 0);
		memset(&serv_addr, '0', sizeof(serv_addr));
		my_address.sin_family = AF_INET;
		my_address.sin_addr.s_addr = inet_addr("10.9.55.100");
		my_address.sin_port = htons(5060);
		this->my_socket = my_socket;
		if (my_socket < 0){
			std::cout<<"Failed to Start"<<std::endl;
		}
		mode ++;
	}
	connect_socket = connect(my_socket, (struct sockaddr *)&my_address, sizeof(my_address));
	///std::cout<<"Connect Socket: "<<connect_socket<<std::endl;
	if (connect_socket < 0 && connect_mode == 1) {
		std::cout<<"Could Not Connect"<<std::endl;
		connect_mode = 1;
		mode = 1;
		return "0";
	}else{
		connect_mode ++;
		flags = fcntl(connect_socket, F_GETFL);	
		fcntl(connect_socket, F_SETFL, flags | O_NONBLOCK);
		int reading = recv(my_socket, buffer, 256, 0);
		std::cout<<"Reading: "<<reading<<std::endl;
		if (reading > 0)
		{
		 	std::cout<<"What it Read: "<<buffer<<std::endl;
			loop ++;
			//std::cout<<"Loop: "<<loop<<std::endl;
			buffer_string = "";
			for (std::size_t char_buffer_place = 0; char_buffer_place < sizeof(buffer); ++char_buffer_place)
			{
				char current_buffer_char = buffer[char_buffer_place];
				std::string current_buffer_string(1, current_buffer_char);
				buffer_string = buffer_string + current_buffer_char;
			}
			return buffer_string;
		}else {
			std::cout<<"Not Receiving Message"<<std::endl;
			connect_mode = 1;
			mode = 1;
			return "0";
		}
	}

	//std::cout<<"Buffer String: "<<buffer_string<<std::endl;
}

float Socket::angle_one(std::string buffer_string){
	std::string angle = "A";
	std::string dest = "B";
	std::string angle_string = "";
	std::string dest_string = "";

	std::size_t find_angle_begin = buffer_string.find(angle);
	std::size_t find_angle_length = angle.find_last_of(angle);
	std::size_t find_angle_end = find_angle_begin + find_angle_length; //adds the length of the string to where it started
	std::size_t find_angle_number_start = find_angle_end + 2;


	std::size_t find_dest_begin = buffer_string.find(dest);

	std::size_t find_angle_number_end = find_dest_begin - 2;


	for (std::size_t current_angle_char_num = find_angle_number_start; current_angle_char_num <= find_angle_number_end; current_angle_char_num++){
		char current_angle_char = buffer_string[current_angle_char_num];
		std::string current_angle_string(1, current_angle_char);
		angle_string = angle_string + current_angle_char;
	}

	float angle_float = atof(angle_string.c_str());

	//std::cout<<"Angle Float: "<<angle_float<<std::endl;

	return angle_float;
}

float Socket::distance(std::string buffer_string){
	std::string dest = "B";
	std::string newang = "C";

	std::string dest_string = "";
	std::string newang_string = "";

	std::size_t find_dest_begin = buffer_string.find(dest);
	std::size_t find_dest_length = dest.find_last_of(dest);
	std::size_t find_dest_end = find_dest_begin + find_dest_length; //adds the length of the string to where it started
	std::size_t find_dest_number_start = find_dest_end + 2;

	std::size_t find_newang_begin = buffer_string.find(newang);

	std::size_t find_dest_number_end = find_newang_begin - 2;

	for (std::size_t current_dest_char_num = find_dest_number_start; current_dest_char_num <= find_dest_number_end; current_dest_char_num++){
		char current_dest_char = buffer_string[current_dest_char_num];
		std::string current_dest_string(1, current_dest_char);
		dest_string = dest_string + current_dest_char;
	}

	float dest_float = atof(dest_string.c_str());

	//std::cout<<"Destination Float: "<<dest_float<<std::endl;

	return dest_float;
}

float Socket::angle_two(std::string buffer_string){
	std::string newang = "C";
	std::string left = "L";

	std::string newang_string = "";
	std::string left_string = "";

	std::size_t find_newang_begin = buffer_string.find(newang);
	std::size_t find_newang_end = buffer_string.find_last_of(newang);
	std::size_t find_newang_number_start = find_newang_end + 2;

	std::size_t find_left_begin = buffer_string.find(left);

	std::size_t find_newang_number_end = find_left_begin - 2;
	
	for (std::size_t current_newang_char_num = find_newang_number_start; current_newang_char_num <= find_newang_number_end; current_newang_char_num++){
		char current_newang_char = buffer_string[current_newang_char_num];
		std::string current_newang_string(1, current_newang_char);
		newang_string = newang_string + current_newang_char;
	}

	float newang_float = atof(newang_string.c_str());

	//std::cout<<"New Angle Float: "<<newang_float<<std::endl;

	return newang_float;
}

float Socket::left_depth(std::string buffer_string){
	std::string left = "L";
	std::string right = "R";

	std::string left_string = "";
	std::string right_string = "";

	std::size_t find_left_begin = buffer_string.find(left);
	std::size_t find_left_end = buffer_string.find_last_of(left);
	std::size_t find_left_number_start = find_left_end + 2;

	std::size_t find_right_begin = buffer_string.find(right);

	std::size_t find_left_number_end = find_right_begin - 2;

	for (std::size_t current_left_char_num = find_left_number_start; current_left_char_num <= find_left_number_end; current_left_char_num++){
		char current_left_char = buffer_string[current_left_char_num];
		std::string current_left_string(1, current_left_char);
		left_string = left_string + current_left_char;
	}
	
	float left_float = atof(left_string.c_str());

	//std::cout<<"Left Depth Float: "<<left_float<<std::endl;

	return left_float;
}

float Socket::right_depth(std::string buffer_string){
	std::string right = "R";

	std::string right_string = "";

	std::size_t find_right_begin = buffer_string.find(right);
	std::size_t find_right_end = buffer_string.find_last_of(right);
	std::size_t find_right_number_start = find_right_end + 2;

	std::size_t find_right_number_end = buffer_string.find_last_of(buffer_string);

	for (std::size_t current_right_char_num = find_right_number_start; current_right_char_num <= find_right_number_end; current_right_char_num++){
		char current_right_char = buffer_string[current_right_char_num];
		std::string current_right_string(1, current_right_char);
		right_string = right_string + current_right_char;
	}

	float right_float = atof(right_string.c_str());

	//std::cout<<"Right Depth Float: "<<right_float<<std::endl;

	return right_float;
}