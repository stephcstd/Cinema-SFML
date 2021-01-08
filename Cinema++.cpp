/// HEADERS
#include "Cinema++.h"
#include "iostream"
#include "SFML/Graphics.hpp"
#include "vector"
#include "fstream"
#include "windows.h"
#include "conio.h"

using namespace std;

/// STRUCTURE DECLARATION
struct Customer
{
    string seat;
};

struct updateDetailConstants
{
    string title,price;
    string moviePosterFile;
};

struct updateDateConstants
{
    string DateDuration;
    string DATE1,DATE2,DATE3,DATE4,DATE5,DATE6,DATE7;
    string DATE8,DATE9,DATE10,DATE11,DATE12,DATE13,DATE14;
    string sTime1,sTime2,sTime3;
};

/// GLOBAL DECLARATION
struct Customer customerData[100];
struct updateDetailConstants Details[100];
struct updateDateConstants Dates;
int customerInDatabase;

string textFileName;
string textFileNameMovie;
string textFileNameDate;
string textFileNameTime;

/// USER DEFINED FUNCTIONS
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void requireEnter()
{
    char enter;
    cout << "\t\t\t PRESS ENTER TO PROCEED..." << endl;
    enter = _getch();

    while(enter != 13)
    {
        enter = _getch();
    }
}

void headerDisplay()
{
    gotoxy(25,2); cout << "\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\t\t\t\t\t\t\xDB2\xDB2\t       \xDB2\xDB2" << endl;
    gotoxy(23,3); cout << "\xDB2\xDB2                       ____         \t\t\t\xDB2\xDB2\t       \xDB2\xDB2" << endl;
    gotoxy(23,4); cout << "\xDB2\xDB2\t    || ||\\  || ||     ||\\    /||   //\\" << "\\\t\t\xDB2\xDB2\t       \xDB2\xDB2" << endl;
    gotoxy(23,5); cout << "\xDB2\xDB2\t    || || \\ || ||---  || \\  / ||  //__\\" << "\\  \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2 \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2" << endl;
    gotoxy(23,6); cout << "\xDB2\xDB2\t    || ||  \\|| ||___  ||  \\/  || //    \\" << "\\\t\xDB2\xDB2\t       \xDB2\xDB2" << endl;
    gotoxy(23,7); cout << "\xDB2\xDB2                                \t\t\t\xDB2\xDB2\t       \xDB2\xDB2" << endl;
    gotoxy(25,8); cout << "\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\t\t\t\t\t\t\xDB2\xDB2\t       \xDB2\xDB2" << endl;
}

/// SYSTEM UPDATE SUB-FUNCTIONS
void updateDateDetails();
void updateMovieDetails();
void loadDetailsFromFile();
void saveDetailsToFile();
void editDatesInput();
void editDetailsInput(int c);
void viewDetails();
void submitEditDates();
void submitEditDetails(int c);

/// CUSTOMER SEAT UPDATE FUNCTION
void saveUpdateSeatToFile(string fileName);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Cinema::systemUpdate()
{
  char command;
    loadDetailsFromFile();

     START:
       headerDisplay();
       gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
       gotoxy(20,26); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
       gotoxy(47,14); cout << "*** S Y S T E M  U P D A T E ***" << endl;

       gotoxy(47,16);cout<<"[1] Update Showing Dates and Time"<< endl;
       gotoxy(47,18);cout<<"[2] Update Movie Details"<< endl;
       gotoxy(47,20);cout<<"[3] Show Movie Details"<< endl;
       gotoxy(47,22);cout<<"Your Choice: ";
       gotoxy(60,22);cin >>command;

  switch(command)
   {
   case '1':
         system ("cls");
         updateDateDetails();
          break;


   case '2':
         system("cls");
         updateMovieDetails();
         break;

   case '3':
         system("cls");
         viewDetails();
         break;


   default:
         system("cls");
         goto START;

   }
}

void loadDetailsFromFile()
{
    ifstream file("systemUpdate.txt");

    int i;

	if(file.is_open())
	{
        do   {

        file >> Dates.DateDuration;
        file >> Dates.DATE1;
        file >> Dates.DATE2;
        file >> Dates.DATE3;
        file >> Dates.DATE4;
        file >> Dates.DATE5;
        file >> Dates.DATE6;
        file >> Dates.DATE7;
        file >> Dates.DATE8;
        file >> Dates.DATE9;
        file >> Dates.DATE10;
        file >> Dates.DATE11;
        file >> Dates.DATE12;
        file >> Dates.DATE13;
        file >> Dates.DATE14;

        file >> Dates.sTime1;
        file >> Dates.sTime2;
        file >> Dates.sTime3;


        for (i=0;i<3;i++)
        {
            file >> Details[i].title;
            file >> Details[i].price;
            file >> Details[i].moviePosterFile;
        }
			}while(!file.eof());
		}
    else
    {
			cout << "Database is empty" << endl;
    }

}


void saveDetailsToFile()
{
    ofstream file("systemUpdate.txt");

    int i;

	if(file.is_open())
    {
            file << Dates.DateDuration<<endl;
            file << Dates.DATE1<<endl;
            file << Dates.DATE2<<endl;
            file << Dates.DATE3<<endl;
            file << Dates.DATE4<<endl;
            file << Dates.DATE5<<endl;
            file << Dates.DATE6<<endl;
            file << Dates.DATE7<<endl;
            file << Dates.DATE8<<endl;
            file << Dates.DATE9<<endl;
            file << Dates.DATE10<<endl;
            file << Dates.DATE11<<endl;
            file << Dates.DATE12<<endl;
            file << Dates.DATE13<<endl;
            file << Dates.DATE14<<endl;
            file << endl;
            file << Dates.sTime1<<endl;
            file << Dates.sTime2<<endl;
            file << Dates.sTime3<<endl;

        for (i=0;i<3;i++)
        {
            file << Details[i].title<<endl;
            file << Details[i].price<<endl;
            file << Details[i].moviePosterFile<<endl;
            file << endl;
        }

        file.close();
    }
    else
    {
        cout << "CAN'T SAVE TO DATABASE!!!" << endl;
    }
}

void updateDateDetails()
{

    loadDetailsFromFile();

    headerDisplay();
    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(47,14); cout <<"*** S H O W I N G  D A T E S & T I M E ***"<<endl;

    //Date Duration
    gotoxy(35,16); cout <<"Enter Date Duration following this format: Jan/1-14/2019"<<endl;
    gotoxy(35,18); cout <<"Date Duration: ";
    gotoxy(50,18); cin  >> Dates.DateDuration;


    //Dates
    gotoxy(35,20); cout <<"Enter Dates following this format: Jan-01-2019"<<endl;
    gotoxy(45,22); cout<<"Enter 1st Date: ";
    gotoxy(61,22); cin>>Dates.DATE1;
    gotoxy(45,24); cout<<"Enter 2nd Date: ";
    gotoxy(61,24); cin>>Dates.DATE2;
    gotoxy(45,26); cout<<"Enter 3rd Date: ";
    gotoxy(61,26); cin>>Dates.DATE3;
    gotoxy(45,28); cout<<"Enter 4th Date: ";
    gotoxy(61,28); cin>>Dates.DATE4;
    gotoxy(45,30); cout<<"Enter 5th Date: ";
    gotoxy(61,30); cin>>Dates.DATE5;
    gotoxy(45,32); cout<<"Enter 6th Date: ";
    gotoxy(61,32); cin>>Dates.DATE6;
    gotoxy(45,34); cout<<"Enter 7th Date: ";
    gotoxy(61,34); cin>>Dates.DATE7;
    gotoxy(45,36); cout<<"Enter 8th Date: ";
    gotoxy(61,36); cin>>Dates.DATE8;
    gotoxy(45,38); cout<<"Enter 9th Date: ";
    gotoxy(61,38); cin>>Dates.DATE9;
    gotoxy(45,40); cout<<"Enter 10th Date: ";
    gotoxy(62,40); cin>>Dates.DATE10;
    gotoxy(45,42); cout<<"Enter 11th Date: ";
    gotoxy(62,42); cin>>Dates.DATE11;
    gotoxy(45,44); cout<<"Enter 12th Date: ";
    gotoxy(62,44); cin>>Dates.DATE12;
    gotoxy(45,46); cout<<"Enter 13th Date: ";
    gotoxy(62,46); cin>>Dates.DATE13;
    gotoxy(45,48); cout<<"Enter 14th Date: ";
    gotoxy(62,48); cin>>Dates.DATE14;


    //Time Slot
    gotoxy(35,50); cout<<"Enter Time Slot following this format: [1pm-3pm]"<<endl;
    gotoxy(42,52); cout<<"Enter Time Slot 1: ";
    gotoxy(61,52); cin>>Dates.sTime1;
    gotoxy(42,54); cout<<"Enter Time Slot 2: ";
    gotoxy(61,54); cin>>Dates.sTime2;
    gotoxy(42,56); cout<<"Enter Time Slot 3: ";
    gotoxy(61,56); cin>>Dates.sTime3;

    gotoxy(42,58); cout<<"Press ENTER TO PROCEED: ";
    gotoxy(20,60); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(66,58); _getch();

    system("cls");
    submitEditDates();

}

void submitEditDates()
{

    char command;

    SubmitEdit:
    headerDisplay();
    gotoxy(20,10); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(20,24); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(50,12); cout <<"*** E D I T  D E T A I L S ***" <<endl;

    gotoxy(59,14); cout<<"[1] SUBMIT "<< endl;
    gotoxy(59,16); cout<<"[2] EDIT"<< endl;
    gotoxy(50,18); cout<<"Your Choice: "<< endl;
    gotoxy(63,18); cin>>command;

    switch(command)
    {
    case '1':
         saveDetailsToFile();
         gotoxy(50,20); cout<<"SHOWING DATE and Time are UPDATED"<<endl;
         gotoxy(50,22); cout<<"PRESS ENTER TO PROCEED: ";
         gotoxy(74,22); _getch();
         system("cls");
         break;

    case '2':
         system("cls");
         editDatesInput();
         system ("cls");
         break;

    default:
         system("cls");
         goto SubmitEdit;
         break;
     }

}

void editDatesInput()
{
   string dateCommand;
   char timeCommand;
   char editChoice;

   EditOption:
    headerDisplay();
    gotoxy(20,10); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(49,12); cout <<"*** E D I T  D E T A I L S ***" <<endl;
    gotoxy(20,30); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;


    gotoxy(47,14); cout<<"What SECTION do you want to EDIT?" <<endl;
    gotoxy(56,16); cout<<"[1] Date Duration" <<endl;
    gotoxy(56,18); cout<<"[2] Showing Dates" <<endl;
    gotoxy(56,20); cout<<"[3] Time Slot" <<endl;
    gotoxy(50,22); cout<<"Enter your command: " <<endl;
    gotoxy(70,22); cin>>editChoice;


    switch(editChoice)
    {
    case '1':
        gotoxy(35,24); cout <<"Enter Date Duration following this format: Jan/1-14/2019"<<endl;
        gotoxy(37,26); cout <<"Date Duration: ";
        gotoxy(52,26); cin >> Dates.DateDuration;
        system("cls");
        submitEditDates();
        break;

    case '2':
       DateOption:
        system("cls");
        headerDisplay();
        gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
        gotoxy(20,24); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
        gotoxy(49,14); cout <<"*** E D I T  D E T A I L S ***" <<endl;
        gotoxy(35,16); cout << "Which Date do you want to edit? 1-14: "<<endl;
        gotoxy(73,16); cin >>dateCommand;


	if (dateCommand == "1")
	{
		    gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 1st Date: ";
            gotoxy(61,20); cin>>Dates.DATE1;
            system("cls");
            submitEditDates();
        }
	else if(dateCommand == "2")
	{
		    gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 2nd Date: ";
            gotoxy(61,20); cin>>Dates.DATE2;
            system("cls");
            submitEditDates();
	}

	else if(dateCommand == "3")
	{
		    gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 3rd Date: ";
            gotoxy(61,20); cin>>Dates.DATE3;
            system("cls");
            submitEditDates();
	}

	else if(dateCommand == "4")
	{
		    gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 4th Date: ";
            gotoxy(61,20); cin>>Dates.DATE4;
            system("cls");
            submitEditDates();
	}

	else if(dateCommand == "5")
	{
		    gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 5th Date: ";
            gotoxy(61,20); cin>>Dates.DATE5;
            system("cls");
            submitEditDates();
	}


	else if(dateCommand == "6")
	{
		    gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 6th Date: ";
            gotoxy(61,20); cin>>Dates.DATE6;
            system("cls");
            submitEditDates();
	}

	else if(dateCommand == "7")
	{
		    gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 7th Date: ";
            gotoxy(61,20); cin>>Dates.DATE7;
            system("cls");
            submitEditDates();

	}
	else if(dateCommand == "8")

	{
		    gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 8th Date: ";
            gotoxy(61,20); cin>>Dates.DATE8;
            system("cls");
            submitEditDates();
	}

	else if(dateCommand == "9")
	{
		    gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 9th Date: ";
            gotoxy(61,20); cin>>Dates.DATE9;
            system("cls");
            submitEditDates();
	}


	else if (dateCommand == "10")
	{

            gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 10th Date: ";
            gotoxy(62,20); cin>>Dates.DATE10;
            system("cls");
            submitEditDates();
	}

	else if(dateCommand == "11")
	{

 		    gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 11th Date: ";
            gotoxy(62,20); cin>>Dates.DATE11;
            system("cls");
            submitEditDates();
	}

	else if(dateCommand == "12")
	{
		    gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 12th Date: ";
            gotoxy(62,20); cin>>Dates.DATE12;
            system("cls");
            submitEditDates();
	}

	else if(dateCommand == "13")
	{
            gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 13th Date: ";
            gotoxy(62,20); cin>>Dates.DATE13;
            system("cls");
            submitEditDates();
	}

	else if(dateCommand == "14")
	{
            gotoxy(35,18); cout <<"Enter dates following this format: Jan-01-2019"<<endl;
            gotoxy(45,20); cout<<"Enter 14th Date: ";
            gotoxy(62,20); cin>>Dates.DATE14;
            system("cls");
            submitEditDates();
	}

	else
	{
		goto DateOption;
	}

    break;


    case '3':
       TimeOption:
        system("cls");
        headerDisplay();
        gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
        gotoxy(20,24); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
        gotoxy(49,14); cout <<"*** E D I T  D E T A I L S ***" <<endl;
        gotoxy(35,16); cout <<"Which Time Slot do you want to edit? 1-3: "<<endl;
        gotoxy(77,16); cin >>timeCommand;

        switch(timeCommand)
        {
            case '1':
                gotoxy(40,18); cout<<"Enter Time Slot following this format: [1pm-3pm]"<<endl;
                gotoxy(42,20); cout<<"Enter Time Slot 1: ";
                gotoxy(61,20); cin>>Dates.sTime1;
                system("cls");
                submitEditDates();
                break;

            case '2':
                gotoxy(40,18); cout<<"Enter Time Slot following this format: [1pm-3pm]"<<endl;
                gotoxy(42,20); cout<<"Enter Time Slot 2: ";
                gotoxy(61,20); cin>>Dates.sTime2;
                system("cls");
                submitEditDates();
                break;

            case '3':
                gotoxy(40,18); cout<<"Enter Time Slot following this format: [1pm-3pm]"<<endl;
                gotoxy(42,20); cout<<"Enter Time Slot 3: ";
                gotoxy(61,20); cin>>Dates.sTime3;
                system("cls");
                submitEditDates();
                break;

            default:
                goto TimeOption;
                break;
        }
        break;


    default:
        system ("cls");
        goto EditOption;
    }

}

void updateMovieDetails()
{
    int i;

    for (i=0;i<3;i++)
    {

        headerDisplay();
        gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
        gotoxy(49,14); cout <<"*** M O V I E   D E T A I L S ***" <<endl;
        gotoxy(20,25); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;


        gotoxy(45,16); cout<<"Enter Title of Movie "<<i+1<<": "<<endl;
        gotoxy(69,16); cin>>Details[i].title;
        gotoxy(45,18); cout<<"Enter Price: "<<endl;
        gotoxy(58,18); cin>>Details[i].price;
        gotoxy(45,20); cout<<"Type Movie Poster File Name following this format (source/filename.format) "<<endl;
        gotoxy(45,21); cout<<"Example. source/Birdbox.jpg  : ";
        gotoxy(76,21); cin>>Details[i].moviePosterFile;
        system("cls");
        submitEditDetails(i);

    }

}


void submitEditDetails(int c)
{
    char command[3];

    SubmitEdit:
     headerDisplay();
     gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
     gotoxy(20,28); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
     gotoxy(50,14); cout <<"*** E D I T  D E T A I L S ***" <<endl;

     gotoxy(59,16); cout<<"[1] SUBMIT "<< endl;
     gotoxy(59,18); cout<<"[2] EDIT"<< endl;
     gotoxy(50,20); cout<<"Your Choice: "<< endl;
     gotoxy(63,20); cin>>command[c];


    switch(command[c])
    {
        case '1':
             saveDetailsToFile();
             gotoxy(53,22); cout<<"PRESS ENTER TO PROCEED:";
             gotoxy(77,22); _getch();
             system("cls");
             break;

        case '2':
             system("cls");
             editDetailsInput(c);
             system ("cls");
             break;

        default:
            system ("cls");
            goto SubmitEdit;
            break;

     }

     system("cls");
}



