#include <iostream>
#include "game.h"
#include <vector>
#include <fstream>

// Pulls all current stored games and saves them to a txt file to load later.
void save_games(vector<Game> games) {
    ofstream save("games.txt");
    if(!save) {
        cerr << "Cannot open save file.";
        exit(0);
    }
    for(Game currgame : games) {
        save << currgame.get_title() << endl;
        if(currgame.has_played()) {
            save << "y\n";
        } else {
            save << "n\n";
        }
    }
    save.close();
}

// Pulls the games from the old save file.
vector<Game> load_games() {
    vector<Game> loaded_games;
    ifstream load("games.txt");
    string line, title;
    char played;
    while(getline(load, line)) {
        title = line;
        getline(load, line);
        played = line.at(0);
        bool has_played = false;
        if(played == 'y') {
            has_played = true;
        }
        Game add_game(title, has_played);
        loaded_games.push_back(add_game);
    }
    load.close();
    return loaded_games;
}

int main() {
    int i;
    vector<Game> games = load_games();
    while(true) {
        cout << "\nEnter your choice\n1: Add game\n2: list games\n3: exit\n";
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
            cout << "\n\nPLAYED GAMES\n==============\n";
            for(Game a : played_games) {
                cout << a.get_title() << endl;
            }
            cout << "\nUNPLAYED GAMES\n================\n";
            for (Game b : unplayed_games) {
                cout << b.get_title() << endl;
            }
        } else if(i == 3) {
            save_games(games);
            cout << "k bye\n";
            exit(0);
        } else {
            cout << "Please enter only 1, 2, or 3\n";
        }
    }
}