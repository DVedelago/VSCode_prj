#include <iostream>
#include <string_view>

enum class Monster_type
{
    ogre,
    dragon,
    orc,
    giant_spider,
    slime,
};

struct Monster
{
    std::string m_name;
    Monster_type m_type{};
    int m_health{};
};

std::string_view getMonsterTypeString(Monster_type m_type)
{
	switch (m_type)
	{
	case Monster_type::ogre:
		return "Ogre";
	case Monster_type::dragon:
		return "Dragon";
	case Monster_type::orc:
		return "Orc";
	case Monster_type::giant_spider:
		return "Giant Spider";
	case Monster_type::slime:
		return "Slime";
	}

	return "Unknown";
}

void printMonster(const Monster& mon)
{
    std::cout << "This " << getMonsterTypeString(mon.m_type) << " is named " << mon.m_name << " and it has " << mon.m_health << " health. \n";
}

int main()
{
    Monster ogre_Thorg {"Thorg", Monster_type::ogre, 145};
    Monster slime_Blurp {"Blurp", Monster_type::slime, 23};

    printMonster(ogre_Thorg);
    printMonster(slime_Blurp);

    return 0;
}