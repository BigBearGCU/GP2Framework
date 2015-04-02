#include "Utils/CommandLineParser.h"

CommandLineParser::CommandLineParser()
{
	m_CommandConfig.clear();
}

CommandLineParser::~CommandLineParser()
{

}

void CommandLineParser::parse(int argc, char** argv)
{
	string command = "";
	string name = "";
	string commandValue = "";
	for (int i = 1; i < argc; ++i)
	{
		command = argv[i];
		name = command.substr(0, command.find(CommandLineParser::SETTING_SEPERATOR));
		commandValue = command.substr(command.find(CommandLineParser::SETTING_SEPERATOR) + 1, command.length() - 1);
		m_CommandConfig.insert({ name, commandValue });
	}
}

const string& CommandLineParser::getCommandConfig(const string& name)
{
	return m_CommandConfig[name];
}