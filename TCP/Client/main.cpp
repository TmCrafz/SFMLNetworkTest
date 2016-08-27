#include <SFML/Network.hpp>
#include <iostream>
#include <string>

// TCP connection test
int main()
{
	std::cout << "Client" << std::endl;
		
	std::string ip;
	std::cout << "IP adress to connect?" << std::endl;
	std::cin >> ip;
	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect(ip, 53000);
	if (status != sf::Socket::Done)
	{
		std::cerr << "Error" << std::endl;
	}
	else
	{
		std::cout << "Success" << std::endl;
	}
	char data[11] = { 'H', 'E', 'L', 'L', 'O', ' ', 'W', 'O', 'R', 'L', 'D' };
	if (socket.send(data, sizeof(data)) != sf::Socket::Done)
	{
		std::cerr << "Error by sending data" << std::endl;
	}
	else
	{
		std::cout << "data send" << std::endl;
	}
}


