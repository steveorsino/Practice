#include <iostream>
#include <string>

using namespace std;

#ifndef JOURNAL_H
#define JOURNAL_H

class Journal
{
  private:
    string userName;
    string title;
    string body;
    time_t timeEntered;
    
  public:
    Journal(string un = "default", string tit = "default", string bd = "default")
    {
      userName = un;
      title = tit;
      body = bd;
      timeEntered = time(0);
    }
    
    
    long getTime() {
      return timeEntered;
    }
    
    string getUser()
    {
      return userName;
    }
    
};

#endif