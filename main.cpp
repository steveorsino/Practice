/*
  Pratice program to refresh
*/

#include "User.h"
#include "Journal.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

int main()
{
  //User user1;
  string uName, fName, lName;
  string input;
  fstream dataFile;
  char choice;
  
  
  
  do {
    
    cout << "Main Menu\n"
        << "\tA. Create a user\n"
        << "\tB. Sign in with username\n"
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
              
              char choice3;
              
              do {
                
                cout << "Journal menu: \n"
                    << "\tA. Update entry\n"
                    << "\tB. Delete entry\n"
                    << "\tC. Exit\n"
                    << "Enter your choice: ";
                cin >> choice3;
                
                if (choice3 == 'A' || choice3 == 'a')
                {
                  cout << "\nUpdate function comming soon!\n";
                }
                else if (choice3 == 'B' || choice3 == 'b')
                {
                  vector<string> entries;
                  vector<string> remainingEntries;
                  journalFile.open("journals.txt", ios::in);
                  
                  journalcount = 0;
                  while (getline(journalFile, jInput))
                  {
                    entries.push_back(jInput);
                    //cout << entries[journalcount] << endl;
                    journalcount++;
                  }
                  
                  journalFile.close();
                  
                  for(int i = 0; i < entries.size(); i += 4)
                  {
                    if (entries[i] == user2.getUserName())
                    {
                      cout << "Username: " << entries[i] << endl;
                      cout << "Title: " << entries[i + 1] << endl;
                      cout << "Body: " << entries[i + 2] << endl;
                      cout << "When entered: " << entries[i + 3] << endl << endl;
                    }
                  }
                  
                  cin.ignore();
                  string delTitle;
                  cout << "\nEnter the title of the entry you wish to delete: ";
                  getline(cin, delTitle);
                  //cout << entries.size() << endl;
                  cout << "deleting: " <<delTitle << endl;
                  
                  for(int i = 1; i < entries.size(); i+=4)
                  {
                    
                    //cout << "IN FOR LOOP " << i <<"\n";
                    if (entries[i] != delTitle )
                      {
                        /*
                        cout << "IN IF STATEMENT\n";
                        cout << entries[i - 1] << endl;
                        cout << entries[i] << endl;
                        cout << entries[i + 1] << endl;
                        cout << entries[i + 2] << endl;
                        */
                        remainingEntries.push_back(entries[i - 1]);
                        remainingEntries.push_back(entries[i]);
                        remainingEntries.push_back(entries[i + 1]);
                        remainingEntries.push_back(entries[i + 2]);
                      }
                    //cout << "\nAFTER IF\n\n";
                  }
                  
                  /*
                  need to install c++ 11 into workspace
                  for (string val : remainingEntries)
                    {
                      cout << val << endl;
                    }
                  */
                  
                  for(int i = 0; i < remainingEntries.size(); i += 4)
                  {
                    if (remainingEntries[i] == user2.getUserName())
                    {
                      cout << "Username: " << remainingEntries[i] << endl;
                      cout << "Title: " << remainingEntries[i + 1] << endl;
                      cout << "Body: " << remainingEntries[i + 2] << endl;
                      cout << "When entered: " << remainingEntries[i + 3] << endl << endl;
                    }
                  }
                  
                  journalFile.open("journals.txt", ios::out);
                  
                  for (int i = 0; i < remainingEntries.size(); i++)
                  {
                    journalFile << remainingEntries[i] << endl;
                  }
                  
                  journalFile.close();
                  
                  
                }
                else if (choice3 == 'C' || choice3 == 'c')
                {
                  cout << "\nBack to user menu\n";
                }
                else {
                  cout << "\nInvalid entry.\n";
                }
                
              } while (choice3 != 'C' && choice3 != 'c');
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