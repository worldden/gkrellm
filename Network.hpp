#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Module.hpp"

class Network : public Module
{
public:
    Network();
    ~Network();
    Network(Network const &src);
    Network &operator=(Network const &src);

    virtual void draw();

    std::string getIn();
    std::string getOut();

    SDL_Surface *getSurfaceIn();
    SDL_Surface *getSurfaceOut();

};

#endif