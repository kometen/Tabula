//
// Created by Claus Guttesen on 06/09/2015.
//

#ifndef TABULA_HTML_H
#define TABULA_HTML_H

#include <string>

class Html {
private:
    const std::string doctype = "<!DOCTYPE html>";
    const std::string body = "body";
    const std::string head = "head";
    const std::string html = "html";
    const std::string meta = "<meta charset=\"utf-8\">";
    const std::string title = "title";
    std::string siteTitle;

public:
    Html();
    ~Html();

    std::string getDoctype();
    std::string getOpeningBody();
    std::string getClosingBody();
    std::string getOpeningHead();
    std::string getClosingHead();
    std::string getOpeningHtml();
    std::string getClosingHtml();
    std::string getMeta();
    std::string getOpeningTitle();
    std::string getClosingTitle();
    void setSiteTitle(std::string siteTitle);
    std::string getSiteTitle();
};

#endif //TABULA_HTML_H
