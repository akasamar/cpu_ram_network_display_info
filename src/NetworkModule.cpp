/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 14:28:50 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/14 14:35:22 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <NetworkModule.hpp>

#include "NetworkModule.hpp"

NetworkModule::NetworkModule()
{

}

NetworkModule::NetworkModule(const NetworkModule &other)
{
	*this = other;
}

NetworkModule &NetworkModule::operator=(const NetworkModule &other)
{
	if (this != &other)
	{
		_in = other._in;
		_out = other._out;
	}
	return *this;
}

NetworkModule::~NetworkModule()
{

}

void NetworkModule::getData(std::map<std::string, std::string> mp)
{
	std::map<std::string, std::string>::iterator it;

	it = mp.find("Packets in");
	_in = it->second;
	it = mp.find("Packets out");
	_out = it->second;
}

std::string NetworkModule::getIn() const {
	return _in;
}

std::string NetworkModule::getOut() const {
	return _out;
}
