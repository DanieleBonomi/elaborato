//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_MESSAGESENDER_H
#define ELABORATO_MESSAGESENDER_H


#include <list>
#include <memory>
class Message;
class MessageReceiver;
//#include "Message.h"
//#include "MessageReceiver.h"

class MessageSender {
public:
    virtual void subscribe(std::shared_ptr<MessageReceiver> user) = 0;
    virtual void unsubscribe(std::shared_ptr<MessageReceiver> user) = 0;
    virtual void send(Message & m) = 0;


public:
    std::list<std::shared_ptr<MessageReceiver>> users;
};


#endif //ELABORATO_MESSAGESENDER_H
