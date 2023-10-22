#ifndef __COMM_H__
#define __COMM_H__
// #include <iostream>
// #include <cstring>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <cstdio>
// #include <unistd.h>
// #include <errno.h>
// #include <assert.h>

// #define IPC_PATH "./fifo"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <cassert>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Log.hpp"

#define PATH_NAME "/home/qkj/104/Linux/lesson13"
#define PROJ_ID 0x14
#define MEM_SIZE 4096

#define FIFO_FILE ".fifo"

key_t CreateKey()
{ // key_t 就是一个int类型
  key_t key = ftok(PATH_NAME, PROJ_ID);
  if (key < 0)
  {
    std::cerr << "ftok: " << strerror(errno) << std::endl;
    exit(1);
  }
  return key;
}

#endif