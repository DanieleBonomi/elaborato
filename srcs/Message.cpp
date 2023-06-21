//
// Created by user on 21/06/2023.
//

#include "../headers/Message.h"

const std::string &Message::getText() const {
    return text;
}

const std::shared_ptr<User> &Message::getSender() const {
    return sender;
}

const std::shared_ptr<Chat> &Message::getChat() const {
    return chat;
}

Message::Message(const std::string &text, const std::shared_ptr<User> &sender, const std::shared_ptr<Chat> &chat)
        : text(text), sender(sender), chat(chat) {}
