#include <SFML/Network.hpp>
#include <iostream>
#include <string>

// UDP connection test 
int main()
{
	std::cout << "Server" << std::endl;
	
	unsigned short port = { 54000 };
	sf::UdpSocket socket;
	if (socket.bind(port) != sf::Socket::Done)
	{
		std::cerr << "Error by binding socket" << std::endl;
	}
	else
	{
		std::cout << "Binding successfully" << std::endl;
	}
	
	char data[11];
	sf::IpAddress senderIp;
	std::size_t received;
	if (socket.receive(data, sizeof(data), received, senderIp, port) != sf::Socket::Done)
	{
		std::cerr << "Error by receiving data" << std::endl; 
	}
	else
	{
		std::cout << "Received: " << received << " bytes from " << senderIp << " on port " << port << std::endl;
		std::cout << "Message:" << std::endl;
		for (char c : data)
		{
			std::cout << c;
		}
		std::cout << std::endl;
	}
}
