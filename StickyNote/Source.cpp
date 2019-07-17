#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
	bool work ; // to find out if user need to return to main menu

	do
	{
	work = false;
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

		cout << "Please Click Enter to return to main menu \n \n";
		cin.get();
		if (cin.get() == '\n')
			work = true;

	}
	break;

case 2:




	break;



case 3:



	break;



case 4:



	break;
}
	
	}while(work);

system ("pause");
return 0;
}