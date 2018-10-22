/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:26:39 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/14 14:14:00 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RAMModule.hpp>

#include "RAMModule.hpp"

RAMModule::RAMModule() {

}

RAMModule::RAMModule(const RAMModule &other)
{
	*this = other;
}

RAMModule &RAMModule::operator=(const RAMModule &other)
{
	if (this != &other)
	{
		_ram = other._ram;
	}
	return *this;
}

RAMModule::~RAMModule() {

}

void RAMModule::getData(std::map<std::string, std::string> mp)
{
	std::map<std::string, std::string>::iterator it;

	it = mp.find("RAM used");
	_ram = it->second;
}

std::string RAMModule::getRAM() const {
	return _ram;
}
