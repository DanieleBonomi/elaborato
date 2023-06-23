//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_MESSAGESENDER_H
#define ELABORATO_MESSAGESENDER_H


#include <list>
#include <memory>


#include "Message.h"
#include "MessageReceiver.h"

class MessageSender {
public:
    virtual ~MessageSender() = 0; // this d'tor mustn't free the memory of the pointed users, because they will be needed later

    virtual void send(std::unique_ptr<Message> m) = 0;
    virtual void subscribe(MessageReceiver *user) = 0;
    virtual void unsubscribe(MessageReceiver *user) = 0;

    MessageSender() {};

protected:
    std::list<MessageReceiver *> users;

};



#endif //ELABORATO_MESSAGESENDER_H
