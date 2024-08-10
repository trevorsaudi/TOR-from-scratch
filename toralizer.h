/* toralize.h */

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PROXY 		"127.0.0.1"
#define PROXYPORT 9050
#define USERNAME 	"shadows" // 7 letter username so we can do 8 bits (7 + 1 null terminated)
#define reqsize 	sizeof(struct proxy_request)
#define ressize		sizeof(struct proxy_response)

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

/*

first structure -> request being sent
+----+----+----+----+----+----+----+----+----+----+----+----+
| VN | CD | DSTPORT |      DSTIP        | USERID       |NULL|
+----+----+----+----+----+----+----+----+----+----+----+----+
   1    1      2              4           variable       1
--------------------------------------------------------------
*/

struct proxy_request {
	int8 vn;
	int8 cd;
	int16 dstport;
	int32 dstip;
	unsigned char username[8]; //seven bits for the the variable and the last bit for the NULL
};

typedef struct proxy_request Req;
/*
+----+----+----+----+----+----+----+----+
| VN | CD | DSTPORT |      DSTIP        |
+----+----+----+----+----+----+----+----+
  1    1      2              4
*/

struct proxy_response{
	int8 vn;
	int8 cd;
	int16 _;
	int32 __;

};

typedef struct proxy_response Res;

Req *request(const char *, const int);
int main(int, char**);

