cmake_minimum_required(VERSION 3.27)
project(ProgramowanieSieciowe C)

set(CMAKE_C_STANDARD 99)

add_executable(Zestaw3UDPServer Zestaw3/udp_server.c)
add_executable(Zestaw3UDPClient Zestaw3/udp_client.c)

