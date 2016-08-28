#include <SFML/Network.hpp>
#include <iostream>
#include <string>

// UDP connection test
int main()
{        
	std::cout << "Client" << std::endl;
	std::cout << "IP ?" << std::endl;
	std::string ip;
	std::cin >> ip;
	sf::UdpSocket socket;
	unsigned short port = 54000;

	char data[11] = { 'H', 'E', 'L', 'L', 'O', ' ', 'W', 'O', 'R', 'L', 'D' };
	if (socket.send(data, sizeof(data), ip, port) != sf::Socket::Done)
	{
		std::cerr << "Error by sending data" << std::endl;
	}
	else
	{
		std::cout << "Sended data successfully" << std::endl;
	}
}


