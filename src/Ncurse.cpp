// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   System.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 14:47:20 by akasamar          #+#    #+#             //
//   Updated: 2018/10/13 14:47:21 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ncurse.hpp"


Ncurse::Ncurse(){
    _isRunning = true;
    FirstArray = new int[100];
    SecondArray = new int[99];
    FirstArray2 = new int[100];
    SecondArray2 = new int[99];
    FirstArray3 = new int[100];
    SecondArray3 = new int[99];
    for (int i = 0; i < 100; i++) {
        FirstArray[i] = 0;
        FirstArray2[i] = 0;
        FirstArray3[i] = 0;
        if (i < 99) {
            SecondArray[i] = 0;
            SecondArray2[i] = 0;
            SecondArray3[i] = 0;
        }
    }
    start_ncurse_mode();
}

Ncurse::Ncurse(Ncurse const & src) {

    *this = src;
}

Ncurse & Ncurse::operator=(Ncurse const & src) {
    this->_win0 = src._win0;
    this->_win01 = src._win01;
    this->_win1 = src._win1;
    this->_win2 = src._win2;
    this->_win3 = src._win3;
    this->FirstArray = src.FirstArray;
    this->SecondArray = src.SecondArray;
    return (*this);
}

Ncurse::~Ncurse(){
    delete [] FirstArray;
    delete [] SecondArray;
    delete [] FirstArray2;
    delete [] SecondArray2;
    delete [] FirstArray3;
    delete [] SecondArray3;
}

void    Ncurse::setWin0(WINDOW *win0)
{
    _win0 = win0;
}

void    Ncurse::setWin01(WINDOW *win01)
{
    _win01 = win01;
}

void    Ncurse::setWin1(WINDOW *win1)
{
    _win1 = win1;
}
void    Ncurse::setWin2(WINDOW *win2)
{
    _win2 = win2;
}

void    Ncurse::setWin3(WINDOW *win3)
{
    _win3 = win3;
}


WINDOW*    Ncurse::getWin0()
{
    return _win0;
}

WINDOW*    Ncurse::getWin01()
{
    return _win01;
}

WINDOW*    Ncurse::getWin1()
{
    return _win1;
}
WINDOW*    Ncurse::getWin2()
{
    return _win2;
}

WINDOW*    Ncurse::getWin3()
{
    return _win3;
}


