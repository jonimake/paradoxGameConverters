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


#ifndef HOI4_STATES_H_
#define HOI4_STATES_H_



#include <map>
#include <string>
#include <vector>
#include "HoI4Localisation.h"
#include "HoI4State.h"
#include "..\V2World\V2Localisation.h"
#include "..\V2World\V2Province.h"
#include "..\CountryMapping.h"
using namespace std;



struct MTo1ProvinceComp
{
	MTo1ProvinceComp() : totalPopulation(0) {};

	vector<V2Province*> provinces;
	int totalPopulation;
};


typedef struct ownersAndCores
{
	string owner;
	vector<string> cores;
} ownersAndCores;


class HoI4States
{
	public:
		HoI4States(V2World* srcWorld) : sourceWorld(srcWorld) { recordAllLandProvinces(); }

		void importStates(map<int, vector<int>>& defaultStateToProvinceMap);
		void convertStates(const HoI4ToVic2ProvinceMapping& provinceMap, const Vic2ToHoI4ProvinceMapping& inverseProvinceMap, const CountryMapping& countryMap, const V2Localisation& Vic2Localisations);

		const map<int, HoI4State*>& getStates() const { return states; }
		const map<int, int>& getProvinceToStateIDMap() const { return provinceToStateIDMap; }

		void output() const;

	private:
		void recordAllLandProvinces();

		map<int, ownersAndCores> determineProvinceOwners(const HoI4ToVic2ProvinceMapping& provinceMap, const CountryMapping& countryMap);
		bool getAppropriateMapping(const HoI4ToVic2ProvinceMapping& provinceMap, int provNum, HoI4ToVic2ProvinceMapping::const_iterator& provinceLink);
		map<V2Country*, MTo1ProvinceComp> determinePotentialOwners(HoI4ToVic2ProvinceMapping::const_iterator provinceLink);
		V2Country* selectProvinceOwner(const map<V2Country*, MTo1ProvinceComp>& provinceBins);
		void createStates(const CountryMapping& countryMap, const Vic2ToHoI4ProvinceMapping& HoI4ToVic2ProvinceMap, const map<int, ownersAndCores>& provinceToOwnersAndCoresMap, const V2Localisation& Vic2Localisations);
		bool createMatchingHoI4State(const Vic2State* vic2State, int stateID, const string& stateOwner, const Vic2ToHoI4ProvinceMapping& HoI4ToVic2ProvinceMap, const map<int, ownersAndCores>& provinceToOwnersAndCoresMap, set<int>& assignedProvinces, const V2Localisation& Vic2Localisations);
		void addProvincesToNewState(HoI4State* newState, const Vic2ToHoI4ProvinceMapping& HoI4ToVic2ProvinceMap, const map<int, ownersAndCores>& provinceToOwnersAndCoresMap, set<int>& assignedProvinces);
		bool isProvinceOwnedByCountryAndNotAlreadyAssigned(int provNum, string stateOwner, const map<int, ownersAndCores>& provinceToOwnersAndCoresMap, set<int>& assignedProvinces);
		void createVPForState(HoI4State* newState, const Vic2ToHoI4ProvinceMapping& provinceMap);
		void addManpowerToNewState(HoI4State* newState);
		void addLocalisation(int HoI4StateID, string Vic2StateID, const V2Localisation& Vic2Localisations);

		void outputHistory() const;
		void outputLocalisations() const;

		V2World* sourceWorld;

		set<int> landProvinces;
		map<int, HoI4State*> states;
		map<int, string> stateFilenames;
		map<int, int> provinceToStateIDMap;
		languageToLocalisationsMap stateLocalisations;		// a map between languages and state localisations
};



#endif // HOI4_STATES_H_
