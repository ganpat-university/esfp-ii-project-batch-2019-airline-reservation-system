#include "iostream"
#include "string"
#include "cstring"

using namespace std;
class flights  {		
	protected:
		int count;
		char route[10][100], temp[100], status, status1;
		float prices[10];
	
	public:
		flights()
		{
			strcpy(route[0],"Delhi to Goa");
			prices[0] = 1000;
			count = 0;
		}

};
class details : public flights {
	private:
	char fname[100][100], mname[100][100], lname[100][100];
	char username[100], sex[100][6];
	int age[50];
	int flightNo;
	int passengers;
	float cost;
	public:
		void updateFlights(int n, char username[])
		{
			cout << "\nWelcome " << username << "!\n\n";
			for(int i = count; i < n; i++)
			{
				cout << "Enter route #" << i+1 << ":";
				scanf(" %[^\n]%*c", &temp);
				strcpy(route[i+1], temp);
				cout << "Rate: ";
				cin >> prices[i+1];
				count++;
			}

			system("pause");
			menu(username);
		}
		void displayFlights(char username[])
		{
			for (int i=0; i <= count; i++)
			{
				cout << "Flight #" << i << " :" << route[i];
				cout << "\nRate: " << prices[i] << "\n";
			}
			cout << "\n";

			system("pause");
			menu(username);
		}
		void get(char username[])
		{			
			cout << "\nWelcome " << username << "!\n";
			cout << "\nAvailable Flights\n\n";
			for (int i=0; i <= count; i++) // 
			{
				cout << "Flight #" << i << ": " << route[i];
				cout << "\nRate: " << prices[i] ;
			}
			cout << "\n";

			cout << "\nEnter the following details:-\n\n";
			cout << "Filght number:";
			cin >> flightNo;
			
			cout << "\nNumber of passengers travelling: ";
			cin >> passengers;

			for(int i=0; i < passengers; i++)
			{
				cout << "Passenger #" << i+1 << "\n";
				cout << "\nFirst name: ";
				scanf(" %[^\n]%*c", &fname[i]);
				cout << "Middle name: ";
				scanf(" %[^\n]%*c", &mname[i]);
				cout << "Last name: ";
				scanf(" %[^\n]%*c", &lname[i]);
				cout << "Age: ";
				cin >> age[i];
				cout << "Sex: ";
				scanf(" %[^\n]%*c", &sex[i]);
				cout << "\n";
			}
			cost = prices[flightNo] * passengers;
			cout << "\nCost: " << cost;
			cout << "\nPayment options unavailable at the moment";
			cout << "\nTickets booked successfully!";
			cout << "\nHave a happy flight!\n";

			system("pause");
			menu(username);
		}
void menu(char username[])
{
	system("cls");
	int choice, flights;	
	cout << "\nWelcome " << username << "!\n";
	cout << "\n0. Add flight database.";
	cout << "\n1. Book a flight.";
	cout << "\n2. View flight list.";
	cout << "\n3. Exit.";
	
	cout << "\nWhat would you like to do today?\n";
	cin >> choice;

	switch(choice)
	{
		case 0:
			cout << "How many fights are you going to add?\n";
			cin >> flights;
			system("cls");
			updateFlights(flights, username);
			break;
			
		case 1:
			system("cls");
			get(username);
			break;
		
		case 2:
			system("cls");
			displayFlights(username);
			break;
		case 3:
			cout << "Thank you!\n";
			system("pause");
			break;
		
		default:
			cout << "wot did u du m8.";
			break;
	}
}
};


int main()
{
	details obj1;

	char username[100];
	char x;
	
	cout << "Enter your name to get started: ";
	scanf(" %[^\n]%*c", &username);
	system("cls");
	obj1.menu(username);
	
	return 0;
}
