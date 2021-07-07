#include<iostream>
#include <string>
using namespace std;
struct node
{
	string name, num;
	node* next;
};
node* head = NULL, * new_node, * temp;
int len = 0;
void add_con()
{
	int pe;
	cout << "How many Contacts you want to Enter:";
	cin >> pe;
	cout << endl;
	for (int i = 0; i < pe; i++) 
	{
		system("CLS");
		new_node = new node;
		cout << "Enter Contact#" << i + 1 << endl;
		cout << "--------------------" << endl;
		cout << "Name:";
		cin >> new_node->name;
		cout << "--------------------" << endl;
		cout << "Phone number:";
		cin >> new_node->num;
		cout << "--------------------" << endl;
		system("pause");
		new_node->next = NULL;
		if (head == NULL)
		{
			head = new_node;
			temp = new_node;
		}
		else
		{
			temp->next = new_node;
			temp = new_node;
		}
	}
}
void display()
{
	if (head == NULL)
	{
		cout << "------------------------------" << endl;
		cout << "||\tNo Contacts\t    ||" << endl;
		cout << "------------------------------" << endl;
	}
	else
	{
		node* trav = head;
		int count=0;
		while (trav != NULL)
		{	
			cout << "------------------------------" << endl;
			cout << "||Full Name:" << trav->name << "\t\t    ||" << endl;
			cout << "||Phone Number:" << trav->num << "\t    ||" << endl;
			cout << "||Index:" << count+1 << "\t\t    ||" << endl;
			cout << "------------------------------" << endl;
			count++;
			trav = trav->next;
			len++;
			
		}
		cout << "==================================" << endl;
		cout << "||Total contacts in the list = " << count <<"||"<< endl;
		cout << "==================================" << endl;

	}
	system("pause");
}
void search_contact()
{
	node* search_node = head;
	string srch;
	int count = 1;
	cout << "Enter your desired contact you want to search ";
	cin >> srch;
	bool found = false;
	if (head == NULL)
	{
		cout << "\nList is Empty " << endl;
	}
	else
	{
		while (search_node != NULL)
		{
			if (srch == search_node->name || srch == search_node->num)
			{
				cout << "\n\t\tFull name: " << search_node->name << endl;
				cout << "\t\tPhone number: " << search_node->num << endl;
				found = true;
				break;
			}
			search_node = search_node->next;
			count++;
		}
	}
	if (found == true)
	{

		cout << "\t\tIndex of the Contact = " << count << endl;
	}
	else
	{
		cout << "Contact not found " << endl;
	}
	system("pause");
}
void del_con()
{
	int pos;
	node* next_node;
	temp = head;
	cout << "Enter your Index number of contact to delete:";
	cin >> pos;
	cout<< endl;
	if (head == NULL)
	{
		system("CLS");
		cout << "List is Empty " << endl;
	}
	else if (pos > len)
	{
		system("CLS");
		cout << "Invalid Position " << endl;
	}
	else if (pos == 1)
	{
		temp = head;
		head = head->next;
		delete temp;
		system("CLS");
		cout << "Contact has been deleted " << endl;
	}
	else
	{
		for (int i = 2; i < pos; i++)
		{
			temp = temp->next;
		}
		next_node = temp->next;
		temp->next = next_node->next;
		delete next_node;
		cout << "Contact has been deleted " << endl;
	}
}
void del_all()
{
	if (head == NULL)
	{
		cout << "List is Empty " << endl;
	}
	else
	{
		temp = 0;
		temp = head;
		while (head != NULL)
		{
			head = head->next;
			delete temp;
		}
		cout << "\t_________________________________________________" << endl;
		cout << "\t|\tALL contact list has been deleted\t|" << endl;
		cout << "\t_________________________________________________" << endl;
	}
}
void menu()
{
	for (int i = 0; i <= 50; i++)
	{
		cout << "=";
	}
	cout << endl;
	cout << "||\t\t\tMenu\t\t\t ||" << endl;
	for (int i = 0; i <= 50; i++)
	{
		cout << "=";
	}
	cout << endl;
	cout << "||\t1.Add Contact\t\t\t\t ||" << endl;
	cout << "||\t2.Display all Contact\t\t\t ||" << endl;
	cout << "||\t3.Search a Contact\t\t\t ||" << endl;
	cout << "||\t4.Delete a Contact\t\t\t ||" << endl;
	cout << "||\t5.Clear All Contacts\t\t\t ||" << endl;
	cout << "||\t6.Exit\t\t\t\t\t ||" << endl;
	for (int i = 0; i <= 50; i++)
	{
		cout << "=";
	}
	cout << endl;
	cout << "Enter Choice:";
	
}
int main()
{
	int op;
	char cho = 1;;
	do
	{

		menu();
		cin >> op;
		cout << endl;
		system("CLS");
		switch (op)
		{
		case 1:
			add_con();
			break;
		case 2:
			len = 0;
			display();
			break;
		case 3:
			search_contact();
			break;
		case 4:
			display();
			del_con();
			break;
		case 5:
			del_all();
			break;
		case 6:
			cout << "Goodbye" << endl;
			exit(0);
			break;
		default:
			cout << "Invalid Option " << endl;
		}
		cout << "Do you want to continue(Y/N):";
		cin >> cho;
		cout << endl;
		if (cho == 'n' || cho == 'N')
		{
			cout << "Goodbye" << endl;
		}
		system("CLS");
	} while (cho == 'y' || cho == 'Y');
}
