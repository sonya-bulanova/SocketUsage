#include "test_task_server.h"

struct sockaddr_in local;

void ActiveServer(){
  int serv_sock = socket(AF_INET, SOCK_STREAM, 0);
  int client_sock;
  inet_aton("127.0.0.1", &local.sin_addr);
  int port = 1234;
  local.sin_port = htons(port);
  local.sin_family = AF_INET;
  bind(serv_sock, (struct sockaddr*) &local, sizeof(local) );
  listen(serv_sock, 5); // 5 -- сколько клиентов пытается соединиться
  //возвращает новый сокет, который связан с клиентом, который сделал коннект

  char buf[BUFSIZ];
  std::string str;
  ssize_t length = 0;
   while (true)
   {
      client_sock = accept(serv_sock, NULL, NULL); //принимаем соединение снаружи
      while ((length = read(client_sock, buf, BUFSIZ)) > 0){
        buf[length] = 0;
        str.append(buf);
        std::cout << str << " ";
        if((std::stoi( str ) >= 10) /*&& (std::stoi( str ) % 32 == 0)*/ ){
          std::cout << "Data received: " << str << std::endl;
        } else {
          std::cout << "Uncorrect data!" << std::endl;
          //exit(3);
        }
        str.clear();
        memset(buf, 0, BUFSIZ);;
      }
   }
}
