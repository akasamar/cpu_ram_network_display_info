/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 14:28:37 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/14 14:35:22 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_NETWORKMODULE_HPP
#define RUSH01_NETWORKMODULE_HPP

#include "IMonitorModule.hpp"
#include <string>
#include <map>
#include "Parser.hpp"

class NetworkModule : public IMonitorModule {
public:
	NetworkModule();
	NetworkModule(const NetworkModule &other);
	NetworkModule &operator= (const NetworkModule &other);
	~NetworkModule();

	void		getData(std::map<std::string, std::string> mp);
	std::string getIn() const;
	std::string getOut() const;

private:
	std::string	_in;
	std::string	_out;
};


#endif //RUSH01_NETWORKMODULE_HPP
