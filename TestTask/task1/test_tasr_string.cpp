#include "test_task_string.h"

std::mutex mtx;
struct sockaddr_in local;

void ReadString(std::string& str) {
    std::lock_guard<std::mutex> guard(mtx);
    std::cin >> str;
    int arr[255]{};
    if (str.size() < 64) {
        //std::cout << str << std::endl;
        for (long unsigned int i = 0; i < str.size(); i++) {
            if (isdigit(str[i])) {
                arr[i] = str[i] - 48;
            }
            else {
                std::cout << "The string contains not only numbers!" << std::endl;
            }
        }
    }
    else {
        std::cout << "The string is longer, than 64!" << std::endl;
        exit(1);
    }

    std::sort(std::begin(arr), std::end(arr), std::greater<int>());

    for (long unsigned int i = 0; i < str.size(); i++) {
        if (arr[i] % 2 == 0) {
            str[i] = arr[i] + 48;
            str[i] = 'K';
        }
        else {
            str[i] = arr[i] + 48;
        }
    }
    for (long unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == 'K') {
            str.insert(i + 1, "B");
            i++;
        }
    }
}

int CountSum(std::string& str, int &sum) {
    std::lock_guard<std::mutex> guard(mtx);
    //std::cout << "ID of 2nd thread: " << std::this_thread::get_id() << std::endl;
    std::cout << str << std::endl;
    //int sum = 0;
    for (long unsigned int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            sum += str[i] - 48;
        }
    }
    return sum;
}

void CreateSocket(int &sum){
  int sock = socket (AF_INET, SOCK_STREAM, 0);
  inet_aton("127.0.0.1", &local.sin_addr);
  local.sin_port = htons(1234);
  local.sin_family = AF_INET;
  connect(sock, (struct sockaddr*) &local, sizeof(local));
  std::string tmp = std::to_string(sum);
  const char * buf = tmp.c_str();
  write(sock, buf, strlen(buf) + 1);
  close(sock);
  sum = 0;
}
