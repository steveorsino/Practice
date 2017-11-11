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
  string fName, lName;
  fstream dataFile;
  char choice;
  
  
  do {
    
    cout << "Hello, What would you like to do today?\n"
        << "\tA. Create a user\n"
        << "\tB. SIgn it with Another User\n"
        << "\tC. Exit\n"
        << "Enter choice: ";
        
    cin >> choice;
    
    if (choice == 'A' || choice == 'a')
    {
      cout << "enter firstname";
      cin >> fName;;
      cout << "enter lastname";
      cin >> lName;
      
      
      User user1(fName, lName);
      
      cout << user1.getFirstName() << " " << user1.getLastName() << endl;
      

      dataFile.open("users.txt", ios::app);
      
      dataFile << user1.getFirstName() << endl;
      dataFile << user1.getLastName() << endl;
      
      dataFile.close();

    }
    
    else if(choice == 'B' || choice == 'b')
    {
      User user2;
      cout << "\nWhat is your first name? ";
      cin >> fName;
      
      dataFile.open("users.txt", ios::in);
      string input;
      while(dataFile >> input)
      {
        if (input == fName)
        {
          //dataFile >> fName;
          dataFile >> lName;
          user2.setFirstName(input);
          user2.setLastName(lName);
        }
        else
        {
          cout << "No user found.\n";
          dataFile.close();
        }
      }
      
      if(user2.getLastName() != "Doe")
      {
        cout << "Welcome back " << user2.getFirstName() << " " << user2.getLastName() << endl;
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