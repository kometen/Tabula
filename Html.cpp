//
// Created by Claus Guttesen on 06/09/2015.
//

#include "Html.h"

Html::Html() { };
Html::~Html() { };

std::string Html::getDoctype() {
    return doctype;
}

std::string Html::getOpeningBody() {
    return "<" + body + ">";
}

std::string Html::getClosingBody() {
    return "</" + body + ">";
}

std::string Html::getOpeningHead() {
    return "<" + head + ">";
}

std::string Html::getClosingHead() {
    return "</" + head + ">";
}

std::string Html::getOpeningHtml() {
    return "<" + html + ">";
}

std::string Html::getClosingHtml() {
    return "</" + html + ">";
}

std::string Html::getMeta() {
    return meta;
}

std::string Html::getOpeningTitle() {
    return "<" + title + ">";
}

std::string Html::getClosingTitle() {
    return "</" + title + ">";
}

void Html::setSiteTitle(std::string siteTitle) {
    this->siteTitle = siteTitle;
}

std::string Html::getSiteTitle() {
    return "<" + title + ">" + siteTitle + "</" + title + ">";
}
