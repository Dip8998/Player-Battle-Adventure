#include <iostream>
#include "Player.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Player::Player(int h, int bs, int minhl, int maxhl, int addMinDam, int addMaxDam, string nam)
    : health(h), baseDamage(bs), maxHealth(h), playerName(nam),
    healMin(minhl), healMax(maxhl), additionalMinDamage(addMinDam), additionalMaxDamage(addMaxDam) {}

void Player::introduction() {
    cout << "Hey, I am " << playerName << "." << endl;
    cout << "Health: " << health << endl;
    cout << "Base Damage: " << baseDamage << endl;
    cout << "Additional Damage: " << additionalMinDamage << " - " << additionalMaxDamage << endl;
    cout << "Healing Capacity: " << healMin << " - " << healMax << endl << endl;
}

void Player::takeDamage(int damage) {
    if (health > 0) {
        health -= damage;
    }
    if (health < 0) {
        health = 0;
    }
    cout << playerName << " took " << damage << " damage. Current health: " << health << endl << endl;
}

void Player::heal() {
    if (health == maxHealth) {
        cout << playerName << " is already at full health." << endl;
    }
    else {
        int randHeal = rand() % (healMax - healMin + 1) + healMin;
        health += randHeal;
        if (health > maxHealth) {
            health = maxHealth;
        }
        cout << playerName << " healed " << randHeal << " points. Current health: " << health << endl;
    }
}

void Player::attack(Player& other) {
    int extraDamage = rand() % (additionalMaxDamage - additionalMinDamage + 1) + additionalMinDamage;
    int totalDamage = baseDamage + extraDamage;
    cout << playerName << " attacks for " << totalDamage << " damage!" << endl;
    other.takeDamage(totalDamage);
}

bool Player::isAlive() {
    return health > 0;
}

std::string Player::getName() {
    return playerName;
}
