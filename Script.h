//
// Created by Claus Guttesen on 27/09/2015.
//

#ifndef TABULA_SCRIPT_H
#define TABULA_SCRIPT_H

#include <string>

class Script {
private:
    // version available Sept. 27'th 2015.
    std::string jQuery = "//code.jquery.com/jquery-2.1.4.min.js";
    // version available Oct. 2'nd 2015.
    std::string jQueryMobile = "//code.jquery.com/mobile/1.4.5/jquery.mobile-1.4.5.min.js";
    std::string script = "script";

public:
    Script();
    ~Script();

    std::string getScript();
    void setScript(std::string script);
    void setjQueryVersion(std::string version);
    std::string getjQueryVersion();
    void setjQueryMobileVersion(std::string version);
    std::string getjQueryMobileVersion();
};

#endif //TABULA_SCRIPT_H
