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
	

}
