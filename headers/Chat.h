//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_CHAT_H
#define ELABORATO_CHAT_H


#include "MessageSender.h"
#include "Message.h"
#include "MessageReceiver.h"
#include <memory>

class Chat : public MessageSender {

public:
    explicit Chat(int channel);
    virtual void send(Message & m) override;
    virtual void subscribe(std::shared_ptr<MessageReceiver> user) override;
    virtual void unsubscribe(std::shared_ptr<MessageReceiver> user) override;

public:
    int channel;
};


#endif //ELABORATO_CHAT_H
