//
// Created by Claus Guttesen on 27/09/2015.
//

#include "Script.h"

void Script::setJqueryVersion(std::string version) {
    jquery = "//code.jquery.com/jquery-" + version + ".min.js";
}

std::string Script::getJqueryVersion() {
    return jquery;
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
