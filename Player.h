#pragma once
#include <string>
using namespace std;
class Player {
protected:
    int health;
    int baseDamage;
    int maxHealth;
    string playerName;
    int healMin;
    int healMax;
    int additionalMinDamage;
    int additionalMaxDamage;

public:
    Player(int h, int bs, int minhl, int maxhl, int addMinDam, int addMaxDam, std::string nam);
    void introduction();
    void takeDamage(int damage);
    void heal();
    void attack(Player& other);
    bool isAlive();
    string getName();
    virtual ~Player() {}
};