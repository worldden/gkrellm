#include "RAM.hpp"

RAM::RAM() {
    _memory = getCommand("system_profiler SPHardwareDataType | grep \"  Memory:\" | cut -d ' ' -f 7-");
}

RAM::~RAM() {}


 std::string RAM::getUsed() {

 	return ("Used: " + getCommand("top -l1 -n1 | grep 'PhysMem:' | cut -d ' ' -f 2,4,5 | rev | cut -b 2- | rev"));
 }
 std::string RAM::getUnused() {

 	return ("Unused: " + getCommand("top -l1 -n1 | grep 'PhysMem:' | cut -d ' ' -f 6"));
 }
 std::string RAM::getMemory() {

 	return(_memory);
 }




SDL_Surface * RAM::getSurfaceUsed() {
    return getSurface("Used: " + getCommand("top -l1 -n1 | grep 'PhysMem:' | cut -d ' ' -f 2,4,5 | rev | cut -b 2- | rev"));
}

SDL_Surface * RAM::getSurfaceUnused() {
    return getSurface("Unused: " + getCommand("top -l1 -n1 | grep 'PhysMem:' | cut -d ' ' -f 6"));
}

SDL_Surface * RAM::getSurfaceMemory() {
    return getSurface(_memory);
}

void RAM::draw() {

}