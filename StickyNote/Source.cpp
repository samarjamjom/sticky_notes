#include <iostream>
#include <string>
#include <fstream>
#include<time.h>
using namespace std;
//function returns the current time in 'day of the week' 'month' 'day of the month' Houre:Minutes:Seconds 'year'
string GetTime() {
	// declaring argument of time() 
	time_t my_time = time(NULL);

	// ctime() used to give the present time 
	return ctime(&my_time);
}

int main()
{
	bool work ; // to find out if user need to return to main menu

	do
	{
		work = false;
		system("cls"); //to clear the screen every time
		cout << "Welcome to the brand new "<<"Sticky Notes! \n"
			<< "Here is the list of operation this program offers:\n\n"
			<<"1- Add new user\n"
			<<"2- Add new note\n"
			<<"3- View notes for a specific user\n"
			<<"4- Exit\n\n";

		cout << "Please Enter Your Choice \n";
		int choice;
		cin >> choice ;
		
		switch (choice )
		{

		case 1:
			{
			cout << "Welcome aboard new user!\n"
				 << "Please let me know your first name: \n";
				string FirstName;
				cin >> FirstName;
				cout << "now please enter your last name: \n";
				string LastName;
				cin >> LastName;
				cout << "Nice to meet you "<< FirstName << " " <<LastName << endl;

				ofstream fout;
				fout.open( FirstName + LastName + ".txt");
				fout.close();

				cout << "Please Click Enter to return to main menu \n";
				cin.get();
				if (cin.get() == '\n')
					work = true;

			}
			break;

		case 2:
			{
				cout << "Let's add a new note ..."
				<< "Please enter your full name \nFirst name:";
				string FirstName,LastName;
				cin >> FirstName ;
				cout << "Last name: ";
				cin>> LastName;
				cin.get();

				//input stream only for check out if file exist or not
				ifstream fin;
				fin.open( FirstName + LastName + ".txt");

				if(!fin)
				{
					cout <<" Oh! Sorry the user name was not found,\n"
						<<"please check the name again and if this is your first time here,\n";
				}

				else
				{
					int x = 0;
					fin.close();
					cout << "Your record is found, I'm now opening your file ...\n";
					string NoteLine;

					//declaring a stream to print the note on the file
					ofstream PrintToFile;

					//open output stream to append content on it "just add to end of note file"
					PrintToFile.open(FirstName + LastName + ".txt", ios::app );

					PrintToFile <<GetTime();
					cout << "Ready!\n"
						<< "Please enter your note to stop enter '##' :\n";
					//cin.get();
					getline(cin, NoteLine);
					while (NoteLine != "##")
					{
						PrintToFile << NoteLine << "\n";
						getline(cin, NoteLine);
					}
					PrintToFile <<"\n";
					PrintToFile.close(); //closing the file
				}

				cout << "Please Click Enter to return to main menu \n";	
				//cin.get();
				if (cin.get() == '\n')
					work = true;
				}	

			break;

		case 3:
			{
				cout << "Retrieve your notes? Absolutely!\n "
				<<"Please enter your full name \nFirst name:";
				string FirstName,LastName;
				cin >> FirstName ;
				cout << "Last name: ";
				cin>> LastName;

				ifstream fin;
				fin.open(FirstName + LastName + ".txt");

				if(fin)
				{
					cout << "Found it!\n"
					<<"Here are your stored notes: \n";
					string str;
					
					while(getline(fin , str))
					cout << str <<endl;

					fin.close();
				}

				else
					cout << "Umm, can’t find any saved notes for you.\n";
			
				cout << "Please Click Enter to return to main menu \n";	
				cin.get();
				if (cin.get() == '\n')
					work = true;
			}
			break;

		case 4:
			return 0;

		}
	
	}while(work);

system ("pause");
return 0;
}