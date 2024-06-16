#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include "readWrite/ReadWriteAPI.h"

//ReadWriteAPI* ReadWriteAPI::Instance = NULL; -> da dinh nghia o file nguon de dam bao tinh dong goi

int main()
{
	ReadWriteAPI* readWriteAPI = ReadWriteAPI::getInstance();
	
	//a=readWriteAPI->readFile("E:\\Sever\\in.txt");
	// std::cout <<std::endl<<a<<std::endl;
	std::cout<<"Hello world";
	return 0;
}
