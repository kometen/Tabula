//
// Created by Claus Guttesen on 08/09/2015.
//

#include "Content.h"

Content::Content() { }

Content::~Content() { }

std::string Content::getContent() {
    Html html {};
    html.setSiteTitle("Tabula content server");
    Script jQueryScript {};
    jQueryScript.setScript(jQueryScript.getjQueryVersion());
    Script jQueryMobileScript {};
    jQueryMobileScript.setScript(jQueryMobileScript.getjQueryMobileVersion());
    Form form {"user"};
    form.setMethod("post");
    Input button {"submit"};
    button.setValue("OK");
    Input firstname {"text"};
    firstname.setName("firstname");
    Input lastname {"text"};
    lastname.setName("lastname");
    URLrecode recode {getPostdata()};
    Div tabs {};
    tabs.addElement("id", "tabs");
    tabs.addElement("data-role", "tabs");
    Div navbar {};
    navbar.addElement("id", "navbar");
    navbar.addElement("data-role", "navbar");
    Div home {};
    home.addElement("id", "home");
    home.addElement("class", "tab-pane");
    home.addElement("class", "fade");
    Div user {};
    user.addElement("id", "user");
    user.addElement("class", "tab-pane");
    user.addElement("class", "fade");
    Div menu {};
    menu.addElement("id", "menu");
    menu.addElement("class", "tab-pane");
    menu.addElement("class", "fade");

    content += html.getDoctype();
    content += html.getOpeningHtml();
    content += html.getHead();
    content += html.getOpeningBody();
    content += tabs.getDivHeader();
    content += navbar.getDivHeader();
    content += "<ul>";
    content += "<li><a href=\"#home\" data-ajax=\"false\">Home</a></li>";
    content += "<li><a href=\"#user\" data-ajax=\"false\">User</a></li>";
    content += "<li><a href=\"#menu\" data-ajax=\"false\">Menu</a></li>";
    content += "</ul>";
    content += navbar.getDivTail();
    content += home.getDivHeader();
    content += "<h4>Home</h4>";
    content += home.getDivTail();
    content += user.getDivHeader();
    content += form.getOpeningElement();
    content += "Fornavn:<br>";
    content += firstname.getLine();
    content += "<br>";
    content += "Efternavn:<br>";
    content += lastname.getLine();
    content += "<br>";
    content += button.getButton();
    content += form.getClosingElement();
    content += "<br>";
    content += user.getDivTail();
    content += menu.getDivHeader();
    content += "<h4>Menu</h4>";
    content += menu.getDivTail();
    content += tabs.getDivTail();
    content += recode.decode();
    content += jQueryScript.getScript();
    content += jQueryMobileScript.getScript();
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

void Content::setPostdata(std::string postdata) {
    this->postdata = postdata;
}

std::string Content::getPostdata() {
    return postdata;
}