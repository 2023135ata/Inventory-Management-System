class Clothing
{
private:
	int no_of_clothing;
	string types_Clothing[3][10];
	
public:
	Clothing(){
		types_Clothing[1][1] = { "jdksl" };
		types_Clothing[1][2] = { "jdksl" };
		for (int i = 0; i < 10; i++)
		{
			cout << "Enter Clothing: " << endl;
			cin >> types_Clothing[1][i];
		}
	}
	void set_no_of_clothing(int a)
	{
		no_of_clothing = a;
	}

	void set_types_Clothing(string b,int i,int j)
	{
		types_Clothing[i][j] = b;
	}

	int get_no_of_clothing()
	{
		return no_of_clothing;
	}

	string get_types_Clothing(int i,int j)
	{
		return types_Clothing[i][j];
	}
};
