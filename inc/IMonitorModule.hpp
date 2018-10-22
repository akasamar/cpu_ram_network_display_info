/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:43:24 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/13 18:58:22 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_IMONITORMODULE_HPP
#define RUSH01_IMONITORMODULE_HPP

#include <map>
#include <string>

class IMonitorModule
{
public:
	virtual ~IMonitorModule() {};

	virtual void getData(std::map<std::string, std::string> mp) = 0;

};

#endif //RUSH01_IMONITORMODULE_HPP
