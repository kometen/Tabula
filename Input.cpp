//
// Created by Claus Guttesen on 06/09/2015.
//

#include "Input.h"

Input::~Input() { }

std::string Input::getButton() {
    std::string data;
    data += "<" + htmltag;
    data += " type=\"" + type + "\"";
    data += " value=\"" + value+ "\">";

    return data;
}

std::string Input::getElement() {
    std::string data;
    data += "<" + htmltag;
    data += " type=\"" + type + "\">";

    return data;
}

void Input::setValue(const std::string value) {
    this->value = value;
}
