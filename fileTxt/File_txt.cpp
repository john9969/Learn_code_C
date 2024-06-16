#include "File_txt.h"
#include <mutex>

std::mutex mtx;

std::int32_t File_txt::readFileTxt(
	const std::string& dir,
	std::string& content)
{
	static std::ifstream file;
	std::string line = "";

	file.open(dir);
	if (!file.is_open()) {
		std::cout << "\nCannot read/write file that does not exist!\n";
		return -1;
	}
		while (std::getline(file, line)) {
			content += line;
		}
		std::string _output="";
		for (char ch : content) {
			if (ch != '\t' && ch != ' ' && ch != '\n' && ch != '\r' && ch != '\v' && ch != '\0') {
				_output += ch;
			}
		}
		content = _output;
		file.close();
		std::cout << content;
		return content.length();
}

int8_t File_txt::write(
	const std::string &content, 
	const std::string &dir)
{
	std::ofstream file(dir, std::ios::trunc); //check err tuanndm-OK
	if (!file.is_open()) {
		std::cout << "Cannot read/write file that does not exist!";
		return 0;
	}
	//check xem co can ham cho de thuc hien xong k tuanndm-OK
	mtx.lock();
	file << content;
	mtx.unlock();
	file.close();
	return 1;
}
//return num replaced, put in private tuanndm-OK
int32_t File_txt::replaceString(
	const std::string &what_key, 
	const std::string &replace_with, 
	std::string& source)
{
	int32_t replaceCnt = 0;
	size_t position = 0;
	while (position != std::string::npos) {
		position = source.find(what_key, position);
		if (position != std::string::npos) {
			source.replace(position, what_key.length(), replace_with);
			position += replace_with.length();
			replaceCnt++;
		}
	}
	return replaceCnt;
}
//tu sua tuanndm
std::int8_t File_txt::writeNew(
	const std::string &_content, 
	const std::string &dir)
{
	return write(_content, dir);
}
//tu sua tuanndm
std::int32_t File_txt::writeReplace(
	const std::string &what_key, 
	const std::string &replace_with,
	std::string &content, 
	const std::string &dir)
{
	std::ofstream file;
	file.open(dir); //check err tuanndm-OK
	if (!file.is_open()) {
		std::cout << "Cannot read/write file that does not exist!";
		return 0;
	}
		//kho qua tuanndm oi !!!, phai mo file 2 lan lien,
		//open file to replace xong close file xong lai open file de write, lieu co cong kenh qua khong ?
		replaceString(what_key, replace_with, content);
		file.close();
		File_txt::write(content, dir);
		return replaceString(what_key, replace_with, content);
}

std::int8_t File_txt::pushContentBefore(
	const std::string &push_str,
	std::string &content, 
	const std::string &dir)
{
	
	std::ofstream file;
	file.open(dir); //check err tuanndm-OK
	if (!file.is_open()) {
		std::cout << "Cannot read/write file that does not exist!";
		return 0;
	}
	content.insert(0, push_str);
	return 1;	
}

std::int8_t File_txt::appendContentLast(
	const std::string &append_str,
	std::string &content, 
	const std::string &dir)
{
	std::ofstream file;
	file.open(dir); //check err tuanndm-OK
	if (!file.is_open()) {
		std::cout << "Cannot read/write file that does not exist!";
		return 0;
	}
	content = content.append(append_str);
	return 1;
}

//std::string File_txt::directory;
//std::string File_txt::content;
//std::fstream File_txt::file;
//uint32_t File_txt::replaceCnt;