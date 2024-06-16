#pragma once
#include<iostream>
#include<string>
#include<fstream>
class File_txt
{
public:
	//File_txt(std::string _Directory);
	static std::int32_t readFileTxt(
		const std::string& dir, 
		std::string& content);

	static int8_t write(
		const std::string& content, 
		const std::string &dir);

	static int32_t replaceString(
		const std::string &what_key, 
		const std::string &replace_with, 
		std::string& source);

	static std::int8_t writeNew(
		const std::string &_content, 
		const std::string &dir);

	static std::int32_t writeReplace(
		const std::string &what_key, 
		const std::string &replace_with, 
		std::string &content, 
		const std::string &dir);

	static std::int8_t pushContentBefore(
	const std::string &push_str,
	std::string &content, 
	const std::string &dir);

	static std::int8_t appendContentLast(
		const std::string &append_str,
		std::string &content, 
		const std::string &dir);

private:
	//static std::string directory;
	//static std::string content;
	//static std::fstream file;
	//static uint32_t replaceCnt;
};
