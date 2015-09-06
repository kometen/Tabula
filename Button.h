//
// Created by Claus Guttesen on 05/09/2015.
//

#ifndef TABULA_BUTTON_H
#define TABULA_BUTTON_H

#include <string>

class Button {
private:
    bool autofocus;
    bool disabled;
    const std::string htmltag = "button";
    std::string name;
    std::string message;
    std::string type;

public:
    Button(const std::string message) : autofocus(false),
                            disabled (false),
                            name ("button"),
                            message(message),
                            type ("submit")
    {};
    ~Button();

    const std::string getElement();

    bool isAutofocus() const { return autofocus; }
    bool isDisabled() const { return disabled; }
    const std::string &getName() const { return name; }
    const std::string &getText() const { return message; }
    const std::string &getType() const { return type; }

    void setAutofocus(bool autofocus);
    void setDisabled(bool disabled);
    void setName(const std::string &name);
    void setText(const std::string &text);
    void setType(const std::string &type);


};



#endif //TABULA_BUTTON_H
