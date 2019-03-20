#ifndef CPU_HPP
#define CPU_HPP

#define CPU_NAME_LEN 1024

#include "Module.hpp"

class CPU: public Module
{
private:
    char    _name[CPU_NAME_LEN];
    size_t  _nameLen;
    int         _count;

public:
    CPU();
    ~CPU();
    CPU(CPU const &src);
    CPU &operator=(CPU const &src);

    //override
    virtual void draw();

    //getters
    std::string getName();
    std::string getUsage();
    int         getCount();

    SDL_Surface *getSurfaceInfo();
    SDL_Surface *getSurfaceUsage();
    SDL_Surface *getSurfaceCPUCount();
};


#endif