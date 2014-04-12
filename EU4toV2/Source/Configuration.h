#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_


#include <string>
#include "Date.h"
using namespace std;



class Configuration // Singleton
{
public:
	Configuration();

	static string getEU4Path()
	{
		return getInstance()->EU4Path;
	}

	static string getEU4DocumentsPath()
	{
		return getInstance()->EU4DocumentsPath;
	}

	static string getEU4ModPath()
	{
		return getInstance()->EU4ModPath;
	}

	static string getV2Path()
	{
		return getInstance()->V2Path;
	}

	static string getV2DocumentsPath()
	{
		return getInstance()->V2DocumentsPath;
	}

	static string getV2Gametype()
	{
		return getInstance()->V2Gametype;
	}

	static string getEU4Mod()
	{
		return getInstance()->EU4Mod;
	}

	static date	getFirstEU4Date()
	{
		return getInstance()->firstEU4Date;
	}

	static void setFirstEU4Date(date _firstDate)
	{
		getInstance()->firstEU4Date = _firstDate;
	}

	static string getResetProvinces()
	{
		return getInstance()->resetProvinces;
	}

	static double getMaxLiteracy()
	{
		return getInstance()->MaxLiteracy;
	}

	static string getRemovetype()
	{
		return getInstance()->Removetype;
	}

	static void setOutputName(string name)
	{
		getInstance()->outputName = name;
	}

	static string getOutputName()
	{
		return getInstance()->outputName;
	}

	static Configuration* getInstance()
	{
		if (instance == NULL)
			instance = new Configuration();
		return instance;
	}

private:
	static Configuration* instance;

	// options from configuration.txt
	string	EU4Path;
	string	EU4DocumentsPath;
	string	EU4ModPath;
	string	V2Path;
	string	V2DocumentsPath;
	string	V2Gametype;
	string	EU4Mod;
	string	resetProvinces;
	double	MaxLiteracy;
	string	Removetype;
	
	// items set during conversion
	date		firstEU4Date;
	string	outputName;
};

#endif // CONFIGURATION_H_