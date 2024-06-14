#include "ReadWriteAPI.h"

ReadWriteAPI* ReadWriteAPI::getInstance()
{
	if (Instance == nullptr)
	{
		Instance = new ReadWriteAPI();
	}
	return Instance;
}
std::int8_t ReadWriteAPI::readFile(std::string _Directory)
{
	return File_txt::readFileTxt(_Directory);
}
std::int8_t ReadWriteAPI::rewriteFile(std::string _content, std::string _Directory)
{
	return File_txt::writeNew(_content, _Directory);
}
std::int8_t ReadWriteAPI::replaceFile(std::string _what_key, std::string _replace_with, std::string _Directory)
{
	return File_txt::writeReplace(_what_key,_replace_with,_Directory);
}
std::int8_t ReadWriteAPI::push(std::string _push_str, std::string _Directory)
{
	return File_txt::pushContentBefore(_push_str, _Directory);
}
std::int8_t ReadWriteAPI::append(std::string _append_str, std::string _Directory)
{
	return File_txt::appendContentLast(_append_str,_Directory);
}