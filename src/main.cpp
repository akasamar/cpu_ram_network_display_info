/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:11:36 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/14 19:55:23 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "SDL.h"
#include "Ncurse.hpp"
#include <ncurses.h>
#include "Parser.hpp"
#include "BaseInfoModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "NetworkModule.hpp"
#include <vector>
#include "WindowMode.hpp"

int main(void)
{
	Parser parser;

	WindowMode	windowMode;
	Ncurse obj;


	std::vector<IMonitorModule *> modules;
	BaseInfoModule baseModule;
	IMonitorModule *bm = &baseModule;
	CPUModule	cpuModule;
	IMonitorModule *cpu = &cpuModule;
	RAMModule	ramModule;
	IMonitorModule *ram = &ramModule;
	NetworkModule	networkModule;
	IMonitorModule *network = &networkModule;
	modules.push_back(bm);
	modules.push_back(cpu);
	modules.push_back(ram);
	modules.push_back(network);


	while (windowMode.isOn() || obj.isRunning())
	{
		parser.parseTopHeader();
		modules[0]->getData(parser.data());
		modules[1]->getData(parser.data());
		modules[2]->getData(parser.data());
		modules[3]->getData(parser.data());
		if (windowMode.isOn())
			windowMode.render(modules);

		if (obj.isRunning())
		{
			obj.render(modules);
			wrefresh(obj.getWin0());
			wrefresh(obj.getWin01());
			wrefresh(obj.getWin1());
			wrefresh(obj.getWin2());
			wrefresh(obj.getWin3());
			obj.displayZazAnimal();
			obj.exitFunction(&windowMode);
		}
	}

	return 0;
}
