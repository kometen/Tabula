//
// Created by Claus Guttesen on 07/09/2015.
//

#include "Form.h"

Form::~Form() { }

const std::string Form::getOpeningElement() {
    std::string data = "";
    data += "<" + htmltag;
    data += " action=\"";
    data += action;
    data += "\">";

    return data;
}

const std::string Form::getClosingElement() {
    std::string data = "";
    data += "</" + htmltag + ">";

    return data;
}