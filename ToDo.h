#include <iostream>
#include <string>

using namespace std;

#ifndef TODO_H
#define TODO_H

class ToDo
{
  private:
    string userName;
    string todo;
    time_t timeEntered;
    time_t timeDue;
    
  public:
    ToDo(string un = "default", string td = "default", long due = 0001)
    {
      userName = un;
      todo = td;
      timeEntered = time(0);
      timeDue = due;
    }
    
    string getUser()
    {
      return userName;
    }
    
    string getToDo()
    {
      return todo;
    }
    
    long getTimeEntered()
    {
      return timeEntered;
    }
    
    long getTimeDue()
    {
      return timeDue;
    }
    
    void setUser(string u)
    {
      userName = u;
    }
    
    void setToDo(string t)
    {
      todo = t;
    }
    
    void setDue(long d)
    {
      timeDue = d;
    }
};

#endif