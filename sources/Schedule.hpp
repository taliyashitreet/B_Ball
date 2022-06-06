#pragma once
#include "Game.hpp"
#include "Team.hpp"
#include "Leauge.hpp"
#include<iterator>
using namespace std;


namespace ariel{
    class Schedule
    {
    private:
    public:
        vector<Game*> Games;
        Schedule(vector<Team*> teams){
            if(teams.size() != 20){
                throw std::invalid_argument("leauge must be with 20 teams");
            }
            for(auto iter1 = teams.begin(); iter1 < teams.end(); iter1++){
                for(auto iter2 = teams.begin(); iter2 < teams.end(); iter2++){
                    if (*iter1 != *iter2)
                    {
                        this->Games.push_back(new Game(*iter1, *iter2));
                        this->Games.push_back(new Game(*iter2, *iter1));
                    }
                }
            }
        }
        ~Schedule(){
             for (int i = (int)this->Games.size() - 1; i >= 0; --i) {
            delete Games.at((unsigned int)i);
        }
        }
    };

    
}