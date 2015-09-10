//
// Created by Claus Guttesen on 06/09/2015.
//

#ifndef TABULA_INPUT_H
#define TABULA_INPUT_H

#include <string>

class Input {
private:
    const std::string htmltag = "input";
    std::string name;
    std::string type;
    std::string value;

public:
    Input(const std::string type) : type(type) {};
    ~Input();

    std::string getButton();
    std::string getElement();
    std::string getLine();

    void setValue(const std::string value);
    void setName(const std::string name);
};

#endif //TABULA_INPUT_H
