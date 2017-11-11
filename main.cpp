/*
  Pratice program
*/

#include "User.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main()
{
  //User user1;
  string uName, fName, lName;
  string input;
  fstream dataFile;
  char choice;
  
  
  
  do {
    
    cout << "Hello, What would you like to do today?\n"
        << "\tA. Create a user\n"
        << "\tB. Sign it with username\n"
        << "\tC. Exit\n"
        << "Enter choice: ";
        
    cin >> choice;
    
    if (choice == 'A' || choice == 'a')
    {
      bool isOpen = false;
      dataFile.open("users.txt", ios::in);
      
      if(dataFile)
      {
      
        do {
          cout << "Create a user name: ";
          cin >> uName;
            
          while(dataFile >> input)
          {

            if (input == uName)
            {
              cout << "\nThis user name already exists.\n\n";
            }
            else {
              isOpen = true;
              dataFile.close();
            }
          }
          
        }while (!isOpen);
      
      
        cout << "Enter first name: ";
        cin >> fName;;
        cout << "Enter last name: ";
        cin >> lName;
        
        
        User user1(uName, fName, lName);
        
        cout << user1.getFirstName() << " " << user1.getLastName() << endl;
        
  
        dataFile.open("users.txt", ios::app);
        
        dataFile << user1.getUserName() << endl;
        dataFile << user1.getFirstName() << endl;
        dataFile << user1.getLastName() << endl;
        
        dataFile.close();
      }
      
      else
      {
        cout << "\nerror opening file" << endl;
      }
    }
    
    else if(choice == 'B' || choice == 'b')
    {
      User user2;
      cout << "\nWhat is your user name? ";
      cin >> uName;
      
      dataFile.open("users.txt", ios::in);

      while(dataFile >> input)
      {
        if (input == uName)
        {
          dataFile >> fName;
          dataFile >> lName;
          user2.setUserName(input);
          user2.setFirstName(fName);
          user2.setLastName(lName);
        }
       
      }
      
      if(user2.getLastName() != "Doe")
      {
        cout << "Welcome back " << user2.getFirstName() << " " << user2.getLastName() << endl;
      }
      else
      {
        cout << "No user found.\n";
        dataFile.close();
      }
      
      dataFile.close();
    }
    
    else if(choice == 'C' || choice == 'c')
    {
      cout << "\n\nHave a great day!!!\n\n";
    }
    
    else
  {
    cout << "\n\nYou entered an invalid choice.\n\n";
  }
    
  }while (choice != 'C' && choice != 'c');
  
  
  return 0;
}