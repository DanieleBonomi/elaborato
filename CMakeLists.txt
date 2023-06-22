cmake_minimum_required(VERSION 3.23)
project(elaborato)

set(CMAKE_CXX_STANDARD 17)

add_executable(elaborato main.cpp src/MessageReceiver.cpp headers/MessageReceiver.h headers/MessageSender.h src/Message.cpp headers/Message.h src/Chat.cpp headers/Chat.h src/Server.cpp headers/Server.h src/User.cpp headers/User.h)
