#ifndef GAME_H
#define GAME_H
#include <string>
using namespace std;

class Game {
    private:
        string title;
        bool played = false;
    public:
        Game(string title, bool played);
        void toggle_played();
        void set_values(string, bool);
        string get_title() {return title;};
        bool has_played() {return played;};
};

Game::Game(string name, bool has_played) {
    title = name;
    played = has_played;
}

void Game::toggle_played() {
    played = !played;
}

#endif