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
    virtual void send(std::shared_ptr<Message> message) override;
    virtual void subscribe(MessageReceiver *user) override;
    virtual void unsubscribe(MessageReceiver *user) override;

    void send(const std::string & text, User * user);

    int getChannel() const;

private:
    int channel;
};


#endif //ELABORATO_CHAT_H
