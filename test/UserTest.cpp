//
// Created by user on 31/08/2023.
//

#include "gtest/gtest.h"
#include "../headers/Server.h"
#include "../headers/Chat.h"
#include "../headers/User.h"
#include "ServerFixture.cpp"

TEST_F(ServerFixture,WriteInChats) { // should I divide this in more TEST_F? Probably


    std::string str = "Hi Test";

    try {
        ASSERT_EQ(server.getMessageFromChat(0).size(), 0) << "MessageLog isn't empty before first message";
        server.getUserAtUsername(t)->writeMessage(str, 0);
        ASSERT_EQ(server.getMessageFromChat(0).size(), 1) << "MessageLog empty after first message";
        EXPECT_TRUE(server.getMessageFromChat(0).back()->getText() == str) << "First message was damaged in MessageLog";
    } catch (std::exception& e) { ASSERT_TRUE(false) << e.what();}


    std::string str2 = "È interessante capire che succede con le accentate";
    try {
        server.getUserAtUsername(t)->writeMessage(str2, 0);
    } catch (std::exception & e) {ASSERT_TRUE(false) << "Unicode messages cause error" << e.what(); }

    EXPECT_TRUE(server.getMessageFromChat(0).back()->getText()==str2 && server.getMessageFromChat(0).back()->getSender()==server.getUserAtUsername(t)) << "Message with unicode was damaged";

    Server s2;
    s2.addChat(0);
    s2.addUser(t);
    std::string str3 = "Direct onMessageReceived";
    std::unique_ptr<Message> m = std::make_unique<Message>(str3,s2.getUserAtUsername(t),0);
    m = s2.getUserAtUsername(t)->onMessageReceived(std::move(m));
    s2.onMessageReceived(std::move(m));
    EXPECT_TRUE(s2.getMessageFromChat(0).back()->getText()==str3 && s2.getMessageFromChat(0).back()->getSender()==s2.getUserAtUsername(t))<< "direct onMessageReceived not working";
}
