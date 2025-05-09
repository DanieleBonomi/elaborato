//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_MESSAGERECEIVER_H
#define ELABORATO_MESSAGERECEIVER_H

#include <memory>
#include "Message.h"

class MessageReceiver {
public:
    virtual ~MessageReceiver();
    virtual void onMessageReceived(std::shared_ptr<Message> message) = 0;
    virtual void onMessageModified(std::shared_ptr<Message> message) = 0;
};


#endif //ELABORATO_MESSAGERECEIVER_H