void       Ncurse::inputDiagram(WINDOW *getWin, int data, int win_num) {

    mvwprintw(getWin1(), 4, 1, "100");
    mvwprintw(getWin1(), 5, 2, "80");
    mvwprintw(getWin1(), 6, 2, "60");
    mvwprintw(getWin1(), 7, 2, "40");
    mvwprintw(getWin1(), 8, 2, "20");
    mvwprintw(getWin2(), 4, 1, "100");
    mvwprintw(getWin2(), 5, 2, "80");
    mvwprintw(getWin2(), 6, 2, "60");
    mvwprintw(getWin2(), 7, 2, "40");
    mvwprintw(getWin2(), 8, 2, "20");
    mvwprintw(getWin3(), 4, 1, "100");
    mvwprintw(getWin3(), 5, 2, "80");
    mvwprintw(getWin3(), 6, 2, "60");
    mvwprintw(getWin3(), 7, 2, "40");
    mvwprintw(getWin3(), 8, 2, "20");

    int k;
    int* FirstArrayMain = new int[100];

    if (win_num == 1) {
        FirstArray[0] = data;
        for (k = 0; k < 99; k++)
            FirstArray[k + 1] = SecondArray[k];
        for (k = 0; k < 100; k++)
            FirstArrayMain[k] = FirstArray[k];
    }
    else if (win_num == 2) {
        FirstArray2[0] = data;
        for (k = 0; k < 99; k++)
            FirstArray2[k + 1] = SecondArray2[k];
        for (k = 0; k < 100; k++)
            FirstArrayMain[k] = FirstArray2[k];
    }
    else if (win_num == 3) {
        FirstArray3[0] = data;
        for (k = 0; k < 99; k++)
            FirstArray3[k + 1] = SecondArray3[k];
        for (k = 0; k < 100; k++)
            FirstArrayMain[k] = FirstArray3[k];
    }
    int z = 0;
    int i = 0;
        while (z < 5) {
            while (i < 100) {
                if (FirstArrayMain[i] > 80 && z == 0) {
                    if (win_num == 3)
                        wattron(getWin,COLOR_PAIR(3) | A_STANDOUT);
                    else
                        wattron(getWin,COLOR_PAIR(1) | A_STANDOUT);
                    mvwprintw(getWin, 4 + z, 5 + i, " ");
                    if (win_num == 3)
                        wattroff(getWin,COLOR_PAIR(3) | A_STANDOUT);
                    else
                        wattroff(getWin,COLOR_PAIR(1) | A_STANDOUT);
                }
                else if (FirstArrayMain[i] > 60 && z == 1) {
                    if (win_num == 3)
                        wattron(getWin,COLOR_PAIR(3) | A_STANDOUT);
                    else
                        wattron(getWin,COLOR_PAIR(1) | A_STANDOUT);
                    mvwprintw(getWin, 4 + z, 5 + i, " ");
                    if (win_num == 3)
                        wattroff(getWin,COLOR_PAIR(3) | A_STANDOUT);
                    else
                        wattroff(getWin,COLOR_PAIR(1) | A_STANDOUT);
                }
                else if (FirstArrayMain[i] > 40 && z == 2) {
                    wattron(getWin,COLOR_PAIR(2) | A_STANDOUT);
                    mvwprintw(getWin, 4 + z, 5 + i, " ");
                    wattroff(getWin,COLOR_PAIR(2) | A_STANDOUT);
                }
                else if (FirstArrayMain[i] > 20 && z == 3) {
                    wattron(getWin,COLOR_PAIR(2) | A_STANDOUT);
                    mvwprintw(getWin, 4 + z, 5 + i, " ");
                    wattroff(getWin,COLOR_PAIR(2) | A_STANDOUT);
                }
                else if (FirstArrayMain[i] > 0 && z == 4) {
                    if (win_num == 3)
                        wattron(getWin,COLOR_PAIR(1) | A_STANDOUT);
                    else
                        wattron(getWin,COLOR_PAIR(3) | A_STANDOUT);
                    mvwprintw(getWin, 4 + z, 5 + i, " ");
                    if (win_num == 3)
                        wattroff(getWin,COLOR_PAIR(1) | A_STANDOUT);
                    else
                        wattroff(getWin,COLOR_PAIR(3) | A_STANDOUT);
                }
                else
                {
                    wattron(getWin,COLOR_PAIR(4) | A_STANDOUT);
                    mvwprintw(getWin, 4 + z, 5 + i, " ");
                    wattroff(getWin,COLOR_PAIR(4) | A_STANDOUT);
                }
                i++;
            }
            z++;
            i = 0;
        }
        if (win_num == 1)
            for (k = 0; k < 99; k++)
                SecondArray[k] = FirstArray[k];
        else if (win_num == 2)
            for (k = 0; k < 99; k++)
                SecondArray2[k] = FirstArray2[k];
        else if (win_num == 3)
            for (k = 0; k < 99; k++)
                SecondArray3[k] = FirstArray3[k];

        delete [] FirstArrayMain;
}

void    Ncurse::checkSizeWindow()
{
    int y, x;
    getmaxyx(stdscr,y,x);
    if (y < 56 || x < 115)
    {
        endwin();
        std::cout << "Too little terminal window for starting this programm." << std::endl;
        exit(0);
    }
}

