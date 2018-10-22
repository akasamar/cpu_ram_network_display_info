/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 12:54:57 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/14 14:27:50 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_CPUMODULE_HPP
#define RUSH01_CPUMODULE_HPP

#include "IMonitorModule.hpp"
#include <string>
#include <map>
#include "Parser.hpp"

class CPUModule : public IMonitorModule {
public:
	CPUModule();
	CPUModule(const CPUModule &other);
	CPUModule &operator= (const CPUModule &other);
	~CPUModule();

	void		getData(std::map<std::string, std::string> mp);
	std::string getName() const;
	std::string getSys() const;
	std::string getUser() const;
	std::string getNIdle() const;

private:
	std::string	_name;
	std::string	_sys;
	std::string	_user;
	std::string	_idle;
};


#endif //RUSH01_CPUMODULE_HPP
