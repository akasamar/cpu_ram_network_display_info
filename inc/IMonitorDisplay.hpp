/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:46:05 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/13 20:29:45 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_IMONITORDISPLAY_HPP
#define RUSH01_IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"
#include "BaseInfoModule.hpp"
#include <vector>

class IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay() {};

//	virtual void displayCPU() = 0;
	virtual void render(std::vector<IMonitorModule *> vec) = 0;
//	virtual void print(std::map<std::string, std::string> mp) = 0;
	virtual void displayBase(const BaseInfoModule *module) = 0;
//	virtual void displayRAM() = 0;
//	virtual void displayNetwork() = 0;
};

#endif //RUSH01_IMONITORDISPLAY_HPP
