//
// Created by Claus Guttesen on 08/09/2015.
//

#include "Content.h"

Content::Content() { }

Content::~Content() { }

std::string Content::getContent() {
    Html html {};
    html.setSiteTitle("Tabula content server");
    Form form {"user"};
    form.setMethod("post");
    Input button {"submit"};
    button.setValue("OK");
    Input firstname {"text"};
    firstname.setName("firstname");
    Input lastname {"text"};
    lastname.setName("lastname");

    content += html.getDoctype();
    content += html.getOpeningHtml();
    content += html.getOpeningHead();
    content += html.getSiteTitle();
    content += html.getMeta();
    content += html.getClosingHead();
    content += html.getOpeningBody();
    content += form.getOpeningElement();
    content += "Fornavn:<br>";
    content += firstname.getLine();
    content += "<br>";
    content += "Efternavn:<br>";
    content += lastname.getLine();
    content += "<br>";
    content += button.getButton();
    content += form.getClosingElement();
    content += html.getClosingBody();
    content += html.getClosingHtml();

    header += "HTTP/1.1 " + OK + cr;
    header += "Server: Tabula content server/0.0.1" + cr;
    header += "Content-Length: " + std::to_string(content.length()) + cr;
    header += "Connnection: close" + cr;
    header += "Content-Type: " + text + " " + cr + cr;

    header += content;
    return header;
}
