#include <iostream>
#include "Player.h"
#include "DerivedPlayers.h"
#include <cstdlib>
#include <ctime>

using namespace std;

void gameLoop(Player& player1, Player& player2) {
    srand(time(0));

    while (player1.isAlive() && player2.isAlive()) {
        for (int i = 0; i < 2; i++) {
            Player* currentPlayer = (i == 0) ? &player1 : &player2;
            Player* opponentPlayer = (i == 0) ? &player2 : &player1;

            cout << currentPlayer->getName() << "'s turn. Press H to heal or D to attack: ";
            char choice;
            cin >> choice;
            cout << endl;

            if (choice == 'H' || choice == 'h') {
                currentPlayer->heal();
            }
            else if (choice == 'D' || choice == 'd') {
                currentPlayer->attack(*opponentPlayer);
            }

            if (!opponentPlayer->isAlive()) {
                break;
            }
        }
    }
    if (player1.isAlive()) {
        cout << player1.getName() << " wins!" << endl;
    }
    else {
        cout << player2.getName() << " wins!" << endl;
    }
}

    int main() {
        cout << "Welcome to the 2-Player Battle Game!" << endl;

        Player* players[2]; 
        string playerLabels[] = { "Player 1", "Player 2" };

        
        for (int i = 0; i < 2; i++) {
            cout << playerLabels[i] << ": Choose your player (1 for Powerful, 2 for Skillful, 3 for Raged): ";
            int choice;
            cin >> choice;
            cout << endl;

            
            if (choice == 1) {
                players[i] = new PowerfulPlayer();
            }
            else if (choice == 2) {
                players[i] = new SkillfulPlayer();
            }
            else if(choice == 3){
                players[i] = new RagedPlayer();
            }
            else {
                cout << "There is no player!" << endl;
            }

            players[i]->introduction();
        }

        
        gameLoop(*players[0], *players[1]);

        delete players[0];
        delete players[1];

        return 0;
    }
