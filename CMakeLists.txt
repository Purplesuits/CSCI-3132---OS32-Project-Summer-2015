cmake_minimum_required(VERSION 3.2)
project(OS32)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(header)

set(TEAM1_SOURCE src/team1/OS32Memory.cpp src/team1/File.cpp src/team1/FileSystem.cpp)
set(TEAM2_SOURCE src/team2/Command.cpp src/team2/Scheduler.cpp)
set(TEAM3_SOURCE src/team3/Login.cpp src/team3/Menu.cpp src/team3/UI.cpp)
set(TEAM4_SOURCE src/team4/Converter.cpp src/team4/encryption.cpp src/team4/Motd.cpp src/team4/Palindrome.cpp src/team4/Utilities.cpp)

add_executable(OS32Setup src/team1/OS32setup.cpp ${TEAM1_SOURCE} ${TEAM2_SOURCE} ${TEAM3_SOURCE} ${TEAM4_SOURCE})
add_executable(OS32 main.cpp ${TEAM1_SOURCE} ${TEAM2_SOURCE} ${TEAM3_SOURCE} ${TEAM4_SOURCE})

add_executable(test_memory src/team1/test_memory.cpp ${TEAM1_SOURCE})
add_executable(test_filesystem src/team1/test_FS.cpp ${TEAM1_SOURCE})
add_executable(test_scheduler src/team2/test_Scheduler.cpp ${TEAM1_SOURCE} ${TEAM2_SOURCE} ${TEAM3_SOURCE} ${TEAM4_SOURCE})
