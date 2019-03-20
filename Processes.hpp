#ifndef PROCESSES_HPP
#define PROCESSES_HPP

#include "Module.hpp"

class Processes: public Module
{
public:
    Processes();
    ~Processes();
    Processes(Processes const &src);
    Processes &operator=(Processes const &src);

    virtual void draw();

    SDL_Surface *getSurfaceInfo();
    std::string getInfo();
};

#endif