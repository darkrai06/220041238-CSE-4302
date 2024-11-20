#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CharacterActions {
public:
    virtual void attack() = 0;
    virtual void defend() = 0;
    virtual void useSpecialAbility() = 0;
    virtual void displayStats() const = 0;
    virtual bool isAlive() const = 0;
    virtual string getName() const = 0;
    virtual int getAttackPower() const = 0;
    virtual int getSpecialPower() const = 0;
};

class BaseCharacter : public CharacterActions {
protected:
    string name;
    int health;
    int mana;
    int attackPower;
    string specialAbilityName;
    int specialAbilityPower;
    int specialUse;
    bool defending;

public:
    BaseCharacter(string n, int h, int ap, string saName, int saPower)
        : name(n), health(h), mana(0), attackPower(ap), specialAbilityName(saName), specialAbilityPower(saPower), specialUse(0), defending(false) {}

    void attack() override
    {
        cout << name << " attacks with power " << attackPower << "!\n";
        mana += 50;
    }

    void defend() override
    {
        defending = true;
    }

    void useSpecialAbility() override
    {
        if (mana >= 100)
        {
            cout << name << " uses " << specialAbilityName << " with power " << specialAbilityPower << "!\n";
            mana = 0;
            specialUse=specialAbilityPower;
        }

        else specialUse=0;
    }

    void takeDamage(int damage)
    {
        if (defending)
        {
            cout << name << " blocks the attack! No damage taken.\n";
            defending = false;
        }
        else
        {
            health -= damage;
            cout << name << " takes " << damage << " damage! Health now: " << health << "\n";
        }
    }

    bool isAlive() const override
    {
        return (health>0);
    }

    void displayStats() const override
    {
        cout << name << " - Health: " << health << ", Mana: " << mana << "\n";
    }

    string getName() const override
    {
        return name;
    }

    int getAttackPower() const override
    {
        return attackPower;
    }

    int getSpecialPower() const override
    {
        return specialUse;
    }
};

class Warrior : public BaseCharacter {
public:
    Warrior(string n, int h, int ap, string saName, int saPower) : BaseCharacter(n,h,ap,saName,saPower) {}
};

class Mage : public BaseCharacter {
public:
    Mage(string n, int h, int ap, string saName, int saPower) : BaseCharacter(n,h,ap,saName,saPower) {}
};

class Archer : public BaseCharacter {
public:
    Archer(string n, int h, int ap, string saName, int saPower) : BaseCharacter(n,h,ap,saName,saPower) {}
};

class BossEnemy {
private:
    int health;
    int attackPower;

public:
    BossEnemy(int h, int ap) : health(h), attackPower(ap) {}

    void takeDamage(int damage)
    {
        health -= damage;
    }

    void displayDamage(int damage)
    {
        cout << "Boss takes " << damage << " damage! Health now: " << health << "\n";
    }

    void attack(BaseCharacter& character)
    {
        cout << "Boss attacks " << character.getName() << " with power " << attackPower << "!\n";
        character.takeDamage(attackPower);
    }

    bool isAlive() const
    {
        return (health>0);
    }
};

class GameEngine {
private:
    vector<BaseCharacter*> players;
    BossEnemy boss;

public:
    int flag=1;
    GameEngine() : boss(150, 30)
    {
        players.push_back(new Warrior("Warrior", 100, 25, "Berserk Rage", 35));
        players.push_back(new Mage("Mage", 120, 20, "Arcane Blast", 30));
        players.push_back(new Archer("Archer", 90, 20, "Fire Arrow", 35));
    }

    void startGame()
    {
        cout << "Game begins! Players VS Boss\n";

        while (boss.isAlive())
        {
            for (auto player : players)
            {
                if (!player->isAlive())
                    continue;

                //player->defend();
                player->attack();
                boss.takeDamage(player->getAttackPower());
                if(!boss.isAlive())
                {
                    boss.displayDamage(player->getAttackPower());
                    break;
                }
                player->useSpecialAbility();
                boss.takeDamage(player->getSpecialPower());
                boss.displayDamage(player->getAttackPower()+player->getSpecialPower());

                if (!boss.isAlive())
                    break;
            }

            if (!boss.isAlive())
                break;

            for (auto player : players)
            {
                if (!player->isAlive())
                    continue;

                boss.attack(*player);
                if (!player->isAlive())
                {
                    flag=0;
                    cout << player->getName() << " has died! Game over.\n";
                    goto jump;
                }
            }
        }

        jump :

        if(flag)
        cout << "Boss defeated! Players win!\n";
    }
};

int main()
{
    GameEngine game;
    game.startGame();
    return 0;
}
