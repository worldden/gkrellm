#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Module.hpp"

class System : public Module
{
private:
    std::string _username;
    std::string _hostname;
    std::string _osname;
    std::string _osversion;

public:
    System();
    ~System();
    System(System const &src);
    System &operator=(System const &src);

    //override
    virtual void draw();

    std::string getUserName();
    std::string getHostName();
    std::string getOSName();
    std::string getOSVersion();

    SDL_Surface *getSurfaceUserName();
    SDL_Surface *getSurfaceHostName();
    SDL_Surface *getSurfaceOSName();
    SDL_Surface *getSurfaceOSVersion();
};

#endif