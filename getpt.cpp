#include "inc.h"

using namespace std;

char secstr[128];

time_t now;

struct stat buf;
struct tm *tmn;

std::string lasc(char path[])
{
stat(path,&buf);
now=buf.st_mtime;
memset(secstr, 0, sizeof(secstr));
tmn=gmtime(&now);
strftime(secstr, sizeof(secstr), "Last-Modified: %a, %d %b %Y %H:%M:%S GMT\n", tmn);
return (string(secstr));
//send(sock,secstr,sizeof secstr,0);
}

std::string sendtm(){
time(&now);
memset(secstr, 0, sizeof(secstr));
tmn=gmtime(&now);
strftime(secstr, sizeof(secstr), "Date: %a, %d %b %Y %H:%M:%S GMT\n", tmn);
return (string(secstr));
//send(sock,secstr,sizeof secstr,0);
}

char* setm(){
time(&now);
memset(secstr, 0, sizeof(secstr));
tmn=localtime(&now);
strftime(secstr, sizeof(secstr), "%d/%b/%Y:%H:%M:%S %z", tmn);
return secstr;
}



//cout<<buf.st_mtime<<endl;
//fprintf()

