// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ncurses.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/14 15:29:27 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/14 15:29:28 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ncurses.hpp"

Ncurses::Ncurses() {


	initscr();
	getmaxyx(stdscr, _maxheight, _maxwidth);
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(0);
	start_color();
	noecho();

	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
  	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
  	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);

  	_data = new DateTime();
    _cpu = new CPU();
    _system = new System();
    _ram = new RAM();
    _network = new Network();
    _disk = new Disk();
    _memory = new Memory();
    _proc = new Processes();

	refresh();
}

void	Ncurses::box() {

	oldalchar = (char)42;
	attron(COLOR_PAIR(3));
	for (int i = 0; i < _maxwidth - 1; i++) {

		move(0, i);
		addch(oldalchar);
	}
	for (int i = 0; i < _maxwidth - 1; i++) {

		move(_maxheight - 2, i);
		addch(oldalchar);
	}

	for (int i = 0; i < _maxwidth - 1; i++) {

		move(9, i);
		addch(oldalchar);
	}

	for (int i = 0; i < _maxwidth - 1; i++) {

		move(16, i);
		addch(oldalchar);
	}

	for (int i = 0; i < _maxwidth - 1; i++) {

		move(23, i);
		addch(oldalchar);
	}

	for (int i = 0; i < _maxwidth - 1; i++) {

		move(29, i);
		addch(oldalchar);
	}
	for (int i = 0; i < _maxwidth - 1; i++) {

		move(35, i);
		addch(oldalchar);
	}
	for (int i = 0; i < _maxwidth - 1; i++) {

		move(42, i);
		addch(oldalchar);
	}


	for (int i = 0; i < _maxheight - 2; i++) {

		move(i, 0);
		addch(oldalchar);
	}

	for (int i = 0; i < _maxheight - 2; i++) {

		move(i, _maxwidth - 1);
		addch(oldalchar);
	}
	attroff(COLOR_PAIR(3));
}

void	Ncurses::printmodule() {


	attron(COLOR_PAIR(4));
	mvprintw(1, 6, "SYSTEM INFO");
	mvprintw(3, 6, _data->getHour());
	mvprintw(4, 6, "Username:%s", _system->getUserName().c_str());
	mvprintw(5, 6, "Hostname:%s",_system->getHostName().c_str());
	mvprintw(6, 6, "%s", _system->getOSName().c_str());
	mvprintw(7, 6, "%s",_system->getOSVersion().c_str());
	attroff(COLOR_PAIR(4));

	attron(COLOR_PAIR(5));
	mvprintw(10, 6, "CPU INFO");
	mvprintw(12, 6, _cpu->getName().c_str());
	mvprintw(13, 6, "%-50s", _cpu->getUsage().c_str());
	mvprintw(14, 6, "Number of cores: %d", _cpu->getCount());
	attroff(COLOR_PAIR(5));


	attron(COLOR_PAIR(6));
	mvprintw(17, 6, "RAM INFO");
	mvprintw(19, 6, "%-50s", _ram->getUsed().c_str());
	mvprintw(20, 6, "%-50s", _ram->getUnused().c_str());
	mvprintw(21, 6, "%s", _ram->getMemory().c_str());
	attroff(COLOR_PAIR(6));

	attron(COLOR_PAIR(2));
	mvprintw(24, 6, "STORAGE INFO");
	mvprintw(26, 6, "%-50s", _disk->getUserCapacity().c_str());
	mvprintw(27, 6, "%-50s", _disk->geUserAvailable().c_str());
	attroff(COLOR_PAIR(2));

	attron(COLOR_PAIR(1));
	mvprintw(30, 6, "NETWORK INFO");
	mvprintw(32, 6, "%-50s", _network->getIn().c_str());
	mvprintw(33, 6, "%-50s", _network->getOut().c_str());
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(3));
	mvprintw(36, 6, "MEMORY REGIONS");
	mvprintw(37, 6, "%-50s", _memory->getTotal().c_str());
	mvprintw(38, 6, "%-50s", _memory->getResident().c_str());
	mvprintw(39, 6, "%-50s", _memory->getPrivate().c_str());
	mvprintw(40, 6, "%-50s", _memory->getShared().c_str());
	attroff(COLOR_PAIR(3));

	attron(COLOR_PAIR(4));
	mvprintw(43, 6, "PROCESSES");
	mvprintw(45, 6, "%-50s", _proc->getInfo().c_str());
	attroff(COLOR_PAIR(4));

	std::string cat;

	cat = "\n"
"       /\\___/\\  \n"
"      ( o   o ) \n"
"      (  =^=  ) \n"
"      (        ) \n"
"      (         ) \n"
"      (          ))))))))))) \n";

	mvprintw(46, 6, "%s", cat.c_str());
	box();
	refresh();

}


Ncurses::Ncurses(Ncurses const & src) {

    *this = src;
}


Ncurses::~Ncurses() {

	nodelay(stdscr, false);
	getch();
	endwin();
}

void Ncurses::start() {

	while(1) {	
		printmodule();
		if (getch() == 27)
			break ;
		}
		usleep(CYCLEDELAY);
}
    
     
   




