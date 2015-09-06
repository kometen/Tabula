//
// Created by Claus Guttesen on 05/09/2015.
//

#include "Button.h"

Button::~Button() { }

const std::string Button::getElement() {
    std::string data;
    data += "<" + htmltag;
    data += " name=\"" + name + "\">";
    data += message;
    data += "</" + htmltag + ">";

    return data;
}

void Button::setAutofocus(bool autofocus) {
    this->autofocus = autofocus;
}

void Button::setDisabled(bool disabled) {
    this->disabled = disabled;
}

void Button::setName(const std::string &name) {
    this->name = name;
}

void Button::setText(const std::string &text) {
    this->message = text;
}

void Button::setType(const std::string &type) {
    this->type = type;
}
