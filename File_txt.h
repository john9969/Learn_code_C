#pragma once
#include<iostream>
#include<string>
#include<fstream>
class File_txt
{
public:
	//File_txt(std::string _Directory);
	static std::int32_t readFileTxt(const std::string& dir, std::string& content);
	//static std::int8_t checkFileStatus(std::string dir, std::string& content);
	static int8_t write(const std::string& content, std::string dir);
	static std::string replaceString(std::string what_key, std::string replace_with, std::string source);
	static std::int8_t writeNew(std::string _content, std::string dir);
	static std::int8_t writeReplace(std::string what_key, std::string replace_with, std::string dir);
	static std::int8_t pushContentBefore(std::string push_str, std::string dir);
	static std::int8_t appendContentLast(std::string append_str, std::string dir);

private:
	//static std::string directory;
	//static std::string content;
	//static std::fstream file;
	//static uint32_t replaceCnt;
};
