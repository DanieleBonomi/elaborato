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
    MessageReceiver() = default;
    virtual std::unique_ptr<Message> onMessageReceived(std::unique_ptr <Message> m) =0;
};


#endif //ELABORATO_MESSAGERECEIVER_H
