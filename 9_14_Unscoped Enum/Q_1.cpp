namespace monster
{
    enum MonsterType
    {
        orcs, 
        goblins,
        trolls,
        ogres,
        seletons,
    };
}


int main()
{
    monster::MonsterType monster { monster::trolls };

    return 0;
}