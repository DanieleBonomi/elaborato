//
// Created by user on 21/06/2023.
//

#include "../headers/Message.h"


Message::Message(const std::string &text, const User * sender) : text(text),sender(sender) {}

const std::string &Message::getText() const {
    return text;
}

const User * Message::getSender() const {
    return sender;
}
