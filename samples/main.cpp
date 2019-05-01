#include "polinom.h"
#include "iomanip"
#include "multitable.h"

using namespace std;

void InputAll(bool frst, bool scnd, bool cons, Polinom& p1, Polinom& p2, double& constant);
Polinom InputPolinom();
string InputName();

int main()
{
	cout << "Program name: Testing polinoms and tables" << endl;

	Polinom p1;
	Polinom p2;
	double constant;
	
	bool exit = false;
	bool prnt = true;
	bool tbl_exit = true;
	bool tbl_prnt = true;

	InputAll(true, true, true, p1, p2, constant);

	int size;
	cout << "Input total size for tables: ";
	cin >> size;
	TMultitable tbl(size);
	
	cout << endl;
	cout << "First: ";
	p1.Print();
	cout << "Second: ";
	p2.Print();
	cout << "Const: " << constant << endl;

	CleanLog();

	while (!exit)
	{
		if (prnt) 
		{
			cout << endl << "Select one of the menu items" << endl;
			cout << "1) Addition" << endl;
			cout << "2) Subtraction" << endl;
			cout << "3) Multiplication by a constatnt" << endl;
			cout << "4) Multiplication by the second polinom" << endl;
			cout << "5) Change input data" << endl;
			cout << "6) Working with tables" << endl;
			cout << "7) Exit" << endl;
			prnt = false;
		}

		cout << endl << "Your selection: ";
		int slct1;
		cin >> slct1;
		
		Polinom res;
		switch (slct1)
		{
		case 1:
			res = p1 + p2;
			cout << "Result: ";
			res.Print();

			break;
		case 2:
			res = p1 - p2;
			cout << "Result: ";
			res.Print();

			break;
		case 3:
			res = p1 * constant;
			cout << "Result: ";
			res.Print();

			break;
		case 4:

			try
			{
				res = p1*p2;
				cout << "Result: ";
				res.Print();
			}

			catch (char* str)
			{
				cout << str << endl;
				cout << "Try to change first or second polinoms" << endl;
			}

			break;
		case 5:

			cout << endl << "Select the item you want to change" << endl;
			cout << "1) First polinom" << endl;
			cout << "2) Second polinom" << endl;
			cout << "3) Constanst" << endl;

			cout << endl << "Your selection: ";
			int slct2;
			cin >> slct2;

			switch (slct2)
			{
			case 1:
				InputAll(true, false, false, p1, p2, constant);
				cout << endl << "First: ";
				p1.Print();

				break;
			case 2:
				InputAll(false, true, false, p1, p2, constant);
				cout << endl << "Second: ";
				p2.Print();

				break;
			case 3:
				InputAll(false, false, true, p1, p2, constant);
				cout << "Const: ";
				cout << constant << endl;

				break;
			}

			prnt = true;

			break;
		case 6:

			while (tbl_exit)
			{
				if(tbl_prnt)
				{
					cout << endl << "Select one of the menu items" << endl;
					cout << "1) Add record" << endl;
					cout << "2) Delete record" << endl;
					cout << "3) Search record" << endl;
					cout << "4) Back to main menu" << endl;
					tbl_prnt = false;
				}

				cout << endl << "Your selection: ";
				int slct3;
				cin >> slct3;

				try
				{
					switch (slct3)
					{
					case 1:

						cout << endl << "Select polinom you want to add " << endl;
						cout << "1) First" << endl;
						cout << "2) Second" << endl;
						cout << "3) Result of last operation" << endl;
						cout << "4) Create new" << endl;

						cout << endl << "Your selection: ";
						int slct4;
						cin >> slct4;

						switch (slct4)
						{
						case 1:
							tbl.Insert(InputName(), p1);

							break;
						case 2:
							tbl.Insert(InputName(), p2);

							break;
						case 3:
							tbl.Insert(InputName(), res);

							break;

						case 4:
							cout << endl;
							Polinom p3;
							p3 = InputPolinom();
							tbl.Insert(InputName(), p3);

							break;
						}

						tbl_prnt = true;

						break;
					case 2:
						tbl.Delete(InputName());

						break;
					case 3:
						tbl.Search(InputName());

						break;
					case 4:
						tbl_exit = false;
						prnt = true;

						break;
					}

				}

				catch(char * str)
				{
					cout << str << endl;
				}

			}

			tbl_exit = true;
			tbl_prnt = true;

				break;
		case 7:
			exit = true;

			break;
		}
	}
}

Polinom InputPolinom()
{
	Polinom res;
	double coef;
	int deg;
	int number;
	bool crct1 = false;

	while (!crct1)
	{
		cout << "Input number of monoms ";
		cin >> number;

		if (number <= 0)
			cout << endl << "Incorrect input, try again" << endl;
		else 
			crct1 = true;
	}

	for (int i = 0; i<number; i++)
	{
		cout << endl << "Monom" << i + 1 << ":" << endl;
		cout << "Coefficient = ";
		cin >> coef;
		cout << "Degree = ";
		cin >> deg;

		Monom mon(coef, deg);
		res.Insert(mon);
	}

	res.ToStandartView();
	return(res);
}

void InputAll(bool frst, bool scnd, bool cons, Polinom& p1, Polinom& p2, double& constant)
{
	if (frst)
	{
		cout << endl << "Input first polinom:" << endl;
		p1 = InputPolinom();
	}

	if (scnd)
	{
		cout << endl << "Input second polinom:" << endl;
		p2 = InputPolinom();
	}

	if (cons)
	{
		cout << endl << "Input constant: ";
		cin >> constant;
		cout << endl;
	}
}

string InputName()
{
	string key;

	cout << endl << "Input name of polinom = ";
	cin >> key;	

	return key;
}