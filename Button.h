//
// Created by Claus Guttesen on 05/09/2015.
//

#ifndef TABULA_BUTTON_H
#define TABULA_BUTTON_H

#include <string>

class Button {
public:
    Button(std::string t) : autofokus (false),
                            disabled (false),
                            name ("button"),
                            text (t),
                            type ("submit")
    {};
    ~Button();
    const std::string getElement();
private:
    bool autofokus;
    bool disabled;
    const std::string element = "button";
    std::string name;
    std::string text;
    std::string type;
};



#endif //TABULA_BUTTON_H
