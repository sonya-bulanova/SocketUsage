//main.cpp
#include "test_task_string.h"

int main()
{
    std::string arr;
    int sum = 0;
    while (true){
      std::thread ReadTh(ReadString, std::ref(arr));
      std::thread SumTh(CountSum, std::ref(arr), std::ref(sum));
      ReadTh.join();
      SumTh.join();
      CreateSocket(sum);
    }
}
