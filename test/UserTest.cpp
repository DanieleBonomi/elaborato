//
// Created by user on 31/08/2023.
//

#include "gtest/gtest.h"
#include "../headers/Server.h"
#include "../headers/Chat.h"
 #include "ServerFixture.h"

TEST_F(ServerFixture,BasicWriteTest) {
    std::string str = "Hi Test";

    ASSERT_EQ(server.getMessageFromChat(0).size(), 0) << "MessageLog isn't empty before first message";
    server.getUserAtId(t_id)->writeMessage(str, 0);
    ASSERT_EQ(server.getMessageFromChat(0).size(), 1) << "MessageLog empty after first message";
    EXPECT_TRUE(server.getMessageFromChat(0).back()->getText() == str) << "First message text was damaged in MessageLog";

}
TEST_F(ServerFixture,UnicodeTest) {

    std::string str2 = "È interessante capire che succede con le accentate";

    EXPECT_NO_THROW(server.getUserAtId(t_id)->writeMessage(str2, 0))<< "Unicode messages cause error";

    EXPECT_TRUE(server.getMessageFromChat(0).back()->getText() == str2 &&
                server.getMessageFromChat(0).back()->getSender() == server.getUserAtId(t_id))
                        << "Message with unicode was damaged";
}
TEST_F(ServerFixture,ReadTest) {
    std::string str1 = "Hello";
    server.getUserAtId(t_id)->writeMessage(str1,0);
    auto messageList = server.getMessageFromChat(0);
    EXPECT_TRUE(messageList.back()->hasRead(server.getUserAtId(t_id)))
        << "User who wrote the message didn't read it";
    EXPECT_FALSE(messageList.back()->hasRead(server.getUserAtId(c_id)))
        << "User who never read the message is flagged as read=true";
    EXPECT_THROW(messageList.back()->hasRead(server.getUserAtId(s_id)),std::runtime_error)
        << "Asking if user who never received the message has read it doesn't give an error";
    server.getUserAtId(c_id)->readAll();
    EXPECT_TRUE(messageList.back()->hasRead(server.getUserAtId(c_id)))
        << "User who read the message is flagged as read=false";
}

TEST(ServerTest,onMessageReceivedTest) {
    //OUTSIDE of Fixture since it messes with directMessageReceived
    Server server(10,false);
    std::string t = "Tizio";
    int t_id = server.addUser(t);
    std::string str3 = "Direct onMessageReceived";
    auto m = std::make_shared<Message>(str3,server.getUserAtId(t_id),0);
    EXPECT_THROW(server.getUserAtId(t_id)->onMessageReceived(m),std::runtime_error) << "direct onMessage allowed";
    EXPECT_THROW(server.onMessageReceived(m),std::runtime_error) << "direct onMessage allowed";
}

TEST_F(ServerFixture,ModificationTest) {
    User * tizio = server.getUserAtId(t_id);
    User * caio = server.getUserAtId(c_id);
    tizio->writeMessage("Hello",0);
    auto mex = server.getMessageFromChat(0).back();
    auto newMex = std::make_shared<Message>(*mex,"Ciao");
    EXPECT_NO_THROW(server.getChatAt(0)->modify(newMex) )
        << "Error modifying message";
    EXPECT_NO_THROW(tizio->readAll()) << "Error modifying message in the user who modified it";
    EXPECT_NO_THROW(caio->readAll()) << "Error modifying message in the user who received it";
    EXPECT_TRUE(server.getMessageFromChat(0).size()==1)
        << "The server stores the modified message more than once";
    auto modif = server.getMessageFromChat(0).back(); // modified mex
    EXPECT_TRUE(modif->getText()=="Ciao") << "Modified message has wrong text";
    EXPECT_TRUE(modif->getChannel() == mex->getChannel()) << "Modified message has wrong channel";
    EXPECT_TRUE(modif->getSender() == mex->getSender()) << "Modified message has wrong sender";
    EXPECT_TRUE(modif->id == modif->id) << "Modified message has wrong id";





}