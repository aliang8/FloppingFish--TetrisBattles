#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "networking.h"

int main( int argc, char *argv[] ) {

  char *host;
  if (argc != 2 ) {
    printf("host not specified, conneting to 127.0.0.1\n");
    host = "127.0.0.1";
  }
  else
    host = argv[1];
  
  int sd;

  sd = client_connect( host );

  char buffer[MESSAGE_BUFFER_SIZE];
  
  while (1) {
    printf("enter message: ");

    fgets( buffer, sizeof(buffer), stdin );

    printf("test1");

    char *p = strchr(buffer, '\n');
    *p = '\0';

    printf("test2");
  
    write( sd, buffer, strlen(buffer));

    printf("test3");

    read( sd, buffer, sizeof(buffer) );
    printf( "received: %s\n", buffer );
  }
  
  return 0;
}
