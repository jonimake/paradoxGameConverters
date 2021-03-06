/*Copyright (c) 2016 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/



#include <fstream>
#include <stdexcept>
#include "Configuration.h"
#include "Flags.h"
#include "Log.h"
#include "ParadoxParser8859_15.h"
#include "ParadoxParserUTF8.h"
#include "HOI4World/HoI4Buildings.h"
#include "HoI4World/HoI4World.h"
#include "V2World/V2World.h"
#include "V2World/V2Factory.h"
#include "V2World/V2Localisation.h"
#include "OSCompatibilityLayer.h"



// Converts the given V2 save into a HoI4 mod.
// Returns 0 on success or a non-zero failure code on error.
int ConvertV2ToHoI4(const std::string& V2SaveFileName)
{
	LOG(LogLevel::Info) << "Converter version 0.1";
	Object*	obj;					// generic object

	Configuration::getInstance();

	LOG(LogLevel::Debug) << "Current directory is " << Utils::getCurrentDirectory();

	// Get HoI4 install location
	LOG(LogLevel::Debug) << "Get HoI4 Install Path";
	string HoI4Loc = Configuration::getHoI4Path();	// the HoI4 install location as stated in the configuration file
	if (HoI4Loc.empty() || !Utils::doesFolderExist(HoI4Loc.c_str()))
	{
		LOG(LogLevel::Error) << "No HoI4 path was specified in configuration.txt, or the path was invalid";
		return (-1);
	}
	else
	{
		LOG(LogLevel::Debug) << "HoI4 path install path is " << HoI4Loc;
	}

	// Get HoI4 Documents Directory
	LOG(LogLevel::Debug) << "Get HoI4 Documents directory";
	string HoI4DocLoc = Configuration::getHoI4DocumentsPath();	// the HoI4 My Documents location as stated in the configuration file
	if (HoI4DocLoc.empty() || !Utils::doesFolderExist(HoI4DocLoc.c_str()))
	{
		LOG(LogLevel::Error) << "No HoI4 documents directory was specified in configuration.txt, or the path was invalid";
		return (-1);
	}
	else
	{
		LOG(LogLevel::Debug) << "HoI4 documents directory is " << HoI4DocLoc;
	}

	// Get V2 install location
	LOG(LogLevel::Debug) << "Get V2 Install Path";
	string V2Loc = Configuration::getV2Path();	// the V2 install location as stated in the configuration file
	if (V2Loc.empty() || !Utils::doesFolderExist(V2Loc.c_str()))
	{
		LOG(LogLevel::Error) << "No Victoria 2 path was specified in configuration.txt, or the path was invalid";
		return (-1);
	}
	else
	{
		LOG(LogLevel::Debug) << "Victoria 2 install path is " << V2Loc;
	}

	// Sanity check Vic2 mods
	LOG(LogLevel::Debug) << "Double-check Vic2 mods";
	vector<string> vic2Mods = Configuration::getVic2Mods();
	for (auto itr: vic2Mods)
	{
		LOG(LogLevel::Debug) << "\tExpecting a mod with name " << itr;
	}

	set<string> fileNames;
	Utils::GetAllFilesInFolder(Configuration::getV2Path() + "/mod", fileNames);
	for (auto fileName: fileNames)
	{
		const int pos = fileName.find_last_of('.');	// the position of the last period in the filename
		if (fileName.substr(pos, fileName.length()) == ".mod")
		{
			string folderName = fileName.substr(0, pos);
			if (Utils::doesFolderExist(Configuration::getV2Path() + "/mod/" + folderName))
			{
				LOG(LogLevel::Debug) << "\tFound mod with name " << folderName;
			}
		}
	}

	// get inventions
	LOG(LogLevel::Info) << "Getting inventions";
	inventionNumToName iNumToname;
	getInventionNums(iNumToname);

	// parse technologies
	LOG(LogLevel::Info) << "Parsing Vic2 technologies";
	map<string, string> armyTechs;
	obj = parser_8859_15::doParseFile((Configuration::getV2Path() + "/technologies/army_tech.txt").c_str());
	if (obj != NULL)
	{
		for (auto tech: obj->getLeaves())
		{
			armyTechs.insert(make_pair(tech->getKey(), tech->getKey()));
		}
	}
	map<string, string> navyTechs;
	obj = parser_8859_15::doParseFile((Configuration::getV2Path() + "/technologies/navy_tech.txt").c_str());
	if (obj != NULL)
	{
		for (auto tech: obj->getLeaves())
		{
			navyTechs.insert(make_pair(tech->getKey(), tech->getKey()));
		}
	}

	// parse continents
	LOG(LogLevel::Info) << "Parsing continents";
	continentMapping continentMap;
	obj = parser_8859_15::doParseFile((Configuration::getV2Path() + "/map/continent.txt").c_str());
	if (obj != NULL)
	{
		initContinentMap(obj, continentMap);
	}

	//get output name
	const int slash		= V2SaveFileName.find_last_of("\\");				// the last slash in the save's filename
	string outputName		= V2SaveFileName.substr(slash + 1, V2SaveFileName.length());
	const int length		= outputName.find_first_of(".");					// the first period after the slash
	outputName				= outputName.substr(0, length);						// the name to use to output the mod
	int dash					= outputName.find_first_of('-');						// the first (if any) dask in the output name
	while (dash != string::npos)
	{
		outputName.replace(dash, 1, "_");
		dash = outputName.find_first_of(L'-');
	}
	int space = outputName.find_first_of(' ');	// the first space (if any) in the output name
	while (space != string::npos)
	{
		outputName.replace(space, 1, "_");
		space = outputName.find_first_of(' ');
	}
	Configuration::setOutputName(outputName);
	LOG(LogLevel::Info) << "Using output name " << outputName;

	string outputFolder = Utils::getCurrentDirectory() + "/output/" + Configuration::getOutputName();
	if (Utils::doesFolderExist(outputFolder.c_str()))
	{
		LOG(LogLevel::Error) << "Output folder " << Configuration::getOutputName() << " already exists! Clear the output folder before running again!";
		exit(0);
	}

	// Parse government mapping
	LOG(LogLevel::Info) << "Parsing governments mappings";
	parser_UTF8::initParser();
	obj = parser_UTF8::doParseFile("governmentMapping.txt");
	if (obj == NULL)
	{
		LOG(LogLevel::Error) << "Could not parse file governmentMapping.txt";
		exit(-1);
	}
	governmentMapper::getInstance()->initGovernmentMap(obj->getLeaves()[0]);

	// Parse issues
	LOG(LogLevel::Info) << "Parsing governments reforms";
	for (auto itr : vic2Mods)
	{
		if (Utils::DoesFileExist(Configuration::getV2Path() + "/mod/" + itr + "/common/issues.txt"))
		{
			obj = parser_8859_15::doParseFile((Configuration::getV2Path() + "/mod/" + itr + "/common/issues.txt").c_str());
			if (obj != NULL)
			{
				governmentMapper::getInstance()->initReforms(obj);
				break;
			}
		}
	}
	if (!governmentMapper::getInstance()->areReformsInitialized())
	{
		obj = parser_8859_15::doParseFile((Configuration::getV2Path() + "/common/issues.txt").c_str());
		if (obj != NULL)
		{
			governmentMapper::getInstance()->initReforms(obj);
		}
	}

	// import Vic2 states
	LOG(LogLevel::Info) << "Importing Vic2 states";

	stateMapping	stateMap;
	stateIdMapping	stateIdMap;
	bool				stateMapInitialized = false;
	for (auto itr: vic2Mods)
	{
		if (Utils::DoesFileExist(Configuration::getV2Path() + "/mod/" + itr + "/map/region.txt"))
		{
			obj = parser_8859_15::doParseFile((Configuration::getV2Path() + "/mod/" + itr + "/map/region.txt").c_str());
			if (obj != NULL)
			{
				initStateMap(obj, stateMap, stateIdMap);
				stateMapInitialized = true;
				break;
			}
		}
	}
	if (!stateMapInitialized)
	{
		obj = parser_8859_15::doParseFile((Configuration::getV2Path() + "/map/region.txt").c_str());
		if (obj != NULL)
		{
			initStateMap(obj, stateMap, stateIdMap);
		}
		else
		{
			LOG(LogLevel::Error) << "Could not import " << Configuration::getV2Path() << "/map/region.txt";
		}
	}

	LOG(LogLevel::Info) << "* Importing V2 save *";

	//	Parse V2 Save
	LOG(LogLevel::Info) << "Parsing save";
	obj = parser_8859_15::doParseFile(V2SaveFileName.c_str());
	if (obj == NULL)
	{
		LOG(LogLevel::Error) << "Could not parse file " << V2SaveFileName << ". File is likely missing.";
		exit(-1);
	}

	// Construct world from V2 save.
	LOG(LogLevel::Info) << "Building world";
	V2World sourceWorld(obj, iNumToname, armyTechs, navyTechs, continentMap);

	// Read all localisations.
	LOG(LogLevel::Info) << "Reading localisation";
	V2Localisation localisation;
	localisation.ReadFromAllFilesInFolder(Configuration::getV2Path() + "/localisation");
	for (auto itr: vic2Mods)
	{
		LOG(LogLevel::Debug) << "Reading mod localisation";
		localisation.ReadFromAllFilesInFolder(Configuration::getV2Path() + "/mod/" + itr + "/localisation");
	}

	sourceWorld.setLocalisations(localisation, stateIdMap);


	// Merge nations
	LOG(LogLevel::Info) << "Merging nations";
	obj = parser_UTF8::doParseFile("merge_nations.txt");
	if (obj == NULL)
	{
		LOG(LogLevel::Error) << "Could not parse file merge_nations.txt";
		exit(-1);
	}
	mergeNations(sourceWorld, obj);

	// Parse province mappings
	LOG(LogLevel::Info) << "Parsing province mappings";
	obj = parser_8859_15::doParseFile("province_mappings.txt");
	if (obj == NULL)
	{
		LOG(LogLevel::Error) << "Could not parse file province_mappings.txt";
		exit(-1);
	}
	HoI4ToVic2ProvinceMapping			provinceMap;
	Vic2ToHoI4ProvinceMapping	inverseProvinceMap;
	resettableMap				resettableProvinces;
	initProvinceMap(obj, provinceMap, inverseProvinceMap, resettableProvinces);
	sourceWorld.checkAllProvincesMapped(inverseProvinceMap);

	// Parse HoI4 data files
	LOG(LogLevel::Info) << "Parsing HoI4 data";
	HoI4World destWorld(&sourceWorld);
	map<int, vector<int>> HoI4DefaultStateToProvinceMap;
	HoI4States* theStates = new HoI4States(&sourceWorld);
	theStates->importStates(HoI4DefaultStateToProvinceMap);
	map<int, int> provinceToSupplyZoneMap;
	destWorld.importSuppplyZones(HoI4DefaultStateToProvinceMap, provinceToSupplyZoneMap);
	destWorld.importStrategicRegions();
	destWorld.checkAllProvincesMapped(provinceMap);
	destWorld.checkCoastalProvinces();

	// Get country mappings
	CountryMapping countryMap;
	countryMap.ReadRules("country_mappings.txt");
	countryMap.CreateMapping(sourceWorld, destWorld);

	// Get adjacencies
	LOG(LogLevel::Info) << "Importing HoI4 adjacencies";
	HoI4AdjacencyMapping HoI4AdjacencyMap = initHoI4AdjacencyMap();

	// Leaders
	map<int, int> leaderIDMap; // <V2, HoI4>

	// Parse government jobs
	/*LOG(LogLevel::Info) << "Parsing government jobs";
	parser_UTF8::initParser();
	obj = parser_UTF8::doParseFile("governmentJobs.txt");
	if (obj == NULL)
	{
		LOG(LogLevel::Error) << "Could not parse file governmentJobs.txt";
		exit(-1);
	}*/
	governmentJobsMap governmentJobs;
	//initGovernmentJobTypes(obj->getLeaves()[0], governmentJobs);

	// Parse leader traits
	LOG(LogLevel::Info) << "Parsing government jobs";
	/*parser_UTF8::initParser();
	obj = parser_UTF8::doParseFile("leader_traits.txt");
	if (obj == NULL)
	{
		LOG(LogLevel::Error) << "Could not parse file leader_traits.txt";
		exit(-1);
	}*/
	leaderTraitsMap leaderTraits;
	//initLeaderTraitsMap(obj->getLeaves()[0], leaderTraits);

	// parse names
	LOG(LogLevel::Info) << "Parsing names";
	namesMapping namesMap;
	vic2Mods = Configuration::getVic2Mods();
	for (auto itr: vic2Mods)
	{
		LOG(LogLevel::Debug) << "Reading mod cultures";
		obj = parser_8859_15::doParseFile((Configuration::getV2Path() + "/mod/" + itr + "/common/cultures.txt").c_str());
		if (obj != NULL)
		{
			initNamesMapping(obj, namesMap);
		}
	}
	obj = parser_8859_15::doParseFile((Configuration::getV2Path() + "/common/cultures.txt").c_str());
	if (obj != NULL)
	{
		initNamesMapping(obj, namesMap);
	}

	// parse portraits list
	LOG(LogLevel::Info) << "Parsing portraits list";
	portraitMapping portraitMap;
	obj = parser_UTF8::doParseFile("portraits.txt");
	if (obj != NULL)
	{
		initPortraitMapping(obj, portraitMap);
	}

	// parse culture mapping
	LOG(LogLevel::Info) << "Parsing culture mappings";
	obj = parser_UTF8::doParseFile("culture_map.txt");
	if (obj == NULL)
	{
		LOG(LogLevel::Error) << "Could not parse file culture_map.txt";
		exit(-1);
	}
	if (obj->getLeaves().size() < 1)
	{
		LOG(LogLevel::Error) << "Failed to parse culture_map.txt";
		return 1;
	}
	cultureMapping cultureMap;
	cultureMap = initCultureMap(obj->getLeaves()[0]);

	// parse personality mapping
	LOG(LogLevel::Info) << "Parsing personality mappings";
	/*obj = parser_UTF8::doParseFile("personality_map.txt");
	if (obj == NULL)
	{
		LOG(LogLevel::Error) << "Could not parse file personality_map.txt";
		exit(-1);
	}
	if (obj->getLeaves().size() < 1)
	{
		LOG(LogLevel::Error) << "Failed to parse personality_map.txt";
		return 1;
	}*/
	personalityMap landPersonalityMap;
	personalityMap seaPersonalityMap;
	//initLeaderPersonalityMap(obj->getLeaves()[0], landPersonalityMap, seaPersonalityMap);

	// parse background mapping
	LOG(LogLevel::Info) << "Parsing background mappings";
	/*obj = parser_UTF8::doParseFile("background_map.txt");
	if (obj == NULL)
	{
		LOG(LogLevel::Error) << "Could not parse file background_map.txt";
		exit(-1);
	}
	if (obj->getLeaves().size() < 1)
	{
		LOG(LogLevel::Error) << "Failed to parse background_map.txt";
		return 1;
	}*/
	backgroundMap landBackgroundMap;
	backgroundMap seaBackgroundMap;
	//initLeaderBackgroundMap(obj->getLeaves()[0], landBackgroundMap, seaBackgroundMap);

	// parse AI focus data
	LOG(LogLevel::Info) << "Parsing AI focuses";
	/*obj = parser_UTF8::doParseFile("ai_focus.txt");
	if (obj == NULL)
	{
		LOG(LogLevel::Error) << "Could not parse file ai_focus.txt";
		exit(-1);
	}
	if (obj->getLeaves().size() < 1)
	{
		LOG(LogLevel::Error) << "Failed to parse ai_focus.txt";
		return 1;
	}*/
	AIFocusModifiers focusModifiers;
	//initAIFocusModifiers(obj, focusModifiers);
	// Convert
	LOG(LogLevel::Info) << "Converting states";
	theStates->convertStates(provinceMap, inverseProvinceMap, countryMap, localisation);
	destWorld.addStates(theStates);
	destWorld.convertNavalBases(inverseProvinceMap);
	LOG(LogLevel::Info) << "Converting countries";
	destWorld.convertCountries(countryMap, inverseProvinceMap, leaderIDMap, localisation, governmentJobs, leaderTraits, namesMap, portraitMap, cultureMap, landPersonalityMap, seaPersonalityMap, landBackgroundMap, seaBackgroundMap);
	LOG(LogLevel::Info) << "Converting industry";
	destWorld.convertIndustry();
	destWorld.convertResources();
	destWorld.convertSupplyZones(provinceToSupplyZoneMap);
	destWorld.convertStrategicRegions();
	LOG(LogLevel::Info) << "Converting diplomacy";
	destWorld.convertDiplomacy(countryMap);
	LOG(LogLevel::Info) << "Converting techs";
	destWorld.convertTechs();
	LOG(LogLevel::Info) << "Adding minimal levels of airbase and port";
	destWorld.addMinimalItems(inverseProvinceMap);
	LOG(LogLevel::Info) << "Setting up factions";
	destWorld.configureFactions(countryMap);
	LOG(LogLevel::Info) << "Generating Leaders";
	destWorld.generateLeaders(leaderTraits, namesMap, portraitMap);
	LOG(LogLevel::Info) << "Converting armies and navies";
	destWorld.convertArmies(inverseProvinceMap);
	destWorld.convertNavies();
	destWorld.convertAirforces();
	LOG(LogLevel::Info) << "Converting victory points";
	destWorld.convertVictoryPoints(countryMap);
	LOG(LogLevel::Info) << "Setting AI focuses";
	destWorld.setAIFocuses(focusModifiers);
	LOG(LogLevel::Info) << "Creating buildings";
	HoI4Buildings buildings(theStates->getProvinceToStateIDMap());
	
	// Output results
	LOG(LogLevel::Info) << "Outputting mod";
	if (!Utils::copyFolder("blankMod/output", "output/output"))
	{
		exit(-1);
	}

	FILE* modFile;	// the .mod file for this mod
	if (fopen_s(&modFile, ("Output/" + Configuration::getOutputName() + ".mod").c_str(), "w") != 0)
	{
		LOG(LogLevel::Error) << "Could not create .mod file";
		exit(-1);
	}
	fprintf(modFile, "name = \"Converted - %s\"\n", Configuration::getOutputName().c_str());
	fprintf(modFile, "path = \"mod/%s/\"\n", Configuration::getOutputName().c_str());
	fprintf(modFile, "user_dir = \"%s_user_dir\"\n", Configuration::getOutputName().c_str());
	fprintf(modFile, "replace = \"history/countries\"\n");
	//fprintf(modFile, "replace = \"history/diplomacy\"\n");
	fprintf(modFile, "replace = \"history/states\"\n");
	fclose(modFile);

	string renameCommand = "move /Y output/output output/" + Configuration::getOutputName();	// the command to rename the mod correctly
	if (!Utils::renameFolder("output/output", "output/" + Configuration::getOutputName()))
	{
		exit(-1);
	}

	destWorld.outputRelations();
	LOG(LogLevel::Info) << "Copying flags";
	copyFlags(destWorld.getCountries());
	//Utils::TryCopyFile("NeededFiles/gfx", "Output/" + Configuration::getOutputName());
	LOG(LogLevel::Info) << "Outputting world";
	destWorld.output();
	buildings.output();

	destWorld.thatsgermanWarCreator(sourceWorld, countryMap);
	LOG(LogLevel::Info) << "* Conversion complete *";
	return 0;
}


int main(const int argc, const char* argv[])
{
	try
	{
		const char* const defaultV2SaveFileName = "input.v2";	// the default name for a save to convert
		string V2SaveFileName;											// the actual name for the save to convert
		if (argc >= 2)
		{
			V2SaveFileName = argv[1];
			LOG(LogLevel::Info) << "Using input file " << V2SaveFileName;
		}
		else
		{
			V2SaveFileName = defaultV2SaveFileName;
			LOG(LogLevel::Info) << "No input file given, defaulting to " << defaultV2SaveFileName;
		}
		return ConvertV2ToHoI4(V2SaveFileName);
	}
	catch (const std::exception& e)	// catch any errors
	{
		LOG(LogLevel::Error) << e.what();
		return -1;
	}
}