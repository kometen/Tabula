//
// Created by Claus Guttesen on 05/10/2015.
//

#ifndef TABULA_DIV_H
#define TABULA_DIV_H

#include <string>
#include <unordered_map>
#include <unordered_set>

class Div {
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> attribute;

public:
    Div();
    ~Div();

    std::string getDivHeader();
    std::string getDivTail();
    void addElement(std::string, std::string);
};

#endif //TABULA_DIV_H
