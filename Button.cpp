//
// Created by Claus Guttesen on 05/09/2015.
//

#include "Button.h"

Button::~Button() { }

const std::string Button::getElement() {
    std::string data;
    data += "<" + element;
    data += " name=\"" + name + "\">";
    data += text;
    data += "</" + element + ">";

    return data;
}
