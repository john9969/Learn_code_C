#pragma once
#include "../fileTxt/File_txt.h"
class ReadWriteAPI
{
public:
	static ReadWriteAPI* getInstance();
	std::int32_t readFile(
		const std::string &_Directory,
		std::string& content);

	std::int8_t rewriteFile(
		const std::string &_content, 
		const std::string &_Directory);

	std::int32_t replaceFile(
		const std::string &_what_key, 
		const std::string &_replace_with,
		std::string &content,
		const std::string &_Directory);

	std::int8_t push(
		const std::string &_push_str,
		std::string &content, 
		const std::string &_Directory);

	std::int8_t append(
		const std::string &_append_str, 
		std::string &content, 
		const std::string &_Directory);

private:
	static ReadWriteAPI* Instance;
	ReadWriteAPI() {};
	~ReadWriteAPI() {};
	ReadWriteAPI(ReadWriteAPI* other) = delete;
	void operator=(ReadWriteAPI* other) = delete;

};

ReadWriteAPI* ReadWriteAPI::Instance = NULL;


