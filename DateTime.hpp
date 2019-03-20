// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DateTime.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 15:07:19 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/13 15:07:20 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DATATIME_HPP
# define DATATIME_HPP

#include <iostream>
#include <unistd.h>
#include "Module.hpp"
# include <SDL.h>


class DateTime : Module {

private:
    char _buffer[80];


public:

    DateTime();
    ~DateTime();

    DateTime(DateTime const &src);
    DateTime &operator=(const DateTime &rhs);

    const char *getHour(void);
    virtual void draw();
    void setHour(void);

    SDL_Surface *getSurfaceData();

};

#endif