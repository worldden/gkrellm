#include "Module.hpp"

Module::Module() {
    _color.r = 0;
    _color.g = 70;
    _color.b = 0;
    _fontSize = 18;

    _font =  TTF_OpenFont("frameworks/ARIAL.TTF", _fontSize);
}

Module::~Module() {
    TTF_CloseFont(_font);
}

Module::Module(Module const &src) {
    *this = src;
}

Module& Module::operator=(Module const &src) {
    _startY = src._startY;

    return *this;
}

int Module::getStartY() {
    return _startY;
}

std::string Module::getTitle() {
    return _title;
}

SDL_Surface * Module::getSurface(std::string msg = "") {
    SDL_Surface *TTF_TextSolid = TTF_RenderText_Solid(_font, msg.c_str(), _color);

    return (TTF_TextSolid);
}


SDL_Surface * Module::getSurfaceTitle() {
    return getSurface(_title);
}

void Module::setFontSize(int size) {
    _fontSize = size;

    TTF_CloseFont(_font);
    _font = TTF_OpenFont("frameworks/ARIAL.TTF", _fontSize);
}

std::string Module::getCommand(const char* cmd) {
    char tmp[256];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");

    if (!pipe){
        return result;
    }

    try {
        while (!feof(pipe)) {
            if (fgets(tmp, 256, pipe) != NULL)
                result += tmp;
        }
    } catch (std::exception &e) {
        pclose(pipe);
    }
    pclose(pipe);

    if (result[result.length() - 1] == '\n'){
        result = result.substr(0, result.length() - 1);
    }

    return result;
}

