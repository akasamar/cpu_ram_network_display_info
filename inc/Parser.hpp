/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:07:40 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/13 21:37:25 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_PARSER_HPP
#define RUSH01_PARSER_HPP

#include <map>
#include <string>
#include <iostream>
#include <iterator>
#include <unistd.h>
#include <sys/utsname.h>
#include <ctime>

class Parser
{
public:
	Parser();
	Parser &operator= (const Parser &other);
	Parser(const Parser &other);
	~Parser();

	void	parseOsInfo();
	void	parseTopHeader();
	void	parseString(const std::string str);
	void	parceCPUInfo();
	std::map<std::string, std::string>	data();

	void	printMap();//del this

private:
	std::map<std::string, std::string>	_data;

};

#endif //RUSH01_PARSER_HPP
