#include "Utils/ConfigParser.h"
#include  "Utils/CommandLineParser.h"

#include <fstream>

ConfigParser::ConfigParser()
{
	m_ConfigFile.ConfigSections.clear();
}

ConfigParser::~ConfigParser()
{

}

const ConfigSection& ConfigParser::getSection(const string& section)
{
	return m_ConfigFile.ConfigSections[section];
}

const std::string& ConfigParser::getSetting(const string& section, const string& name)
{
	return m_ConfigFile.ConfigSections[section].Options[name];
}

bool ConfigParser::parse(const string& filename)
{
	auto file=ifstream(filename);
	
	if (file.bad())
		return false;

	string line = "";
	string sectionName = "";
	string settingName = "";
	string settingOption = "";
	ConfigSection * pCurrentSection = nullptr;
	while (!file.eof())
	{
		getline(file, line);
		if (line[0] == ConfigParser::HEADER_OPEN_TOKEN)
		{
			//read section header
			sectionName = line.substr(1, line.find(ConfigParser::HEADER_CLOSE_TOKEN) - 1);
			ConfigSection section = ConfigSection();
			section.Name = sectionName;
			m_ConfigFile.ConfigSections.insert({ sectionName, section });
			pCurrentSection = &m_ConfigFile.ConfigSections[sectionName];
		}
		else
		{
			if (line.find('=') > 0)
			{
				//we have a setting
				settingName = line.substr(0, line.find(ConfigParser::SETTING_SEPERATOR));
				settingOption = line.substr(line.find(ConfigParser::SETTING_SEPERATOR) + 1, line.length() - 1);
				pCurrentSection->Options.insert({ settingName, settingOption });
			}
		}
	}
	return true;
}

void ConfigParser::replace(CommandLineParser * commandLineoOptions)
{
	//Iterate through sections
	for (auto &sections : m_ConfigFile.ConfigSections)
	{
		//Iterate through sections settings
		for (auto &settings : sections.second.Options)
		{
			if (commandLineoOptions->containsCommand(settings.first))
			{
				settings.second = commandLineoOptions ->getCommandConfig(settings.first);
			}
		}
	}
}