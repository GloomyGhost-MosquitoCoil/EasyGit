#include <cstring>
#include <iostream>
#include<cstdio>

using namespace std;

void usage()
{
	cout << "Usage of eit:" << endl;
	cout << "\t-c: commit";
}


void debug(int argc,char* arr[])
{
	cout << argc << endl;
	int i = 1;
	for (; i < argc; i++) 
	{
		cout << arr[i] << ' ';
	}
	cout << "\n";
	system("pause");
}


int runscript(const char* script)
{
	system(script);
	return 0;
}


void runback(const char* type)
{
	cout << "Running Git Command: " << type << endl;
}


void runner(const char* command)
{
	runback(command);
	runscript(command);
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
		// 处理简化参数
		else 
		{
			switch (argv[i++][1])
			{
			case 'c':
				switch (argv[i++][0])
				{
				case 'm':
					switch (argv[i++][0])
					{
					case 'a':
						runner("git commit -m \"Add New Feature\"");
						break;
					case 'b':
						runner("git commit -m \"Bug Fixed\"");
						break;
					default:
						cout << "[ERROR] invalid option : '-c m " << argv[--i][0] << "'" << endl;
						return -1;
					}
					break;
				default:
					cout << "[ERROR] invalid option : '-" << argv[i][0] << " " << argv[i][0] << "'" << endl;
					return -1;
				}
			case 'h':
				usage();
				return 0;
			case 'l':
				switch (argv[i++][0]) 
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

