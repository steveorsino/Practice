/*
The purpose of this program is to practice c++.
Author: Stephen Orsino
11/11/2017

*/

#include <iostream>
#include <string>

using namespace std;

#ifndef USER_H
#define USER_H

class User
{
  private:
    string userName;
    string firstName;
    string lastName;
    //Journal journals[100];
    
  public:
  
    User(string un = "default", string fn = "John", string ln = "Doe") 
    {
      userName = un;
      firstName = fn; 
      lastName = ln;
    }
    
    void setUserName(string un)
    {
      userName = un;
    }
  
    void setFirstName(string fn)
    {
      firstName = fn;
    }
    
    void setLastName(string ln)
    {
      lastName = ln;
    }
    
    /*
    void setJournals(Journal *j[])
    {
      int count = j->size();
      for(int i = 0; i < count; i++)
      {
        journals[i] = j[i];
      }
      
    }
    */
    
    string getUserName()
    {
      return userName;
    }
  
    string getFirstName()
    {
      return firstName;
    }
    
    string getLastName()
    {
      return lastName;
    }
    
    
};

#endif
