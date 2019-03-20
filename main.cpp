// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 13:04:12 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/13 13:04:13 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <unistd.h>
#include <string.h>
#include <iostream>

#include "graphic.hpp"
#include "DateTime.hpp"
#include "Ncurses.hpp"


int main (int ac, char *av[]) {

    std::string input;

    if (ac != 2){

        system("printf '\e[8;56;50t'");
        std::cout << "Select display" << std::endl << "1: Graphic" << std::endl << "2: Terminal" << std::endl;
        std::cin >> input;
    }

	if ((ac == 2 && !strcmp(av[1], "1")) || input == "1")
    {
    //	std::cout << "Grafic" << std::endl;
    	Graphic	graph;
        try {
            graph.start();
        }
        catch (...) {

        }

    }
    else if ((ac == 2 && !strcmp(av[1], "2")) || input == "2")
    {
    //	 std::cout << "Ncerces" << std::endl;
    //     system("printf '\e[8;50;50t'");
         Ncurses    term;
        try {
            term.start();
        }
        catch (...){

        }
    }
    else
        std::cout << "ERROR: Please Select1 or 2." << std::endl;
    return 0;
}

