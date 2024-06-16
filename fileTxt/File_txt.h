#include<iostream>
#include<string>
#include<fstream>
 #include <stdint.h>

class File_txt
{
public:
	File_txt();
	//File_txt(std::string _Directory);
	static int32_t readFileTxt(
		const std::string& dir, 
		std::string& content);

	static int8_t write(
		const std::string& content, 
		const std::string &dir);

	static int8_t writeNew(
		const std::string &_content, 
		const std::string &dir);

	static int32_t writeReplace(
		const std::string &what_key, 
		const std::string &replace_with, 
		std::string &content, 
		const std::string &dir);

	static int8_t pushContentBefore(
	const std::string &push_str,
	std::string &content, 
	const std::string &dir);

	static int8_t appendContentLast(
		const std::string &append_str,
		std::string &content, 
		const std::string &dir);

private:
	static int32_t replaceString(
		const std::string &what_key, 
		const std::string &replace_with, 
		std::string& source);

};
