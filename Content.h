//
// Created by Claus Guttesen on 08/09/2015.
//

#ifndef TABULA_CONTENT_H
#define TABULA_CONTENT_H

#include <string>
#include "Input.h"
#include "Form.h"

class Content {
private:
    std::string content = "";
    std::string header = "";
    const std::string cr = "\r\n";
    const std::string OK = "200 OK";
    const std::string text = "text/html;";
    const std::string charset = "charset=utf-8";

public:
    Content();
    ~Content();

    std::string getContent();
};


#endif //TABULA_CONTENT_H
