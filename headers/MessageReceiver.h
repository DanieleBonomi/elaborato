//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_MESSAGERECEIVER_H
#define ELABORATO_MESSAGERECEIVER_H

class Message;
//#include "Message.h"

class MessageReceiver {
public:
    virtual ~MessageReceiver();
    MessageReceiver() = default;
    virtual void onMessageReceived(Message & m) = 0;
};


#endif //ELABORATO_MESSAGERECEIVER_H
