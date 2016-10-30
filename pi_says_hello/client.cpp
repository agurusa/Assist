#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "tcpconnector.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc != 3) {
        printf("usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }
  int len;
  char line[256];
  string gotIt;
  string turnOff;
  gotIt = "Got it!";
  turnOff = "turn off";
  TCPConnector* connector = new TCPConnector();
  TCPStream* stream = connector->connect(argv[2], atoi(argv[1]));
  printf("Client (pi) started\n");
  while (stream){
    len = stream->receive(line, sizeof(line));
    line[len] = 0;
    if (line == turnOff){
      printf("Ok, bye bye\n");
      delete stream;
      exit(0);
    }
    else{
      printf("received- %s\n", line);
      stream->send(gotIt.c_str(), gotIt.size());
    }
  }
  exit(0);
}