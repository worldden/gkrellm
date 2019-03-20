#include "Disk.hpp"

Disk::Disk() {}
Disk::~Disk() {}

Disk::Disk(Disk const &src) {
    *this = src;
}

Disk& Disk::operator=(Disk const &src) {
    _title = src._title;

    return *this;
}

std::string Disk::getUserCapacity() {

	return ("User capacity: " + getCommand("system_profiler SPStorageDataType | grep 'Capacity' | tail -n1 | cut -d ' ' -f 8,9"));
}
std::string Disk::geUserAvailable() {

	return ("User space left: " + getCommand(" system_profiler SPStorageDataType | grep 'Available:' | tail -n1 | cut -d ' ' -f 8,9"));
}

SDL_Surface * Disk::getSurfaceUserCapacity() {
    return getSurface("User capacity: " + getCommand("system_profiler SPStorageDataType | grep 'Capacity' | tail -n1 | cut -d ' ' -f 8,9"));
}

SDL_Surface * Disk::getSurfaceUserAvailable() {
    return getSurface("User space left: " + getCommand(" system_profiler SPStorageDataType | grep 'Available:' | tail -n1 | cut -d ' ' -f 8,9"));

}


void Disk::draw() {

}