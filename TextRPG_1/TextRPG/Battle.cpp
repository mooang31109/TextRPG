#include "Battle.h"

bool battle(Player* player, Monster& monster, vector<Item>& inventory)
{
    cout << "\n[ Battle Start! ] "
        << player->getName() << "(" << player->getJob() << ")"
        << " vs " << monster.getName() << endl;

    while (player->getHP() > 0 && monster.getHP() > 0)
    {
        // 플레이어 턴
        cout << "\n--- Player Turn ---" << endl;
        /*
        player->attack();
        int dmg = max(1, player->getPower() - monster.getDefense());
        int prevHP = monster.getHP();
        monster.setHP(monster.getHP() - dmg);
        cout << dmg << " damage to " << monster.getName() << "!" << endl;
        cout << monster.getName() << " HP: " << player -> getHP()
            << " -> " << monster.getHP();
        */
        player->attack(&monster);
        if (monster.getHP() <= 0) { cout << " (Dead)" << endl; break; }
        cout << endl;

        // 몬스터 턴
        cout << "\n--- Monster Turn ---" << endl;
        int prevPlayerHP = player->getHP();
        monster.attack(player);
        cout << monster.getName() << " attacks! "
            << player->getName() << " HP: " << prevPlayerHP
            << " -> " << player->getHP();
        if (player->getHP() <= 0) { cout << " (Dead)" << endl; break; }
        cout << endl;
    }

    // 승리/패배 판정
    if (player->getHP() > 0)
    {
        Item dropped = { monster.getDropItemName(), monster.getDropItemPrice() };
        inventory.push_back(dropped);

        int expGet = monster.getexpReward();
        player->setExp(player->getExp() + expGet);
        cout << "  -> +" << expGet << "EXP! (EXP: "
            << player->getExp() << "/" << player->getMaxExp() << ")" << endl;

        //레벨업!
        if (player->getExp() >= player->getMaxExp())
        {
            player->levelUp();
        }

        cout << "\nVictory!" << endl;
        cout << "  -> Got: " << dropped.name << "!" << endl;
        cout << "  -> Saved to inventory." << endl;
        return true;
    }
    else
    {
        cout << "\nDefeated... Game Over." << endl;
        return false;
    }
}