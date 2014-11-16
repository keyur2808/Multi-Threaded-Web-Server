#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include "dirchk.h"

using namespace std;

  DIR *d;
  struct dirent *dir1;
  struct stat stat_buf;
  char *buffer;
  const char c[]="<html>";
  const char ce[]="</html>";
  char *bufr;


void ISDIR(int *di,char *path)
{
  int status = stat (path, &stat_buf);
  if (status != 0) {

  }
  if (S_ISDIR (stat_buf.st_mode)) {
    *di=1;
    }

}

char *lst(char *path,int *len)
//int main()
{

  d = opendir(path);
  int vects=0;
  buffer=(char *)malloc(1*5000);
  bufr=buffer;
  string s;
  vector<string> filevect;
  if (d)
  {
    while ((dir1 = readdir(d)) != NULL)
    {

      if(*dir1->d_name=='.')
      continue;
      s=(string)dir1->d_name+"<br>";
      vects=vects+strlen("<br>")+strlen(dir1->d_name);
      filevect.push_back(s);

    }

    closedir(d);
  }
sort(filevect.begin(), filevect.end());
std::string s1 = accumulate(filevect.begin(), filevect.end(), std::string());
memcpy(buffer,s1.c_str(),s1.length());
buffer=buffer+s1.length();
memcpy(buffer,&ce,7);
vects=vects+7;
*len=vects;

  return (bufr);
}

