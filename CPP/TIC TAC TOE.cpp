#include <iostream>
#include <fstream>
using namespace std;

ifstream fin;
ofstream fout;

int size = 0;
int temp = 1;
float input = 0;
int Table [100][100] = {};
bool IsGame = false;

void PrintBoard()
{
	system("CLS");
	int i = 0, j = 0;
	cout<<"\n\n\n";
	for (i = 0; i<size; i++)
	{
		cout<<"\n";
		for (j = 0; j<6-size; j++)
			cout<<"\t";
		for (j = 0; j<size-1; j++)
		{
			cout<<"\t|\t";
		}
		cout<<"\n";
		for (j = 0; j<6-size; j++)
			cout<<"\t";
		for (j = 0; j<size; j++)
		{
			if (Table [i][j]==79)
				cout<<"O";
			else if (Table [i][j]==88)
				cout<<"X";
			else
				cout<<Table [i][j];
			if (j!=size-1)
				cout<<"\t|\t";
		}
		cout<<"\n";
		for (j = 0; j<6-size; j++)
			cout<<"\t";
		for (j = 0; j<size-1; j++)
		{
			cout<<"\t|\t";
		}
		cout<<"\n";
		if (i!=size-1)
		{
			for (j = 0; j<5-size; j++)
				cout<<"\t";
			for (j = 0; j<16*size; j++)
				cout<<"-";
		}
	}
	cout<<endl<<endl;
}

bool LoadGame()
{
	if (size==3)
		fin.open("SaveGame_Size3.txt");
	else if (size==4)
		fin.open("SaveGame_Size4.txt");
	else if (size==5)
		fin.open("SaveGame_Size5.txt");
	else if (size==6)
		fin.open("SaveGame_Size6.txt");
	else if (size==7)
		fin.open("SaveGame_Size7.txt");
	fin>>temp;
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			Table [i][j] = 0;
			fin>>Table [i][j];
		}
	}
	if (Table [0][0]==0)
	{
		cout<<"\n\nOops! Saved file not found for size "<<size<<" x "<<size<<".\n\n";
		system("pause");
		return 1;
	}
	else
		return 0;
}

void SaveGame()
{
	if (size==3)
		fout.open("SaveGame_Size3.txt");
	else if (size==4)
		fout.open("SaveGame_Size4.txt");
	else if (size==5)
		fout.open("SaveGame_Size5.txt");
	else if (size==6)
		fout.open("SaveGame_Size6.txt");
	else if (size==7)
		fout.open("SaveGame_Size7.txt");
	else
		fout.open("SaveGame_SizePoly.txt");

	fout<<temp<<endl;
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			fout<<Table [i][j]<<endl;
		}
	}
	cout<<"\n\nGame has been saved successfully!\n";
	fin.close();
	system("pause");
	PrintBoard();
}

bool IsValidMove()
{
	bool flag = true, flag1 = false;
	if (input==size*size+1)
		flag1 = true;
	else if (input<1)
	{
		cout<<"\nThe number you entered is too short.\n";
		flag = false;
	}
	else if (input>size*size)
	{
		cout<<"\nThe number you entered is too big.\n";
		flag = false;
	}
	else
	{
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; (j<size)&&(!flag1); j++)	//returns true if there is any space for the input
			{
				if (input==Table [i][j])
				{
					flag1 = true;
				}
			}
		}
	}
	flag = flag&&flag1;
	if (!flag||(input==size*size+1))
	{
		cout<<"You can only input from these number;\n";
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
			{
				if ((Table [i][j]!=79)&&(Table [i][j]!=88))
					cout<<Table [i][j]<<" ";
			}
		}
		if (!flag)
			cout<<"\n\n\nTry Again!\n";
		cout<<"\n\n";
		system("pause");
	}
	return (flag);
}

bool IsWin()
{
	bool flag1 = true, flag2 = true, flag3 = true, flag4 = true, flag = false;
	for (int i = 0; i<size; i++)
	{
		flag1 = true, flag2 = true, flag3 = true, flag4 = true;
		for (int j = 0; (j<size)&&(!flag); j++)
		{
			if (Table [i][0]!=Table [i][j])		//Check horizontally
				flag1 = false;
			if (Table [0][i]!=Table [j][i])		//Check vertically
				flag2 = false;
			if (Table [i][i]!=Table [j][j])		//Check in Principal Diagonal
				flag3 = false;
			if (Table [j][size-j-1]!=Table [size-j-1][j])	//Check in Secondary Diagonal
				flag4 = false;
		}
		if ((flag1||flag2||flag3||flag4)==1)
		{
			flag = true;
		}
	}

	if (flag)
	{
		cout<<"\n\n\t\tCongratulations!\tPlayer ";
		if (temp%2==0)
			cout<<"X";
		else
			cout<<"O";
		cout<<" is winner.\n\n\n";
	}
	return flag;
}

