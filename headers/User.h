//
// Created by user on 21/06/2023.
//

#ifndef ELABORATO_USER_H
#define ELABORATO_USER_H


#include <string>
#include "MessageReceiver.h"

class User : public MessageReceiver {
public:
    explicit User(const std::string &username);

private:
    int id;
    std::string username;
};


#endif //ELABORATO_USER_H
