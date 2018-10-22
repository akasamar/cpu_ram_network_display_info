/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:26:28 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/14 14:08:37 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_RAMMODULE_HPP
#define RUSH01_RAMMODULE_HPP

#include "IMonitorModule.hpp"
#include <string>
#include <map>
#include "Parser.hpp"

class RAMModule : public IMonitorModule {
public:
	RAMModule();
	RAMModule(const RAMModule &other);
	RAMModule &operator= (const RAMModule &other);
	~RAMModule();

	void		getData(std::map<std::string, std::string> mp);
	std::string	getRAM() const;

private:
	std::string	_ram;
};


#endif //RUSH01_RAMMODULE_HPP
