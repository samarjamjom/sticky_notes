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
//to clear the screen before moving to next step
system("cls");
switch (choice )
{

case 1: //this case is used to add a note file for the user
	{
	cout << "Welcome aboard new user!\n"
	     << "Please let me know your first name: \n";
		string FirstName;
		cin >> FirstName;
		cout << "now please enter your last name: \n";
		string LastName;
		cin >> LastName;
		ofstream fout;
		fout.open(FirstName + LastName + ".txt");
		//check if the user already have a note file
		if (fout) {
			cout << FirstName << " " << LastName << " you already have a note file!";
		}
		else {
			cout << "Nice to meet you " << FirstName << " " << LastName << endl;
			fout.close();
		}
		cout << "Please Click Enter to return to main menu \n \n";
		cin.get();
		if (cin.get() == '\n')
			work = true;

	}
	break;

case 2: //this case is used to add new notes
	{
	cout << "Let's add a new note ..."
		<< "Please enter your full name \nFirst name:";
	string FirstName,LastName;
	cin >> FirstName ;
	cout << "Last name: ";
	cin>> LastName;

	//declaring a stream to print the note the file
	ofstream PrintToFile;
	//std::fstream::in | std::fstream::out | std::fstream::app is added so the file keeps its previous cpntent
	PrintToFile.open(FirstName + LastName + ".txt", std::fstream::in | std::fstream::out | std::fstream::app);

	//check if the user have a note file if not error message appears
	if (!PrintToFile){
		cout << "Oh! Sorry the user name was not found, please check the name again and if this is your first time here,\n"
			<< " please go ahead and create a new user from the main menu ...";
		}
	else {
		cout << "Your record is found, I'm now opening your file ….\n";
		string NoteLine;
		PrintToFile <<GetTime()<<"\n";
		cout << "Ready!\n"
			<< "Please enter your note to stop enter '##' :\n";
		getline(cin, NoteLine);
		while (NoteLine != "##") {
			PrintToFile << NoteLine << "\n";
			getline(cin, NoteLine);
		}
		}
	PrintToFile.close(); //closing the file
	cout << "Please Click Enter to return to main menu";
	cin.get();
	if (cin.get() == '\n')
		work = true;
	}	

	break;



case 3:



	break;



case 4:
	{
	return 0;
	}


	break;
}
	
	}while(work);

system ("pause");
return 0;
}