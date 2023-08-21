#ifndef __UTIL_HPP__
#define __UTIL_HPP__
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctype.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "log.hpp"
#include "./task/task.hpp"
#include "./threadPool/threadPool.hpp"
#define SOCKET_ERR 1
#define BIND_ERR 2
#define LISTEN_ERR 3
#define USAGE_ERR 4
#define CONN_ERR 5

#define BUFFER_SIZE 1024
#endif