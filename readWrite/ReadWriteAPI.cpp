#include "ReadWriteAPI.h"

ReadWriteAPI* ReadWriteAPI::getInstance()
{
	if (Instance == nullptr)
	{
		Instance = new ReadWriteAPI();
	}
	return Instance;
}
std::int32_t ReadWriteAPI::readFile(
	const std::string &_Directory,
	std::string &_content)
{
	return File_txt::readFileTxt(_Directory,_content);
}
std::int8_t ReadWriteAPI::rewriteFile(
	const std::string &_content, 
	const std::string &_Directory)
{
	return File_txt::writeNew(_content, _Directory);
}
std::int32_t ReadWriteAPI::replaceFile(
	const std::string &_what_key, 
	const std::string &_replace_with,
	std::string &content,
	const std::string &_Directory)
{
	return File_txt::writeReplace(_what_key,_replace_with, content,_Directory);
}
std::int8_t ReadWriteAPI::push(
		const std::string &_push_str,
		std::string &content, 
		const std::string &_Directory)
{
	return File_txt::pushContentBefore(_push_str, content, _Directory);
}
std::int8_t ReadWriteAPI::append(
	const std::string &_append_str, 
	std::string &content, 
	const std::string &_Directory)
{
	return File_txt::appendContentLast(_append_str, content, _Directory);
}