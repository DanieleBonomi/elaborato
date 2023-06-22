//
// Created by user on 21/06/2023.
//

#include "../headers/Message.h"


Message::Message(const std::string &text, const std::shared_ptr<MessageReceiver> &sender) : text(text),
                                                                                            sender(sender) {}

const std::string &Message::getText() const {
    return text;
}

const std::shared_ptr<MessageReceiver> &Message::getSender() const {
    return sender;
}
