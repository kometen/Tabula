//
// Created by Claus Guttesen on 27/09/2015.
//

#ifndef TABULA_SCRIPT_H
#define TABULA_SCRIPT_H

#include <string>

class Script {
private:
    std::string jquery = "//code.jquery.com/jquery-2.1.4.min.js"; // version available Sept. 27'th 2015.
    std::string script = "script";

public:
    Script();
    ~Script();

    std::string getScript();
    void setScript(std::string script);
    void setJqueryVersion(std::string version);
    std::string getJqueryVersion();
};

#endif //TABULA_SCRIPT_H
