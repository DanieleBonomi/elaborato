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

    EXPECT_ANY_THROW(s.getChatAtChannel(1)) << "Chat still in server list after being removed";

    EXPECT_ANY_THROW(s.removeChat(1)) << "Chat can be removed twice";

    EXPECT_ANY_THROW(s.addChat(1)) << "Chat can be added twice";

    EXPECT_ANY_THROW(s.removeChat(99)) << "Chat can be even if outside of chats";

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

    EXPECT_ANY_THROW(server.getUserAtId(id1)) << "User still in server list after being removed";

    EXPECT_ANY_THROW(server.removeUser(id1)) << "User can be removed twice";

    EXPECT_THROW(server.addUser(t); server.addUser(t) ,std::runtime_error) << "User can be added twice to the same server";

    EXPECT_ANY_THROW(server.removeUser(id1)) << "User can removed be even if outside of users";

}
