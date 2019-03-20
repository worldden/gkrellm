#include "Memory.hpp"

Memory::Memory() {}
Memory::~Memory() {}
Memory::Memory(Memory const &src) {
    *this = src;
}
Memory& Memory::operator=(Memory const &src) {
    _title = src._title;

    return *this;
}

void Memory::draw() {

}

SDL_Surface * Memory::getSurfaceTotal() {
    return getSurface("Total: " + getCommand("top -l1 -n1 | grep 'MemRegions:' | cut -d ' ' -f 2"));
}

SDL_Surface * Memory::getSurfaceResident() {
    return getSurface("Resident: " + getCommand("top -l1 -n1 | grep 'MemRegions:' | cut -d ' ' -f 4"));
}

SDL_Surface * Memory::getSurfacePrivate() {
    return getSurface("Private: " + getCommand("top -l1 -n1 | grep 'MemRegions:' | cut -d ' ' -f 6"));
}

SDL_Surface * Memory::getSurfaceShared() {
    return getSurface("Shared: " + getCommand("top -l1 -n1 | grep 'MemRegions:' | cut -d ' ' -f 8"));
}

std::string Memory::getTotal() {

    return ("Total: " + getCommand("top -l1 -n1 | grep 'MemRegions:' | cut -d ' ' -f 2"));
}

std::string Memory::getResident() {

	 return ("Resident: " + getCommand("top -l1 -n1 | grep 'MemRegions:' | cut -d ' ' -f 4"));
}
    
std::string Memory::getPrivate() {

	return ("Private: " + getCommand("top -l1 -n1 | grep 'MemRegions:' | cut -d ' ' -f 6"));
}

std::string Memory::getShared() {

	return ("Shared: " + getCommand("top -l1 -n1 | grep 'MemRegions:' | cut -d ' ' -f 8"));
}
