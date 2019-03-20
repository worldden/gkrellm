#include "System.hpp"

System::System() {
    _username = getCommand("echo $(logname)");
    _hostname = getCommand("hostname");
    _osname = getCommand("sw_vers -productName");
    _osversion = getCommand("sw_vers -productVersion");

    setFontSize(18);
}

System::~System() {}
System::System(System const &src) {
    *this = src;
}

System& System::operator=(System const &src) {
    _hostname = src._hostname;
    _username = src._username;

    return *this;
}

std::string System::getHostName() {
    return _hostname;
}

std::string System::getUserName() {
    return _username;
}

std::string System::getOSName() {

    return ("Version: " + _osversion);
}

std::string System::getOSVersion() {

    return ("OS: " + _osname);
}

SDL_Surface * System::getSurfaceUserName() {
    return getSurface("Username: " + _username);
}

SDL_Surface * System::getSurfaceHostName() {
    return getSurface("Hostname: " + _hostname);
}

SDL_Surface * System::getSurfaceOSVersion() {
    return getSurface("Version: " + _osversion);
}

SDL_Surface * System::getSurfaceOSName() {
    return getSurface("OS: " + _osname);
}

void System::draw() {

}