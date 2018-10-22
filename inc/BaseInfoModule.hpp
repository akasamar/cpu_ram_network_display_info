/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseInfoModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:59:44 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/13 21:45:55 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_BASEINFOMODULE_HPP
#define RUSH01_BASEINFOMODULE_HPP

#include "IMonitorModule.hpp"
#include <string>
#include <map>
#include "Parser.hpp"

class BaseInfoModule : public IMonitorModule
{
public:
	BaseInfoModule();
	BaseInfoModule(const BaseInfoModule &other);
	BaseInfoModule &operator= (const BaseInfoModule &other);
	~BaseInfoModule();

	void		getData(std::map<std::string, std::string> mp);
	std::string	getUserName() const;
	std::string	getHostName() const;
	std::string	getOSName() const;
	std::string	getOSVer() const;
	std::string	getTimer() const;

private:
	std::string	_hostname;
	std::string	_username;
	std::string	_osname;
	std::string	_osver;
	std::string	_timer;
};

#endif //RUSH01_BASEINFOMODULE_HPP
