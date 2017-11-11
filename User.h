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
    string firstName;
    string lastName;
    
  public:
  
    User(string fn = "John", string ln = "Doe") 
    {
      firstName = fn; 
      lastName = ln;
    }
  
    void setFirstName(string fn)
    {
      firstName = fn;
    }
    
    void setLastName(string ln)
    {
      lastName = ln;
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
