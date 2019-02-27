This is the Client Side of the Socket. In src/main/cpp/, there is a file called socket.cpp.
The update() function in socket.cpp receives and returns strings from the server. Here is the server code:


std::string string_in(){
	int angle_numerator = rand() % 1893;
	int angle_denominator = rand() % 1893 + 1;
	float angle = (float)angle_numerator / (float)angle_denominator;

	int dest_numerator = rand() % 1893;
	int dest_denominator = rand() % 1893 + 1;
	float dest = (float)dest_numerator / (float)dest_denominator;

	int newang_numerator = rand() % 1893;
	int newang_denominator = rand() % 1893 + 1;
	float newang = (float)newang_numerator / (float)newang_denominator;

	int left_numerator = rand() % 1893;
	int left_denominator = rand() % 1893 + 1;
	float left = (float)left_numerator / (float)left_denominator;

	int right_numerator = rand() % 1893;
	int right_denominator = rand() % 1893 + 1;
	float right = (float)right_numerator / (float)right_denominator;

	std::string angle_string = "A ";
	std::string dest_string = "B ";
	std::string newang_string = "C ";
	std::string left_string = "L ";
	std::string right_string = "R ";
	std::string semicolon = " ";
	std::string null = "\0";

	std::ostringstream angle_num_string;
	std::ostringstream dest_num_string;
	std::ostringstream newang_num_string;
	std::ostringstream left_num_string;
	std::ostringstream right_num_string;

	angle_num_string << angle;
	dest_num_string << dest;
	newang_num_string << newang;
	left_num_string << left;
	right_num_string << right;

	std::string input = angle_string + angle_num_string.str() + semicolon + dest_string + dest_num_string.str() + semicolon + newang_string + newang_num_string.str() +
	semicolon + left_string + left_num_string.str() + semicolon + right_string +right_num_string.str() + null;
	std::cout<<"Input: "<<input<<std::endl;
	return input;
}

int main()
{
	int backlog = 3, sends;
	struct sockaddr_in servaddr;
	struct sockaddr clientaddr;
	int clientlen = sizeof(clientaddr);
	int flags;
	char buffer_rec[512] = {7};
	std::cout<<"Buffer Rec Up Here: "<<buffer_rec<<std::endl;
	
	char buffer_shutdown[MAXBUF] = "Goodnight";
	memset(&servaddr, '0', sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5060);
	servaddr.sin_addr.s_addr = /*inet_addr("127.0.0.1");*/ INADDR_ANY;
	int baccept, servsock;
	servsock = socket(AF_INET, SOCK_STREAM, 0);
	int clientsock;
	int opt = 1;
	bool breakout = 0;
	int loop = 0;

	if (servsock < 0)
	{
		std::cout << "Failed to create socket" << std::endl;
	}
	if (setsockopt(servsock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0)
	{
		std::cout<<"Set Sock Opt Fail"<<std::endl;
	}
	int binding = bind(servsock, (struct sockaddr *)&servaddr, sizeof(servaddr));
	std::cout<<"Binded: "<<binding<<std::endl;
	int list = listen(servsock, backlog);
	std::cout<<"Listening"<<std::endl;
	std::cout << "list"<<list << std::endl;
	std::cout<<"Listening for Real"<<std::endl;
	baccept = accept(servsock, (struct sockaddr *)&clientaddr, (socklen_t* )&clientlen);
	flags = fcntl(baccept, F_GETFL);
	fcntl(baccept, F_SETFL, flags | O_NONBLOCK);
	if (baccept < 0)
	{
		std::cout<<"Didn't Accept"<<std::endl;
		//return 0;
	}

	while(1){
		std::string input = string_in();
		char buffer_data[MAXBUF];
		strcpy(buffer_data, input.c_str());
		if (baccept > 0)
		{
			int sending = send(baccept , buffer_data , sizeof(buffer_data), 0 );
			//std::cout<<"Sending: "<<sending<<std::endl;
			std::cout<<"What it sent: "<<buffer_data<<std::endl;
			loop ++;
			std::cout<<"Loop: "<<loop<<std::endl;
			usleep(1000 * 30);
		}
		
	}
}