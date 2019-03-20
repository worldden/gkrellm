#ifndef RAM_HPP
#define RAM_HPP

#include "Module.hpp"

class RAM : public Module
{
private:
    std::string _memory;

public:
    RAM();
    ~RAM();
    RAM(RAM const &src);
    RAM &operator=(RAM const &src);

    virtual void draw();

    std::string getUsed();
    std::string getUnused();
    std::string getMemory();

    SDL_Surface *getSurfaceUsed();
    SDL_Surface *getSurfaceUnused();
    SDL_Surface *getSurfaceMemory();

};

#endif