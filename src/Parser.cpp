/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:07:48 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/14 14:26:54 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser()
{
	char 	hostName[255];

	//Retrieving host and username
	int hn = gethostname(hostName, 255);
	if (hn == 0)
		_data["Host name"] = hostName;
	else
		_data["Host name"] = std::string("unknown");
	_data["User name"] = getlogin();

	//Retrieving CPU name
	parceCPUInfo();
	parseOsInfo();

}

Parser &Parser::operator=(const Parser &other) {
	if (this != &other)
	{
		_data = other._data;
	}
	return *this;
}

Parser::Parser(const Parser &other)
{
	*this = other;
}

Parser::~Parser()
{

}

void Parser::parseOsInfo()
{
	FILE	*stream;
	char 	buffer[128];

	stream = popen("sw_vers", "r");
	if (!stream) throw std::runtime_error("popen() error!");
	try
	{
		while (!feof(stream))
		{
			if (fgets(buffer, 128, stream) != NULL)
			{
				parseString(buffer);
			}
		}
	}
	catch (std::runtime_error &re)
	{
		std::cout << "sw_vers" << re.what() << std::endl;
		pclose(stream);
	}
	pclose(stream);
}

void Parser::parseTopHeader()
{
	FILE	*stream;
	char 	buffer[128];

	stream = popen("top -l 1 -n 1", "r");
	if (!stream) throw std::runtime_error("popen() error!");
	try
	{
		while (!feof(stream))
		{
			if (fgets(buffer, 128, stream) != NULL)
			{
				parseString(buffer);
			}
		}
	}
	catch (std::runtime_error &re)
	{
		std::cout << re.what() << std::endl;
		pclose(stream);
	}
	pclose(stream);
}

void Parser::parseString(const std::string str)
{
	if (str.find("CPU usage") != std::string::npos)
	{
		std::size_t pos = str.find("user");
		_data["CPU user"] = str.substr(pos - 7, 6);
		pos = str.find("sys");
		_data["CPU sys"] = str.substr(pos - 7, 6);
		pos = str.find("idle");
		_data["CPU idle"] = str.substr(pos - 7, 6);
	}
	if (str.find("ProductName") != std::string::npos)
		_data["OS name"] = str.substr(13, str.size() - 14);
	if (str.find("ProductVersion") != std::string::npos)
		_data["OS version"] = str.substr(16, str.size() - 17);
	if (str.find("PhysMem") != std::string::npos)
	{
		_data["RAM used"] = str.substr(9, str.size() - 10);
	}
	if (str.find("Networks") != std::string::npos)
	{
		std::size_t st = str.find("packets");
		std::size_t end = str.find(" in");
		_data["Packets in"] = str.substr(st + 9, str.size() - st - end);
		st = str.find("in, ");
		end = str.find(" out");
		_data["Packets out"] = str.substr(st + 4, 13);
	}

	//Getting current time
	time_t rawtime;
	struct	tm *timeinfo;
	char buffer[80];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", timeinfo);
	_data["Time"] = std::string(buffer);
}

void Parser::printMap()
{
	std::map<std::string, std::string>::iterator it = _data.begin();
	while (it != _data.end())
	{
		std::cout << it->first << " :: " << it->second << std::endl;
		it++;
	}
	std::cout << "---------------" << std::endl;
}

std::map<std::string, std::string> Parser::data() {
	return _data;
}

void Parser::parceCPUInfo()
{
	FILE	*stream;
	char 	buffer[128];

	stream = popen("sysctl -n machdep.cpu.brand_string", "r");
	if (!stream) throw std::runtime_error("popen() error!");
	try
	{
		fgets(buffer, 128, stream);
		std::string str = buffer;

		_data["CPU name"] = str.substr(0, str.size() - 1);
	}
	catch (std::runtime_error &re)
	{
		std::cout << re.what() << std::endl;
		pclose(stream);
	}
	pclose(stream);
}

