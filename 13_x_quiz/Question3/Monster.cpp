
#include <string>
#include <string_view>
#include <iostream>

class Monster
{
public:

	enum class MonsterType
	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		max_monster_types
	};

	Monster(const MonsterType& type, const std::string& name, const std::string& roar, const int& hitPoints) 
		: m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
	{
	}
	
	std::string_view getTypeString() const
	{
		switch (m_type)
		{
		case MonsterType::dragon: return "dragon";
		case MonsterType::goblin: return "goblin";
		case MonsterType::ogre: return "ogre";
		case MonsterType::orc: return "orc";
		case MonsterType::skeleton: return "skeleton";
		case MonsterType::troll: return "troll";
		case MonsterType::vampire: return "vampire";
		case MonsterType::zombie: return "zombie";
		default: return "???";
		}
	}

	void print() const
	{
		std::cout << "The " << getTypeString() << " has " << m_hitPoints << " hitpoints and says: " << m_roar << '\n';
	}

private:

	MonsterType m_type{};
	std::string m_name;
	std::string m_roar{};
	int m_hitPoints{};

	
};

class MonsterGenerator
{
public:

	// Generate a random number between min and max (inclusive)
	// Assumes std::srand() has already been called
	// Assumes max - min <= RAND_MAX
	static int getRandomNumber(int min, int max)
	{
		static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
	}

	static Monster generateMonster()
	{
		auto type{ }

	}
};



