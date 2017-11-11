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
    
    void setUserName(string u)
    {
      userName = u;
    }
    
    void setTitle(string t) 
    {
      title = t;
    }
    
    void setBody(string b)
    {
      body = b;
    }
    
    long getTime() {
      return timeEntered;
    }
    
    string getUser()
    {
      return userName;
    }
    
    string getTitle()
    {
      return title;
    }
    
    string getBody()
    {
      return body;
    }
    
};

#endif