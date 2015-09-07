//
// Created by Claus Guttesen on 07/09/2015.
//

#ifndef TABULA_FORM_H
#define TABULA_FORM_H

#include <string>

class Form {
private:
    const std::string htmltag = "form";
    std::string action = "";

public:
    Form(std::string action) : action(action) {}
    ~Form();

    std::string getOpeningElement();
    std::string getClosingElement();
};


#endif //TABULA_FORM_H
