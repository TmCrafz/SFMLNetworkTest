#include <SFML/Network.hpp>
#include <iostream>

// TCP connection test
int main()
{
	std::cout << "Server" << std::endl;
	sf::TcpListener listener;
	
	if (listener.listen(53000) != sf::Socket::Done)
	{
		std::cerr << "Error By binding to port" << std::endl;
	}
	else
	{
		std::cout << "Successfully binding port" << std::endl;
	}
	sf::TcpSocket client;
	if (listener.accept(client) != sf::Socket::Done)
	{
		std::cerr << "Error by accepted new connection" << std::endl;
	}
	else
	{
		std::cout << "Successfully accepting connection" << std::endl;
	}
	char data[11];
	std::size_t received;
	if (client.receive(data, sizeof(data), received) != sf::Socket::Done)
	{
		std::cerr << "Error by receiving data" << std::endl;
	}
	else
	{
		std::cout << "Received " << received << " Bytes" << std::endl;
		std::cout << "Data:" << std::endl;
		for (char c : data)
		{
			std::cout << c;
		}
		std::cout << std::endl;
	}
}
