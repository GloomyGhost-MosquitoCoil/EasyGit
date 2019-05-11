#include <cstring>
#include <iostream>

using namespace std;

void usage()
{
	cout << "Usage of egit:" << endl;
	cout << "\t-c: commit" << endl;
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


int checker(const int argc, const int s, char* argv[])
{
	if (argc != s)
	{
		cout << "Arg Error!" << endl;
		for (int i = 0; i < argc; i++) {
			cout << argv[i] << " ";
		}
		cout << "" << endl;
		usage();
		return 1;
	}
	else
	{
		return 0;
	}
}


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		usage();
	}

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
			case 'a':
				runner("git add .");
				break;
			case 'c':
				switch (argv[i++][0])
				{
				case 'm':
					if (checker(argc, 4, argv))
					{
						break;
					}
					switch (argv[i++][0])
					{
					case 'a':
						runner("git commit -m \"Add New Feature\"");
						break;
					case 'b':
						runner("git commit -m \"Bug Fixed\"");
						break;
					case 'c':
						runner("git commit -m \"Changed Some Files\"");
						break;
					case 'd':
						runner("git commit -m \"Deleted Some Files\"");
						break;
					default:
						cout << "[ERROR] invalid option : '-c m " << argv[--i][0] << "'" << endl;
						return -1;
					}
					break;
				default:
					cout << "[ERROR] invalid option : '-" << argv[--i][0] << " " << argv[i][0] << "'" << endl;
					return -1;
				}
				break;
			case 'h':
				cout << "The usage of egit:";
				usage();
				cout << "The usage of git";
				system("git --help");
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
	return 0;
}

