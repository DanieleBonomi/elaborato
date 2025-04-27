//
// Created by user on 31/08/2023.
//

#include "gtest/gtest.h"
#include "../headers/Server.h"
#include "../headers/Chat.h"
#include "ServerFixture.h"

TEST(ServerTest,AvoidSameIDs) {
    Server s;
    EXPECT_TRUE(s.getFreeId()!=s.getFreeId()) << "SAME ID given by server";
}

TEST(ServerTest,ChatCheck) {
    Server s;
    s.addChat(1);
    s.addChat(2);
    EXPECT_EQ(s.getChatAt(1)->getChannel(), 1) << "Chat at channel doesn't have correct channel";
    EXPECT_EQ(s.getChatAt(2)->getChannel(), 2) << "Chat at channel doesn't have correct channel";


    s.removeChat(1);

    EXPECT_THROW(s.getChatAt(1),std::out_of_range) << "Chat still in server list after being removed";

    EXPECT_THROW(s.removeChat(1),std::runtime_error) << "Chat can be removed twice";

    EXPECT_THROW(s.addChat(1),std::runtime_error) << "Chat can be added twice";

    EXPECT_THROW(s.removeChat(99),std::runtime_error) << "Chat can be even if outside of chats";


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

    EXPECT_THROW(server.getUserAtId(id1);,std::runtime_error)
        << "User still in server list after being removed";

    EXPECT_THROW(server.removeUser(id1);, std::runtime_error)
        << "User can be removed twice";

    EXPECT_THROW({ server.addUser(t); server.addUser(t);} ,std::runtime_error)
        << "User can be added twice to the same server";

    EXPECT_THROW(server.removeUser(id1);,std::runtime_error)
        << "User can removed be even if outside of users";
}

TEST_F(ServerFixture,AvoidSameMessageId) {
    const int totCount = 10;
    auto user = server.getUserAtId(t_id);
    for (int i=0; i<totCount; i++) {
        user->writeMessage("MEX " + std::to_string(i),0);
    }
    auto messages = server.getMessageFromChat(0);

    for (auto i=messages.begin(); i!=std::prev(messages.end()); i++) {

        for (auto j=std::next(i); j!=messages.end(); j++) {
            EXPECT_FALSE((*i)->id == (*j)->id)
                << " found 2 messages with the same id";
            // i is iterator<std::shared_ptr<Message>> so two * are needed (or *i->)
        }
    }
}