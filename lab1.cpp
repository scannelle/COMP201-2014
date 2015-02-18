#include <iostream>
#include <fstream>
#include <cstring> // C style string: char * (an array of characters)
#include <string> // C++ style string: string

using namespace std;

int main(int argc, char *argv[])
{
	int x = 0, length = 0, q=0;
	int arr[100];
	ifstream ifs;
	ofstream ofs;
	ifs.open(argv[1]);
	ofs.open("output.txt");
	if (ifs.fail())
	{
		cout << "Could not open " << argv[1] << "!" << endl;
		return 1;
	}
	if (ofs.fail())
	{
		cout << "Could not open output.txt!" << endl;
		return 1;
	}
	while (ifs >> length)
	{
		cout << "read " << length << endl;
	}
	cout << " x   x^2   sum \n-------------------" << endl;
	ofs << " x   x^2   sum \n-------------------" << endl;
	for (int i = 0; i < length; i++)
	{
		x+=arr[i];
		cout << " " << arr[i] << "   " << arr[i] * arr[i] << "   " << x << endl;
		ofs << " " << arr[i] << "   " << arr[i] * arr[i] << "   " << x << endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}