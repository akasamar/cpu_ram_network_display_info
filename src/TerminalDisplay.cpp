/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 19:29:25 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/13 19:45:59 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <TerminalDisplay.hpp>

#include "TerminalDisplay.hpp"

TerminalDisplay::TerminalDisplay()
{
	//here we initialize ncurses
}

TerminalDisplay::TerminalDisplay(const TerminalDisplay &other)
{
	*this = other;
}

TerminalDisplay &TerminalDisplay::operator=(const TerminalDisplay &other)
{
	if (this != &other)
	{
		//to do: copy all stuff
	}
	return *this;
}

TerminalDisplay::~TerminalDisplay()
{

}

void TerminalDisplay::render(std::vector<IMonitorModule *> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i]->display();
	}
}

