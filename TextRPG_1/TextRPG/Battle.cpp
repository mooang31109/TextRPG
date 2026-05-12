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
        cout << "1. Attack" << endl;
        cout << "2. Use Item" << endl;
        cout << "Choose: ";

        int turnChoice;
        cin >> turnChoice;

        if (turnChoice == 1)
        {
            player->attack(&monster);
        }
        else if (turnChoice == 2)
        {
            // 포션만 필터링해서 출력
            cout << "[ Inventory ]" << endl;
            vector<int> potionIndex; // 포션 위치 저장

            for (int i = 0; i < inventory.size(); i++)
            {
                if (inventory[i].type == "potion")
                {
                    potionIndex.push_back(i);
                    cout << potionIndex.size() << ". ";
                    inventory[i].PrintInfo();
                }
            }
            if (potionIndex.empty())
            {
                cout << "No items available." << endl;
                continue; // 아이템 없으면 턴 다시
            }
            cout << "Choose item: ";
            int itemChoice;
            cin >> itemChoice;

            // 범위 확인
            if (itemChoice < 1 || itemChoice > potionIndex.size())
            {
                cout << "Invalid choice." << endl;
                continue;
            }

            // 실제 인벤토리 인덱스
            int realIndex = potionIndex[itemChoice - 1];
            Item& selected = inventory[realIndex];

            // HP 포션
            if (selected.name == "HP Potion")
            {
                int before = player->getHP();
                int after = min(player->getHP() + 50, player->getMaxHP());
                player->setHP(after);
                cout << "* HP Potion used! HP restored by 50"
                    << " (" << before << " -> " << after << ")" << endl;
            }
            // MP 포션
            else if (selected.name == "MP Potion")
            {
                int before = player->getMP();
                int after = min(player->getMP() + 50, player->getMaxMP());
                player->setMP(after);
                cout << "* MP Potion used! MP restored by 50"
                    << " (" << before << " -> " << after << ")" << endl;
            }

            // 사용한 아이템 인벤토리에서 제거
            inventory.erase(inventory.begin() + realIndex);
            continue; // 아이템 사용 시 몬스터 턴 없이 다시 플레이어 턴
        }
        /*
        player->attack();
        int dmg = max(1, player->getPower() - monster.getDefense());
        int prevHP = monster.getHP();
        monster.setHP(monster.getHP() - dmg);
        cout << dmg << " damage to " << monster.getName() << "!" << endl;
        cout << monster.getName() << " HP: " << player -> getHP()
            << " -> " << monster.getHP();
        */

        /*
        player->attack(&monster);
        if (monster.getHP() <= 0) { cout << " (Dead)" << endl; break; }
        cout << endl;
        */

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