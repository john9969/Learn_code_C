#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include "fileTxt/File_txt.h"
#include "readWrite/ReadWriteAPI.h"

//ReadWriteAPI* ReadWriteAPI::Instance = NULL; -> da dinh nghia o file nguon de dam bao tinh dong goi

int main()
{
	ReadWriteAPI* readWriteAPI = ReadWriteAPI::getInstance();
	int a = 5;
	//log
	//a=readWriteAPI->readFile("E:\\Sever\\in.txt");
	std::cout <<std::endl<<a<<std::endl;
	std::cout<<"Hello world";
	return 0;
}