void editDetailsInput(int c)
{

    char editCommand[3];

    EditOption:

      headerDisplay();
      gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
      gotoxy(20,31); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
      gotoxy(50,14); cout <<"*** E D I T  D E T A I L S ***" <<endl;

      gotoxy(45,16); cout<<"What section do you want to update?"<<endl;
      gotoxy(55,18); cout<<"[1] TITLE"<<endl;
      gotoxy(55,20); cout<<"[2] PRICE"<<endl;
      gotoxy(55,22); cout<<"[3] MOVIE POSTER FILE"<<endl;
      gotoxy(50,24); cout<<"Your Choice: ";
      gotoxy(63,24); cin>>editCommand[c];


     switch (editCommand[c])
        {
            case '1':
               gotoxy(45,26); cout<<"Enter Title of Movie "<<c+1<<": "<<endl;
               gotoxy(69,26);cin>>Details[c].title;
               system("cls");
               submitEditDetails(c);
               break;

            case '2':
               gotoxy(45,26); cout<<"Enter Price: "<<endl;
               gotoxy(57,26); cin>>Details[c].price;
               system("cls");
               submitEditDetails(c);
               break;


            case '3':
                gotoxy(45,26); cout<<"Type Movie Poster File Name following this format (source/filename.format) "<<endl;
                gotoxy(45,27); cout<<"Example. source/Birdbox.jpg  : ";
                gotoxy(75,27); cin >>Details[c].moviePosterFile;
                system("cls");
                submitEditDetails(c);
                break;

           default:
               system("cls");
               goto EditOption;
               break;
        }

}

