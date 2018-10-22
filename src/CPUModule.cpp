/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 12:55:47 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/14 13:25:30 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.hpp"

CPUModule::CPUModule()
{

}

CPUModule::CPUModule(const CPUModule &other)
{
	*this = other;
}

CPUModule &CPUModule::operator=(const CPUModule &other)
{
	if (this != &other)
	{
		_idle = other._idle;
		_name = other._name;
		_sys = other._sys;
		_user = other._user;
	}
	return *this;
}

CPUModule::~CPUModule()
{

}

void CPUModule::getData(std::map<std::string, std::string> mp)
{
	std::map<std::string, std::string>::iterator it;

	it = mp.find("CPU idle");
	_idle = it->second;
	it = mp.find("CPU name");
	_name = it->second;
	it = mp.find("CPU sys");
	_sys = it->second;
	it = mp.find("CPU user");
	_user = it->second;
}

std::string CPUModule::getName() const {
	return _name;
}

std::string CPUModule::getSys() const {
	return _sys;
}

std::string CPUModule::getUser() const {
	return _user;
}

std::string CPUModule::getNIdle() const {
	return _idle;
}
