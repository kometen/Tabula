//
// Created by Claus Guttesen on 05/10/2015.
//

#include "Div.h"

Div::Div() { }
Div::~Div() { }

std::string Div::getDivHeader() {
    std::string value = "";
    value.append("<div ");

    unsigned int loops = 0;

    // First add attribute name to div.
    for (auto um: attribute) {
        ++loops;
        auto first_element = true;
        value.append(um.first);
        value.append(("=\""));
        // Then add element(s) to the attribute name.
        for (auto v: um.second) {
            // Do not add space before first element, only to the one(s) following.
            if (first_element) {
                first_element = false;
            } else {
                value.append(" ");
            }
            value.append(v);
        }
        value.append("\"");
        // Add space unless we are at the last element in the unordered map. Do-this-unless is a nice ruby idiom.
        if (loops < attribute.size()) {
            value.append(" ");
        }
    }
    value.append(">");

    return value;
}

std::string Div::getDivTail() {
    return "</div>";
}

void Div::addElement(std::string a, std::string e) {
    // If attribute is 'id' only allow one unique identifier. Otherwise add on a needed basis.
    if (a == "id") {
        auto search = this->attribute.find(a);
        if (search == this->attribute.end()) {
            std::unordered_set<std::string> el = {e};
            this->attribute.emplace(a, el);
        } else {
            search->second.clear();
            search->second.emplace(e);
        }
    } else {
        auto search = this->attribute.find(a);
        if (search == this->attribute.end()) {
            std::unordered_set<std::string> el = {e};
            this->attribute.emplace(a, el);
        } else {
            search->second.emplace(e);
        }
    }
}
