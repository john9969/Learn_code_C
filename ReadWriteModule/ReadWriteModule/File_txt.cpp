#include "File_txt.h"
/*File_txt::File_txt(std::string _Directory)
	:directory(_Directory)
{
	file.open(directory);
	if (!file.is_open()) {
		file_status = -1;
		content = "Cannot read/write file that does not exist!";
	}
	else {
		//get string of content with no special character
		std::string line = "";
		while (std::getline(file, line)) {
			content += line;
		}

		std::string _output;
		for (char ch : content) {
			if (ch != '\t' && ch != ' ' && ch != '\n' && ch != '\r' && ch != '\v' && ch != '\0') {
				_output += ch;
			}
		}
		content = _output;

		file.close();
		if (content.empty()) { file_status = 0; }
		else { file_status = 1; }
	}
}*/

std::int32_t File_txt::readFileTxt(const std::string& dir,std::string& content)
{
	static std::ifstream file;
	std::string line = "";

	file.open(dir);
	if (!file.is_open()) {
		std::cout << "Cannot read/write file that does not exist!";
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

/*std::int8_t File_txt::checkFileStatus(std::string dir)
{
	static std::ifstream file;
	file.open(dir);
	std::string check = "";
	if (!file.is_open()) {
		std::cout << "Cannot read/write file that does not exist!";
		return -1;  // Unexist File
	}
	
	else if(File_txt::readFileTxt(dir, check)==1 && check != ""){
		file.close();
		return 1;   // File had content
	}
	else { 
		return 0; } // File with empty content
}
*/

int8_t File_txt::write(const std::string &content, std::string dir)
{
	static std::ofstream file;
	std::ofstream file(dir, std::ios::trunc); //check err tuanndm-OK
	if (!file.is_open()) {
		std::cout << "Cannot read/write file that does not exist!";
		return 0;
	}
	//check xem co can ham cho de thuc hien xong k tuanndm
	file << content;
	file.close();
	return 1;
}
//return num replaced, put in private
std::string File_txt::replaceString(std::string what_key, std::string replace_with, std::string& source)
{

	size_t position = 0;
	while (position != std::string::npos) {
		position = source.find(what_key, position);
		if (position != std::string::npos) {
			source.replace(position, what_key.length(), replace_with);
			position += replace_with.length();
			replaceCnt++;
		}
	}
	return source;
}
//tu sua tuanndm
std::int8_t File_txt::writeNew(std::string _content, std::string dir)
{
	if (File_txt::checkFileStatus(dir) == -1) {
		return 0;
	}
	else {
		File_txt::write(_content, dir);
		return 1;
	}
}
//tu sua tuanndm
std::int8_t File_txt::writeReplace(std::string what_key, std::string replace_with, std::string dir)
{
	replaceCnt = 0;
	if (File_txt::checkFileStatus(dir) == -1 || File_txt::checkFileStatus(dir) == 0) {
		return 0;      
	}
	else{
		File_txt::readFileTxt(dir);
		//when fuction replace is running, replaceCnt will be changed if "content" has "what_key" inside.
		content = replaceString(what_key, replace_with, content);
		if (replaceCnt != 0) {
			return File_txt::write(content, dir);
			return 1;
		}
		else
			return 0;
	}
}

std::int8_t File_txt::pushContentBefore(std::string push_str, std::string dir)
{
	
	if (File_txt::checkFileStatus(dir) == -1) {
		return 0;
	}
	else {
		File_txt::readFileTxt(dir); // chekc status ? 
		content = push_str + content; // thay bang push back
		File_txt::write(content, dir);
		return 1;
	}
}

std::int8_t File_txt::appendContentLast(std::string append_str, std::string dir)
{
	if (File_txt::checkFileStatus(dir) == -1) {
		return 0;
	}
	else {
		File_txt::readFileTxt(dir);
		content = content + append_str;
		File_txt::write(content, dir);
		return 1;
	}
}

//std::string File_txt::directory;
//std::string File_txt::content;
//std::fstream File_txt::file;
//uint32_t File_txt::replaceCnt;