#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "Module.hpp"

class Memory: public Module
{
public:
    Memory();
    ~Memory();
    Memory(Memory const &src);
    Memory &operator=(Memory const &src);

    virtual void draw();

    std::string getTotal();
    std::string getResident();
    std::string getPrivate();
    std::string getShared();

    SDL_Surface *getSurfaceTotal();
    SDL_Surface *getSurfaceResident();
    SDL_Surface *getSurfacePrivate();
    SDL_Surface *getSurfaceShared();

};

#endif