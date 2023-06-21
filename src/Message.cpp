//
// Created by user on 21/06/2023.
//

#include "../headers/Message.h"

Message::Message(const std::string &text, const std::shared_ptr<User> &sender,
                 const std::shared_ptr<MessageSender> &chat) : text(text), sender(sender), chat(chat) {}

const std::string &Message::getText() const {
    return text;
}

const std::shared_ptr<User> &Message::getSender() const {
    return sender;
}

const std::shared_ptr<MessageSender> &Message::getChat() const {
    return chat;
}
