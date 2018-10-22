/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 19:29:29 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/13 19:43:20 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_TERMINALDISPLAY_HPP
#define RUSH01_TERMINALDISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include <vector>
#include <algorithm>

class TerminalDisplay : public IMonitorDisplay {
public:
	TerminalDisplay();
	TerminalDisplay(const TerminalDisplay &other);
	TerminalDisplay &operator= (const TerminalDisplay &other);
	~TerminalDisplay();

	void render(std::vector<IMonitorModule *> vec);
};


#endif //RUSH01_TERMINALDISPLAY_HPP
