//
// Created by Claus Guttesen on 08/09/2015.
//

#ifndef TABULA_CONTENT_H
#define TABULA_CONTENT_H

#include <string>
#include "Html.h"
#include "Input.h"
#include "Form.h"

class Content {
private:
    std::string content = "";
    std::string header = "";
    std::string postdata = "";
    const std::string cr = "\r\n";
    const std::string OK = "200 OK";
    const std::string text = "text/html;";

public:
    Content();
    ~Content();

    std::string getContent();
    void setPostdata(std::string postdata);
    std::string getPostdata();
};


#endif //TABULA_CONTENT_H
