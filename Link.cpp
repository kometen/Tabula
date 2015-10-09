//
// Created by Claus Guttesen on 02/10/2015.
//

#include "Link.h"

Link::Link() { }
Link::~Link() { }

std::string Link::getLink() {
    std::string data = "<link rel=\"stylesheet\" type=\"text/css\" href=\"" + link + "\">";

    return data;
}

std::string Link::getjQueryMobileStylesheetVersion() {
    return jQueryMobileStylesheet;
}

void Link::setjQueryMobileStylesheetVersion(std::string version) {
    jQueryMobileStylesheet = "//code.jquery.com/mobile/" + version + "/jquery.mobile-1.4.5.min.js";
}

void Link::setLink(std::string link) {
    this->link = link;
}
