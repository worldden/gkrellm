// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   graphic.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 13:13:03 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/13 13:13:04 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GRAPHIC_HPP
# define GRAPHIC_HPP

# define WIDTH        320
# define HEIGHT        1040
# define CYCLEDELAY    200000

#include <iostream>
#include <unistd.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include "DateTime.hpp"
#include "CPU.hpp"
#include "System.hpp"
#include "RAM.hpp"
#include "Network.hpp"
#include "Disk.hpp"
#include "IMonitorDisplay.hpp"
#include "Memory.hpp"
#include "Processes.hpp"

class Graphic : public IMonitorDisplay {
private:
    DateTime *_data;
    CPU *_cpu;
    System *_system;
    RAM *_ram;
    Network *_network;
    Disk *_disk;
    Memory *_memory;
    Processes *_proc;

    SDL_Window *_window;
    SDL_Surface *_bmp;
    const Uint8 *_state;
    int quit;
    SDL_Event e;
    TTF_Font *font;
    SDL_Color color;
    SDL_Surface *TTF_TextSolid;
    SDL_Surface *image;
    SDL_Surface *image2;
    SDL_Surface *cat[3];

public:

    Graphic();

    Graphic(Graphic const &src);

    ~Graphic();

    //	Graphic & operator=(Graphic const & src);


    //SDL_Surface		*_time; // Серфейс который будет получать время

    void	GetSurface();
    void set_pixel(int x, int y, Uint32 pixel);

    void printmodule();
    virtual void start();

};

#endif