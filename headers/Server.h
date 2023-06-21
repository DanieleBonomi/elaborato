//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_SERVER_H
#define ELABORATO_SERVER_H


#include <map>
#include <memory>
#include "Chat.h"

class Server { // singleton
public:
    static std::shared_ptr<Server> getIstance();



    void addChat(std::shared_ptr<Chat> chat);
    void removeChat(int channel);
    std::shared_ptr<Chat> getChatAtChannel(int channel) const;

    int getFreeId();

private:
    explicit Server(int maxChats);

private:
    int maxChats;
    int usedID;
    std::map<int,std::shared_ptr<Chat>> chats;

    inline static std::shared_ptr<Server> instance = nullptr; // for singleton

};


#endif //ELABORATO_SERVER_H
