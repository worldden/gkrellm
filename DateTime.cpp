// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DateTime.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 15:30:51 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/13 15:30:52 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "DateTime.hpp"
#include <string>
#include <iostream>


DateTime::DateTime(){
    _title = "Date";
    setFontSize(18);
};

DateTime::~DateTime() {

};

void DateTime::setHour(void) {

    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(_buffer, 80, "Time: %d-%m-%Y %I:%M:%S", timeinfo);
}

const char *DateTime::getHour(void) {
    setHour();
    return _buffer;
}



SDL_Surface * DateTime::getSurfaceData() {
    setHour();

    return getSurface(_buffer);
}

void DateTime::draw() {

}