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
    virtual ~MessageSender() = default; // this d'tor mustn't free the memory of the pointed receivers, because they will be needed later

    virtual void send(Message m) = 0;
    virtual void subscribe(MessageReceiver *user) = 0;
    virtual void unsubscribe(MessageReceiver *user) = 0;


protected:
    std::list<MessageReceiver *> receivers;

};



#endif //ELABORATO_MESSAGESENDER_H
