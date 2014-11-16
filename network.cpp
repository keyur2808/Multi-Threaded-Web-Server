#include <netinet/tcp.h>
#include "inc.h"
#include "network.h"


int yes=1,info;
int listen_sd;
int n;

socklen_t addrlen;


void sock_setup(){
struct sockaddr_in me;
memset(&me,0,sizeof me);
me.sin_family=AF_INET;
me.sin_addr.s_addr=INADDR_ANY;
me.sin_port=htons(port);


listen_sd=socket(AF_INET,SOCK_STREAM,0);
if (listen_sd<0)
{
perror("socket");
}

info=setsockopt(listen_sd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof (int));
if (info<0)
{
perror("setsockopt");
}

info=setsockopt(listen_sd,IPPROTO_TCP,TCP_NODELAY,&yes,sizeof (int));
if (info<0)
{
perror("setsockopt");
}

info=bind(listen_sd,(struct sockaddr*)&me,sizeof me);
if (info<0)
{
perror("socket");
}

info=listen(listen_sd,n);
if (info<0)
{
perror("socket");
}

}

