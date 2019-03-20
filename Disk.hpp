#ifndef DISK_HPP
#define DISK_HPP

#include "Module.hpp"

class Disk: public Module
{
public:
    Disk();
    ~Disk();
    Disk(Disk const &src);
    Disk &operator=(Disk const &src);

    virtual void draw();

    std::string getUserCapacity();
    std::string geUserAvailable();

    SDL_Surface *getSurfaceUserCapacity();
    SDL_Surface *getSurfaceUserAvailable();

};

#endif