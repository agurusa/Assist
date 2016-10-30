#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "tcpacceptor.h"

int main(int argc, char** argv){
  if (argc < 2 || argc > 4){
    printf("usage: server <port> [<ip>]\n");
    exit(1);
  }
  TCPStream* stream = NULL;
  TCPAcceptor* acceptor = NULL;
  if (argc == 3){
    acceptor = new TCPAcceptor(atoi(argv[1]), argv[2]);
  }
  else{
    acceptor = new TCPAcceptor(atoi(argv[1]));
  }
  if (acceptor->start() == 0){
  }
    while (1){
      stream = acceptor->accept();
      ssize_t len;
      char line[256];
      string message;
      message = "Server (laptop) started\n";
      printf("sending - %s\n", message.c_str());
      stream->send(message.c_str(), message.size());
      while (stream) {
        string turnOff;
        turnOff = "turn off";
        printf("What would you like to send to the pi?\n");
        string directions;
        getline(cin, directions);
        // change directions to all lowercase letters. Need to add function to delete extra spaces.
        for (int i=0; i<directions.length();i++){
          directions[i] = tolower(directions[i]);
        }
        // if the user gives the pi directions to turn off, first tell the pi, then turn off the server.
        if (directions == turnOff){
          printf("Ok. Turning the system off.\n");
          stream->send(directions.c_str(), directions.size());
          delete stream;
          exit(0);
        }
        // otherwise, send the directions to the pi, then receive feedback from the pi.
        else{
          stream->send(directions.c_str(), directions.size());
          len = stream->receive(line, sizeof(line));
          printf("Pi says: %s\n", line);
        }
      }
    }
  exit(0);
}