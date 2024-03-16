//
// Created by user on 31/08/2023.
//

#include "gtest/gtest.h"
#include "../headers/Server.h"
#include "../headers/Chat.h"
#include "../headers/User.h"
#include "ServerFixture.cpp"

TEST_F(ServerFixture,BasicWriteTest) {


    std::string str = "Hi Test";

    ASSERT_EQ(server.getMessageFromChat(0).size(), 0) << "MessageLog isn't empty before first message";
    server.getUserAtId(t_id)->writeMessage(str, 0);
    ASSERT_EQ(server.getMessageFromChat(0).size(), 1) << "MessageLog empty after first message";
    EXPECT_TRUE(server.getMessageFromChat(0).back()->getText() == str) << "First message was damaged in MessageLog";

}
TEST_F(ServerFixture,UnicodeTest) {

    std::string str2 = "È interessante capire che succede con le accentate";
    try {
        server.getUserAtId(t_id)->writeMessage(str2, 0);
    } catch (std::exception &e) { ASSERT_TRUE(false) << "Unicode messages cause error" << e.what(); }

    EXPECT_TRUE(server.getMessageFromChat(0).back()->getText() == str2 &&
                server.getMessageFromChat(0).back()->getSender() == server.getUserAtId(t_id))
                        << "Message with unicode was damaged";
}
TEST(ServerTest,onMessageReceivedTest) {
    //OUTSIDE of Fixture since it messes with directMessageReceived
    Server server(10,false);
    std::string t = "Tizio";
    int t_id = server.addUser(t);
    std::string str3 = "Direct onMessageReceived";
    std::unique_ptr<Message> m = std::make_unique<Message>(str3,server.getUserAtId(t_id),0);
    m = server.getUserAtId(t_id)->onMessageReceived(std::move(m));
    server.onMessageReceived(std::move(m));
    EXPECT_TRUE(server.getMessageFromChat(0).back()->getText()==str3 && server.getMessageFromChat(0).back()->getSender()==server.getUserAtId(t_id))<< "direct onMessageReceived not working";

}
