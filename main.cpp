#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include "Cinema++.h"

using namespace std;

Cinema cinema;

struct Person
{
    string surname;
    string contact;
    string username;
    string password;
};

struct Person Admin[100];
int adminInDatabase;

void gotoxyAdmin(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/// USER DEFINED FUNCTIONS
void headerDisplayAdmin()
{
    gotoxyAdmin(25,2); cout << "\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\t\t\t\t\t\t\xDB2\xDB2\t       \xDB2\xDB2" << endl;
    gotoxyAdmin(23,3); cout << "\xDB2\xDB2                       ____         \t\t\t\xDB2\xDB2\t       \xDB2\xDB2" << endl;
    gotoxyAdmin(23,4); cout << "\xDB2\xDB2\t    || ||\\  || ||     ||\\    /||   //\\" << "\\\t\t\xDB2\xDB2\t       \xDB2\xDB2" << endl;
    gotoxyAdmin(23,5); cout << "\xDB2\xDB2\t    || || \\ || ||---  || \\  / ||  //__\\" << "\\  \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2 \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2" << endl;
    gotoxyAdmin(23,6); cout << "\xDB2\xDB2\t    || ||  \\|| ||___  ||  \\/  || //    \\" << "\\\t\xDB2\xDB2\t       \xDB2\xDB2" << endl;
    gotoxyAdmin(23,7); cout << "\xDB2\xDB2                                \t\t\t\xDB2\xDB2\t       \xDB2\xDB2" << endl;
    gotoxyAdmin(25,8); cout << "\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\t\t\t\t\t\t\xDB2\xDB2\t       \xDB2\xDB2" << endl;
}

void requireEnterAdmin()
{
    char enter;
    cout << "\t\t\t PRESS ENTER TO PROCEED..." << endl;
    enter = _getch();

    while(enter != 13)
    {
        enter = _getch();
    }
}

void adminLoginLog();
void adminMenu();
void addAdmin();
void loadAdminFromFile();
void saveAdminToFile();
void showAdmin();

int main()
{
    char menuChoice;

    loadAdminFromFile();

    /// WINDOW CONFIG
    system("COLOR 70");

    mainmenu:

    headerDisplayAdmin();

    gotoxyAdmin(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxyAdmin(52,14); cout << "*** M A I N M E N U ***" << endl;
    gotoxyAdmin(45,17); cout << "[1] Administration Login" << endl;
    gotoxyAdmin(45,19); cout << "[2] Register for Administrator" << endl;

    gotoxyAdmin(20,25); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxyAdmin(45,21); cout << "Enter Option: " << endl;
    gotoxyAdmin(59,21); scanf("%s",&menuChoice);

    switch(menuChoice)
    {
        case '1':
            system("cls");
            adminLoginLog();
            break;

        case '2':
            system("cls");
            addAdmin();
            break;

        default:
            system("cls");
            goto mainmenu;
            break;
    }

    system("cls");
    goto mainmenu;

}

void adminLoginLog()
{
    headerDisplayAdmin();

    gotoxyAdmin(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxyAdmin(48,14); cout << "*** A D M I N  L O G I N ***" << endl;


    gotoxyAdmin(20,25); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    if(adminInDatabase > 0)
	{
		string user, pass;


		gotoxyAdmin(49,17);cout << "Enter Username: " << endl;

		gotoxyAdmin(49,19);cout << "Enter Password: " << endl;

        gotoxyAdmin(65,17);cin >> user;
		gotoxyAdmin(65,19);cin >> pass;

		for(int i = 0; i<adminInDatabase; i++)
		{
			if(user == (Admin+i)->username && pass == (Admin+i)->password)
			{
                system("cls");
                adminMenu();
			}
			else
            {
                cout << "Invalid input" << endl;
            }
		}
	}
	else
	{
		cout << "There's nobody in database" << endl;
	}

	requireEnterAdmin();
}


void adminMenu()
{
    char adminChoice;

    AdminMenu:

    headerDisplayAdmin();

    gotoxyAdmin(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxyAdmin(45,14); cout << "*** A D M I N I S T R A T I O N ***" << endl;

    gotoxyAdmin(50,17); cout << "[1] Start Reservation" << endl;
    gotoxyAdmin(50,19); cout << "[2] System Update" << endl;
    gotoxyAdmin(50,21); cout << "[3] View Customer's Data" << endl;
    gotoxyAdmin(50,23); cout << "[4] Edit Customer's Data" << endl;
    gotoxyAdmin(50,25); cout << "[5] Delete Customer's Data" << endl;
    gotoxyAdmin(50,27); cout << "[6] Admin Accounts" << endl;

    gotoxyAdmin(20,33); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxyAdmin(50,29); cout << "Enter Option: " << endl;
    gotoxyAdmin(64,29); cin >> adminChoice;

    switch(adminChoice)
    {
        case '1':
            system("cls");
            cinema.mainmenu();
            break;

        case '2':
            system("cls");
            cinema.systemUpdate();
            break;

        case '3':
            system("cls");
            cinema.viewCustomerData();
            break;

        case '4':
            system("cls");
            cinema.editCustomerData();
            break;

        case '5':
            system("cls");
            cinema.deleteCustomerData();
            break;

        case '6':
            system("cls");
            showAdmin();
            break;

        default:
            system("cls");
            goto AdminMenu;
            break;
    }

    system("cls");
    goto AdminMenu;
}

void addAdmin()
{
    headerDisplayAdmin();

    gotoxyAdmin(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxyAdmin(20,27); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxyAdmin(45,14); cout << "*** R E G I S T R A T I O N ***" << endl;

    gotoxyAdmin(47,17); cout << "|SURNAME|: " << endl;
    gotoxyAdmin(47,19); cout << "|CONTACT NO.|: " << endl;
    gotoxyAdmin(47,21); cout << "|USERNAME|: " << endl;
    gotoxyAdmin(47,23); cout << "|PASSWORD|: " << endl;

    gotoxyAdmin(58,17); cin >> (Admin+adminInDatabase)->surname;
    gotoxyAdmin(62,19); cin >> (Admin+adminInDatabase)->contact;
    gotoxyAdmin(59,21); cin >> (Admin+adminInDatabase)->username;
    gotoxyAdmin(59,23); cin >> (Admin+adminInDatabase)->password;

    adminInDatabase++;
    saveAdminToFile();
}

void loadAdminFromFile()
{
    ifstream file("Database/adminFile.txt");

	if(file.is_open())
	{
		file >> adminInDatabase;

		if(adminInDatabase >= 0)
		{
			int i = 0;

			do
			{
				file >> Admin[i].surname;
                file >> Admin[i].contact;
	            file >> Admin[i].username;
	            file >> Admin[i].password;

	            i++;

			}while(!file.eof());
		}
		else
		{
			cout << "Database is empty" << endl;
		}
	}
	else
	{
		cout << "The file doesnt exists" << endl;
	}
}

void saveAdminToFile()
{
    ofstream file("Database/adminFile.txt");

	if(file.is_open())
    {
        file << adminInDatabase << endl;

        for(int i = 0; i<adminInDatabase; i++)
        {
            file << (Admin+i)->surname << endl;
            file << (Admin+i)->contact << endl;
            file << (Admin+i)->username << endl;
            file << (Admin+i)->password << endl;
            file << endl;
        }
        file.close();
    }
    else
    {
        cout << "CAN'T SAVE TO DATABASE!!!" << endl;
    }
}

void showAdmin()
{
    char adminOption;

    adminAccounts:

    headerDisplayAdmin();

    gotoxyAdmin(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxyAdmin(45,14); cout << "*** A D M I N  A C C O U N T S ***" << endl;

    gotoxyAdmin(47,17); cout << "[1] View All Admin Account" << endl;
    gotoxyAdmin(47,19); cout << "[2] Search Admin Account" << endl;
    gotoxyAdmin(47,21); cout << "[3] Delete Admin Account" << endl;

    gotoxyAdmin(47,25); cout <<"\n\t\t    \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

    gotoxyAdmin(47,23); cout << "Enter Option: " << endl;
    gotoxyAdmin(61,23); scanf("%s",&adminOption);

    switch(adminOption)
    {
        case '1':

            system("cls");

            headerDisplayAdmin();

            gotoxyAdmin(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

            gotoxyAdmin(45,14); cout << "*** A D M I N  A C C O U N T S ***" << endl;

            if(adminInDatabase > 0)
            {
                for(int i = 0; i < adminInDatabase; i++)
                {
                    cout << "\n\t\t\t\t\t\t   |ACCOUNT NO.|: " << (i+1) << endl;
                    cout << "\n\t\t\t\t\t\t   |SURNAME|: " << Admin[i].surname << endl;
                    cout << "\n\t\t\t\t\t\t   |CONTACT NO.|: " << Admin[i].contact << endl;
                    cout << "\n\t\t\t\t\t\t   |USERNAME|: " << Admin[i].username + "\n" << endl;
                }

                cout <<"\t\t    \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

            }
            else
            {
                cout << "\t\tThere is NO ADMIN ACCOUNT yet" << endl;
            }

            requireEnterAdmin();

            break;


        case '2':

            system("cls");

            headerDisplayAdmin();

            gotoxyAdmin(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

            gotoxyAdmin(45,14); cout << "*** A D M I N  A C C O U N T S ***" << endl;

            if(adminInDatabase > 0)
            {
                string name;

                cout << "\n\t\t\t\t\t\t   TYPE NAME: ";
                cin >> name;

                for(int i = 0; i<adminInDatabase; i++)
                {
                    if(name == (Admin+i)->surname)
                    {
                        cout << "\n\t\t\t\t\t\t   |Account No.|: " << (i+1) << endl;
                        cout << "\n\t\t\t\t\t\t   |Surname|: " << Admin[i].surname << endl;
                        cout << "\n\t\t\t\t\t\t   |Contact No.|: " << Admin[i].contact << endl;
                        cout << "\n\t\t\t\t\t\t   |Username|: " << Admin[i].username << endl;
                    }
                    else
                    {
                        cout << "Not matched" << endl;
                    }
                }

                cout <<"\n\t\t    \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

            }
            else
            {
                cout << "There is nobody in database what do you want to look for?" << endl;
            }

            requireEnterAdmin();

            break;


        case '3':

            system("cls");

            headerDisplayAdmin();

            gotoxyAdmin(20,11); cout <<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

            gotoxyAdmin(45,14); cout << "*** A D M I N  A C C O U N T S ***" << endl;

            if(adminInDatabase > 0)
            {
                int index;

                cout << "\n\t\t\t\t   Who do you want to remove? Type account no.: ";
                cin >> index;

                if(adminInDatabase >= index && index > 0)
                {
                    for(int k = index; k<adminInDatabase; k++)
                    {
                        (Admin+(k-1))->surname = (Admin+k)->surname;
                        (Admin+(k-1))->contact = (Admin+k)->contact;
                        (Admin+(k-1))->username = (Admin+k)->username;
                        (Admin+(k-1))->password = (Admin+k)->password;
                    }

                    cout <<"\n\t\t    \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;

                    cout << "Admin has been removed." << endl;

                    adminInDatabase--;
                    saveAdminToFile();
                }
                else
                {
                    cout <<"\n\t\t    \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB" << endl;


                    cout << "There is nobody like that" << endl;
                }
            }
            else
            {
                cout << "There is nothing to remove" << endl;
            }

            requireEnterAdmin();

            break;


        default:
            system("cls");
            goto adminAccounts;
            break;
    }
}
