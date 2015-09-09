//
// Created by Claus Guttesen on 08/09/2015.
//

#include "Content.h"

Content::Content() { }

Content::~Content() { }

std::string Content::getContent() {
    Form form {"user"};
    Input button {"submit"};
    button.setValue("OK");
    Input firstname {"text"};
    Input lastname {"text"};

    content += form.getOpeningElement();
    content += "Fornavn:<br>";
    content += firstname.getElement();
    content += "<br>";
    content += "Efternavn:<br>";
    content += lastname.getElement();
    content += "<br>";
    content += button.getButton();
    content += form.getClosingElement();

    header += "HTTP/1.1 " + OK + cr;
    header += "Server: Tabula content server/0.0.1" + cr;
    header += "Content-Length: " + std::to_string(content.length()) + cr;
    header += "Connnection: close" + cr;
    header += "Content-Type: " + text + " " + charset + cr + cr;

    header += content;
    return header;
}