void viewDetails()
{

      loadDetailsFromFile();

      headerDisplay();
      gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
      gotoxy(48,14); cout <<"*** M O V I E  D E T A I L S ***" <<endl;

      gotoxy(48,16); cout <<"|Date Duration|: " <<Dates.DateDuration <<endl;
      gotoxy(48,18); cout <<"|Time Slot 1|: " <<Dates.sTime1 <<endl;
      gotoxy(48,20); cout <<"|Time Slot 2|: " <<Dates.sTime2 <<endl;
      gotoxy(48,22); cout <<"|Time Slot 3|: " <<Dates.sTime3 <<endl;

      for(int i=0;i<3;i++)
      {
          cout<<"\n\n\t\t\t\t\t        |Movie " <<i+1 <<" Title|: " << Details[i].title <<endl;
          cout<<"\n\t\t\t\t\t        |Price|: "<< Details[i].price <<endl;
          cout<<"\n\t\t\t\t\t        |Movie Poster File Name|: "<<Details[i].moviePosterFile <<endl;
      }

      gotoxy(42,46); cout<<"Press ENTER TO GO BACK: ";
      gotoxy(20,48); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
      gotoxy(66,46); _getch();

      system("cls");

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///RESERVATION SUB-FUNCTIONS
void loadCustomerFromFile(string fileName)
{
    ifstream file("Database/"+fileName);

    if(file.is_open())
    {
        file >> customerInDatabase;

        if(customerInDatabase > 0)
        {
            int i = 0;

            do
            {
                file >> (customerData+i)->seat;

                i++;

            }while(!file.eof());

            file.close();
        }
        else
        {
            cout << "Database is empty" << endl;
        }
    }
    else
    {
        cout << "The file doesn't exists" << endl;
        customerInDatabase = 0;
    }
}

void saveCustomerToFile(int quanti, string fileName)
{
    customerInDatabase += quanti + 1;

    ofstream file("Database/"+fileName);

    if(file.is_open())
    {
        file << customerInDatabase << endl;

        for(int i = 0; i<customerInDatabase; i++)
        {
            file << (customerData+i)->seat << endl;
        }

        file.close();
    }
    else
    {
        cout << "CAN'T SAVE TO DATABASE!!!" << endl;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Cinema::mainmenu()
{
    /// WINDOW CONFIG
    sf::RenderWindow window(sf::VideoMode(950,700), "C I N E M A  + +", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    /// IMAGE
    sf::Texture menuBackground;
    menuBackground.loadFromFile("source/ReservingMenu.png");

    sf::Sprite spriteMenuBackground(menuBackground);
    spriteMenuBackground.setPosition(0,0);

    /// FONT
    sf::Font menuFont;
    menuFont.loadFromFile("source/urbandefender.ttf");

    /// MENU OPTIONS
    sf::Text startReservation("START RESERVATION", menuFont, 35);
    startReservation.setColor(sf::Color::White);
    startReservation.setPosition(320,470);

    /// Rectangle Button Option
    sf::RectangleShape rectStartReservation(sf::Vector2f(380 ,65));
    rectStartReservation.setFillColor(sf::Color::Blue);
    rectStartReservation.setPosition(285,460);

	while (window.isOpen())
    {
        sf::Event customerChoiceMenu;

        while (window.pollEvent(customerChoiceMenu))
        {
            /// WINDOW TERMINATOR
            if (customerChoiceMenu.type == sf::Event::Closed)
                window.close();

            /// MAINMENU CHOICE BY MOUSE
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::FloatRect rectStartReservationPos = rectStartReservation.getGlobalBounds();

            /// BORDER INDEX COLOR
            if(rectStartReservationPos.contains(mousePos.x,mousePos.y))
                rectStartReservation.setFillColor(sf::Color::Red);
            else
                rectStartReservation.setFillColor(sf::Color::Blue);

            if (customerChoiceMenu.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceMenu.mouseButton.button == sf::Mouse::Left && rectStartReservationPos.contains(mousePos.x,mousePos.y))
                {
                    window.close();
                    movieChoice();
                }
            }
        }

        window.draw(spriteMenuBackground);
        window.draw(rectStartReservation);
        window.draw(startReservation);
        window.display();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Cinema::movieChoice()
{
    loadDetailsFromFile();

    string movie1 = Details[0].title;
    string movie2 = Details[1].title;
    string movie3 = Details[2].title;

    string detail1 = "\t\t\t\t\t\t  " + Details[0].price + "\n" + "\t\t\t   " + Dates.DateDuration;
    string detail2 = "\t\t\t\t\t\t  " + Details[1].price + "\n" + "\t\t\t\t" +  Dates.DateDuration;
    string detail3 = "\t\t\t\t\t\t  " + Details[2].price + "\n" + "\t\t\t\t" + Dates.DateDuration;

    string posterFileNameMovie1 = Details[0].moviePosterFile;
    string posterFileNameMovie2 = Details[1].moviePosterFile;
    string posterFileNameMovie3 = Details[2].moviePosterFile;

    string tempTextFileNameMovie1 = "[" + movie1 +"]-";
    string tempTextFileNameMovie2 = "[" + movie2 +"]-";
    string tempTextFileNameMovie3 = "[" + movie3 +"]-";

    /// WINDOW CONFIG
    sf::RenderWindow window(sf::VideoMode(950,700), "C I N E M A  + +", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    /// IMAGE
    sf::Texture movieBackground,moviePoster1,moviePoster2,moviePoster3;
    movieBackground.loadFromFile("source/moviechoiceTemp.jpg");
    moviePoster1.loadFromFile(posterFileNameMovie1);
    moviePoster2.loadFromFile(posterFileNameMovie2);
    moviePoster3.loadFromFile(posterFileNameMovie3);

    sf::Sprite spriteMovieBackground(movieBackground),spriteMoviePoster1(moviePoster1),spriteMoviePoster2(moviePoster2),spriteMoviePoster3(moviePoster3);
    spriteMovieBackground.setPosition(0,0);
    spriteMoviePoster1.setPosition(43,215);
    spriteMoviePoster2.setPosition(342,215);
    spriteMoviePoster3.setPosition(645,215);

    /// FONT
    sf::Font movieFont;
    movieFont.loadFromFile("source/BebasRegular.otf");

    /// MOVIE OPTIONS
    sf::Text title1(movie1, movieFont, 35);
    title1.setColor(sf::Color::Black);
    title1.setPosition(75,160);

    sf::Text title2(movie2, movieFont, 35);
    title2.setColor(sf::Color::Black);
    title2.setPosition(380,160);

    sf::Text title3(movie3, movieFont, 35);
    title3.setColor(sf::Color::Black);
    title3.setPosition(695,160);

    sf::Text movieDetails1(detail1,movieFont,25);
    movieDetails1.setColor(sf::Color::Black);
    movieDetails1.setPosition(60,600);

    sf::Text movieDetails2(detail2,movieFont,25);
    movieDetails2.setColor(sf::Color::Black);
    movieDetails2.setPosition(350,600);

    sf::Text movieDetails3(detail3,movieFont,25);
    movieDetails3.setColor(sf::Color::Black);
    movieDetails3.setPosition(650,600);

    /// Rectangle Button Option
    sf::RectangleShape rectMovie1(sf::Vector2f(273,385));
    rectMovie1.setFillColor(sf::Color::Blue);
    rectMovie1.setPosition(38,210);

    sf::RectangleShape rectMovie2(sf::Vector2f(273,385));
    rectMovie2.setFillColor(sf::Color::Blue);
    rectMovie2.setPosition(337,210);

    sf::RectangleShape rectMovie3(sf::Vector2f(273,385));
    rectMovie3.setFillColor(sf::Color::Blue);
    rectMovie3.setPosition(640,210);

    while (window.isOpen())
    {
        sf::Event customerChoiceMovie;

        while (window.pollEvent(customerChoiceMovie))
        {
            /// WINDOW TERMINATOR
            if (customerChoiceMovie.type == sf::Event::Closed)
                window.close();

            /// MOVIE CHOICE BY MOUSE
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::FloatRect rectMovie1Pos = rectMovie1.getGlobalBounds();
            sf::FloatRect rectMovie2Pos = rectMovie2.getGlobalBounds();
            sf::FloatRect rectMovie3Pos = rectMovie3.getGlobalBounds();

            /// BORDER INDEX COLOR
            if(rectMovie1Pos.contains(mousePos.x,mousePos.y))
                rectMovie1.setFillColor(sf::Color::Red);
            else
                rectMovie1.setFillColor(sf::Color::Blue);

            if(rectMovie2Pos.contains(mousePos.x,mousePos.y))
                rectMovie2.setFillColor(sf::Color::Red);
            else
                rectMovie2.setFillColor(sf::Color::Blue);

            if(rectMovie3Pos.contains(mousePos.x,mousePos.y))
                rectMovie3.setFillColor(sf::Color::Red);
            else
                rectMovie3.setFillColor(sf::Color::Blue);

            if (customerChoiceMovie.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceMovie.mouseButton.button == sf::Mouse::Left && rectMovie1Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameMovie = tempTextFileNameMovie1;
                    window.close();
                    dateChoice();
                }

                if (customerChoiceMovie.mouseButton.button == sf::Mouse::Left && rectMovie2Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameMovie = tempTextFileNameMovie2;
                    window.close();
                    dateChoice();
                }

                if (customerChoiceMovie.mouseButton.button == sf::Mouse::Left && rectMovie3Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameMovie = tempTextFileNameMovie3;
                    window.close();
                    dateChoice();
                }
            }
        }

        window.draw(spriteMovieBackground);
        window.draw(rectMovie1);
        window.draw(rectMovie2);
        window.draw(rectMovie3);
        window.draw(spriteMoviePoster1);
        window.draw(spriteMoviePoster2);
        window.draw(spriteMoviePoster3);
        window.draw(title1);
        window.draw(title2);
        window.draw(title3);
        window.draw(movieDetails1);
        window.draw(movieDetails2);
        window.draw(movieDetails3);
        window.display();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Cinema::dateChoice()
{
    loadDetailsFromFile();

    string Date1 = Dates.DATE1;
    string Date2 = Dates.DATE2;
    string Date3 = Dates.DATE3;
    string Date4 = Dates.DATE4;
    string Date5 = Dates.DATE5;
    string Date6 = Dates.DATE6;
    string Date7 = Dates.DATE7;
    string Date8 = Dates.DATE8;
    string Date9 = Dates.DATE9;
    string Date10 = Dates.DATE10;
    string Date11 = Dates.DATE11;
    string Date12 = Dates.DATE12;
    string Date13 = Dates.DATE13;
    string Date14 = Dates.DATE14;

    string tempTextFileNameDate1 = "[" + Date1 +"]-";
    string tempTextFileNameDate2 = "[" + Date2 +"]-";
    string tempTextFileNameDate3 = "[" + Date3 +"]-";
    string tempTextFileNameDate4 = "[" + Date4 +"]-";
    string tempTextFileNameDate5 = "[" + Date5 +"]-";
    string tempTextFileNameDate6 = "[" + Date6 +"]-";
    string tempTextFileNameDate7 = "[" + Date7 +"]-";
    string tempTextFileNameDate8 = "[" + Date8 +"]-";
    string tempTextFileNameDate9 = "[" + Date9 +"]-";
    string tempTextFileNameDate10 = "[" + Date10 +"]-";
    string tempTextFileNameDate11 = "[" + Date11 +"]-";
    string tempTextFileNameDate12 = "[" + Date12 +"]-";
    string tempTextFileNameDate13 = "[" + Date13 +"]-";
    string tempTextFileNameDate14 = "[" + Date14 +"]-";


    /// WINDOW CONFIG
    sf::RenderWindow window(sf::VideoMode(950,700), "C I N E M A  + +", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    /// IMAGE
    sf::Texture dateBackground;
    dateBackground.loadFromFile("source/dateMenu.png");

    sf::Sprite spriteDateBackground(dateBackground);
    spriteDateBackground.setPosition(0,0);

    /// FONT
    sf::Font dateFont;
    dateFont.loadFromFile("source/BebasRegular.otf");

    /// DATE OPTIONS
    sf::Text date1(Date1, dateFont, 30);
    date1.setColor(sf::Color::White);
    date1.setPosition(128,235);

    sf::Text date2(Date2, dateFont, 30);
    date2.setColor(sf::Color::White);
    date2.setPosition(323,235);

    sf::Text date3(Date3, dateFont, 30);
    date3.setColor(sf::Color::White);
    date3.setPosition(518,235);

    sf::Text date4(Date4, dateFont, 30);
    date4.setColor(sf::Color::White);
    date4.setPosition(713,235);

    sf::Text date5(Date5, dateFont, 30);
    date5.setColor(sf::Color::White);
    date5.setPosition(128,335);

    sf::Text date6(Date6, dateFont, 30);
    date6.setColor(sf::Color::White);
    date6.setPosition(323,335);

    sf::Text date7(Date7, dateFont, 30);
    date7.setColor(sf::Color::White);
    date7.setPosition(518,335);

    sf::Text date8(Date8, dateFont, 30);
    date8.setColor(sf::Color::White);
    date8.setPosition(713,335);

    sf::Text date9(Date9, dateFont, 30);
    date9.setColor(sf::Color::White);
    date9.setPosition(128,430);

    sf::Text date10(Date10, dateFont, 30);
    date10.setColor(sf::Color::White);
    date10.setPosition(323,430);

    sf::Text date11(Date11, dateFont, 30);
    date11.setColor(sf::Color::White);
    date11.setPosition(518,430);

    sf::Text date12(Date12, dateFont, 30);
    date12.setColor(sf::Color::White);
    date12.setPosition(713,430);

    sf::Text date13(Date13, dateFont, 30);
    date13.setColor(sf::Color::White);
    date13.setPosition(323,525);

    sf::Text date14(Date14, dateFont, 30);
    date14.setColor(sf::Color::White);
    date14.setPosition(518,525);

    /// Rectangle Button Option
    sf::RectangleShape rectDate1(sf::Vector2f(162,72));
    rectDate1.setFillColor(sf::Color::Blue);
    rectDate1.setPosition(106,220);

    sf::RectangleShape rectDate2(sf::Vector2f(162,72));
    rectDate2.setFillColor(sf::Color::Blue);
    rectDate2.setPosition(300,220);

    sf::RectangleShape rectDate3(sf::Vector2f(162,72));
    rectDate3.setFillColor(sf::Color::Blue);
    rectDate3.setPosition(495,220);

    sf::RectangleShape rectDate4(sf::Vector2f(162,72));
    rectDate4.setFillColor(sf::Color::Blue);
    rectDate4.setPosition(690,220);

    sf::RectangleShape rectDate5(sf::Vector2f(162,72));
    rectDate5.setFillColor(sf::Color::Blue);
    rectDate5.setPosition(106,315);

    sf::RectangleShape rectDate6(sf::Vector2f(162,72));
    rectDate6.setFillColor(sf::Color::Blue);
    rectDate6.setPosition(300,315);

    sf::RectangleShape rectDate7(sf::Vector2f(162,72));
    rectDate7.setFillColor(sf::Color::Blue);
    rectDate7.setPosition(495,315);

    sf::RectangleShape rectDate8(sf::Vector2f(162,72));
    rectDate8.setFillColor(sf::Color::Blue);
    rectDate8.setPosition(690,315);

    sf::RectangleShape rectDate9(sf::Vector2f(162,72));
    rectDate9.setFillColor(sf::Color::Blue);
    rectDate9.setPosition(106,410);

    sf::RectangleShape rectDate10(sf::Vector2f(162,72));
    rectDate10.setFillColor(sf::Color::Blue);
    rectDate10.setPosition(300,410);

    sf::RectangleShape rectDate11(sf::Vector2f(162,72));
    rectDate11.setFillColor(sf::Color::Blue);
    rectDate11.setPosition(495,410);

    sf::RectangleShape rectDate12(sf::Vector2f(162,72));
    rectDate12.setFillColor(sf::Color::Blue);
    rectDate12.setPosition(690,410);

    sf::RectangleShape rectDate13(sf::Vector2f(162,72));
    rectDate13.setFillColor(sf::Color::Blue);
    rectDate13.setPosition(300,505);

    sf::RectangleShape rectDate14(sf::Vector2f(162,72));
    rectDate14.setFillColor(sf::Color::Blue);
    rectDate14.setPosition(495,505);

    while (window.isOpen())
    {
        sf::Event customerChoiceDate;

        while (window.pollEvent(customerChoiceDate))
        {
            /// WINDOW TERMINATOR
            if (customerChoiceDate.type == sf::Event::Closed)
                window.close();

            /// DATE CHOICE BY MOUSE
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::FloatRect rectDate1Pos = rectDate1.getGlobalBounds();
            sf::FloatRect rectDate2Pos = rectDate2.getGlobalBounds();
            sf::FloatRect rectDate3Pos = rectDate3.getGlobalBounds();
            sf::FloatRect rectDate4Pos = rectDate4.getGlobalBounds();
            sf::FloatRect rectDate5Pos = rectDate5.getGlobalBounds();
            sf::FloatRect rectDate6Pos = rectDate6.getGlobalBounds();
            sf::FloatRect rectDate7Pos = rectDate7.getGlobalBounds();
            sf::FloatRect rectDate8Pos = rectDate8.getGlobalBounds();
            sf::FloatRect rectDate9Pos = rectDate9.getGlobalBounds();
            sf::FloatRect rectDate10Pos = rectDate10.getGlobalBounds();
            sf::FloatRect rectDate11Pos = rectDate11.getGlobalBounds();
            sf::FloatRect rectDate12Pos = rectDate12.getGlobalBounds();
            sf::FloatRect rectDate13Pos = rectDate13.getGlobalBounds();
            sf::FloatRect rectDate14Pos = rectDate14.getGlobalBounds();

            /// BORDER INDEX COLOR
            if(rectDate1Pos.contains(mousePos.x,mousePos.y))
                rectDate1.setFillColor(sf::Color::Red);
            else
                rectDate1.setFillColor(sf::Color::Blue);

            if(rectDate2Pos.contains(mousePos.x,mousePos.y))
                rectDate2.setFillColor(sf::Color::Red);
            else
                rectDate2.setFillColor(sf::Color::Blue);

            if(rectDate3Pos.contains(mousePos.x,mousePos.y))
                rectDate3.setFillColor(sf::Color::Red);
            else
                rectDate3.setFillColor(sf::Color::Blue);

            if(rectDate4Pos.contains(mousePos.x,mousePos.y))
                rectDate4.setFillColor(sf::Color::Red);
            else
                rectDate4.setFillColor(sf::Color::Blue);

            if(rectDate5Pos.contains(mousePos.x,mousePos.y))
                rectDate5.setFillColor(sf::Color::Red);
            else
                rectDate5.setFillColor(sf::Color::Blue);

            if(rectDate6Pos.contains(mousePos.x,mousePos.y))
                rectDate6.setFillColor(sf::Color::Red);
            else
                rectDate6.setFillColor(sf::Color::Blue);

            if(rectDate7Pos.contains(mousePos.x,mousePos.y))
                rectDate7.setFillColor(sf::Color::Red);
            else
                rectDate7.setFillColor(sf::Color::Blue);

            if(rectDate8Pos.contains(mousePos.x,mousePos.y))
                rectDate8.setFillColor(sf::Color::Red);
            else
                rectDate8.setFillColor(sf::Color::Blue);

            if(rectDate9Pos.contains(mousePos.x,mousePos.y))
                rectDate9.setFillColor(sf::Color::Red);
            else
                rectDate9.setFillColor(sf::Color::Blue);

            if(rectDate10Pos.contains(mousePos.x,mousePos.y))
                rectDate10.setFillColor(sf::Color::Red);
            else
                rectDate10.setFillColor(sf::Color::Blue);

            if(rectDate11Pos.contains(mousePos.x,mousePos.y))
                rectDate11.setFillColor(sf::Color::Red);
            else
                rectDate11.setFillColor(sf::Color::Blue);

            if(rectDate12Pos.contains(mousePos.x,mousePos.y))
                rectDate12.setFillColor(sf::Color::Red);
            else
                rectDate12.setFillColor(sf::Color::Blue);

            if(rectDate13Pos.contains(mousePos.x,mousePos.y))
                rectDate13.setFillColor(sf::Color::Red);
            else
                rectDate13.setFillColor(sf::Color::Blue);

            if(rectDate14Pos.contains(mousePos.x,mousePos.y))
                rectDate14.setFillColor(sf::Color::Red);
            else
                rectDate14.setFillColor(sf::Color::Blue);

            if (customerChoiceDate.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate1Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate1;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate2Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate2;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate3Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate3;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate4Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate4;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate5Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate5;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate6Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate6;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate7Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate7;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate8Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate8;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate9Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate9;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate10Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate10;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate11Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate11;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate12Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate12;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate13Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate13;
                    window.close();
                    timeChoice();
                }

                if (customerChoiceDate.mouseButton.button == sf::Mouse::Left && rectDate14Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameDate = tempTextFileNameDate14;
                    window.close();
                    timeChoice();
                }
            }
        }

        window.draw(spriteDateBackground);
        window.draw(rectDate1);
        window.draw(rectDate2);
        window.draw(rectDate3);
        window.draw(rectDate4);
        window.draw(rectDate5);
        window.draw(rectDate6);
        window.draw(rectDate7);
        window.draw(rectDate8);
        window.draw(rectDate9);
        window.draw(rectDate10);
        window.draw(rectDate11);
        window.draw(rectDate12);
        window.draw(rectDate13);
        window.draw(rectDate14);
        window.draw(date1);
        window.draw(date2);
        window.draw(date3);
        window.draw(date4);
        window.draw(date5);
        window.draw(date6);
        window.draw(date7);
        window.draw(date8);
        window.draw(date9);
        window.draw(date10);
        window.draw(date11);
        window.draw(date12);
        window.draw(date13);
        window.draw(date14);
        window.display();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Cinema::timeChoice()
{
    loadDetailsFromFile();

    string Time1 = Dates.sTime1;
    string Time2 = Dates.sTime2;
    string Time3 = Dates.sTime3;

    string tempTextFileNameTime1 =  Time1;
    string tempTextFileNameTime2 =  Time2;
    string tempTextFileNameTime3 =  Time3;

    /// WINDOW CONFIG
    sf::RenderWindow window(sf::VideoMode(950,700), "C I N E M A  + +", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    /// IMAGE
    sf::Texture timeBackground;
    timeBackground.loadFromFile("source/timeMenu.png");

    sf::Sprite spriteTimeBackground(timeBackground);
    spriteTimeBackground.setPosition(0,0);

    /// FONT
    sf::Font timeFont;
    timeFont.loadFromFile("source/BebasRegular.otf");

    /// TIME OPTIONS
    sf::Text time1(Time1, timeFont, 40);
    time1.setColor(sf::Color::White);
    time1.setPosition(405,270);

    sf::Text time2(Time2, timeFont, 40);
    time2.setColor(sf::Color::White);
    time2.setPosition(405,387);

    sf::Text time3(Time3, timeFont, 40);
    time3.setColor(sf::Color::White);
    time3.setPosition(405,515);

    /// Rectangle Button Option
    sf::RectangleShape rectTime1(sf::Vector2f(230,101));
    rectTime1.setFillColor(sf::Color::Blue);
    rectTime1.setPosition(355,247);

    sf::RectangleShape rectTime2(sf::Vector2f(230,101));
    rectTime2.setFillColor(sf::Color::Blue);
    rectTime2.setPosition(355,366);

    sf::RectangleShape rectTime3(sf::Vector2f(230,101));
    rectTime3.setFillColor(sf::Color::Blue);
    rectTime3.setPosition(355,496);

    while (window.isOpen())
    {
        sf::Event customerChoiceTime;

        while (window.pollEvent(customerChoiceTime))
        {
            /// WINDOW TERMINATOR
            if (customerChoiceTime.type == sf::Event::Closed)
                window.close();

            /// TIME CHOICE BY MOUSE
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::FloatRect rectTime1Pos = rectTime1.getGlobalBounds();
            sf::FloatRect rectTime2Pos = rectTime2.getGlobalBounds();
            sf::FloatRect rectTime3Pos = rectTime3.getGlobalBounds();

            /// BORDER INDEX COLOR
            if(rectTime1Pos.contains(mousePos.x,mousePos.y))
                rectTime1.setFillColor(sf::Color::Red);
            else
                rectTime1.setFillColor(sf::Color::Blue);

            if(rectTime2Pos.contains(mousePos.x,mousePos.y))
                rectTime2.setFillColor(sf::Color::Red);
            else
                rectTime2.setFillColor(sf::Color::Blue);

            if(rectTime3Pos.contains(mousePos.x,mousePos.y))
                rectTime3.setFillColor(sf::Color::Red);
            else
                rectTime3.setFillColor(sf::Color::Blue);

            if (customerChoiceTime.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceTime.mouseButton.button == sf::Mouse::Left && rectTime1Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameTime = tempTextFileNameTime1;
                    window.close();
                    seatChoice();
                }

                if (customerChoiceTime.mouseButton.button == sf::Mouse::Left && rectTime2Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameTime = tempTextFileNameTime2;
                    window.close();
                    seatChoice();
                }

                if (customerChoiceTime.mouseButton.button == sf::Mouse::Left && rectTime3Pos.contains(mousePos.x,mousePos.y))
                {
                    textFileNameTime = tempTextFileNameTime3;
                    window.close();
                    seatChoice();
                }
            }
        }

        window.draw(spriteTimeBackground);
        window.draw(rectTime1);
        window.draw(rectTime2);
        window.draw(rectTime3);
        window.draw(time1);
        window.draw(time2);
        window.draw(time3);
        window.display();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Cinema::seatChoice()
{
    int reserveQuanti = -1;

    textFileName = textFileNameMovie + textFileNameDate + textFileNameTime + ".txt";

    bool reserveA1 = false;
    bool reserveA2 = false;
    bool reserveA3 = false;
    bool reserveA4 = false;
    bool reserveA5 = false;
    bool reserveA6 = false;
    bool reserveA7 = false;
    bool reserveA8 = false;
    bool reserveA9 = false;
    bool reserveA10 = false;

    bool reserveB1 = false;
    bool reserveB2 = false;
    bool reserveB3 = false;
    bool reserveB4 = false;
    bool reserveB5 = false;
    bool reserveB6 = false;
    bool reserveB7 = false;
    bool reserveB8 = false;
    bool reserveB9 = false;
    bool reserveB10 = false;

    bool reserveC1 = false;
    bool reserveC2 = false;
    bool reserveC3 = false;
    bool reserveC4 = false;
    bool reserveC5= false;
    bool reserveC6 = false;
    bool reserveC7 = false;
    bool reserveC8 = false;
    bool reserveC9 = false;
    bool reserveC10 = false;

    bool reserveD1 = false;
    bool reserveD2 = false;
    bool reserveD3 = false;
    bool reserveD4 = false;
    bool reserveD5 = false;
    bool reserveD6 = false;
    bool reserveD7 = false;
    bool reserveD8 = false;
    bool reserveD9 = false;
    bool reserveD10 = false;

    bool reserveE1 = false;
    bool reserveE2 = false;
    bool reserveE3 = false;
    bool reserveE4 = false;
    bool reserveE5 = false;
    bool reserveE6 = false;
    bool reserveE7 = false;
    bool reserveE8 = false;
    bool reserveE9 = false;
    bool reserveE10 = false;

    bool reserveF1 = false;
    bool reserveF2 = false;
    bool reserveF3 = false;
    bool reserveF4 = false;
    bool reserveF5 = false;
    bool reserveF6 = false;
    bool reserveF7 = false;
    bool reserveF8 = false;
    bool reserveF9 = false;
    bool reserveF10 = false;

    bool reserveG1 = false;
    bool reserveG2 = false;
    bool reserveG3 = false;
    bool reserveG4 = false;
    bool reserveG5 = false;
    bool reserveG6 = false;
    bool reserveG7 = false;
    bool reserveG8 = false;
    bool reserveG9 = false;
    bool reserveG10 = false;

    bool reserveH1 = false;
    bool reserveH2 = false;
    bool reserveH3 = false;
    bool reserveH4 = false;
    bool reserveH5 = false;
    bool reserveH6 = false;
    bool reserveH7 = false;
    bool reserveH8 = false;
    bool reserveH9 = false;
    bool reserveH10 = false;

    bool reserveI1 = false;
    bool reserveI2 = false;
    bool reserveI3 = false;
    bool reserveI4 = false;
    bool reserveI5 = false;
    bool reserveI6 = false;
    bool reserveI7 = false;
    bool reserveI8 = false;
    bool reserveI9 = false;
    bool reserveI10 = false;

    bool reserveJ1 = false;
    bool reserveJ2 = false;
    bool reserveJ3 = false;
    bool reserveJ4 = false;
    bool reserveJ5 = false;
    bool reserveJ6 = false;
    bool reserveJ7 = false;
    bool reserveJ8 = false;
    bool reserveJ9 = false;
    bool reserveJ10 = false;

    bool statusA1 = false;
    bool statusA2 = false;
    bool statusA3 = false;
    bool statusA4 = false;
    bool statusA5 = false;
    bool statusA6 = false;
    bool statusA7 = false;
    bool statusA8 = false;
    bool statusA9 = false;
    bool statusA10 = false;

    bool statusB1 = false;
    bool statusB2 = false;
    bool statusB3 = false;
    bool statusB4 = false;
    bool statusB5 = false;
    bool statusB6 = false;
    bool statusB7 = false;
    bool statusB8 = false;
    bool statusB9 = false;
    bool statusB10 = false;

    bool statusC1 = false;
    bool statusC2 = false;
    bool statusC3 = false;
    bool statusC4 = false;
    bool statusC5 = false;
    bool statusC6 = false;
    bool statusC7 = false;
    bool statusC8 = false;
    bool statusC9 = false;
    bool statusC10 = false;

    bool statusD1 = false;
    bool statusD2 = false;
    bool statusD3 = false;
    bool statusD4 = false;
    bool statusD5 = false;
    bool statusD6 = false;
    bool statusD7 = false;
    bool statusD8 = false;
    bool statusD9 = false;
    bool statusD10 = false;

    bool statusE1 = false;
    bool statusE2 = false;
    bool statusE3 = false;
    bool statusE4 = false;
    bool statusE5 = false;
    bool statusE6 = false;
    bool statusE7 = false;
    bool statusE8 = false;
    bool statusE9 = false;
    bool statusE10 = false;

    bool statusF1 = false;
    bool statusF2 = false;
    bool statusF3 = false;
    bool statusF4 = false;
    bool statusF5 = false;
    bool statusF6 = false;
    bool statusF7 = false;
    bool statusF8 = false;
    bool statusF9 = false;
    bool statusF10 = false;

    bool statusG1 = false;
    bool statusG2 = false;
    bool statusG3 = false;
    bool statusG4 = false;
    bool statusG5 = false;
    bool statusG6 = false;
    bool statusG7 = false;
    bool statusG8 = false;
    bool statusG9 = false;
    bool statusG10 = false;

    bool statusH1 = false;
    bool statusH2 = false;
    bool statusH3 = false;
    bool statusH4 = false;
    bool statusH5 = false;
    bool statusH6 = false;
    bool statusH7 = false;
    bool statusH8 = false;
    bool statusH9 = false;
    bool statusH10 = false;

    bool statusI1 = false;
    bool statusI2 = false;
    bool statusI3 = false;
    bool statusI4 = false;
    bool statusI5 = false;
    bool statusI6 = false;
    bool statusI7 = false;
    bool statusI8 = false;
    bool statusI9 = false;
    bool statusI10 = false;

    bool statusJ1 = false;
    bool statusJ2 = false;
    bool statusJ3 = false;
    bool statusJ4 = false;
    bool statusJ5 = false;
    bool statusJ6 = false;
    bool statusJ7 = false;
    bool statusJ8 = false;
    bool statusJ9 = false;
    bool statusJ10 = false;

    /// WINDOW CONFIG
    sf::RenderWindow window(sf::VideoMode(950,700), "C I N E M A  + +", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);
    window.setActive(false);

    /// IMAGE
    sf::Texture seatBackground;
    seatBackground.loadFromFile("source/SEATPLANnew.jpg");

    sf::Sprite spriteSeatBackground(seatBackground);
    spriteSeatBackground.setPosition(0,0);

    ///Font
    sf::Font submitFont;
    submitFont.loadFromFile("source/BebasRegular.otf");

    ///Text
    sf::Text submitText("SUBMIT", submitFont, 30);
    submitText.setColor(sf::Color::White);
    submitText.setPosition(850,33);

    /// Submit Button
    sf::RectangleShape rectSubmit(sf::Vector2f(90,45));
    rectSubmit.setFillColor(sf::Color::Blue);
    rectSubmit.setPosition(840,30);

    /// Rectangle Button Option
    sf::RectangleShape rectSeatA1(sf::Vector2f(42,34));
    rectSeatA1.setFillColor(sf::Color::Green);
    rectSeatA1.setPosition(148,606);

    sf::RectangleShape rectSeatA2(sf::Vector2f(42,34));
    rectSeatA2.setFillColor(sf::Color::Green);
    rectSeatA2.setPosition(220,606);

    sf::RectangleShape rectSeatA3(sf::Vector2f(42,34));
    rectSeatA3.setFillColor(sf::Color::Green);
    rectSeatA3.setPosition(291,606);

    sf::RectangleShape rectSeatA4(sf::Vector2f(42,34));
    rectSeatA4.setFillColor(sf::Color::Green);
    rectSeatA4.setPosition(364,606);

    sf::RectangleShape rectSeatA5(sf::Vector2f(42,34));
    rectSeatA5.setFillColor(sf::Color::Green);
    rectSeatA5.setPosition(435,606);

    sf::RectangleShape rectSeatA6(sf::Vector2f(42,34));
    rectSeatA6.setFillColor(sf::Color::Green);
    rectSeatA6.setPosition(523,606);

    sf::RectangleShape rectSeatA7(sf::Vector2f(42,34));
    rectSeatA7.setFillColor(sf::Color::Green);
    rectSeatA7.setPosition(594,606);

    sf::RectangleShape rectSeatA8(sf::Vector2f(42,34));
    rectSeatA8.setFillColor(sf::Color::Green);
    rectSeatA8.setPosition(665,606);

    sf::RectangleShape rectSeatA9(sf::Vector2f(42,34));
    rectSeatA9.setFillColor(sf::Color::Green);
    rectSeatA9.setPosition(736,606);

    sf::RectangleShape rectSeatA10(sf::Vector2f(42,34));
    rectSeatA10.setFillColor(sf::Color::Green);
    rectSeatA10.setPosition(807,606);


    sf::RectangleShape rectSeatB1(sf::Vector2f(42,34));
    rectSeatB1.setFillColor(sf::Color::Green);
    rectSeatB1.setPosition(148,564);

    sf::RectangleShape rectSeatB2(sf::Vector2f(42,34));
    rectSeatB2.setFillColor(sf::Color::Green);
    rectSeatB2.setPosition(220,564);

    sf::RectangleShape rectSeatB3(sf::Vector2f(42,34));
    rectSeatB3.setFillColor(sf::Color::Green);
    rectSeatB3.setPosition(291,564);

    sf::RectangleShape rectSeatB4(sf::Vector2f(42,34));
    rectSeatB4.setFillColor(sf::Color::Green);
    rectSeatB4.setPosition(364,564);

    sf::RectangleShape rectSeatB5(sf::Vector2f(42,34));
    rectSeatB5.setFillColor(sf::Color::Green);
    rectSeatB5.setPosition(435,564);

    sf::RectangleShape rectSeatB6(sf::Vector2f(42,34));
    rectSeatB6.setFillColor(sf::Color::Green);
    rectSeatB6.setPosition(523,564);

    sf::RectangleShape rectSeatB7(sf::Vector2f(42,34));
    rectSeatB7.setFillColor(sf::Color::Green);
    rectSeatB7.setPosition(594,564);

    sf::RectangleShape rectSeatB8(sf::Vector2f(42,34));
    rectSeatB8.setFillColor(sf::Color::Green);
    rectSeatB8.setPosition(665,564);

    sf::RectangleShape rectSeatB9(sf::Vector2f(42,34));
    rectSeatB9.setFillColor(sf::Color::Green);
    rectSeatB9.setPosition(736,564);

    sf::RectangleShape rectSeatB10(sf::Vector2f(42,34));
    rectSeatB10.setFillColor(sf::Color::Green);
    rectSeatB10.setPosition(807,564);

    sf::RectangleShape rectSeatC1(sf::Vector2f(42,34));
    rectSeatC1.setFillColor(sf::Color::Green);
    rectSeatC1.setPosition(148,521);

    sf::RectangleShape rectSeatC2(sf::Vector2f(42,34));
    rectSeatC2.setFillColor(sf::Color::Green);
    rectSeatC2.setPosition(220,521);

    sf::RectangleShape rectSeatC3(sf::Vector2f(42,34));
    rectSeatC3.setFillColor(sf::Color::Green);
    rectSeatC3.setPosition(291,521);

    sf::RectangleShape rectSeatC4(sf::Vector2f(42,34));
    rectSeatC4.setFillColor(sf::Color::Green);
    rectSeatC4.setPosition(364,521);

    sf::RectangleShape rectSeatC5(sf::Vector2f(42,34));
    rectSeatC5.setFillColor(sf::Color::Green);
    rectSeatC5.setPosition(435,521);

    sf::RectangleShape rectSeatC6(sf::Vector2f(42,34));
    rectSeatC6.setFillColor(sf::Color::Green);
    rectSeatC6.setPosition(523,521);

    sf::RectangleShape rectSeatC7(sf::Vector2f(42,34));
    rectSeatC7.setFillColor(sf::Color::Green);
    rectSeatC7.setPosition(594,521);

    sf::RectangleShape rectSeatC8(sf::Vector2f(42,34));
    rectSeatC8.setFillColor(sf::Color::Green);
    rectSeatC8.setPosition(665,521);

    sf::RectangleShape rectSeatC9(sf::Vector2f(42,34));
    rectSeatC9.setFillColor(sf::Color::Green);
    rectSeatC9.setPosition(736,521);

    sf::RectangleShape rectSeatC10(sf::Vector2f(42,34));
    rectSeatC10.setFillColor(sf::Color::Green);
    rectSeatC10.setPosition(807,521);

    sf::RectangleShape rectSeatD1(sf::Vector2f(42,34));
    rectSeatD1.setFillColor(sf::Color::Green);
    rectSeatD1.setPosition(148,479);

    sf::RectangleShape rectSeatD2(sf::Vector2f(42,34));
    rectSeatD2.setFillColor(sf::Color::Green);
    rectSeatD2.setPosition(220,479);

    sf::RectangleShape rectSeatD3(sf::Vector2f(42,34));
    rectSeatD3.setFillColor(sf::Color::Green);
    rectSeatD3.setPosition(291,479);

    sf::RectangleShape rectSeatD4(sf::Vector2f(42,34));
    rectSeatD4.setFillColor(sf::Color::Green);
    rectSeatD4.setPosition(364,479);

    sf::RectangleShape rectSeatD5(sf::Vector2f(42,34));
    rectSeatD5.setFillColor(sf::Color::Green);
    rectSeatD5.setPosition(435,479);

    sf::RectangleShape rectSeatD6(sf::Vector2f(42,34));
    rectSeatD6.setFillColor(sf::Color::Green);
    rectSeatD6.setPosition(523,479);

    sf::RectangleShape rectSeatD7(sf::Vector2f(42,34));
    rectSeatD7.setFillColor(sf::Color::Green);
    rectSeatD7.setPosition(594,479);

    sf::RectangleShape rectSeatD8(sf::Vector2f(42,34));
    rectSeatD8.setFillColor(sf::Color::Green);
    rectSeatD8.setPosition(665,479);

    sf::RectangleShape rectSeatD9(sf::Vector2f(42,34));
    rectSeatD9.setFillColor(sf::Color::Green);
    rectSeatD9.setPosition(736,479);

    sf::RectangleShape rectSeatD10(sf::Vector2f(42,34));
    rectSeatD10.setFillColor(sf::Color::Green);
    rectSeatD10.setPosition(807,479);

    sf::RectangleShape rectSeatE1(sf::Vector2f(42,34));
    rectSeatE1.setFillColor(sf::Color::Green);
    rectSeatE1.setPosition(148,436);

    sf::RectangleShape rectSeatE2(sf::Vector2f(42,34));
    rectSeatE2.setFillColor(sf::Color::Green);
    rectSeatE2.setPosition(220,436);

    sf::RectangleShape rectSeatE3(sf::Vector2f(42,34));
    rectSeatE3.setFillColor(sf::Color::Green);
    rectSeatE3.setPosition(291,436);

    sf::RectangleShape rectSeatE4(sf::Vector2f(42,34));
    rectSeatE4.setFillColor(sf::Color::Green);
    rectSeatE4.setPosition(364,436);

    sf::RectangleShape rectSeatE5(sf::Vector2f(42,34));
    rectSeatE5.setFillColor(sf::Color::Green);
    rectSeatE5.setPosition(435,436);

    sf::RectangleShape rectSeatE6(sf::Vector2f(42,34));
    rectSeatE6.setFillColor(sf::Color::Green);
    rectSeatE6.setPosition(523,436);

    sf::RectangleShape rectSeatE7(sf::Vector2f(42,34));
    rectSeatE7.setFillColor(sf::Color::Green);
    rectSeatE7.setPosition(594,436);

    sf::RectangleShape rectSeatE8(sf::Vector2f(42,34));
    rectSeatE8.setFillColor(sf::Color::Green);
    rectSeatE8.setPosition(665,436);

    sf::RectangleShape rectSeatE9(sf::Vector2f(42,34));
    rectSeatE9.setFillColor(sf::Color::Green);
    rectSeatE9.setPosition(736,436);

    sf::RectangleShape rectSeatE10(sf::Vector2f(42,34));
    rectSeatE10.setFillColor(sf::Color::Green);
    rectSeatE10.setPosition(807,436);

    sf::RectangleShape rectSeatF1(sf::Vector2f(42,34));
    rectSeatF1.setFillColor(sf::Color::Green);
    rectSeatF1.setPosition(148,338);

    sf::RectangleShape rectSeatF2(sf::Vector2f(42,34));
    rectSeatF2.setFillColor(sf::Color::Green);
    rectSeatF2.setPosition(220,338);

    sf::RectangleShape rectSeatF3(sf::Vector2f(42,34));
    rectSeatF3.setFillColor(sf::Color::Green);
    rectSeatF3.setPosition(291,338);

    sf::RectangleShape rectSeatF4(sf::Vector2f(42,34));
    rectSeatF4.setFillColor(sf::Color::Green);
    rectSeatF4.setPosition(364,338);

    sf::RectangleShape rectSeatF5(sf::Vector2f(42,34));
    rectSeatF5.setFillColor(sf::Color::Green);
    rectSeatF5.setPosition(435,338);

    sf::RectangleShape rectSeatF6(sf::Vector2f(42,34));
    rectSeatF6.setFillColor(sf::Color::Green);
    rectSeatF6.setPosition(523,338);

    sf::RectangleShape rectSeatF7(sf::Vector2f(42,34));
    rectSeatF7.setFillColor(sf::Color::Green);
    rectSeatF7.setPosition(594,338);

    sf::RectangleShape rectSeatF8(sf::Vector2f(42,34));
    rectSeatF8.setFillColor(sf::Color::Green);
    rectSeatF8.setPosition(665,338);

    sf::RectangleShape rectSeatF9(sf::Vector2f(42,34));
    rectSeatF9.setFillColor(sf::Color::Green);
    rectSeatF9.setPosition(736,338);

    sf::RectangleShape rectSeatF10(sf::Vector2f(42,34));
    rectSeatF10.setFillColor(sf::Color::Green);
    rectSeatF10.setPosition(807,338);

    sf::RectangleShape rectSeatG1(sf::Vector2f(42,34));
    rectSeatG1.setFillColor(sf::Color::Green);
    rectSeatG1.setPosition(148,297);

    sf::RectangleShape rectSeatG2(sf::Vector2f(42,34));
    rectSeatG2.setFillColor(sf::Color::Green);
    rectSeatG2.setPosition(220,297);

    sf::RectangleShape rectSeatG3(sf::Vector2f(42,34));
    rectSeatG3.setFillColor(sf::Color::Green);
    rectSeatG3.setPosition(291,297);

    sf::RectangleShape rectSeatG4(sf::Vector2f(42,34));
    rectSeatG4.setFillColor(sf::Color::Green);
    rectSeatG4.setPosition(364,297);

    sf::RectangleShape rectSeatG5(sf::Vector2f(42,34));
    rectSeatG5.setFillColor(sf::Color::Green);
    rectSeatG5.setPosition(435,297);

    sf::RectangleShape rectSeatG6(sf::Vector2f(42,34));
    rectSeatG6.setFillColor(sf::Color::Green);
    rectSeatG6.setPosition(523,297);

    sf::RectangleShape rectSeatG7(sf::Vector2f(42,34));
    rectSeatG7.setFillColor(sf::Color::Green);
    rectSeatG7.setPosition(594,297);

    sf::RectangleShape rectSeatG8(sf::Vector2f(42,34));
    rectSeatG8.setFillColor(sf::Color::Green);
    rectSeatG8.setPosition(665,297);

    sf::RectangleShape rectSeatG9(sf::Vector2f(42,34));
    rectSeatG9.setFillColor(sf::Color::Green);
    rectSeatG9.setPosition(736,297);

    sf::RectangleShape rectSeatG10(sf::Vector2f(42,34));
    rectSeatG10.setFillColor(sf::Color::Green);
    rectSeatG10.setPosition(807,297);

    sf::RectangleShape rectSeatH1(sf::Vector2f(42,34));
    rectSeatH1.setFillColor(sf::Color::Green);
    rectSeatH1.setPosition(148,254);

    sf::RectangleShape rectSeatH2(sf::Vector2f(42,34));
    rectSeatH2.setFillColor(sf::Color::Green);
    rectSeatH2.setPosition(220,254);

    sf::RectangleShape rectSeatH3(sf::Vector2f(42,34));
    rectSeatH3.setFillColor(sf::Color::Green);
    rectSeatH3.setPosition(291,254);

    sf::RectangleShape rectSeatH4(sf::Vector2f(42,34));
    rectSeatH4.setFillColor(sf::Color::Green);
    rectSeatH4.setPosition(364,254);

    sf::RectangleShape rectSeatH5(sf::Vector2f(42,34));
    rectSeatH5.setFillColor(sf::Color::Green);
    rectSeatH5.setPosition(435,254);

    sf::RectangleShape rectSeatH6(sf::Vector2f(42,34));
    rectSeatH6.setFillColor(sf::Color::Green);
    rectSeatH6.setPosition(523,254);

    sf::RectangleShape rectSeatH7(sf::Vector2f(42,34));
    rectSeatH7.setFillColor(sf::Color::Green);
    rectSeatH7.setPosition(594,254);

    sf::RectangleShape rectSeatH8(sf::Vector2f(42,34));
    rectSeatH8.setFillColor(sf::Color::Green);
    rectSeatH8.setPosition(665,254);

    sf::RectangleShape rectSeatH9(sf::Vector2f(42,34));
    rectSeatH9.setFillColor(sf::Color::Green);
    rectSeatH9.setPosition(736,254);

    sf::RectangleShape rectSeatH10(sf::Vector2f(42,34));
    rectSeatH10.setFillColor(sf::Color::Green);
    rectSeatH10.setPosition(807,254);

    sf::RectangleShape rectSeatI1(sf::Vector2f(42,34));
    rectSeatI1.setFillColor(sf::Color::Green);
    rectSeatI1.setPosition(148,207);

    sf::RectangleShape rectSeatI2(sf::Vector2f(42,34));
    rectSeatI2.setFillColor(sf::Color::Green);
    rectSeatI2.setPosition(220,207);

    sf::RectangleShape rectSeatI3(sf::Vector2f(42,34));
    rectSeatI3.setFillColor(sf::Color::Green);
    rectSeatI3.setPosition(291,207);

    sf::RectangleShape rectSeatI4(sf::Vector2f(42,34));
    rectSeatI4.setFillColor(sf::Color::Green);
    rectSeatI4.setPosition(364,207);

    sf::RectangleShape rectSeatI5(sf::Vector2f(42,34));
    rectSeatI5.setFillColor(sf::Color::Green);
    rectSeatI5.setPosition(435,207);

    sf::RectangleShape rectSeatI6(sf::Vector2f(42,34));
    rectSeatI6.setFillColor(sf::Color::Green);
    rectSeatI6.setPosition(523,207);

    sf::RectangleShape rectSeatI7(sf::Vector2f(42,34));
    rectSeatI7.setFillColor(sf::Color::Green);
    rectSeatI7.setPosition(594,207);

    sf::RectangleShape rectSeatI8(sf::Vector2f(42,34));
    rectSeatI8.setFillColor(sf::Color::Green);
    rectSeatI8.setPosition(665,207);

    sf::RectangleShape rectSeatI9(sf::Vector2f(42,34));
    rectSeatI9.setFillColor(sf::Color::Green);
    rectSeatI9.setPosition(736,207);

    sf::RectangleShape rectSeatI10(sf::Vector2f(42,34));
    rectSeatI10.setFillColor(sf::Color::Green);
    rectSeatI10.setPosition(807,207);

    sf::RectangleShape rectSeatJ1(sf::Vector2f(42,34));
    rectSeatJ1.setFillColor(sf::Color::Green);
    rectSeatJ1.setPosition(148,163);

    sf::RectangleShape rectSeatJ2(sf::Vector2f(42,34));
    rectSeatJ2.setFillColor(sf::Color::Green);
    rectSeatJ2.setPosition(220,163);

    sf::RectangleShape rectSeatJ3(sf::Vector2f(42,34));
    rectSeatJ3.setFillColor(sf::Color::Green);
    rectSeatJ3.setPosition(291,163);

    sf::RectangleShape rectSeatJ4(sf::Vector2f(42,34));
    rectSeatJ4.setFillColor(sf::Color::Green);
    rectSeatJ4.setPosition(364,163);

    sf::RectangleShape rectSeatJ5(sf::Vector2f(42,34));
    rectSeatJ5.setFillColor(sf::Color::Green);
    rectSeatJ5.setPosition(435,163);

    sf::RectangleShape rectSeatJ6(sf::Vector2f(42,34));
    rectSeatJ6.setFillColor(sf::Color::Green);
    rectSeatJ6.setPosition(523,163);

    sf::RectangleShape rectSeatJ7(sf::Vector2f(42,34));
    rectSeatJ7.setFillColor(sf::Color::Green);
    rectSeatJ7.setPosition(594,163);

    sf::RectangleShape rectSeatJ8(sf::Vector2f(42,34));
    rectSeatJ8.setFillColor(sf::Color::Green);
    rectSeatJ8.setPosition(665,163);

    sf::RectangleShape rectSeatJ9(sf::Vector2f(42,34));
    rectSeatJ9.setFillColor(sf::Color::Green);
    rectSeatJ9.setPosition(736,163);

    sf::RectangleShape rectSeatJ10(sf::Vector2f(42,34));
    rectSeatJ10.setFillColor(sf::Color::Green);
    rectSeatJ10.setPosition(807,163);

    while (window.isOpen())
    {
        sf::Event customerChoiceSeat;

        while(window.pollEvent(customerChoiceSeat))
        {
            /// WINDOW TERMINATOR
            if (customerChoiceSeat.type == sf::Event::Closed)
                window.close();

            /// SEAT CHOICE BY MOUSE
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            sf::FloatRect rectSubmitPos = rectSubmit.getGlobalBounds();

            sf::FloatRect rectSeatA1Pos = rectSeatA1.getGlobalBounds();
            sf::FloatRect rectSeatA2Pos = rectSeatA2.getGlobalBounds();
            sf::FloatRect rectSeatA3Pos = rectSeatA3.getGlobalBounds();
            sf::FloatRect rectSeatA4Pos = rectSeatA4.getGlobalBounds();
            sf::FloatRect rectSeatA5Pos = rectSeatA5.getGlobalBounds();
            sf::FloatRect rectSeatA6Pos = rectSeatA6.getGlobalBounds();
            sf::FloatRect rectSeatA7Pos = rectSeatA7.getGlobalBounds();
            sf::FloatRect rectSeatA8Pos = rectSeatA8.getGlobalBounds();
            sf::FloatRect rectSeatA9Pos = rectSeatA9.getGlobalBounds();
            sf::FloatRect rectSeatA10Pos =rectSeatA10.getGlobalBounds();

            sf::FloatRect rectSeatB1Pos = rectSeatB1.getGlobalBounds();
            sf::FloatRect rectSeatB2Pos = rectSeatB2.getGlobalBounds();
            sf::FloatRect rectSeatB3Pos = rectSeatB3.getGlobalBounds();
            sf::FloatRect rectSeatB4Pos = rectSeatB4.getGlobalBounds();
            sf::FloatRect rectSeatB5Pos = rectSeatB5.getGlobalBounds();
            sf::FloatRect rectSeatB6Pos = rectSeatB6.getGlobalBounds();
            sf::FloatRect rectSeatB7Pos = rectSeatB7.getGlobalBounds();
            sf::FloatRect rectSeatB8Pos = rectSeatB8.getGlobalBounds();
            sf::FloatRect rectSeatB9Pos = rectSeatB9.getGlobalBounds();
            sf::FloatRect rectSeatB10Pos =rectSeatB10.getGlobalBounds();

            sf::FloatRect rectSeatC1Pos = rectSeatC1.getGlobalBounds();
            sf::FloatRect rectSeatC2Pos = rectSeatC2.getGlobalBounds();
            sf::FloatRect rectSeatC3Pos = rectSeatC3.getGlobalBounds();
            sf::FloatRect rectSeatC4Pos = rectSeatC4.getGlobalBounds();
            sf::FloatRect rectSeatC5Pos = rectSeatC5.getGlobalBounds();
            sf::FloatRect rectSeatC6Pos = rectSeatC6.getGlobalBounds();
            sf::FloatRect rectSeatC7Pos = rectSeatC7.getGlobalBounds();
            sf::FloatRect rectSeatC8Pos = rectSeatC8.getGlobalBounds();
            sf::FloatRect rectSeatC9Pos = rectSeatC9.getGlobalBounds();
            sf::FloatRect rectSeatC10Pos =rectSeatC10.getGlobalBounds();

            sf::FloatRect rectSeatD1Pos = rectSeatD1.getGlobalBounds();
            sf::FloatRect rectSeatD2Pos = rectSeatD2.getGlobalBounds();
            sf::FloatRect rectSeatD3Pos = rectSeatD3.getGlobalBounds();
            sf::FloatRect rectSeatD4Pos = rectSeatD4.getGlobalBounds();
            sf::FloatRect rectSeatD5Pos = rectSeatD5.getGlobalBounds();
            sf::FloatRect rectSeatD6Pos = rectSeatD6.getGlobalBounds();
            sf::FloatRect rectSeatD7Pos = rectSeatD7.getGlobalBounds();
            sf::FloatRect rectSeatD8Pos = rectSeatD8.getGlobalBounds();
            sf::FloatRect rectSeatD9Pos = rectSeatD9.getGlobalBounds();
            sf::FloatRect rectSeatD10Pos =rectSeatD10.getGlobalBounds();

            sf::FloatRect rectSeatE1Pos = rectSeatE1.getGlobalBounds();
            sf::FloatRect rectSeatE2Pos = rectSeatE2.getGlobalBounds();
            sf::FloatRect rectSeatE3Pos = rectSeatE3.getGlobalBounds();
            sf::FloatRect rectSeatE4Pos = rectSeatE4.getGlobalBounds();
            sf::FloatRect rectSeatE5Pos = rectSeatE5.getGlobalBounds();
            sf::FloatRect rectSeatE6Pos = rectSeatE6.getGlobalBounds();
            sf::FloatRect rectSeatE7Pos = rectSeatE7.getGlobalBounds();
            sf::FloatRect rectSeatE8Pos = rectSeatE8.getGlobalBounds();
            sf::FloatRect rectSeatE9Pos = rectSeatE9.getGlobalBounds();
            sf::FloatRect rectSeatE10Pos =rectSeatE10.getGlobalBounds();

            sf::FloatRect rectSeatF1Pos = rectSeatF1.getGlobalBounds();
            sf::FloatRect rectSeatF2Pos = rectSeatF2.getGlobalBounds();
            sf::FloatRect rectSeatF3Pos = rectSeatF3.getGlobalBounds();
            sf::FloatRect rectSeatF4Pos = rectSeatF4.getGlobalBounds();
            sf::FloatRect rectSeatF5Pos = rectSeatF5.getGlobalBounds();
            sf::FloatRect rectSeatF6Pos = rectSeatF6.getGlobalBounds();
            sf::FloatRect rectSeatF7Pos = rectSeatF7.getGlobalBounds();
            sf::FloatRect rectSeatF8Pos = rectSeatF8.getGlobalBounds();
            sf::FloatRect rectSeatF9Pos = rectSeatF9.getGlobalBounds();
            sf::FloatRect rectSeatF10Pos =rectSeatF10.getGlobalBounds();

            sf::FloatRect rectSeatG1Pos = rectSeatG1.getGlobalBounds();
            sf::FloatRect rectSeatG2Pos = rectSeatG2.getGlobalBounds();
            sf::FloatRect rectSeatG3Pos = rectSeatG3.getGlobalBounds();
            sf::FloatRect rectSeatG4Pos = rectSeatG4.getGlobalBounds();
            sf::FloatRect rectSeatG5Pos = rectSeatG5.getGlobalBounds();
            sf::FloatRect rectSeatG6Pos = rectSeatG6.getGlobalBounds();
            sf::FloatRect rectSeatG7Pos = rectSeatG7.getGlobalBounds();
            sf::FloatRect rectSeatG8Pos = rectSeatG8.getGlobalBounds();
            sf::FloatRect rectSeatG9Pos = rectSeatG9.getGlobalBounds();
            sf::FloatRect rectSeatG10Pos =rectSeatG10.getGlobalBounds();

            sf::FloatRect rectSeatH1Pos = rectSeatH1.getGlobalBounds();
            sf::FloatRect rectSeatH2Pos = rectSeatH2.getGlobalBounds();
            sf::FloatRect rectSeatH3Pos = rectSeatH3.getGlobalBounds();
            sf::FloatRect rectSeatH4Pos = rectSeatH4.getGlobalBounds();
            sf::FloatRect rectSeatH5Pos = rectSeatH5.getGlobalBounds();
            sf::FloatRect rectSeatH6Pos = rectSeatH6.getGlobalBounds();
            sf::FloatRect rectSeatH7Pos = rectSeatH7.getGlobalBounds();
            sf::FloatRect rectSeatH8Pos = rectSeatH8.getGlobalBounds();
            sf::FloatRect rectSeatH9Pos = rectSeatH9.getGlobalBounds();
            sf::FloatRect rectSeatH10Pos =rectSeatH10.getGlobalBounds();

            sf::FloatRect rectSeatI1Pos = rectSeatI1.getGlobalBounds();
            sf::FloatRect rectSeatI2Pos = rectSeatI2.getGlobalBounds();
            sf::FloatRect rectSeatI3Pos = rectSeatI3.getGlobalBounds();
            sf::FloatRect rectSeatI4Pos = rectSeatI4.getGlobalBounds();
            sf::FloatRect rectSeatI5Pos = rectSeatI5.getGlobalBounds();
            sf::FloatRect rectSeatI6Pos = rectSeatI6.getGlobalBounds();
            sf::FloatRect rectSeatI7Pos = rectSeatI7.getGlobalBounds();
            sf::FloatRect rectSeatI8Pos = rectSeatI8.getGlobalBounds();
            sf::FloatRect rectSeatI9Pos = rectSeatI9.getGlobalBounds();
            sf::FloatRect rectSeatI10Pos =rectSeatI10.getGlobalBounds();

            sf::FloatRect rectSeatJ1Pos = rectSeatJ1.getGlobalBounds();
            sf::FloatRect rectSeatJ2Pos = rectSeatJ2.getGlobalBounds();
            sf::FloatRect rectSeatJ3Pos = rectSeatJ3.getGlobalBounds();
            sf::FloatRect rectSeatJ4Pos = rectSeatJ4.getGlobalBounds();
            sf::FloatRect rectSeatJ5Pos = rectSeatJ5.getGlobalBounds();
            sf::FloatRect rectSeatJ6Pos = rectSeatJ6.getGlobalBounds();
            sf::FloatRect rectSeatJ7Pos = rectSeatJ7.getGlobalBounds();
            sf::FloatRect rectSeatJ8Pos = rectSeatJ8.getGlobalBounds();
            sf::FloatRect rectSeatJ9Pos = rectSeatJ9.getGlobalBounds();
            sf::FloatRect rectSeatJ10Pos =rectSeatJ10.getGlobalBounds();

            /// BORDER SUBMIT INDEX COLOR
            if(rectSubmitPos.contains(mousePos.x,mousePos.y))
                rectSubmit.setFillColor(sf::Color::Red);
            else
                rectSubmit.setFillColor(sf::Color::Blue);

             if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSubmitPos.contains(mousePos.x,mousePos.y) && reserveQuanti >= 0)
                {
                    saveCustomerToFile(reserveQuanti,textFileName);
                    window.close();
                    paymentProcess();
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatA1Pos.contains(mousePos.x,mousePos.y) && reserveA1 == false)
                {
                    if(statusA1)
                    {
                        statusA1 = false;
                        rectSeatA1.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusA1 = true;
                        rectSeatA1.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "A1";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatA2Pos.contains(mousePos.x,mousePos.y) && reserveA2 == false)
                {
                    if(statusA2)
                    {
                        statusA2 = false;
                        rectSeatA2.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusA2 = true;
                        rectSeatA2.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "A2";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatA3Pos.contains(mousePos.x,mousePos.y) && reserveA3 == false)
                {
                    if(statusA3)
                    {
                        statusA3 = false;
                        rectSeatA3.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusA3 = true;
                        rectSeatA3.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "A3";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatA4Pos.contains(mousePos.x,mousePos.y) && reserveA4 == false)
                {
                    if(statusA4)
                    {
                        statusA4 = false;
                        rectSeatA4.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusA4 = true;
                        rectSeatA4.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "A4";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatA5Pos.contains(mousePos.x,mousePos.y) && reserveA5 == false)
                {
                    if(statusA5)
                    {
                        statusA5 = false;
                        rectSeatA5.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusA5 = true;
                        rectSeatA5.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "A5";

                    }
                }
            }


         if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatA6Pos.contains(mousePos.x,mousePos.y) && reserveA6 == false)
                {
                    if(statusA6)
                    {
                        statusA6 = false;
                        rectSeatA6.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusA6 = true;
                        rectSeatA6.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "A6";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatA7Pos.contains(mousePos.x,mousePos.y) && reserveA7 == false)
                {
                    if(statusA7)
                    {
                        statusA7 = false;
                        rectSeatA7.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusA7 = true;
                        rectSeatA7.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "A7";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatA8Pos.contains(mousePos.x,mousePos.y) && reserveA8 == false)
                {
                    if(statusA8)
                    {
                        statusA8 = false;
                        rectSeatA8.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusA8 = true;
                        rectSeatA8.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "A8";

                    }
                }
            }


            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatA9Pos.contains(mousePos.x,mousePos.y) && reserveA9 == false)
                {
                    if(statusA9)
                    {
                        statusA9 = false;
                        rectSeatA9.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusA9 = true;
                        rectSeatA9.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "A9";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatA10Pos.contains(mousePos.x,mousePos.y) && reserveA10 == false)
                {
                    if(statusA10)
                    {
                        statusA10 = false;
                        rectSeatA10.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusA10 = true;
                        rectSeatA10.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "A10";

                    }
                }
            }

             if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatB1Pos.contains(mousePos.x,mousePos.y) && reserveB1 == false)
                {
                    if(statusB1)
                    {
                        statusB1 = false;
                        rectSeatB1.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusB1 = true;
                        rectSeatB1.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "B1";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatB2Pos.contains(mousePos.x,mousePos.y) && reserveB2 == false)
                {
                    if(statusB2)
                    {
                        statusB2 = false;
                        rectSeatB2.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusB2 = true;
                        rectSeatB2.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "B2";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatB3Pos.contains(mousePos.x,mousePos.y) && reserveB3 == false)
                {
                    if(statusB3)
                    {
                        statusB3 = false;
                        rectSeatB3.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusB3 = true;
                        rectSeatB3.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "B3";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatB4Pos.contains(mousePos.x,mousePos.y) && reserveB4 == false)
                {
                    if(statusB4)
                    {
                        statusB4 = false;
                        rectSeatB4.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusB4 = true;
                        rectSeatB4.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "B4";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatB5Pos.contains(mousePos.x,mousePos.y) && reserveB5 == false)
                {
                    if(statusB5)
                    {
                        statusB5 = false;
                        rectSeatB5.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusB5 = true;
                        rectSeatB5.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "B5";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatB6Pos.contains(mousePos.x,mousePos.y) && reserveB6 == false)
                {
                    if(statusB6)
                    {
                        statusB6 = false;
                        rectSeatB6.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusB6 = true;
                        rectSeatB6.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "B6";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatB7Pos.contains(mousePos.x,mousePos.y) && reserveB7 == false)
                {
                    if(statusB7)
                    {
                        statusB7 = false;
                        rectSeatB7.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusB7 = true;
                        rectSeatB7.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "B7";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatB8Pos.contains(mousePos.x,mousePos.y) && reserveB8 == false)
                {
                    if(statusB8)
                    {
                        statusB8 = false;
                        rectSeatB8.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusB8 = true;
                        rectSeatB8.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "B8";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatB9Pos.contains(mousePos.x,mousePos.y) && reserveB9 == false)
                {
                    if(statusB9)
                    {
                        statusB9 = false;
                        rectSeatB9.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusB9 = true;
                        rectSeatB9.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "B9";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatB10Pos.contains(mousePos.x,mousePos.y) && reserveB10 == false)
                {
                    if(statusB10)
                    {
                        statusB10 = false;
                        rectSeatB10.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusB10 = true;
                        rectSeatB10.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "B10";

                    }
                }
            }

             if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatC1Pos.contains(mousePos.x,mousePos.y) && reserveC1 == false)
                {
                    if(statusC1)
                    {
                        statusC1 = false;
                        rectSeatC1.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusC1 = true;
                        rectSeatC1.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "C1";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatC2Pos.contains(mousePos.x,mousePos.y) && reserveC2 == false)
                {
                    if(statusC2)
                    {
                        statusC2 = false;
                        rectSeatC2.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusC2 = true;
                        rectSeatC2.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "C2";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatC3Pos.contains(mousePos.x,mousePos.y) && reserveC3 == false)
                {
                    if(statusC3)
                    {
                        statusC3 = false;
                        rectSeatC3.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusC3 = true;
                        rectSeatC3.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "C3";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatC4Pos.contains(mousePos.x,mousePos.y) && reserveC4 == false)
                {
                    if(statusC4)
                    {
                        statusC4 = false;
                        rectSeatC4.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusC4 = true;
                        rectSeatC4.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "C4";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatC5Pos.contains(mousePos.x,mousePos.y) && reserveC5 == false)
                {
                    if(statusC5)
                    {
                        statusC5 = false;
                        rectSeatC5.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusC5 = true;
                        rectSeatC5.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "C5";

                    }
                }
            }

                         if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatC6Pos.contains(mousePos.x,mousePos.y) && reserveC6 == false)
                {
                    if(statusC6)
                    {
                        statusC6 = false;
                        rectSeatC6.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusC6 = true;
                        rectSeatC6.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "C6";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatC7Pos.contains(mousePos.x,mousePos.y) && reserveC7 == false)
                {
                    if(statusC7)
                    {
                        statusC7 = false;
                        rectSeatC7.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusC7 = true;
                        rectSeatC7.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "C7";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatC8Pos.contains(mousePos.x,mousePos.y) && reserveC8 == false)
                {
                    if(statusC8)
                    {
                        statusC8 = false;
                        rectSeatC8.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusC8 = true;
                        rectSeatC8.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "C8";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatC9Pos.contains(mousePos.x,mousePos.y) && reserveC9 == false)
                {
                    if(statusC9)
                    {
                        statusC9 = false;
                        rectSeatC9.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusC9 = true;
                        rectSeatC9.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "C9";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatC10Pos.contains(mousePos.x,mousePos.y) && reserveC10 == false)
                {
                    if(statusC10)
                    {
                        statusC10 = false;
                        rectSeatC10.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusC10 = true;
                        rectSeatC10.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "C10";

                    }
                }
            }


             if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatD1Pos.contains(mousePos.x,mousePos.y) && reserveD1 == false)
                {
                    if(statusD1)
                    {
                        statusD1 = false;
                        rectSeatD1.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusD1 = true;
                        rectSeatD1.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "D1";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatD2Pos.contains(mousePos.x,mousePos.y) && reserveD2 == false)
                {
                    if(statusD2)
                    {
                        statusD2 = false;
                        rectSeatD2.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusD2 = true;
                        rectSeatD2.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "D2";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatD3Pos.contains(mousePos.x,mousePos.y) && reserveD3 == false)
                {
                    if(statusD3)
                    {
                        statusD3 = false;
                        rectSeatD3.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusD3 = true;
                        rectSeatD3.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "D3";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatD4Pos.contains(mousePos.x,mousePos.y) && reserveD4 == false)
                {
                    if(statusD4)
                    {
                        statusD4 = false;
                        rectSeatD4.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusD4 = true;
                        rectSeatD4.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "D4";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatD5Pos.contains(mousePos.x,mousePos.y) && reserveD5 == false)
                {
                    if(statusD5)
                    {
                        statusD5 = false;
                        rectSeatD5.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusD5 = true;
                        rectSeatD5.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "D5";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatD6Pos.contains(mousePos.x,mousePos.y) && reserveD6 == false)
                {
                    if(statusD6)
                    {
                        statusD6 = false;
                        rectSeatD6.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusD6 = true;
                        rectSeatD6.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "D6";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatD7Pos.contains(mousePos.x,mousePos.y) && reserveD7 == false)
                {
                    if(statusD7)
                    {
                        statusD7 = false;
                        rectSeatD7.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusD7 = true;
                        rectSeatD7.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "D7";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatD8Pos.contains(mousePos.x,mousePos.y) && reserveD8 == false)
                {
                    if(statusD8)
                    {
                        statusD8 = false;
                        rectSeatD8.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusD8 = true;
                        rectSeatD8.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "D8";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatD9Pos.contains(mousePos.x,mousePos.y) && reserveD9 == false)
                {
                    if(statusD9)
                    {
                        statusD9 = false;
                        rectSeatD9.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusD9 = true;
                        rectSeatD9.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "D9";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatD10Pos.contains(mousePos.x,mousePos.y) && reserveD10 == false)
                {
                    if(statusD10)
                    {
                        statusD10 = false;
                        rectSeatD10.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusD10 = true;
                        rectSeatD10.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "D10";

                    }
                }
            }



            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatE1Pos.contains(mousePos.x,mousePos.y) && reserveE1 == false)
                {
                    if(statusE1)
                    {
                        statusE1 = false;
                        rectSeatE1.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusE1 = true;
                        rectSeatE1.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "E1";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatE2Pos.contains(mousePos.x,mousePos.y) && reserveE2 == false)
                {
                    if(statusE2)
                    {
                        statusE2 = false;
                        rectSeatE2.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusE2 = true;
                        rectSeatE2.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "E2";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatE3Pos.contains(mousePos.x,mousePos.y) && reserveE3 == false)
                {
                    if(statusE3)
                    {
                        statusE3 = false;
                        rectSeatE3.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusE3 = true;
                        rectSeatE3.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "E3";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatE4Pos.contains(mousePos.x,mousePos.y) && reserveE4 == false)
                {
                    if(statusE4)
                    {
                        statusE4 = false;
                        rectSeatE4.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusE4 = true;
                        rectSeatE4.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "E4";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatE5Pos.contains(mousePos.x,mousePos.y) && reserveE5 == false)
                {
                    if(statusE5)
                    {
                        statusE5 = false;
                        rectSeatE5.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusE5 = true;
                        rectSeatE5.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "E5";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatE6Pos.contains(mousePos.x,mousePos.y) && reserveE6 == false)
                {
                    if(statusE6)
                    {
                        statusE6 = false;
                        rectSeatE6.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusE6 = true;
                        rectSeatE6.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "E6";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatE7Pos.contains(mousePos.x,mousePos.y) && reserveE7 == false)
                {
                    if(statusE7)
                    {
                        statusE7 = false;
                        rectSeatE7.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusE7 = true;
                        rectSeatE7.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "E7";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatE8Pos.contains(mousePos.x,mousePos.y) && reserveE8 == false)
                {
                    if(statusE8)
                    {
                        statusE8 = false;
                        rectSeatE8.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusE8 = true;
                        rectSeatE8.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "E8";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatE9Pos.contains(mousePos.x,mousePos.y) && reserveE9 == false)
                {
                    if(statusE9)
                    {
                        statusE9 = false;
                        rectSeatE9.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusE9 = true;
                        rectSeatE9.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "E9";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatE10Pos.contains(mousePos.x,mousePos.y) && reserveE10 == false)
                {
                    if(statusE10)
                    {
                        statusE10 = false;
                        rectSeatE10.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusE10 = true;
                        rectSeatE10.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "E10";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatF1Pos.contains(mousePos.x,mousePos.y) && reserveF1 == false)
                {
                    if(statusF1)
                    {
                        statusF1 = false;
                        rectSeatF1.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusF1 = true;
                        rectSeatF1.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "F1";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatF2Pos.contains(mousePos.x,mousePos.y) && reserveF2 == false)
                {
                    if(statusF2)
                    {
                        statusF2 = false;
                        rectSeatF2.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusF2 = true;
                        rectSeatF2.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "F2";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatF3Pos.contains(mousePos.x,mousePos.y) && reserveF3 == false)
                {
                    if(statusF3)
                    {
                        statusF3 = false;
                        rectSeatF3.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusF3 = true;
                        rectSeatF3.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "F3";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatF4Pos.contains(mousePos.x,mousePos.y) && reserveF4 == false)
                {
                    if(statusF4)
                    {
                        statusF4 = false;
                        rectSeatF4.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusF4 = true;
                        rectSeatF4.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "F4";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatF5Pos.contains(mousePos.x,mousePos.y) && reserveF5 == false)
                {
                    if(statusF5)
                    {
                        statusF5 = false;
                        rectSeatF5.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusF5 = true;
                        rectSeatF5.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "F5";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatF6Pos.contains(mousePos.x,mousePos.y) && reserveF6 == false)
                {
                    if(statusF6)
                    {
                        statusF6 = false;
                        rectSeatF6.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusF6 = true;
                        rectSeatF6.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "F6";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatF7Pos.contains(mousePos.x,mousePos.y) && reserveF7 == false)
                {
                    if(statusF7)
                    {
                        statusF7 = false;
                        rectSeatF7.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusF7 = true;
                        rectSeatF7.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "F7";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatF8Pos.contains(mousePos.x,mousePos.y) && reserveF8 == false)
                {
                    if(statusF8)
                    {
                        statusF8 = false;
                        rectSeatF8.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusF8 = true;
                        rectSeatF8.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "F8";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatF9Pos.contains(mousePos.x,mousePos.y) && reserveF9 == false)
                {
                    if(statusF9)
                    {
                        statusF9 = false;
                        rectSeatF9.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusF9 = true;
                        rectSeatF9.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "F9";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatF10Pos.contains(mousePos.x,mousePos.y) && reserveF10 == false)
                {
                    if(statusF10)
                    {
                        statusF10 = false;
                        rectSeatF10.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusF10 = true;
                        rectSeatF10.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "F10";

                    }
                }
            }


             if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatG1Pos.contains(mousePos.x,mousePos.y) && reserveG1 == false)
                {
                    if(statusG1)
                    {
                        statusG1 = false;
                        rectSeatG1.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusG1 = true;
                        rectSeatG1.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "G1";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatG2Pos.contains(mousePos.x,mousePos.y) && reserveG2 == false)
                {
                    if(statusG2)
                    {
                        statusG2 = false;
                        rectSeatG2.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusG2 = true;
                        rectSeatG2.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "G2";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatG3Pos.contains(mousePos.x,mousePos.y) && reserveG3 == false)
                {
                    if(statusG3)
                    {
                        statusG3 = false;
                        rectSeatG3.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusG3 = true;
                        rectSeatG3.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "G3";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatG4Pos.contains(mousePos.x,mousePos.y) && reserveG4 == false)
                {
                    if(statusG4)
                    {
                        statusG4 = false;
                        rectSeatG4.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusG4 = true;
                        rectSeatG4.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "G4";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatG5Pos.contains(mousePos.x,mousePos.y) && reserveG5 == false)
                {
                    if(statusG5)
                    {
                        statusG5 = false;
                        rectSeatG5.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusG5 = true;
                        rectSeatG5.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "G5";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatG6Pos.contains(mousePos.x,mousePos.y) && reserveG6 == false)
                {
                    if(statusG6)
                    {
                        statusG6 = false;
                        rectSeatG6.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusG6 = true;
                        rectSeatG6.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "G6";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatG7Pos.contains(mousePos.x,mousePos.y) && reserveG7 == false)
                {
                    if(statusG7)
                    {
                        statusG7 = false;
                        rectSeatG7.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusG7 = true;
                        rectSeatG7.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "G7";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatG8Pos.contains(mousePos.x,mousePos.y) && reserveG8 == false)
                {
                    if(statusG8)
                    {
                        statusG8 = false;
                        rectSeatG8.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusG8 = true;
                        rectSeatG8.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "G8";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatG9Pos.contains(mousePos.x,mousePos.y) && reserveG9 == false)
                {
                    if(statusG9)
                    {
                        statusG9 = false;
                        rectSeatG9.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusG9 = true;
                        rectSeatG9.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "G9";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatG10Pos.contains(mousePos.x,mousePos.y) && reserveG10 == false)
                {
                    if(statusG10)
                    {
                        statusG10 = false;
                        rectSeatG10.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusG10 = true;
                        rectSeatG10.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "G10";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatH1Pos.contains(mousePos.x,mousePos.y) && reserveH1 == false)
                {
                    if(statusH1)
                    {
                        statusH1 = false;
                        rectSeatH1.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusH1 = true;
                        rectSeatH1.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "H1";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatH2Pos.contains(mousePos.x,mousePos.y) && reserveH2 == false)
                {
                    if(statusH2)
                    {
                        statusH2 = false;
                        rectSeatH2.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusH2 = true;
                        rectSeatH2.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "H2";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatH3Pos.contains(mousePos.x,mousePos.y) && reserveH3 == false)
                {
                    if(statusH3)
                    {
                        statusH3 = false;
                        rectSeatH3.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusH3 = true;
                        rectSeatH3.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "H3";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatH4Pos.contains(mousePos.x,mousePos.y) && reserveH4 == false)
                {
                    if(statusH4)
                    {
                        statusH4 = false;
                        rectSeatH4.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusH4 = true;
                        rectSeatH4.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "H4";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatH5Pos.contains(mousePos.x,mousePos.y) && reserveH5 == false)
                {
                    if(statusH5)
                    {
                        statusH5 = false;
                        rectSeatH5.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusH5 = true;
                        rectSeatH5.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "H5";

                    }
                }
            }

                         if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatH6Pos.contains(mousePos.x,mousePos.y) && reserveH6 == false)
                {
                    if(statusH6)
                    {
                        statusH6 = false;
                        rectSeatH6.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusH6 = true;
                        rectSeatH6.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "H6";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatH7Pos.contains(mousePos.x,mousePos.y) && reserveH7 == false)
                {
                    if(statusH7)
                    {
                        statusH7 = false;
                        rectSeatH7.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusH7 = true;
                        rectSeatH7.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "H7";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatH8Pos.contains(mousePos.x,mousePos.y) && reserveH8 == false)
                {
                    if(statusH8)
                    {
                        statusH8 = false;
                        rectSeatH8.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusH8 = true;
                        rectSeatH8.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "H8";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatH9Pos.contains(mousePos.x,mousePos.y) && reserveH9 == false)
                {
                    if(statusH9)
                    {
                        statusH9 = false;
                        rectSeatH9.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusH9 = true;
                        rectSeatH9.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "H9";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatH10Pos.contains(mousePos.x,mousePos.y) && reserveH10 == false)
                {
                    if(statusH10)
                    {
                        statusH10 = false;
                        rectSeatH10.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusH10 = true;
                        rectSeatH10.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "H10";

                    }
                }
            }


            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatI1Pos.contains(mousePos.x,mousePos.y) && reserveI1 == false)
                {
                    if(statusI1)
                    {
                        statusI1 = false;
                        rectSeatI1.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusI1 = true;
                        rectSeatI1.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "I1";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatI2Pos.contains(mousePos.x,mousePos.y) && reserveI2 == false)
                {
                    if(statusI2)
                    {
                        statusI2 = false;
                        rectSeatI2.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusI2 = true;
                        rectSeatI2.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "I2";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatI3Pos.contains(mousePos.x,mousePos.y) && reserveI3 == false)
                {
                    if(statusI3)
                    {
                        statusI3 = false;
                        rectSeatI3.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusI3 = true;
                        rectSeatI3.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "I3";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatI4Pos.contains(mousePos.x,mousePos.y) && reserveI4 == false)
                {
                    if(statusI4)
                    {
                        statusI4 = false;
                        rectSeatI4.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusI4 = true;
                        rectSeatI4.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "I4";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatI5Pos.contains(mousePos.x,mousePos.y) && reserveI5 == false)
                {
                    if(statusI5)
                    {
                        statusI5 = false;
                        rectSeatI5.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusI5 = true;
                        rectSeatI5.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "I5";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatI6Pos.contains(mousePos.x,mousePos.y) && reserveI6 == false)
                {
                    if(statusI6)
                    {
                        statusI6 = false;
                        rectSeatI6.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusI6 = true;
                        rectSeatI6.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "I6";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatI7Pos.contains(mousePos.x,mousePos.y) && reserveI7 == false)
                {
                    if(statusI7)
                    {
                        statusI7 = false;
                        rectSeatI7.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusI7 = true;
                        rectSeatI7.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "I7";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatI8Pos.contains(mousePos.x,mousePos.y) && reserveI8 == false)
                {
                    if(statusI8)
                    {
                        statusI8 = false;
                        rectSeatI8.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusI8 = true;
                        rectSeatI8.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "I8";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatI9Pos.contains(mousePos.x,mousePos.y) && reserveI9 == false)
                {
                    if(statusI9)
                    {
                        statusI9 = false;
                        rectSeatI9.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusI9 = true;
                        rectSeatI9.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "I9";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatI10Pos.contains(mousePos.x,mousePos.y) && reserveI10 == false)
                {
                    if(statusI10)
                    {
                        statusI10 = false;
                        rectSeatI10.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusI10 = true;
                        rectSeatI10.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "I10";

                    }
                }
            }


            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatJ1Pos.contains(mousePos.x,mousePos.y) && reserveJ1 == false)
                {
                    if(statusJ1)
                    {
                        statusJ1 = false;
                        rectSeatJ1.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusJ1 = true;
                        rectSeatJ1.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "J1";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatJ2Pos.contains(mousePos.x,mousePos.y) && reserveJ2 == false)
                {
                    if(statusJ2)
                    {
                        statusJ2 = false;
                        rectSeatJ2.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusJ2 = true;
                        rectSeatJ2.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "J2";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatJ3Pos.contains(mousePos.x,mousePos.y) && reserveJ3 == false)
                {
                    if(statusJ3)
                    {
                        statusJ3 = false;
                        rectSeatJ3.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusJ3 = true;
                        rectSeatJ3.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "J3";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatJ4Pos.contains(mousePos.x,mousePos.y) && reserveJ4 == false)
                {
                    if(statusJ4)
                    {
                        statusJ4 = false;
                        rectSeatJ4.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusJ4 = true;
                        rectSeatJ4.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "J4";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatJ5Pos.contains(mousePos.x,mousePos.y) && reserveJ5 == false)
                {
                    if(statusJ5)
                    {
                        statusJ5 = false;
                        rectSeatJ5.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusJ5 = true;
                        rectSeatJ5.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "J5";

                    }
                }
            }

                         if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatJ6Pos.contains(mousePos.x,mousePos.y) && reserveJ6 == false)
                {
                    if(statusJ6)
                    {
                        statusJ6 = false;
                        rectSeatJ6.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusJ6 = true;
                        rectSeatJ6.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "J6";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatJ7Pos.contains(mousePos.x,mousePos.y) && reserveJ7 == false)
                {
                    if(statusJ7)
                    {
                        statusJ7 = false;
                        rectSeatJ7.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusJ7 = true;
                        rectSeatJ7.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "J7";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatJ8Pos.contains(mousePos.x,mousePos.y) && reserveJ8 == false)
                {
                    if(statusJ8)
                    {
                        statusJ8 = false;
                        rectSeatJ8.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusJ8 = true;
                        rectSeatJ8.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "J8";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatJ9Pos.contains(mousePos.x,mousePos.y) && reserveJ9 == false)
                {
                    if(statusJ9)
                    {
                        statusJ9 = false;
                        rectSeatJ9.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusJ9 = true;
                        rectSeatJ9.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "J9";

                    }
                }
            }

            if (customerChoiceSeat.type == sf::Event::MouseButtonPressed)
            {
                if (customerChoiceSeat.mouseButton.button == sf::Mouse::Left && rectSeatJ10Pos.contains(mousePos.x,mousePos.y) && reserveJ10 == false)
                {
                    if(statusJ10)
                    {
                        statusJ10 = false;
                        rectSeatJ10.setFillColor(sf::Color::Green);
                        reserveQuanti--;
                    }
                    else
                    {
                        statusJ10 = true;
                        rectSeatJ10.setFillColor(sf::Color::Blue);
                        reserveQuanti++;

                        (customerData+(customerInDatabase+reserveQuanti))->seat = "J10";

                    }
                }
            }

            loadCustomerFromFile(textFileName);

            for(int i = 0; i<customerInDatabase; i++)
            {
                if((customerData+i)->seat == "A1")
                {
                    rectSeatA1.setFillColor(sf::Color::Red);
                    reserveA1 = true;
                }

                if((customerData+i)->seat == "A2")
                {
                    rectSeatA2.setFillColor(sf::Color::Red);
                    reserveA2 = true;
                }

                if((customerData+i)->seat == "A3")
                {
                    rectSeatA3.setFillColor(sf::Color::Red);
                    reserveA3 = true;
                }

                if((customerData+i)->seat == "A4")
                {
                    rectSeatA4.setFillColor(sf::Color::Red);
                    reserveA4 = true;
                }

                if((customerData+i)->seat == "A5")
                {
                    rectSeatA5.setFillColor(sf::Color::Red);
                    reserveA5 = true;
                }

                if((customerData+i)->seat == "A6")
                {
                    rectSeatA6.setFillColor(sf::Color::Red);
                    reserveA6 = true;
                }

                if((customerData+i)->seat == "A7")
                {
                    rectSeatA7.setFillColor(sf::Color::Red);
                    reserveA7 = true;
                }

                if((customerData+i)->seat == "A8")
                {
                    rectSeatA8.setFillColor(sf::Color::Red);
                    reserveA8 = true;
                }

                if((customerData+i)->seat == "A9")
                {
                    rectSeatA9.setFillColor(sf::Color::Red);
                    reserveA9 = true;
                }

                if((customerData+i)->seat == "A10")
                {
                    rectSeatA10.setFillColor(sf::Color::Red);
                    reserveA10 = true;
                }


                if((customerData+i)->seat == "B1")
                {
                    rectSeatB1.setFillColor(sf::Color::Red);
                    reserveB1 = true;
                }

                if((customerData+i)->seat == "B2")
                {
                    rectSeatB2.setFillColor(sf::Color::Red);
                    reserveB2 = true;
                }

                if((customerData+i)->seat == "B3")
                {
                    rectSeatB3.setFillColor(sf::Color::Red);
                    reserveB3 = true;
                }

                if((customerData+i)->seat == "B4")
                {
                    rectSeatB4.setFillColor(sf::Color::Red);
                    reserveB4 = true;
                }

                if((customerData+i)->seat == "B5")
                {
                    rectSeatB5.setFillColor(sf::Color::Red);
                    reserveB5 = true;
                }

                if((customerData+i)->seat == "B6")
                {
                    rectSeatB6.setFillColor(sf::Color::Red);
                    reserveB6 = true;
                }

                if((customerData+i)->seat == "B7")
                {
                    rectSeatB7.setFillColor(sf::Color::Red);
                    reserveB7 = true;
                }

                if((customerData+i)->seat == "B8")
                {
                    rectSeatB8.setFillColor(sf::Color::Red);
                    reserveB8 = true;
                }

                if((customerData+i)->seat == "B9")
                {
                    rectSeatB9.setFillColor(sf::Color::Red);
                    reserveB9 = true;
                }

                if((customerData+i)->seat == "B10")
                {
                    rectSeatB10.setFillColor(sf::Color::Red);
                    reserveB10 = true;
                }


                if((customerData+i)->seat == "C1")
                {
                    rectSeatC1.setFillColor(sf::Color::Red);
                    reserveC1 = true;
                }

                if((customerData+i)->seat == "C2")
                {
                    rectSeatC2.setFillColor(sf::Color::Red);
                    reserveC2 = true;
                }

                if((customerData+i)->seat == "C3")
                {
                    rectSeatC3.setFillColor(sf::Color::Red);
                    reserveC3 = true;
                }

                if((customerData+i)->seat == "C4")
                {
                    rectSeatC4.setFillColor(sf::Color::Red);
                    reserveC4 = true;
                }

                if((customerData+i)->seat == "C5")
                {
                    rectSeatC5.setFillColor(sf::Color::Red);
                    reserveC5 = true;
                }

                if((customerData+i)->seat == "C6")
                {
                    rectSeatC6.setFillColor(sf::Color::Red);
                    reserveC6 = true;
                }

                if((customerData+i)->seat == "C7")
                {
                    rectSeatC7.setFillColor(sf::Color::Red);
                    reserveC7 = true;
                }

                if((customerData+i)->seat == "C8")
                {
                    rectSeatC8.setFillColor(sf::Color::Red);
                    reserveC8 = true;
                }

                if((customerData+i)->seat == "C9")
                {
                    rectSeatC9.setFillColor(sf::Color::Red);
                    reserveC9 = true;
                }

                if((customerData+i)->seat == "C10")
                {
                    rectSeatC10.setFillColor(sf::Color::Red);
                    reserveC10 = true;
                }


                if((customerData+i)->seat == "D1")
                {
                    rectSeatD1.setFillColor(sf::Color::Red);
                    reserveD1 = true;
                }

                if((customerData+i)->seat == "D2")
                {
                    rectSeatD2.setFillColor(sf::Color::Red);
                    reserveD2 = true;
                }

                if((customerData+i)->seat == "D3")
                {
                    rectSeatD3.setFillColor(sf::Color::Red);
                    reserveD3 = true;
                }

                if((customerData+i)->seat == "D4")
                {
                    rectSeatD4.setFillColor(sf::Color::Red);
                    reserveD4 = true;
                }

                if((customerData+i)->seat == "D5")
                {
                    rectSeatD5.setFillColor(sf::Color::Red);
                    reserveD5 = true;
                }

                if((customerData+i)->seat == "D6")
                {
                    rectSeatD6.setFillColor(sf::Color::Red);
                    reserveD6 = true;
                }

                if((customerData+i)->seat == "D7")
                {
                    rectSeatD7.setFillColor(sf::Color::Red);
                    reserveD7 = true;
                }

                if((customerData+i)->seat == "D8")
                {
                    rectSeatD8.setFillColor(sf::Color::Red);
                    reserveD8 = true;
                }

                if((customerData+i)->seat == "D9")
                {
                    rectSeatD9.setFillColor(sf::Color::Red);
                    reserveD9 = true;
                }

                if((customerData+i)->seat == "D10")
                {
                    rectSeatD10.setFillColor(sf::Color::Red);
                    reserveD10 = true;
                }


                if((customerData+i)->seat == "E1")
                {
                    rectSeatE1.setFillColor(sf::Color::Red);
                    reserveE1 = true;
                }

                if((customerData+i)->seat == "E2")
                {
                    rectSeatE2.setFillColor(sf::Color::Red);
                    reserveE2 = true;
                }

                if((customerData+i)->seat == "E3")
                {
                    rectSeatE3.setFillColor(sf::Color::Red);
                    reserveE3 = true;
                }

                if((customerData+i)->seat == "E4")
                {
                    rectSeatE4.setFillColor(sf::Color::Red);
                    reserveE4 = true;
                }

                if((customerData+i)->seat == "E5")
                {
                    rectSeatE5.setFillColor(sf::Color::Red);
                    reserveE5 = true;
                }

                if((customerData+i)->seat == "E6")
                {
                    rectSeatE6.setFillColor(sf::Color::Red);
                    reserveE6 = true;
                }

                if((customerData+i)->seat == "E7")
                {
                    rectSeatE7.setFillColor(sf::Color::Red);
                    reserveE7 = true;
                }

                if((customerData+i)->seat == "E8")
                {
                    rectSeatE8.setFillColor(sf::Color::Red);
                    reserveE8 = true;
                }

                if((customerData+i)->seat == "E9")
                {
                    rectSeatE9.setFillColor(sf::Color::Red);
                    reserveE9 = true;
                }

                if((customerData+i)->seat == "E10")
                {
                    rectSeatE10.setFillColor(sf::Color::Red);
                    reserveE10 = true;
                }


                if((customerData+i)->seat == "F1")
                {
                    rectSeatF1.setFillColor(sf::Color::Red);
                    reserveF1 = true;
                }

                if((customerData+i)->seat == "F2")
                {
                    rectSeatF2.setFillColor(sf::Color::Red);
                    reserveF2 = true;
                }

                if((customerData+i)->seat == "F3")
                {
                    rectSeatF3.setFillColor(sf::Color::Red);
                    reserveF3 = true;
                }

                if((customerData+i)->seat == "F4")
                {
                    rectSeatF4.setFillColor(sf::Color::Red);
                    reserveF4 = true;
                }

                if((customerData+i)->seat == "F5")
                {
                    rectSeatF5.setFillColor(sf::Color::Red);
                    reserveF5 = true;
                }

                if((customerData+i)->seat == "F6")
                {
                    rectSeatF6.setFillColor(sf::Color::Red);
                    reserveF6 = true;
                }

                if((customerData+i)->seat == "F7")
                {
                    rectSeatF7.setFillColor(sf::Color::Red);
                    reserveF7 = true;
                }

                if((customerData+i)->seat == "F8")
                {
                    rectSeatF8.setFillColor(sf::Color::Red);
                    reserveF8 = true;
                }

                if((customerData+i)->seat == "F9")
                {
                    rectSeatF9.setFillColor(sf::Color::Red);
                    reserveF9 = true;
                }

                if((customerData+i)->seat == "F10")
                {
                    rectSeatF10.setFillColor(sf::Color::Red);
                    reserveF10 = true;
                }


                if((customerData+i)->seat == "G1")
                {
                    rectSeatG1.setFillColor(sf::Color::Red);
                    reserveG1 = true;
                }

                if((customerData+i)->seat == "G2")
                {
                    rectSeatG2.setFillColor(sf::Color::Red);
                    reserveG2 = true;
                }

                if((customerData+i)->seat == "G3")
                {
                    rectSeatG3.setFillColor(sf::Color::Red);
                    reserveG3 = true;
                }

                if((customerData+i)->seat == "G4")
                {
                    rectSeatG4.setFillColor(sf::Color::Red);
                    reserveG4 = true;
                }

                if((customerData+i)->seat == "G5")
                {
                    rectSeatG5.setFillColor(sf::Color::Red);
                    reserveG5 = true;
                }

                if((customerData+i)->seat == "G6")
                {
                    rectSeatG6.setFillColor(sf::Color::Red);
                    reserveG6 = true;
                }

                if((customerData+i)->seat == "G7")
                {
                    rectSeatG7.setFillColor(sf::Color::Red);
                    reserveG7 = true;
                }

                if((customerData+i)->seat == "G8")
                {
                    rectSeatG8.setFillColor(sf::Color::Red);
                    reserveG8 = true;
                }

                if((customerData+i)->seat == "G9")
                {
                    rectSeatG9.setFillColor(sf::Color::Red);
                    reserveG9 = true;
                }

                if((customerData+i)->seat == "G10")
                {
                    rectSeatG10.setFillColor(sf::Color::Red);
                    reserveG10 = true;
                }


                if((customerData+i)->seat == "H1")
                {
                    rectSeatH1.setFillColor(sf::Color::Red);
                    reserveH1 = true;
                }

                if((customerData+i)->seat == "H2")
                {
                    rectSeatH2.setFillColor(sf::Color::Red);
                    reserveH2 = true;
                }

                if((customerData+i)->seat == "H3")
                {
                    rectSeatH3.setFillColor(sf::Color::Red);
                    reserveH3 = true;
                }

                if((customerData+i)->seat == "H4")
                {
                    rectSeatH4.setFillColor(sf::Color::Red);
                    reserveH4 = true;
                }

                if((customerData+i)->seat == "H5")
                {
                    rectSeatH5.setFillColor(sf::Color::Red);
                    reserveH5 = true;
                }

                if((customerData+i)->seat == "H6")
                {
                    rectSeatH6.setFillColor(sf::Color::Red);
                    reserveH6 = true;
                }

                if((customerData+i)->seat == "H7")
                {
                    rectSeatH7.setFillColor(sf::Color::Red);
                    reserveH7 = true;
                }

                if((customerData+i)->seat == "H8")
                {
                    rectSeatH8.setFillColor(sf::Color::Red);
                    reserveH8 = true;
                }

                if((customerData+i)->seat == "H9")
                {
                    rectSeatH9.setFillColor(sf::Color::Red);
                    reserveH9 = true;
                }

                if((customerData+i)->seat == "H10")
                {
                    rectSeatH10.setFillColor(sf::Color::Red);
                    reserveH10 = true;
                }


                if((customerData+i)->seat == "I1")
                {
                    rectSeatI1.setFillColor(sf::Color::Red);
                    reserveI1 = true;
                }

                if((customerData+i)->seat == "I2")
                {
                    rectSeatI2.setFillColor(sf::Color::Red);
                    reserveI2 = true;
                }

                if((customerData+i)->seat == "I3")
                {
                    rectSeatI3.setFillColor(sf::Color::Red);
                    reserveI3 = true;
                }

                if((customerData+i)->seat == "I4")
                {
                    rectSeatI4.setFillColor(sf::Color::Red);
                    reserveI4 = true;
                }

                if((customerData+i)->seat == "I5")
                {
                    rectSeatI5.setFillColor(sf::Color::Red);
                    reserveI5 = true;
                }

                if((customerData+i)->seat == "I6")
                {
                    rectSeatI6.setFillColor(sf::Color::Red);
                    reserveI6 = true;
                }

                if((customerData+i)->seat == "I7")
                {
                    rectSeatI7.setFillColor(sf::Color::Red);
                    reserveI7 = true;
                }

                if((customerData+i)->seat == "I8")
                {
                    rectSeatI8.setFillColor(sf::Color::Red);
                    reserveI8 = true;
                }

                if((customerData+i)->seat == "I9")
                {
                    rectSeatI9.setFillColor(sf::Color::Red);
                    reserveI9 = true;
                }

                if((customerData+i)->seat == "I10")
                {
                    rectSeatI10.setFillColor(sf::Color::Red);
                    reserveI10 = true;
                }


                if((customerData+i)->seat == "J1")
                {
                    rectSeatJ1.setFillColor(sf::Color::Red);
                    reserveJ1 = true;
                }

                if((customerData+i)->seat == "J2")
                {
                    rectSeatJ2.setFillColor(sf::Color::Red);
                    reserveJ2 = true;
                }

                if((customerData+i)->seat == "J3")
                {
                    rectSeatJ3.setFillColor(sf::Color::Red);
                    reserveJ3 = true;
                }

                if((customerData+i)->seat == "J4")
                {
                    rectSeatJ4.setFillColor(sf::Color::Red);
                    reserveJ4 = true;
                }

                if((customerData+i)->seat == "J5")
                {
                    rectSeatJ5.setFillColor(sf::Color::Red);
                    reserveJ5 = true;
                }

                if((customerData+i)->seat == "J6")
                {
                    rectSeatJ6.setFillColor(sf::Color::Red);
                    reserveJ6 = true;
                }

                if((customerData+i)->seat == "J7")
                {
                    rectSeatJ7.setFillColor(sf::Color::Red);
                    reserveJ7 = true;
                }

                if((customerData+i)->seat == "J8")
                {
                    rectSeatJ8.setFillColor(sf::Color::Red);
                    reserveJ8 = true;
                }

                if((customerData+i)->seat == "J9")
                {
                    rectSeatJ9.setFillColor(sf::Color::Red);
                    reserveJ9 = true;
                }

                if((customerData+i)->seat == "J10")
                {
                    rectSeatJ10.setFillColor(sf::Color::Red);
                    reserveJ10 = true;
                }

            }

        }

        window.draw(spriteSeatBackground);

        window.draw(rectSeatA1);
        window.draw(rectSeatA2);
        window.draw(rectSeatA3);
        window.draw(rectSeatA4);
        window.draw(rectSeatA5);
        window.draw(rectSeatA6);
        window.draw(rectSeatA7);
        window.draw(rectSeatA8);
        window.draw(rectSeatA9);
        window.draw(rectSeatA10);

        window.draw(rectSeatB1);
        window.draw(rectSeatB2);
        window.draw(rectSeatB3);
        window.draw(rectSeatB4);
        window.draw(rectSeatB5);
        window.draw(rectSeatB6);
        window.draw(rectSeatB7);
        window.draw(rectSeatB8);
        window.draw(rectSeatB9);
        window.draw(rectSeatB10);

        window.draw(rectSeatC1);
        window.draw(rectSeatC2);
        window.draw(rectSeatC3);
        window.draw(rectSeatC4);
        window.draw(rectSeatC5);
        window.draw(rectSeatC6);
        window.draw(rectSeatC7);
        window.draw(rectSeatC8);
        window.draw(rectSeatC9);
        window.draw(rectSeatC10);

        window.draw(rectSeatD1);
        window.draw(rectSeatD2);
        window.draw(rectSeatD3);
        window.draw(rectSeatD4);
        window.draw(rectSeatD5);
        window.draw(rectSeatD6);
        window.draw(rectSeatD7);
        window.draw(rectSeatD8);
        window.draw(rectSeatD9);
        window.draw(rectSeatD10);

        window.draw(rectSeatE1);
        window.draw(rectSeatE2);
        window.draw(rectSeatE3);
        window.draw(rectSeatE4);
        window.draw(rectSeatE5);
        window.draw(rectSeatE6);
        window.draw(rectSeatE7);
        window.draw(rectSeatE8);
        window.draw(rectSeatE9);
        window.draw(rectSeatE10);

        window.draw(rectSeatF1);
        window.draw(rectSeatF2);
        window.draw(rectSeatF3);
        window.draw(rectSeatF4);
        window.draw(rectSeatF5);
        window.draw(rectSeatF6);
        window.draw(rectSeatF7);
        window.draw(rectSeatF8);
        window.draw(rectSeatF9);
        window.draw(rectSeatF10);

        window.draw(rectSeatG1);
        window.draw(rectSeatG2);
        window.draw(rectSeatG3);
        window.draw(rectSeatG4);
        window.draw(rectSeatG5);
        window.draw(rectSeatG6);
        window.draw(rectSeatG7);
        window.draw(rectSeatG8);
        window.draw(rectSeatG9);
        window.draw(rectSeatG10);

        window.draw(rectSeatH1);
        window.draw(rectSeatH2);
        window.draw(rectSeatH3);
        window.draw(rectSeatH4);
        window.draw(rectSeatH5);
        window.draw(rectSeatH6);
        window.draw(rectSeatH7);
        window.draw(rectSeatH8);
        window.draw(rectSeatH9);
        window.draw(rectSeatH10);

        window.draw(rectSeatI1);
        window.draw(rectSeatI2);
        window.draw(rectSeatI3);
        window.draw(rectSeatI4);
        window.draw(rectSeatI5);
        window.draw(rectSeatI6);
        window.draw(rectSeatI7);
        window.draw(rectSeatI8);
        window.draw(rectSeatI9);
        window.draw(rectSeatI10);

        window.draw(rectSeatJ1);
        window.draw(rectSeatJ2);
        window.draw(rectSeatJ3);
        window.draw(rectSeatJ4);
        window.draw(rectSeatJ5);
        window.draw(rectSeatJ6);
        window.draw(rectSeatJ7);
        window.draw(rectSeatJ8);
        window.draw(rectSeatJ9);
        window.draw(rectSeatJ10);

        window.draw(rectSubmit);
        window.draw(submitText);

        window.display();

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Cinema::paymentProcess()
{
    /// WINDOW CONFIG
    sf::RenderWindow window(sf::VideoMode(950,700), "C I N E M A  + +", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);

    /// IMAGE
    sf::Texture paymentBackground;
    paymentBackground.loadFromFile("source/PAYMENT.jpg");

    sf::Sprite spritePaymentBackground(paymentBackground);
    spritePaymentBackground.setPosition(0,0);

    while (window.isOpen())
    {
        sf::Event customerChoiceTime;

        while (window.pollEvent(customerChoiceTime))
        {
            if (customerChoiceTime.type == sf::Event::Closed)
                window.close();

            window.draw(spritePaymentBackground);
            window.display();
        }
    }
}

void searchCustomerData()
{
    system("cls");

    loadDetailsFromFile();

    char choiceMovie;
    string choiceDate;
    char choiceTime;

    string databaseName;
    string movie;
    string date;
    string time;

    EnterMovie:

    headerDisplay();
    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(20,26); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(45,14); cout << "*** C U S T O M E R  D A T A ***" << endl;

    gotoxy(45,17); cout << "Enter Movie: ";
    gotoxy(50,19); cout << "[1] " + Details[0].title;
    gotoxy(50,21); cout << "[2] " + Details[1].title;
    gotoxy(50,23); cout << "[3] " + Details[2].title;
    gotoxy(58,17); cin >> choiceMovie;

    switch(choiceMovie)
    {
        case '1':
            movie = "[" + Details[0].title + "]-";
            break;

        case '2':
            movie = "[" + Details[1].title + "]-";
            break;

        case '3':
            movie = "[" + Details[2].title + "]-";
            break;

        default:
            system("cls");
            goto EnterMovie;
    }

    system("cls");

    EnterDate:

    headerDisplay();
    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(20,34); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(48,14); cout << "*** C U S T O M E R  D A T A ***" << endl;

    gotoxy(40,17); cout << "Enter Date: ";
    gotoxy(42,19); cout << "[1] " + Dates.DATE1;
    gotoxy(42,21); cout << "[2] " + Dates.DATE2;
    gotoxy(42,23); cout << "[3] " + Dates.DATE3;
    gotoxy(42,25); cout << "[4] " + Dates.DATE4;
    gotoxy(42,27); cout << "[5] " + Dates.DATE5;
    gotoxy(42,29); cout << "[6] " + Dates.DATE6;
    gotoxy(42,31); cout << "[7] " + Dates.DATE7;

    gotoxy(70,19); cout << "[8] " + Dates.DATE8;
    gotoxy(70,21); cout << "[9] " + Dates.DATE9;
    gotoxy(70,23); cout << "[10] " + Dates.DATE10;
    gotoxy(70,25); cout << "[11] " + Dates.DATE11;
    gotoxy(70,27); cout << "[12] " + Dates.DATE12;
    gotoxy(70,29); cout << "[13] " + Dates.DATE13;
    gotoxy(70,31); cout << "[14] " + Dates.DATE14;

    gotoxy(52,17); cin >> choiceDate;

	if ( choiceDate == "1")
	{
		date = "[" + Dates.DATE1 +"]-";
    }
	else if ( choiceDate == "2")
    {
        date = "[" + Dates.DATE2 +"]-";
    }
    else if ( choiceDate == "3")
    {
        date = "[" + Dates.DATE3 +"]-";
    }
    else if ( choiceDate == "4")
    {
        date = "[" + Dates.DATE4 +"]-";
    }
    else if (choiceDate == "5")
    {
        date = "[" + Dates.DATE5 +"]-";
    }
    else if (choiceDate == "6")
    {
        date = "[" + Dates.DATE6 +"]-";
    }
    else if (choiceDate == "7")
    {
        date = "[" + Dates.DATE7 +"]-";
    }
    else if (choiceDate == "8")
    {
        date = "[" + Dates.DATE8 +"]-";
    }
    else if (choiceDate == "9")
    {
        date = "[" + Dates.DATE9 +"]-";
    }
    else if (choiceDate == "10")
    {
        date = "[" + Dates.DATE11 +"]-";
    }
    else if (choiceDate == "11")
    {
        date = "[" + Dates.DATE11 +"]-";
    }
    else if (choiceDate == "12")
    {
        date = "[" + Dates.DATE12 +"]-";
    }
    else if (choiceDate == "13")
    {
        date = "[" + Dates.DATE13 +"]-";
    }
    else if (choiceDate == "14")
    {
        date = "[" + Dates.DATE14 +"]-";
    }
    else
    {
        system("cls");
        goto EnterDate;
    }

    system("cls");

    EnterTime:

    headerDisplay();
    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(48,14); cout << "*** C U S T O M E R  D A T A ***" << endl;

    gotoxy(20,26); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(48,17); cout << "Enter Time: ";
    gotoxy(57,19); cout << "[1] " + Dates.sTime1 <<endl;
    gotoxy(57,21); cout << "[2] " + Dates.sTime2 <<endl;
    gotoxy(57,23); cout << "[3] " + Dates.sTime3 <<endl;
    gotoxy(60,17); cin >> choiceTime;

    switch(choiceTime)
    {
        case '1':
            time = Dates.sTime1;
            break;

        case '2':
            time = Dates.sTime2;
            break;

        case '3':
            time = Dates.sTime3;
            break;

        default:
            system("cls");
            goto EnterTime;
    }

    system("cls");

    databaseName = movie + date + time + ".txt";

    loadCustomerFromFile(databaseName);

}

void Cinema::viewCustomerData()
{
    searchCustomerData();

    headerDisplay();
    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(48,14); cout << "*** C U S T O M E R  D A T A ***" << endl;

    if(customerInDatabase > 0)
    {
        for(int i = 0; i < customerInDatabase; i++)
        {
            cout << "\n\n\t\t\t\t\t\t   |SEAT NO.|: " << (i+1);
            cout << "\n\t\t\t\t\t\t   |SEAT CODE|: " << customerData[i].seat << endl;
        }


        cout <<"\n\n\t\t    \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t\tThere is NO CUSTOMER DATA yet" << endl;
    }

    requireEnter();
}

void Cinema::editCustomerData()
{
    system("cls");

    loadDetailsFromFile();

    char choiceMovie;
    string choiceDate;
    char choiceTime;

    string databaseName;
    string movie;
    string date;
    string time;

    EnterMovie:

    headerDisplay();
    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(20,26); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(45,14); cout << "*** C U S T O M E R  D A T A ***" << endl;

    gotoxy(45,17); cout << "Enter Movie: ";
    gotoxy(50,19); cout << "[1] " + Details[0].title;
    gotoxy(50,21); cout << "[2] " + Details[1].title;
    gotoxy(50,23); cout << "[3] " + Details[2].title;
    gotoxy(58,17); cin >> choiceMovie;

    switch(choiceMovie)
    {
        case '1':
            movie = "[" + Details[0].title + "]-";
            break;

        case '2':
            movie = "[" + Details[1].title + "]-";
            break;

        case '3':
            movie = "[" + Details[2].title + "]-";
            break;

        default:
            system("cls");
            goto EnterMovie;
    }

    system("cls");

    EnterDate:

    headerDisplay();
    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(20,34); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(48,14); cout << "*** C U S T O M E R  D A T A ***" << endl;

    gotoxy(40,17); cout << "Enter Date: ";
    gotoxy(42,19); cout << "[1] " + Dates.DATE1;
    gotoxy(42,21); cout << "[2] " + Dates.DATE2;
    gotoxy(42,23); cout << "[3] " + Dates.DATE3;
    gotoxy(42,25); cout << "[4] " + Dates.DATE4;
    gotoxy(42,27); cout << "[5] " + Dates.DATE5;
    gotoxy(42,29); cout << "[6] " + Dates.DATE6;
    gotoxy(42,31); cout << "[7] " + Dates.DATE7;

    gotoxy(70,19); cout << "[8] " + Dates.DATE8;
    gotoxy(70,21); cout << "[9] " + Dates.DATE9;
    gotoxy(70,23); cout << "[10] " + Dates.DATE10;
    gotoxy(70,25); cout << "[11] " + Dates.DATE11;
    gotoxy(70,27); cout << "[12] " + Dates.DATE12;
    gotoxy(70,29); cout << "[13] " + Dates.DATE13;
    gotoxy(70,31); cout << "[14] " + Dates.DATE14;

    gotoxy(52,17); cin >> choiceDate;

	if ( choiceDate == "1")
	{
		date = "[" + Dates.DATE1 +"]-";
    }
	else if ( choiceDate == "2")
    {
        date = "[" + Dates.DATE2 +"]-";
    }
    else if ( choiceDate == "3")
    {
        date = "[" + Dates.DATE3 +"]-";
    }
    else if ( choiceDate == "4")
    {
        date = "[" + Dates.DATE4 +"]-";
    }
    else if (choiceDate == "5")
    {
        date = "[" + Dates.DATE5 +"]-";
    }
    else if (choiceDate == "6")
    {
        date = "[" + Dates.DATE6 +"]-";
    }
    else if (choiceDate == "7")
    {
        date = "[" + Dates.DATE7 +"]-";
    }
    else if (choiceDate == "8")
    {
        date = "[" + Dates.DATE8 +"]-";
    }
    else if (choiceDate == "9")
    {
        date = "[" + Dates.DATE9 +"]-";
    }
    else if (choiceDate == "10")
    {
        date = "[" + Dates.DATE11 +"]-";
    }
    else if (choiceDate == "11")
    {
        date = "[" + Dates.DATE11 +"]-";
    }
    else if (choiceDate == "12")
    {
        date = "[" + Dates.DATE12 +"]-";
    }
    else if (choiceDate == "13")
    {
        date = "[" + Dates.DATE13 +"]-";
    }
    else if (choiceDate == "14")
    {
        date = "[" + Dates.DATE14 +"]-";
    }
    else
    {
        system("cls");
        goto EnterDate;
    }

    system("cls");

    EnterTime:

    headerDisplay();
    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(48,14); cout << "*** C U S T O M E R  D A T A ***" << endl;

    gotoxy(20,26); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(48,17); cout << "Enter Time: ";
    gotoxy(57,19); cout << "[1] " + Dates.sTime1 <<endl;
    gotoxy(57,21); cout << "[2] " + Dates.sTime2 <<endl;
    gotoxy(57,23); cout << "[3] " + Dates.sTime3 <<endl;
    gotoxy(60,17); cin >> choiceTime;

    switch(choiceTime)
    {
        case '1':
            time = Dates.sTime1;
            break;

        case '2':
            time = Dates.sTime2;
            break;

        case '3':
            time = Dates.sTime3;
            break;

        default:
            system("cls");
            goto EnterTime;
    }

    system("cls");

    databaseName = movie + date + time + ".txt";

    loadCustomerFromFile(databaseName);

    short seatNo;
    short notAvailable;

    editCustomerDataMenu:

    headerDisplay();

    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(48,14); cout << "*** C U S T O M E R  D A T A ***" << endl;

    if(customerInDatabase > 0)
    {
        gotoxy(35,16); cout << "Enter the seat no. you would like to edit: ";
        gotoxy(78,16); cin >> seatNo;

        gotoxy(35,18); cout << "Enter new seat code using format 'A1': ";
        gotoxy(74,18); cin >> customerData[seatNo-1].seat;

        gotoxy(20,21); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t\tThere is NO CUSTOMER DATA yet" << endl;
    }

    for(int i=0; i<customerInDatabase; i++)
    {
        if(customerData[seatNo].seat == customerData[i].seat)
        {
            notAvailable++;
        }
    }

    cout << notAvailable << endl;
    cout << customerInDatabase << endl;

    if(notAvailable <= 1)
    {
        saveUpdateSeatToFile(databaseName);
    }
    else
    {
        cout << "Seat was already reserved!" << endl;
    }

    requireEnter();
    EXIT_SUCCESS;
}

void saveUpdateSeatToFile(string fileName)
{
    ofstream file("Database/"+fileName);

    if(file.is_open())
    {
        file << customerInDatabase << endl;

        for(int i = 0; i<customerInDatabase; i++)
        {
            file << (customerData+i)->seat << endl;
        }

        file.close();
    }
    else
    {
        cout << "CAN'T SAVE TO DATABASE!!!" << endl;
    }
}

void Cinema::deleteCustomerData()
{
    system("cls");

    loadDetailsFromFile();

    char choiceMovie;
    string choiceDate;
    char choiceTime;

    string databaseName;
    string movie;
    string date;
    string time;

    EnterMovie:

    headerDisplay();
    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(20,26); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(45,14); cout << "*** C U S T O M E R  D A T A ***" << endl;

    gotoxy(45,17); cout << "Enter Movie: ";
    gotoxy(50,19); cout << "[1] " + Details[0].title;
    gotoxy(50,21); cout << "[2] " + Details[1].title;
    gotoxy(50,23); cout << "[3] " + Details[2].title;
    gotoxy(58,17); cin >> choiceMovie;

    switch(choiceMovie)
    {
        case '1':
            movie = "[" + Details[0].title + "]-";
            break;

        case '2':
            movie = "[" + Details[1].title + "]-";
            break;

        case '3':
            movie = "[" + Details[2].title + "]-";
            break;

        default:
            system("cls");
            goto EnterMovie;
    }

    system("cls");

    EnterDate:

    headerDisplay();
    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(20,34); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(48,14); cout << "*** C U S T O M E R  D A T A ***" << endl;

    gotoxy(40,17); cout << "Enter Date: ";
    gotoxy(42,19); cout << "[1] " + Dates.DATE1;
    gotoxy(42,21); cout << "[2] " + Dates.DATE2;
    gotoxy(42,23); cout << "[3] " + Dates.DATE3;
    gotoxy(42,25); cout << "[4] " + Dates.DATE4;
    gotoxy(42,27); cout << "[5] " + Dates.DATE5;
    gotoxy(42,29); cout << "[6] " + Dates.DATE6;
    gotoxy(42,31); cout << "[7] " + Dates.DATE7;

    gotoxy(70,19); cout << "[8] " + Dates.DATE8;
    gotoxy(70,21); cout << "[9] " + Dates.DATE9;
    gotoxy(70,23); cout << "[10] " + Dates.DATE10;
    gotoxy(70,25); cout << "[11] " + Dates.DATE11;
    gotoxy(70,27); cout << "[12] " + Dates.DATE12;
    gotoxy(70,29); cout << "[13] " + Dates.DATE13;
    gotoxy(70,31); cout << "[14] " + Dates.DATE14;

    gotoxy(52,17); cin >> choiceDate;

	if ( choiceDate == "1")
	{
		date = "[" + Dates.DATE1 +"]-";
    }
	else if ( choiceDate == "2")
    {
        date = "[" + Dates.DATE2 +"]-";
    }
    else if ( choiceDate == "3")
    {
        date = "[" + Dates.DATE3 +"]-";
    }
    else if ( choiceDate == "4")
    {
        date = "[" + Dates.DATE4 +"]-";
    }
    else if (choiceDate == "5")
    {
        date = "[" + Dates.DATE5 +"]-";
    }
    else if (choiceDate == "6")
    {
        date = "[" + Dates.DATE6 +"]-";
    }
    else if (choiceDate == "7")
    {
        date = "[" + Dates.DATE7 +"]-";
    }
    else if (choiceDate == "8")
    {
        date = "[" + Dates.DATE8 +"]-";
    }
    else if (choiceDate == "9")
    {
        date = "[" + Dates.DATE9 +"]-";
    }
    else if (choiceDate == "10")
    {
        date = "[" + Dates.DATE11 +"]-";
    }
    else if (choiceDate == "11")
    {
        date = "[" + Dates.DATE11 +"]-";
    }
    else if (choiceDate == "12")
    {
        date = "[" + Dates.DATE12 +"]-";
    }
    else if (choiceDate == "13")
    {
        date = "[" + Dates.DATE13 +"]-";
    }
    else if (choiceDate == "14")
    {
        date = "[" + Dates.DATE14 +"]-";
    }
    else
    {
        system("cls");
        goto EnterDate;
    }

    system("cls");

    EnterTime:

    headerDisplay();
    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(48,14); cout << "*** C U S T O M E R  D A T A ***" << endl;

    gotoxy(20,26); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxy(48,17); cout << "Enter Time: ";
    gotoxy(57,19); cout << "[1] " + Dates.sTime1 <<endl;
    gotoxy(57,21); cout << "[2] " + Dates.sTime2 <<endl;
    gotoxy(57,23); cout << "[3] " + Dates.sTime3 <<endl;
    gotoxy(60,17); cin >> choiceTime;

    switch(choiceTime)
    {
        case '1':
            time = Dates.sTime1;
            break;

        case '2':
            time = Dates.sTime2;
            break;

        case '3':
            time = Dates.sTime3;
            break;

        default:
            system("cls");
            goto EnterTime;
    }

    system("cls");

    databaseName = movie + date + time + ".txt";

    loadCustomerFromFile(databaseName);

    short seatNo;

    deleteCustomerDataMenu:

    headerDisplay();

    gotoxy(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;
    gotoxy(48,14); cout << "*** C U S T O M E R  D A T A ***" << endl;

    gotoxy(35,16); cout << "Enter the seat no. you would like to delete: ";
    gotoxy(80,16); cin >> seatNo;

    if(customerInDatabase >= seatNo && seatNo > 0)
    {
        for(int k = seatNo; k<customerInDatabase; k++)
        {
            (customerData+(k-1))->seat = (customerData+k)->seat;
        }

        cout <<"\n\t\t    \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

        cout << "seat has been removed." << endl;

        customerInDatabase--;
        saveUpdateSeatToFile(databaseName);
    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t\tThere is NO CUSTOMER SEAT like that" << endl;
    }

    requireEnter();
    EXIT_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
