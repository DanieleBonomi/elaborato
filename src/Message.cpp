//
// Created by user on 21/06/2023.
//

#include <stdexcept>
#include "../headers/Message.h"


Message::Message(const std::string &text, const User * sender, int channel)
    : text(text),sender(sender),channel (channel),id(idCount++)  {}

int Message::idCount=0;

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

bool Message::hasRead(const MessageReceiver * user) const {
    if (read.count(user)) { // if user in read keys
        return read.at(user); // at is const but map.operator[] isn't
    }
    throw std::runtime_error("Checking read for user who never received the message");
}

Message::Message(const Message &other, const std::string& text) {
    this->id = other.id;
    this->channel = other.channel;
    this->sender = other.sender;
    this->text = text;
}
