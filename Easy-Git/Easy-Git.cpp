#include <cstring>
#include <iostream>
#include<cstdio>

using namespace std;

void usage()
{
	cout << "Usage of eit" << endl;
}


int runscript(const char* script)
{
	const char* command_exec = "git";

	system("pause");
	return 0;
}


int main(int argc, char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		// 直接运行GIT命令
		if ('-' != argv[i][0]) 
		{
			cout << "Calling Git...." << endl;
		}

		else 
		{
			switch (argv[i][1])
			{
			case 'w':
				cout << "w" << endl;
				break;
			case 'h':
				usage();
				return 0;
			case 'l':
				switch (argv[++i][0]) 
				{
				case 'd':
					cout << "d" << endl;
					break;
				default:
					cout << "aaaa" << endl;
					break;
				}
				break;
			default:
				cout << "[ERROR] invalid option : '-" << argv[i][1] << "'" << endl;
				usage();
				return -1;
			}
		}
	}
	system("pause");
	return 0;
}

