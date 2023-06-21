cmake_minimum_required(VERSION 3.23)
project(elaborato)

set(CMAKE_CXX_STANDARD 14)

add_executable(elaborato main.cpp MessageReceiver.cpp MessageReceiver.h MessageSender.cpp MessageSender.h Message.cpp Message.h Chat.cpp Chat.h Server.cpp Server.h)
