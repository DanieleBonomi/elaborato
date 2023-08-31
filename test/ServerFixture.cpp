//
// Created by user on 30/08/2023.
//
#include "gtest/gtest.h"
#include "../headers/Server.h"

class BaseFixture : public ::testing::Test {

protected:
    Server server;
    virtual void SetUp(){
        server.addChat(0);
        server.addChat(1);
        std::string t = "Tizio";
        std::string c = "Caio";
        std::string s = "Sempronio";
        server.addUser(t); //should I create a std::string and assign it char [] instead?
        server.addUser(c);
        server.addUser(s);

    }
};