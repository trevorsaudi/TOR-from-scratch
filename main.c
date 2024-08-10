#include "toralizer.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

Req *request(const char *dstip, const int dstport){
	Req *req;
	req = malloc(reqsize); //allocate space for the structure
	
	req->vn = 4;
	req->cd = 1;
	req->dstport = htons(dstport);
	req->dstip = inet_addr(dstip);	
	strncpy(req->username, USERNAME, 8);
	
	return req;
}

int main(int argc, char *argv[]){

	char *host;
	int port, s;
	struct sockaddr_in sock;
	Req *req;
  Res *res;
  char buf[ressize];
  int success;

	if(argc < 3){
	fprintf(stderr, "Usage: %s <host> <port>\n",argv[0]);
	return -1;
	}

	host = argv[1];
	port = atoi(argv[2]);

	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0){
	
	fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
	
	return -1;
	}
	sock.sin_family = AF_INET;
	sock.sin_port = htons(PROXYPORT);
	sock.sin_addr.s_addr = inet_addr(PROXY);
	
	if(connect(s, (struct sockaddr*)&sock, sizeof(sock)) != 0){
		printf("%s", strerror(errno));
		return -1;
	};
                                  
	req = request(host, port);
	write(s, req, reqsize);
	memset(buf, 0, ressize);
  
  if(read(s, buf, ressize) < 1 ){
	fprintf(stderr, "Unable to read buffer: %s\n", strerror(errno));
    free(req);
    close(s);
    return -1;
  }
  res = (Res *)buf;
  success = (res->cd == 90); //success is a boolean and will check whether the CD value is 90 which means success
  if(!success){
    fprintf(stderr, "Unable to connect to "
                    "the proxy, error code: %d\n", res->cd);
    close(s);
    free(req);
  }

  printf("Successfully connected through the proxy to %s:%d\n", host, port);
  close(s);
  free(req);

  return 0;
}

