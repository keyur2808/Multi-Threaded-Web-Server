#ifndef NETWORK_H
#define NETWORK_H

#define TRUE 1
#define FALSE 0

#include "inc.h"
//struct sockaddr ip;
//struct clist;
extern socklen_t addrlen;
extern int listen_sd;
extern int n;

extern struct sockaddr_in remoteaddr; // client address
extern int port;
extern char remoteIP[INET6_ADDRSTRLEN];
//struct timeval timeout;
//void MyIP();
void *get_in_addr(struct sockaddr *sa);
void sock_setup();
unsigned int get_in_port(struct sockaddr *sa);
#endif // STHREAD_H

