/*
  Pratice program
*/

#include "User.h"
#include "Journal.h"
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
      Journal journal1;
      string jTitle, jBody;
      int journalcount = 0;
      cout << journal1.getTime() << endl;
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
          
          
          
          /*
          Journal *userJournals[journalcount];
          
          journalFile.open("journals.txt", ios::in);
          journalcount = 0;
          
          while(journalfile >> jInput)
          {
            if(jInput == user2.getUserName())
            {
              userJournals[journalcount]->setUserName(jInput);
              journalFile >> jInput;
              userJournals[journalcount]->setTitle(jInput);
              journalFile >> jInput;
              userJournals[journalcount]->setBody(jInput);
              user2.setJournals(userJournals);
              journalcount++;
            }
          }
          journalFile.close();
          */
          
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
      
      fstream journalFile;
      journalFile.open("journals.txt", ios::in);
      journalcount = 0;
      string jInput;
      
      if(!journalFile)
      {
        cout << "\nERROR\n";
      }
      
      while(journalFile >> jInput)
      {
        if(jInput == user2.getUserName())
        {
          journalcount++;
        }
      }
      journalFile.close();
      
      cout << "\nYou have " << journalcount << " journal entries.\n";
      
      char choice2;
      do {

        cout << "What would you like to do today, " << user2.getFirstName() << "?\n";
        cout << "\tA. create a new journal entry\n"
              << "\tB. Display your entries\n"
              << "\tC. Exit\n"
              << "Enter your choice: ";
        cin >> choice2;
        
        if (choice2 == 'A' || choice2 == 'a')
        {
          cin.ignore();
          cout << "Enter a ttile for your new Journal entry: ";
          getline(cin, jTitle);
          cout << "Enter the body of your new Journal entry: ";
          getline(cin, jBody);
          
          cout << "Title: " << jTitle << endl;
          cout << "Body: " << jBody << endl;
          
          journal1.setUserName(user2.getUserName());
          journal1.setTitle(jTitle);
          journal1.setBody(jBody);
          
          journalFile.open("journals.txt", ios::app);
          journalFile << journal1.getUser() << endl;
          journalFile << journal1.getTitle() << endl;
          journalFile << journal1.getBody() << endl;
          journalFile << journal1.getTime() << endl;
          journalFile.close();
        }
        
        else if (choice2 == 'B' || choice2 == 'b')
        {
           cin.ignore();
           journalFile.open("journals.txt", ios::in);
           while(getline(journalFile,jInput))
            {
              if(jInput == user2.getUserName())
              {
                cout << "User: " << jInput << endl;
                getline(journalFile,jInput);
                cout << "Title: " << jInput << endl;
                getline(journalFile,jInput);
                cout <<"Body: " << jInput << endl;
                journalFile >> jInput;
                cout << "Timestamp: " << jInput << endl << endl; 
                //cin.ignore();
              }
            }
            journalFile.close();
        }
        
        else if (choice2 == 'C' || choice2 == 'c')
        {
          cout << "Back to main menu.\n";
        }
        
        else
        {
          cout << "Invalid choice.\n\n";
        }
        
      } while (choice2 != 'C' && choice2 != 'c');
      
      
      
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