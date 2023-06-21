cmake_minimum_required(VERSION 3.23)
project(elaborato)

set(CMAKE_CXX_STANDARD 14)

add_executable(elaborato main.cpp srcs/MessageReceiver.cpp headers/MessageReceiver.h srcs/MessageSender.cpp headers/MessageSender.h srcs/Message.cpp headers/Message.h srcs/Chat.cpp headers/Chat.h srcs/Server.cpp headers/Server.h srcs/User.cpp headers/User.h)
