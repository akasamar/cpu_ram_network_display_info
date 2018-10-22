/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WindowMode.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 20:42:47 by aminadzh          #+#    #+#             */
/*   Updated: 2018/10/14 19:58:23 by aminadzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <WindowMode.hpp>

#include "WindowMode.hpp"

WindowMode::WindowMode()
{
	init();
}

WindowMode::WindowMode(const WindowMode &other)
{
	*this = other;
}

WindowMode &WindowMode::operator=(const WindowMode &other)
{
	if (this != &other)
	{
		//to do: copy all stuff
	}
	return *this;
}

WindowMode::~WindowMode()
{

}

void WindowMode::render(std::vector<IMonitorModule *> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (dynamic_cast<BaseInfoModule *>(vec[i]))
			displayBase(dynamic_cast<BaseInfoModule *>(vec[i]));
		if (dynamic_cast<RAMModule *>(vec[i]))
			displayRAM(dynamic_cast<RAMModule *>(vec[i]));
		if (dynamic_cast<NetworkModule *>(vec[i]))
			displayNetwork(dynamic_cast<NetworkModule *>(vec[i]));
	}

	SDL_RenderPresent(_renderer);
	SDL_RenderClear(_renderer);
	getEvent();
}

void WindowMode::displayBase(const BaseInfoModule *module)
{
	SDL_FillRect(_baseSurface, NULL, 0x000000);
	SDL_FillRect(_baseSurface, NULL, SDL_MapRGB(_baseSurface->format, 255, 0, 0));
	SDL_Color	white = {255, 255, 255, 255};
	SDL_Color	green = {0, 255, 0, 255};
	SDL_Color	blue = {0, 0, 255, 255};
	int x = 0, y = 0;

	displaySting("Host name: ", _baseRect.x + 10, _baseRect.y + 10, green, &x, &y);
	displaySting(module->getHostName(), x, _baseRect.y + 10, white, &x, &y);
	displaySting("User name: ", _baseSurface->w / 2, _baseRect.y + 10, green, &x, &y);
	displaySting(module->getUserName(), x, _baseRect.y + 10, white, &x, NULL);
	displaySting("OS name: ", _baseRect.x + 10, y, green, &x, NULL);
	displaySting(module->getOSName(), x, y, white, &x, NULL);
	displaySting("OS Version: ", _baseSurface->w / 2, y, green, &x, NULL);
	displaySting(module->getOSVer(), x, y, white, &x, &y);
	SDL_Surface	*timeSurf = TTF_RenderText_Solid(_font, module->getTimer().c_str(), blue);
	SDL_Rect	timeRect = {_baseSurface->w / 2 - timeSurf->w / 2, y, timeSurf->w, timeSurf->h};
	SDL_BlitSurface(timeSurf, NULL, _baseSurface, &timeRect);
	SDL_FreeSurface(timeSurf);

	SDL_Texture	*tex = SDL_CreateTextureFromSurface(_renderer, _baseSurface);
	SDL_RenderCopy(_renderer, tex, NULL, &_baseRect);
	SDL_DestroyTexture(tex);

}

void WindowMode::displayRAM(const RAMModule *module)
{
	SDL_FillRect(_ramSurface, NULL, 0x000000);
	SDL_FillRect(_ramSurface, NULL, SDL_MapRGB(_ramSurface->format, 0, 255, 0));
	SDL_Color	white = {255, 255, 255, 255};
	SDL_Surface	*surf = TTF_RenderText_Solid(_font, module->getRAM().c_str(), white);
	SDL_Rect	dstRect = {_ramRect.w / 2 - surf->w / 2, 10, surf->w, surf->h};
	SDL_BlitSurface(surf, NULL, _ramSurface, &dstRect);
	SDL_FreeSurface(surf);

	SDL_Texture	*tex = SDL_CreateTextureFromSurface(_renderer, _ramSurface);
	SDL_RenderCopy(_renderer, tex, NULL, &_ramRect);
	SDL_DestroyTexture(tex);
}

void WindowMode::displaySting(std::string str, int x, int y, SDL_Color color, int *nextX, int *nextY)
{
	SDL_Surface	*surface = TTF_RenderText_Solid(_font, str.c_str(), color);
	SDL_Rect	dstRect = {x, y, surface->w, surface->h};
	SDL_BlitSurface(surface, NULL, _baseSurface, &dstRect);
	if (nextX)
		*nextX = x +  surface->w;
	if (nextY)
		*nextY = y + surface->h;
	SDL_FreeSurface(surface);
}

bool WindowMode::isOn() {
	return _isOn;
}

void WindowMode::getEvent()
{
	SDL_Event	event;

	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT) {
			_isOn = false;
			clear();
		}
	}
}

void WindowMode::displayNetwork(const NetworkModule *module)
{
	SDL_FillRect(_networkSurface, NULL, 0x000000);
//	SDL_FillRect(_networkSurface, NULL, SDL_MapRGB(_networkSurface->format, 0, 0, 255));

	SDL_Color	white = {255, 255, 255, 255};
	SDL_Color	blue = {0, 0, 255, 255};

	SDL_Surface	*heading = TTF_RenderText_Solid(_font, "NETWORK", blue);
	SDL_Rect	headRect = {_networkRect.w / 2 - heading->w / 2, 10, heading->w, heading->h};
	SDL_BlitSurface(heading, NULL, _networkSurface, &headRect);
	SDL_FreeSurface(heading);

	SDL_Surface	*in = TTF_RenderText_Solid(_font, module->getIn().c_str(), white);
	SDL_Rect	inRect = {_networkRect.w / 4 - in->w / 2, 10 + headRect.h, in->w, in->h};
	SDL_BlitSurface(in, NULL, _networkSurface, &inRect);
	SDL_FreeSurface(in);

	SDL_Surface	*out = TTF_RenderText_Solid(_font, module->getOut().c_str(), white);
	SDL_Rect	outRect = {_networkRect.w / 4 * 3 - out->w / 2, 10 + headRect.h, out->w, out->h};
	SDL_BlitSurface(out, NULL, _networkSurface, &outRect);
	SDL_FreeSurface(out);

	SDL_Texture	*tex = SDL_CreateTextureFromSurface(_renderer, _networkSurface);
	SDL_RenderCopy(_renderer, tex, NULL, &_networkRect);
	SDL_DestroyTexture(tex);
}

void WindowMode::clear() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	SDL_Quit();
}

void WindowMode::init()
{
	_window = NULL;
	_renderer = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		if (!(_window = SDL_CreateWindow("ft_gkrellm", 0, 0, 700, 1000, SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI)))
			_isOn = false;
		else
		{
			SDL_GetWindowSize(_window, &_winW, &_winH);
			SDL_SetWindowOpacity(_window, 0.8f);
			if (!(_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC)))
				_isOn = false;
			else
				_isOn = true;
			if (!(_baseSurface = SDL_CreateRGBSurface(0, _winW * 2, _winH / 4, 32 , 0, 0, 0, 0)))
				_isOn = false;
			if (!(_ramSurface = SDL_CreateRGBSurface(0, _winW * 2, _winH / 7, 32 , 0, 0, 0, 0)))
				_isOn = false;
			if (!(_networkSurface = SDL_CreateRGBSurface(0, _winW * 2, _winH / 4, 32 , 0, 0, 0, 0)))
				_isOn = false;
		}
		if (TTF_Init() < 0)
			_isOn = false;
		if (!(_font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 50)))
			_isOn = false;
	}
	else
		_isOn = false;

	_baseRect.x = 0;
	_baseRect.y = 0;
	_baseRect.h = _baseSurface->h;
	_baseRect.w = _baseSurface->w;

	_ramRect.x = 0;
	_ramRect.y = _baseRect.h;
	_ramRect.h = _ramSurface->h;
	_ramRect.w = _ramSurface->w;

	_networkRect.x = 0;
	_networkRect.y = _ramRect.h + _baseRect.h;
	_networkRect.h = _networkSurface->h;
	_networkRect.w = _networkSurface->w;
}

void WindowMode::turnOn() {
	_isOn = true;
	init();
}
