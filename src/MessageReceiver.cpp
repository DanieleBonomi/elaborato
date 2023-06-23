//
// Created by user on 21/06/2023.
//

#include "../headers/MessageReceiver.h"

MessageReceiver::~MessageReceiver() {

}

std::unique_ptr<Message> MessageReceiver::onMessageReceived(std::unique_ptr<Message> m) {
    return m;
}
