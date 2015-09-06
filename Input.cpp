//
// Created by Claus Guttesen on 06/09/2015.
//

#include "Input.h"

Input::~Input() { }

const std::string Input::getElement() {
    std::string data;
    data += "<" + htmltag;
    data += " type=\"" + type + "\">";
    data += "</" + htmltag + ">";

    return data;
}
