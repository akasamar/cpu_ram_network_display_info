/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseInfoModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:59:39 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/14 13:25:30 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseInfoModule.hpp"

BaseInfoModule::BaseInfoModule() {

}

void BaseInfoModule::getData(std::map<std::string, std::string> mp)
{
	std::map<std::string, std::string>::iterator it;

	it = mp.find("User name");
	_username = it->second;
	it = mp.find("Host name");
	_hostname = it->second;
	it = mp.find("OS name");
	_osname = it->second;
	it = mp.find("OS version");
	_osver = it->second;
	it = mp.find("Time");
	_timer = it->second;
}

BaseInfoModule &BaseInfoModule::operator=(const BaseInfoModule &other) {
	if (this != &other)
	{
		_hostname = other._hostname;
		_username = other._username;
	}
	return *this;
}

std::string BaseInfoModule::getUserName() const {
	return _username;
}

BaseInfoModule::~BaseInfoModule()
{

}

BaseInfoModule::BaseInfoModule(const BaseInfoModule &other)
{
	*this = other;
}

std::string BaseInfoModule::getHostName() const {
	return _hostname;
}

std::string BaseInfoModule::getOSName() const {
	return _osname;
}

std::string BaseInfoModule::getOSVer() const {
	return _osver;
}

std::string BaseInfoModule::getTimer() const {
	return _timer;
}
