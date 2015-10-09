//
// Created by Claus Guttesen on 02/10/2015.
//

#ifndef TABULA_LINK_H
#define TABULA_LINK_H

#include <string>

class Link {
private:
    // version available Oct. 2'nd 2015.
    std::string jQueryMobileStylesheet = "//code.jquery.com/mobile/1.4.5/jquery.mobile-1.4.5.min.css";
    std::string link = "link";

public:
    Link();
    ~Link();

    std::string getLink();
    void setLink(std::string link);
    void setjQueryMobileStylesheetVersion(std::string version);
    std::string getjQueryMobileStylesheetVersion();
};


#endif //TABULA_LINK_H