void    Ncurse::create_win()
{

    const int     max_y = 10;
    const int     max_x = 110;

    setWin0(newwin(7, 35, 8, 1));
    setWin01(newwin(7, 41, 8, 70));
    setWin1(newwin(max_y, max_x, 15, 1));
    setWin2(newwin(max_y, max_x, 30, 1));
    setWin3(newwin(max_y, max_x, 45, 1));
    box(getWin0(), 0, 0);
    box(getWin01(), 0, 0);
    box(getWin1(), 0, 0);
    box(getWin2(), 0, 0);
    box(getWin3(), 0, 0);
    refresh();
}

void   Ncurse::displayZazAnimal()
{
    static int k;
    if (k == 0) {
        mvprintw(6, 46, STR1);
        mvprintw(7, 46, STR2);
        mvprintw(8, 46, STR3);
        mvprintw(9, 46, STR4);
        mvprintw(10, 46, STR5);
        mvprintw(11, 46, STR6);
        mvprintw(12, 46, STR7);
        mvprintw(13, 46, STR8);
        mvprintw(14, 46, STR9);
        k = 1;
    }
    else
    {
        mvprintw(8, 46, STR10);
        k = 0;
    }
    refresh();
};

void Ncurse::start_ncurse_mode()
{
    initscr();
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
    start_color();

    checkSizeWindow();

    create_win();


    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);

    wattron(getWin1(), COLOR_PAIR(1) | A_BOLD);
    wattron(getWin2(), COLOR_PAIR(1) | A_BOLD);
    wattron(getWin3(), COLOR_PAIR(1) | A_BOLD);

    mvwprintw(getWin1(), 1, 100, "CPU User");
    mvwprintw(getWin2(), 1, 101, "CPU Sys");
    mvwprintw(getWin3(), 1, 100, "CPU Idle");

    wattroff(getWin1(), COLOR_PAIR(1) | A_BOLD);
    wattroff(getWin2(), COLOR_PAIR(1) | A_BOLD);
    wattroff(getWin3(), COLOR_PAIR(1) | A_BOLD);
}

void    Ncurse::exitFunction(WindowMode *mod)
{
    mvprintw(1,1,"Press \'Q\' for exit out the program.");
    refresh();
    char c = getch();
    if (c == 'q')
    {
        endwin();
        _isRunning = false;
        std::cout << "This project was created by akasamar. Bye Bye." << std::endl;
//        exit(0);
        clear();
    }
    else if (c == 'w')
	{
    	mod->turnOn();
	}
}

void Ncurse::render(std::vector<IMonitorModule *> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (dynamic_cast<BaseInfoModule *>(vec[i]))
            displayBase(dynamic_cast<BaseInfoModule *>(vec[i]));
        else if (dynamic_cast<CPUModule *>(vec[i]))
            displayCPU(dynamic_cast<CPUModule *>(vec[i]));
        else if (dynamic_cast<RAMModule *>(vec[i]))
            displayRAM(dynamic_cast<RAMModule *>(vec[i]));
        else if (dynamic_cast<NetworkModule *>(vec[i]))
            displayNetwork(dynamic_cast<NetworkModule *>(vec[i]));
    }
}

void Ncurse::displayBase(const BaseInfoModule *module)
{
    if (module) {
        wattron(_win0, COLOR_PAIR(5) | A_BOLD);
        mvwprintw(_win0, 1, 1, "Hostname: ");
        mvwprintw(_win0, 2, 1, "Username: ");
        mvwprintw(_win0, 3, 1, "OS: ");
        mvwprintw(_win0, 4, 1, "Ver.: ");
        mvwprintw(_win0, 5, 1, "Time: ");
        wattroff(_win0, COLOR_PAIR(5) | A_BOLD);
        wattron(_win0, COLOR_PAIR(6) | A_BOLD);
        mvwprintw(_win0, 1, 11, "%s", module->getHostName().c_str());
        mvwprintw(_win0, 2, 11, "%s", module->getUserName().c_str());
        mvwprintw(_win0, 3, 5, "%s", module->getOSName().c_str());
        mvwprintw(_win0, 4, 8, "%s", module->getOSVer().c_str());
        mvwprintw(_win0, 5, 8, "%s", module->getTimer().c_str());
        wattroff(_win0, COLOR_PAIR(6) | A_BOLD);
    }
}

