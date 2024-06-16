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
	int a;
	//log
	a=readWriteAPI->readFile("E:\\Sever\\in.txt");
	std::cout <<std::endl<<a<<std::endl;
	return 0;
}
