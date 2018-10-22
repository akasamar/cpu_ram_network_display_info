// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   System.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 14:23:25 by akasamar          #+#    #+#             //
//   Updated: 2018/10/13 14:23:26 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NCURSE_HPP
#define NCURSE_HPP

#define STR1 "     /\\__/\\"
#define STR2 "    /`    '\\"
#define STR3 "  === 0  0 ==="
#define STR4 "    \\  --  /"
#define STR5 "   /        \\"
#define STR6 "  /          \\"
#define STR7 " |            |"
#define STR8 "  \\  ||  ||  /"
#define STR9 "   \\_oo__oo_/#######o"
#define STR10 "  === _  _ ==="

#include <iostream>
#include <string>
#include <ncurses.h>
#include "IMonitorDisplay.hpp"
#include <zconf.h>
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "NetworkModule.hpp"
#include "WindowMode.hpp"




class Ncurse : public IMonitorDisplay{
public:
    Ncurse();
    ~Ncurse();
    Ncurse(Ncurse const & src);
    Ncurse & operator=(Ncurse const & src);

    void    setWin0(WINDOW *win0);
    void    setWin01(WINDOW *win0);
    void    setWin1(WINDOW *win1);
    void    setWin2(WINDOW *win2);
    void    setWin3(WINDOW *win3);

    WINDOW*    getWin0();
    WINDOW*    getWin01();
    WINDOW*    getWin1();
    WINDOW*    getWin2();
    WINDOW*    getWin3();

    void        inputDiagram(WINDOW *win, int data, int win_num);
    void        start_ncurse_mode();
    void        displayZazAnimal();
    void        exitFunction(WindowMode *mod);

    virtual void render(std::vector<IMonitorModule *> vec);
    virtual void displayBase(const BaseInfoModule *module);
    virtual void displayCPU(const CPUModule *module);
    virtual void displayRAM(const RAMModule *module);
    virtual void displayNetwork(const NetworkModule *module);

    bool	isRunning();


private:
    WINDOW* _win0;
    WINDOW* _win01;
    WINDOW* _win1;
    WINDOW* _win2;
    WINDOW* _win3;
    int * FirstArray;
    int * SecondArray;
    int * FirstArray2;
    int * SecondArray2;
    int * FirstArray3;
    int * SecondArray3;

    void create_win();
    void checkSizeWindow();

    bool	_isRunning;
};

void start_ncurse_mode();

#endif