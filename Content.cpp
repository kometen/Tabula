//
// Created by Claus Guttesen on 08/09/2015.
//

#include "Content.h"

Content::Content() { }

Content::~Content() { }

std::string Content::getContent() {
    Form form {"user"};
    form.setMethod("post");
    Input button {"submit"};
    button.setValue("OK");
    Input firstname {"text"};
    firstname.setName("firstname");
    Input lastname {"text"};
    lastname.setName("lastname");

    content += form.getOpeningElement();
    content += "Fornavn:<br>";
    content += firstname.getLine();
    content += "<br>";
    content += "Efternavn:<br>";
    content += lastname.getLine();
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