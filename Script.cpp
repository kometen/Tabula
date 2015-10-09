//
// Created by Claus Guttesen on 27/09/2015.
//

#include "Script.h"

void Script::setjQueryVersion(std::string version) {
    jQuery = "//code.jquery.com/jquery-" + version + ".min.js";
}

std::string Script::getjQueryVersion() {
    return jQuery;
}

void Script::setjQueryMobileVersion(std::string version) {
    jQueryMobile = "//code.jquery.com/mobile/1.4.5/jquery.mobile-" + version + ".min.js";
}

std::string Script::getjQueryMobileVersion() {
    return jQueryMobile;
}

std::string Script::getScript() {
    std::string data = "<script src=\"" + script + "\"></script>";

    return data;
}

void Script::setScript(std::string script) {
    this->script = script;
}

Script::Script() { }
Script::~Script() { }