void Ncurse::displayCPU(const CPUModule *module)
{
   if (module)
    {
        wattron(_win1, COLOR_PAIR(5) | A_BOLD);
        wattron(_win2, COLOR_PAIR(5) | A_BOLD);
        wattron(_win3, COLOR_PAIR(5) | A_BOLD);
        mvwprintw(_win1, 1, 1, "CPU name: ");
        mvwprintw(_win1, 2, 1, "User CPU data: ");
        mvwprintw(_win2, 1, 1, "CPU system: ");
        mvwprintw(_win3, 1, 1, "CPU Idle: ");
        wattroff(_win1, COLOR_PAIR(5) | A_BOLD);
        wattroff(_win2, COLOR_PAIR(5) | A_BOLD);
        wattroff(_win3, COLOR_PAIR(5) | A_BOLD);
        wattron(_win1, COLOR_PAIR(6) | A_BOLD);
        wattron(_win2, COLOR_PAIR(6) | A_BOLD);
        wattron(_win3, COLOR_PAIR(6) | A_BOLD);
        mvwprintw(_win1, 1, 11, "%s", module->getName().c_str());
        mvwprintw(_win1, 1, 51, "x4");
        mvwprintw(_win1, 2, 15, "          ");
        mvwprintw(_win1, 2, 16, "%s", module->getUser().c_str());
        mvwprintw(_win2, 1, 12, "          ");
        mvwprintw(_win2, 1, 13, "%s", module->getSys().c_str());
        mvwprintw(_win3, 1, 10, "          ");
        mvwprintw(_win3, 1, 11, "%s", module->getNIdle().c_str());
        wattroff(_win1, COLOR_PAIR(6) | A_BOLD);
        wattroff(_win2, COLOR_PAIR(6) | A_BOLD);
        wattroff(_win3, COLOR_PAIR(6) | A_BOLD);
        inputDiagram(getWin1(), atoi(module->getUser().c_str()), 1);
        inputDiagram(getWin2(), atoi(module->getSys().c_str()), 2);
        inputDiagram(getWin3(), atoi(module->getNIdle().c_str()), 3);
    }
}

void Ncurse::displayRAM(const RAMModule *module)
{
    if (module) {
        wattron(_win01, COLOR_PAIR(5) | A_BOLD);
        mvwprintw(_win01, 1, 1, "RAM Info: ");
        wattroff(_win01, COLOR_PAIR(5) | A_BOLD);

        wattron(_win01, COLOR_PAIR(6) | A_BOLD);
        mvwprintw(_win01, 2, 1, "                                      ");
        mvwprintw(_win01, 2, 1, "%s", module->getRAM().c_str());
        wattroff(_win01, COLOR_PAIR(6) | A_BOLD);
    }
}

void Ncurse::displayNetwork(const NetworkModule *module)
{
    if (module) {
        wattron(_win01, COLOR_PAIR(5) | A_BOLD);
        mvwprintw(_win01, 3, 1, "Network packets: ");
        mvwprintw(_win01, 4, 1, "In: ");
        mvwprintw(_win01, 5, 1, "Out: ");
        wattroff(_win01, COLOR_PAIR(5) | A_BOLD);

        wattron(_win01, COLOR_PAIR(6) | A_BOLD);
        mvwprintw(_win01, 4, 5, "               ");
        mvwprintw(_win01, 4, 6, "%s", module->getIn().c_str());
        mvwprintw(_win01, 5, 6, "                     ");
        mvwprintw(_win01, 5, 6, "%s", module->getOut().c_str());
        wattroff(_win01, COLOR_PAIR(6) | A_BOLD);
    }
}

bool Ncurse::isRunning() {
    return _isRunning;
}

//std::string NetworkModule::getIn() const {
//    return _in;
//}
//
//std::string NetworkModule::getOut() const {
//    return _out;
//}