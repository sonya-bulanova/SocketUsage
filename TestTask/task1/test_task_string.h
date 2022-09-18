//test_task_string.h
#include <iostream>
#include <algorithm>
#include <thread>
#include <mutex>

#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void ReadString(std::string& str);
int CountSum(std::string& str, int &sum);
void CreateSocket(int &sum);
