//
// Created by user on 30/08/2023.
//
#include "gtest/gtest.h"
#include "../headers/Server.h"

class ServerFixture : public ::testing::Test {

protected:
    Server server;
    std::string t = "Tizio";
    std::string c = "Caio";
    std::string s = "Sempronio";

    virtual void SetUp() override{
        server.addChat(0);
        server.addChat(1);
        server.addChat(2);

        server.addUser(t);
        server.addUser(c);
        server.addUser(s);

        server.signToChat(t,0);
        server.signToChat(c,0);

        server.signToChat(t,1);

    }
};