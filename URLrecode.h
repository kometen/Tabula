//
// Created by Claus Guttesen on 15/09/2015.
//

#ifndef TABULA_URLRECODE_H
#define TABULA_URLRECODE_H

#include <sstream>
#include <string>

class URLrecode {
private:
    char h;
    std::ostringstream escaped {'0'};
    std::string text;
    char from_hex(char ch);

public:
    URLrecode(std::string text);
    ~URLrecode();

    std::string decode();
};


#endif //TABULA_URLRECODE_H
