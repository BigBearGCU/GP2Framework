#include <map>
#include <string>

using namespace std;

class CommandLineParser
{
public:
	CommandLineParser();
	~CommandLineParser();

	void parse(int argc, char** argv);

	const string& getCommandConfig(const string& name);

	bool containsCommand(const string& name)
	{
		if (m_CommandConfig.find(name) != end(m_CommandConfig))
			return true;

		return false;
	}
private:
	map<string, string> m_CommandConfig;
	static const char SETTING_SEPERATOR = '=';
};