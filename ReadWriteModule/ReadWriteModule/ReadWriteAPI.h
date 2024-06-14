#pragma once
#include"File_txt.h"
class ReadWriteAPI
{
public:
	static ReadWriteAPI* getInstance();
	std::int8_t readFile(std::string _Directory);
	std::int8_t rewriteFile(std::string _content, std::string _Directory);
	std::int8_t replaceFile(std::string _what_key, std::string _replace_with, std::string _Directory);
	std::int8_t push(std::string _push_str, std::string _Directory);
	std::int8_t append(std::string _append_str, std::string _Directory);

private:
	static ReadWriteAPI* Instance;
	ReadWriteAPI() {};
	~ReadWriteAPI() {};
	ReadWriteAPI(ReadWriteAPI* other) = delete;
	void operator=(ReadWriteAPI* other) = delete;

};


