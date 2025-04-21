//
// Created by user on 21/06/2023.
//

#include <stdexcept>
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

void Message::setUpRead(const std::list<MessageReceiver *>& users) {
    for (MessageReceiver * user : users) {
        read[user] = false;
    }
}

void Message::setRead(const MessageReceiver *user) {
    if (read.count(user)) { // check if user is in map keys
        read[user] = true;
    } else {
        throw std::runtime_error("Message set as read by user who never received it");
    }
}
