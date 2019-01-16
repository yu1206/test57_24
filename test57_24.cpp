#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include "direct.h"
#include "FileMove.h"
using namespace cv;
using namespace std;
extern void SplitString(const string& s, vector<string>& v, const string& c);
int test57_24(int argc, char *argv[])
{

	string  txtName = "E:\\LISA-Traffic-Light\\dayTrainingall\\dayClip";
	string carsrc = "E:\\LISA-Traffic-Light\\dayTrainingall\\dayClip\\frames";

	/*
	string txtName1 = txtName + "\\"+"trainval-bigall.txt";
	string cardst = "E:\\LISA-Traffic-Light\\dayTrainingall\\dayClip\\frames-bigall";
	*/
	
	string txtName1 = txtName + "\\" + "trainval-bigone.txt";
	string cardst = "E:\\LISA-Traffic-Light\\dayTrainingall\\dayClip\\frames-bigone";


	fstream finRead1;
	finRead1.open(txtName1, ios::in);
	if (!finRead1.is_open())
	{
		cout << "finRead3 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	string line; 
	RenameMover RM;
	while (getline(finRead1, line))
	{

		if (line.empty())
		{
			break;
		}
		stringstream str_s(line);
		string name1;
		str_s >> name1;
		int npos = name1.find_last_of('/');
		
		string name2 = name1.substr(npos+1, name1.size() - npos);

		string strsrc = carsrc + "\\" + name2;
		string strdst = cardst+ "\\" + name2;
		RM.move(strsrc, strdst);

		/*strsrc = dirNameCar1 + "\\" + name1 + ".txt";
		strdst = dirNameCar + "\\" + name1 + ".txt";
		RM.move(strsrc, strdst);*/

	}
	finRead1.close();
	
	
	
	
	

	return 0;
}