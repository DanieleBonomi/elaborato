//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_CHAT_H
#define ELABORATO_CHAT_H

#include <memory>

#include "Message.h"
#include "MessageReceiver.h"
#include "MessageSender.h"
#include "User.h"

class Chat : MessageSender {

public:
    explicit Chat(int channel);

    void subscribe(MessageReceiver *user) override;
    void unsubscribe(MessageReceiver *user) override;

    void send(const std::string & text, User * user) override;
    void send(std::shared_ptr<Message> message) override;
    void modify(std::shared_ptr<Message> message) override;

    int getChannel() const;

private:
    int channel;
    std::list<MessageReceiver *> receivers;
};


#endif //ELABORATO_CHAT_H
