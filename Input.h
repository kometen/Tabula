//
// Created by Claus Guttesen on 06/09/2015.
//

#ifndef TABULA_INPUT_H
#define TABULA_INPUT_H

#include <string>

class Input {
private:
    const std::string htmltag = "input";
    std::string type;

public:
    Input(const std::string type) : type(type) {};
    ~Input();

    const std::string getElement();
};

#endif //TABULA_INPUT_H
