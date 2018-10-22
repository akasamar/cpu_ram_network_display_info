/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WindowMode.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 20:41:42 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/14 19:58:23 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_WINDOWMODE_HPP
#define RUSH01_WINDOWMODE_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "BaseInfoModule.hpp"
#include "NetworkModule.hpp"
#include "RAMModule.hpp"
#include <vector>
#include <algorithm>
#include "SDL.h"
#include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"

class WindowMode : public IMonitorDisplay {
public:
	WindowMode();
	WindowMode(const WindowMode &other);
	WindowMode &operator= (const WindowMode &other);
	~WindowMode();

	void	getEvent();
	bool	isOn();
	void 	render(std::vector<IMonitorModule *> vec);
	void	displayBase(const BaseInfoModule *module);
	void	displayRAM(const RAMModule *module);
	void	displayNetwork(const NetworkModule *module);
	void	displaySting(std::string str, int x, int y, SDL_Color color, int *nextX, int *nextY);
	void	clear();
	void	init();
	void	turnOn();

private:
	int 			_winH;
	int 			_winW;
	bool			_isOn;
	SDL_Window		*_window;
	SDL_Renderer	*_renderer;
	SDL_Surface		*_baseSurface;
	SDL_Rect		_baseRect;
	SDL_Surface		*_ramSurface;
	SDL_Rect		_ramRect;
	SDL_Surface		*_networkSurface;
	SDL_Rect		_networkRect;
	TTF_Font		*_font;
};


#endif //RUSH01_WINDOWMODE_HPP
