//
// Created by user on 30/08/2023.
//
#include "gtest/gtest.h"
#include "../headers/Server.h"

class ServerFixture : public ::testing::Test {

protected:
    Server server = Server(10,false);

    int t_id,c_id,s_id;
    void SetUp() override{

            std::string t = "Tizio";
            std::string c = "Caio";
            std::string s = "Sempronio";

            server.addChat(0);
            server.addChat(1);
            server.addChat(2);

            t_id = server.addUser(t);
            c_id = server.addUser(c);
            s_id = server.addUser(s);

            server.signToChat(t_id, 0);
            server.signToChat(c_id, 0);

            server.signToChat(t_id, 1);
    }
};