//
// Created by Claus Guttesen on 07/09/2015.
//

#include "Form.h"

Form::~Form() { }

std::string Form::getOpeningElement() {
    std::string data = "";
    data += "<" + htmltag;
    data += " action=\"";
    data += action;
    data += "\"";
    data += " method=\"";
    data += method;
    data += "\">";

    return data;
}

std::string Form::getClosingElement() {
    std::string data = "";
    data += "</" + htmltag + ">";

    return data;
}

std::string Form::getMethod() {
    return method;
}

void Form::setMethod(const std::string method) {
    this->method = method;
}
