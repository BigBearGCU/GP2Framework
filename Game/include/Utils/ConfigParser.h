#include <string>
#include <map>

using namespace std;

struct ConfigSection
{
	string Name;
	map<string, string> Options;
};

struct ConfigFile
{
	map<string, ConfigSection> ConfigSections;
};

class CommandLineParser;

class ConfigParser
{
public:
	ConfigParser();
	~ConfigParser();

	const ConfigSection& getSection(const string& section);
	const std::string& getSetting(const string& section, const string& name);

	bool parse(const string& filename);

	ConfigFile * getAllConfig()
	{
		return &m_ConfigFile;
	};

	void replace(CommandLineParser * commandLineoOptions);

private:
	ConfigFile m_ConfigFile;
	static const char HEADER_OPEN_TOKEN = '[';
	static const char HEADER_CLOSE_TOKEN = ']';
	static const char SETTING_SEPERATOR = '=';
};