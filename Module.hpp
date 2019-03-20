#ifndef MODULE_HPP
#define MODULE_HPP

#include <stdio.h>
#include <stdint.h>
#include <stdexcept>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <string>
#include <iostream>
#include <sstream>
# include <SDL.h>
# include <SDL_ttf.h>


#include "IMonitorModule.hpp"

class Module: public IMonitorModule
{
protected:
    std::string _title;
    int _fontSize;
    int _startY;
    Module();
    TTF_Font* _font;
    SDL_Color _color;

public:
    ~Module();
    Module(Module const &src);
    Module &operator=(Module const &src);

    virtual void draw() = 0;
    int getStartY();
    std::string getTitle();
    SDL_Surface *getSurface(std::string);
    SDL_Surface *getSurfaceTitle();

    void setFontSize(int size);
    std::string getCommand(const char* cmd);
};

#endif