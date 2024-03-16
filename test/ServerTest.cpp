//
// Created by user on 31/08/2023.
//

#include "gtest/gtest.h"
#include "../headers/Server.h"
#include "../headers/Chat.h"
#include "../headers/User.h"

TEST(ServerTest,AvoidSameIDs) {
    Server s;
    EXPECT_TRUE(s.getFreeId()!=s.getFreeId()) << "SAME ID given by server";
}

TEST(ServerTest,ChatCheck) {
    Server s;
    s.addChat(1);
    s.addChat(2);
    EXPECT_EQ(s.getChatAtChannel(1)->getChannel(),1) << "Chat at channel doesn't have correct channel";
    EXPECT_EQ(s.getChatAtChannel(2)->getChannel(),2) << "Chat at channel doesn't have correct channel";


    s.removeChat(1);
    bool err = false;
    try {
        auto chat = s.getChatAtChannel(1);
    } catch (...) {
        err = true;
    }
    EXPECT_TRUE(err) << "Chat still in server list after being removed";

    err = false;
    try {
        s.removeChat(1);
    } catch (...) {
        err = true;
    }
    EXPECT_TRUE(err) << "Chat can be removed twice";

    err = false;
    try {
        s.addChat(1);
    } catch (...) {
        err = true;
    }
    EXPECT_TRUE(err) << "Chat can be added twice";

    err = false;
    try {
        s.removeChat(99);
    } catch (...) {
        err = true;
    }
    EXPECT_TRUE(err) << "Chat can be even if outside of chats";

    //FIXME Expect_true-> expect_throw

}

TEST(ServerTest,UserCheck) {
    Server server;
    std::string t = "Tizio";
    std::string c = "Caio";
    std::string s = "Sempronio";
    int id1 = server.addUser(t);
    int id2 = server.addUser(c);
    EXPECT_EQ(server.getUserAtId(id1)->getUsername(),t) << "User at username doesn't have correct username";
    EXPECT_EQ(server.getUserAtId(id2)->getUsername(),c) << "User at username doesn't have correct username";

    server.removeUser(id1);
    bool err = false;
    try {
        auto user = server.getUserAtId(id1);
    } catch (...) {
        err = true;
    }
    EXPECT_TRUE(err) << "User still in server list after being removed";

    err = false;
    try {
        server.removeUser(id1);
    } catch (...) {
        err = true;
    }
    EXPECT_TRUE(err) << "User can be removed twice";

    err = false;
    try {
        server.addUser(t);
        server.addUser(t);
    } catch (std::runtime_error & e) {
        err = true;
    }
    EXPECT_TRUE(err) << "User can be added twice to the same server";

    err = false;
    try {
        server.removeUser(id1);
    } catch (...) {
        err = true;
    }
    EXPECT_TRUE(err) << "User can removed be even if outside of users";

}