bool IsDraw()
{
	bool flag = true;
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (Table [i][j]!=79&&Table [i][j]!=88)		//Check all the entries with the ASCII values of X and O.
				flag = false;
		}
	}
	if (flag)
		cout<<"\n\nGame has been drawn.\n\n\n";
	return flag;
}

void PlayerTurn()
{
	int k = 0, index1 = 0, index2 = 0;
	bool flag = false;
	while (!flag)
	{
		cout<<"\nOptions;\nEnter -1 to save the game\nEnter "<<size*size+1<<" to see the remaining possible entries\nEnter "<<size*size+2<<" to exit the game\n\n\n";
		cout<<"\n\nIt's Player ";
		if ((temp+1)%2==0)
			cout<<"X";
		else
			cout<<"O";
		cout<<" turn. Enter a number : ";
		cin>>input;
		if (input==size*size+2)
		{
			flag = true;
			IsGame = true;		//This flag controls the input of Player.
		}
		else if (input==-1)
		{
			SaveGame();
		}
		else if (IsValidMove())
		{
			k = 0;
			for (int i = 0; i<size; i++)
			{
				for (int j = 0; j<size&&!flag; j++)
				{
					if (k!=input-1)
						k++;
					else
					{
						flag = true;
						index1 = i;
						index2 = j;
					}
				}
			}
			temp++;
			if (temp%2==0)
				Table [index1][index2] = 88;
			else
				Table [index1][index2] = 79;
		}
		else
		{
			PrintBoard();
			// This is used to avoid crashing and misbehaviour of program.
			cin.clear();
			cin.ignore(120, '\n');
		}
	}
}

void GameStart()
{
	bool flag = true;
	temp = 1;
	int k = 0;
	int choice = 0;
	while (flag)
	{
		system("CLS");
		cout<<"\nThis game is programmed by Muhammad Sameer Farooq.\n";
		while (flag)
		{
			cout<<"\nInput the size of Table : ";
			cin>>size;
			if (size>2&&cin)
				flag = false;
			else
			{
				cout<<"\nInvalid Input.\n\n";
				cin.clear();
				cin.ignore(120, '\n');
			}
		}
		cout<<"\n\nOptions;\nEnter 1 to start a new game\nEnter 2 to load the last saved game\n\n\t\tEnter your choice : ";
		cin>>choice;
		if (choice==1)
		{
			for (int i = 0; i<size; i++)
			{
				for (int j = 0; j<size; j++)
				{
					Table [i][j] = ++k;
				}
			}
		}
		else if (choice==2)
		{
			flag = LoadGame();
		}
		else
		{
			cout<<"\n\nInvalid Input.\n\n";
			system("pause");
			flag = true;
			cin.clear();
			cin.ignore(120, '\n');
		}
	}
	PrintBoard();
	while (!flag)
	{
		IsGame = false;
		PlayerTurn();	// Calling the PlayerTurn function until unless either game is drawn or win by any Player.
		if (!IsGame)
		{
			PrintBoard();
			flag = IsWin()||IsDraw();
			if (flag)
				system("pause");
		}
		else
			flag = true;
	}
}

int main()
{
	int choice = 0;
	bool flag = false, flag1 = true;
	while (flag1)
	{
		GameStart();
		flag = true;
		while (flag)
		{
			cout<<"\n\nThanks for playing the game.\n\nPress;\n1-->To Play Again\n2-->To exit this application\n\n\t\tEnter your choice : ";
			cin>>choice;
			flag = false;
			if (choice==1)
			{
				system("pause");
			}
			else if (choice==2)
				flag1 = false;
			else
			{
				cout<<"\n\nInvalid Input.\n\n";
				flag = true;
				cin.clear();
				cin.ignore(120, '\n');
				system("pause");
			}
		}
	}
	return 0;
}
