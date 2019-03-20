#include "Network.hpp"

Network::Network() {

}

Network::~Network() {

}

Network::Network(Network const &src) {
    *this = src;
}

Network& Network::operator=(Network const &src) {
    _title = src._title;

    return *this;
}

std::string Network::getIn() {

	return ("Input packets: " + getCommand("top -l1 -n1 | grep 'Networks' | cut -d ' ' -f 3"));
}
std::string Network::getOut() {

	return ("Output packets: " + getCommand("top -l1 -n1 | grep 'Networks' | cut -d ' ' -f 5"));
}

SDL_Surface * Network::getSurfaceIn() {
    return getSurface("Input packets: " + getCommand("top -l1 -n1 | grep 'Networks' | cut -d ' ' -f 3"));
}

SDL_Surface * Network::getSurfaceOut() {
    return getSurface("Output packets: " + getCommand("top -l1 -n1 | grep 'Networks' | cut -d ' ' -f 5"));
}

void Network::draw() {

}
