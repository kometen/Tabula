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

    data += "HTTP/1.1 " + OK + cr;
    data += "Server: Tabula content server/0.0.1" + cr;
    data += "Content-Length: " + std::to_string(content.length()) + cr;
    data += "Connnection: close" + cr;
    data += "Content-Type: " + text + " " + charset + cr + cr;
    data += content;
    return data;
}
