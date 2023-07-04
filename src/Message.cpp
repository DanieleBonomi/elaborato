//
// Created by user on 21/06/2023.
//

#include "../headers/Message.h"


Message::Message(const std::string &text, const User * sender, int channel) : text(text),sender(sender),channel (channel)  {}

const std::string &Message::getText() const {
    return text;
}

const User * Message::getSender() const {
    return sender;
}

int Message::getChannel() const {
    return channel;
}
