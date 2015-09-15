//
// Created by Claus Guttesen on 15/09/2015.
//

#include "URLrecode.h"

URLrecode::URLrecode(std::string text) {
    this->text = text;
}

URLrecode::~URLrecode() { }

std::string URLrecode::decode() {
    for (auto i = text.begin(), n = text.end(); i != n; ++i) {
        std::string::value_type c = (*i);

        if (c == '%') {
            if (i[1] && i[2]) {
                h = from_hex(i[1]) << 4 | from_hex(i[2]);
                escaped << h;
                i += 2;
            }
        } else if (c == '+') {
            escaped << ' ';
        } else {
            escaped << c;
        }
    }

    return escaped.str();
}

char URLrecode::from_hex(char ch) {
    return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}
