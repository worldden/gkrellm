#include "Processes.hpp"

Processes::Processes() {}
Processes::~Processes() {}
Processes::Processes(Processes const &src) {
    *this = src;
}

Processes& Processes::operator=(Processes const &src) {
    _title = src._title;

    return *this;
}

SDL_Surface * Processes::getSurfaceInfo() {
    std::string res;

    res = getCommand("top -l1 -n1 | grep \"Processes:\" | cut -d ' ' -f 2-7");
    res = res.substr(0, res.length() - 1);

    return getSurface(res);
}

std::string Processes::getInfo() {
	std::string res;

    res = getCommand("top -l1 -n1 | grep \"Processes:\" | cut -d ' ' -f 2-7");
    res = res.substr(0, res.length() - 1);

    return (res);

}

void Processes::draw() {

}