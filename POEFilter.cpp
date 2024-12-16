#include <string>
#include <vector>
#include <set>

struct Color {
	uint8_t r, g, b, a;
};

struct AlertSound {
	int id;//1-16
	int volume;//0-300
	bool positional;//true/false
};

struct MiniMapDisplay {
	int Size;//2 (small), 1 (medium), 0 (largest), -1 (disabled)
	std::string color;//Red,Green,Blue,Brown,White,Yellow,Cyan,Grey,Orange,Pink,Purple.
	std::string shape;//Circle,Diamond,Hexagon,Square,Star,Triangle,Cross,Moon,Raindrop,Kite,Pentagon,UpsideDownHouse
	std::string effect;//<color> [Temp] temp is optional. This is the light beam emitted for an item when it's dropped. "None" to disable.
};

struct CustomAlert {
	std::string Filename;//name of the file to use for the custom alert. "None" (disable), need relative path from directory, or absolute path. Should use relative.
};

class filter {
public:

	//Conditions
	int AreaLevel;//0-100
	int ItemLevel;//0-100
	int DropLevel;//0-100
	int Quality;//0-20
	std::string Rarity;//Normal, Magic, Rare, Unique TODO: Make Rarity set.
	std::vector<std::string> Class;//specifying item classes. partial class names are allowed and will match any classes with that text in the name.
	std::vector<std::string> BaseType;
	int Sockets;//0-2? Number of rune sockets on the item.
	int Height;//1-4 The number of slots the item takes on the Y-axis
	int Width;//1-2 The number of slots the item takes on the X-axis
	std::string HasExplicitMod;//filter by mods on an item by name. For example: [HasExplicitMod "Tyrannical"] (Tyrannical=Local Physical Damage 155-169%)
	bool AnyEnchantment;//Any Lybrinith Mod - TODO: Does this apply?
	std::string HasEnchantment;//Specific Enchantment from Lybrinith - TODO: Again, does this apply?
	int StackSize;//1-n Applies to currency stacks in notes on website. TODO: Does it apply to essence?
	int GemLevel;//1-21 TODO: Does this apply? Gems don't really have levels in the same sense in POE2. Uncut level perhaps?
	std::string GemQualityType;//Superior/Divergent/Anomalous/Phantasmal - TODO: Does this apply?
	bool Identified;//Is or is not Identified.
	bool Corrupted;//Is or is not Corrupted.
	bool Mirrored;//Is or is not Mirrored.
	bool ElderItem;//Is or is not Elder item. TODO: Does this apply?
	bool ShaperItem;//Is or is not Shaper item. TODO: Does this apply?
	std::string HasInfluence;//If an item has influence of a certain type. Note that this also affects maps that are influenced. If want item that has no Influence, choose value as None.
	int HasSearingExarchImplicit;//0-6 TODO: Does this apply?
	int HasEaterOfWorldsIMplicit;//0-6 TODO: Does this apply?
	bool FracturedItem;//if an item is fractured or not.
	bool SynthesisedItem;//if an item is synthesised or not.
	bool ElderMap;
	bool ShapedMap;
	bool BlightedMap;
	int WaystoneTier;//1-17
	bool HasImplicitMod;//if an item has any implicit mod or not.
	bool HasCruciblePassiveTree;//if an item has a crucible passive skill tree or not.

	//Actions
	Color SetBorderColor;//r,g,b,a 0-255
	Color SetTextColor;//r,g,b,a 0-255
	Color SetBackgroundColor;//r,g,b,a 0-255
	int SetFontSize;//18-45 (default: 32)
	AlertSound PlayAlertSound;//id, volume, and if it should be positional (true/false)
	bool DisableDropSound;
	bool EnableDropSound;

};

int main() {
	static std::set<std::string> ClassSet = {
		//Currency
		"Stackable Currency",

		//Armour / Armor
		"Amulet",
		"Belt",
		"Body Armour",
		"Boots",
		"Charm",
		"Gloves",
		"Helmet",
		"Ring",

		//Weapons (Mainhand/Offhand)
		"Bows",
		"Claws",
		"Daggers",
		"One Hand Maces",
		"One Hand Axes",
		"One Hand Swords",
		"Quarterstaves",
		"Quivers",
		"Sceptres",
		"Shields",
		"Staves",
		"Two Hand Axes",
		"Two Hand Maces",
		"Two Hand Swords",
		"Wands",

		//Gems - Can't find correct tag for Uncut versions or Spirit gems. Perhaps using basetype instead
		"Skill Gems",
		"Support Gems",
		//"Spirit Gem",
		//"Uncut Skill Gem",
		//"Uncut Support Gem",
		//"Uncut Spirit Gem",

		//Misc
		"Jewels",
		"Vault Keys"
		"Waystones",
		"Quest Items",

	};

	static std::set<std::string> BaseTypeSet = {

	};

	static std::set<std::string> RaritySet = {
		"Normal", "Magic", "Rare", "Unique"
	};


}