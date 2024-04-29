void login()
{
	string username;
	string username2;
	int select;
	int pasword;
	int select2;
	int pass;

	cout << "1. EMPLOYEE " << endl;
	cout << "2. CUSTOMER" << endl;
	cin >> select;

	if(select == 1 )
	{
		cout << "\n enter pasword: ";
		cin >> pasword;

		if (pasword == 12345678)
		{
			cout << "\n welcome " << endl;
			cout << "our invntory currently contains:" << endl;
			menu();

		}
		else
		{
			cout << "incorrect password " << endl;
		}
			
	}
	if (select == 2)
	{
		cout << "1.Signin " << endl;
		cout << "2.Login" << endl;
		cin >> select2;
		cout << endl;

		if (select2 == 1)
		{
			cout << "\n Enter Username: ";
			cin >> username;

			cout << "\n Create Password: ";
			cin >> pass;

			//add cls 

			cout << "Now login" << endl;
			 
			cout << "\n Enter username: ";
			cin >> username2;

			cout << "\n enter Pasword: ";
			cin >> pasword;

			if (username == username2 && pasword == pass)
			{
				cout << "our invntory currently contains:" << endl;

				menu();

			}
			else
			{
				cout << "Incorrect pasword" << endl; 
			}

		}
		if (select2 == 2)
		{

			cout << "\n Enter Pasword: ";
			cin >> pasword;
			if (pasword == 12345678)
			{
				cout << "our invntory currently contains:" << endl;

				menu();
			}
		}
	}
}
