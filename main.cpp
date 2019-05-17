#include <iostream>
#include "game.h"
#include <vector>
#include <fstream>

void save_games() {
    ofstream save("games.txt");
    if(!save) {
        cerr << "Cannot open save file.";
        exit(0);
    }
    save << "Example title\n";
    save.close();
}

int main() {
    int i;
    vector<Game> games;
    while(true) {
        cout << "Enter your choice\n1: Add game\n2: list games\n3: exit\n";
        cin >> i;
        cin.ignore();
        if(i == 1) {
            string title;
            bool played = false;
            cout << "Enter the name of the game:\n";
            getline(cin, title);
            cout << "Have you played this game?(y/n)\n";
            string input;
            bool done = false;
            while(done == false) {
                getline(cin, input);
                if(tolower(input[0]) == 'y') {
                    played = true;
                    done = true;
                } else if(tolower(input[0]) != 'n') {
                    cout << "Please enter just y or n\n";
                } else {done = true;}
            }
            Game newgame = Game(title, played);
            games.push_back(newgame);
        } else if(i == 2) {
            vector<Game> played_games;
            vector<Game> unplayed_games;
            for(Game currGame : games) {
                if(currGame.has_played()) {
                    played_games.push_back(currGame);
                } else {
                    unplayed_games.push_back(currGame);
                }
            }
            cout << "PLAYED GAMES\n==============\n";
            for(Game a : played_games) {
                cout << a.get_title() << endl;
            }
            cout << "\nUNPLAYED GAMES\n================\n";
            for (Game b : unplayed_games) {
                cout << b.get_title() << endl;
            }
        } else if(i == 3) {
            save_games();
            cout << "k bye\n";
            exit(0);
        } else {
            cout << "Please enter only 1, 2, or 3\n";
        }
    }
}