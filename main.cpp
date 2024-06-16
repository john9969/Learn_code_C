#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include "File_txt.h"
#include "ReadWriteAPI.h"

ReadWriteAPI* ReadWriteAPI::Instance = NULL;

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
