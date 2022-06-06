#include "Leauge.hpp"
using namespace std;
int const NumTeams = 20;
double const EPS = 0.001;

namespace ariel
{
    Leauge::Leauge()
    {
        this->leaugeEnd = false;
        for (int i = 0; i < NumTeams; ++i)
        {
            double r = ((double)rand() / (RAND_MAX)) + 1;
            this->teams.push_back(new Team(to_string(i), r));
        }
    }
    Leauge::Leauge(vector<Team *> teams)
    {
        if (teams.size() > NumTeams)
        {
            throw invalid_argument("Too much teams\n");
        }
        for (auto iter = teams.begin(); iter < teams.end(); iter++)
        {
            this->teams.push_back(*iter);
        }
        for (int i = 0; i < NumTeams - teams.size(); i++)
        {
            double r = ((double)rand() / (RAND_MAX)) + 1;
            this->teams.push_back(new Team(to_string(i), r));
        }
        
    }
        Leauge::~Leauge() {
        for (int i = (int)teams.size() - 1; i >= 0; --i) {
            delete teams.at((unsigned int)i);
        }
    }
     void Leauge::start(){
        Schedule* schedule = new Schedule(this->teams);
        for (auto iter = schedule->Games.begin(); iter < schedule->Games.end(); iter++) {
            (*iter)->GameMove();
        }
        this->leaugeEnd = true;
        fix();
    
    }
    void Leauge::fix(){

            if (!this->leaugeEnd){
            throw invalid_argument("Leauge didn't start yet\n");
        }
        for (unsigned int i = 0; i < NumTeams; ++i) {
            this->teams.at(i)->score = this->teams.at(i)->wins + EPS*(this->teams.at(i)->scorePts -this->teams.at(i)->sufferedPts);
        }
         for (size_t i = 0; i < this->teams.size() - 1; ++i) {
            for (size_t j = 0; j < this->teams.size() - i - 1; ++j) {
                if (this->teams.at(j)->score < this->teams.at(j + 1)->score)
                    swap(this->teams.at(j), this->teams.at(j + 1));
            }
        }

    }
    // void Leauge::printLeauge(int limit){
    //     if (!this->leaugeEnd){
    //         throw invalid_argument("leauge not started yet\n");
    //     }
    //     cout << "\n---------Leauge Rank---------" << endl;

    //     for (unsigned int i = 0; i < limit; ++i) {
    //         cout << "\n" << endl;
    //         cout << i+1 << ". " << this->teams.at(i)->name << "\n Wins-Loses: " << this->teams.at(i)->wins
    //                   << "-" << this->teams.at(i)->loses<< ".\nScore-Suffer: " << this->teams.at(i)->scorePts << "-"
    //                   << this->teams.at(i)->sufferedPts << ".\nTOTAL SCORE: " << this->teams.at(i)->score << std::endl;
    //     }
    //     int maxWINS = 0;
    //     Team* maxWin;
    //     int maxLOSES = 0;
    //     Team* maxLose;
    //     for (auto iter = this->teams.begin(); iter < this->teams.end(); iter++){
    //         if((*iter)->winSpree_max > maxWINS){
    //             maxWINS = (*iter)->winSpree_max;
    //             maxWin = *iter;
    //         }
    //         if((*iter)->loseSpree_max > maxLOSES){
    //             maxLOSES = (*iter)->loseSpree_max;
    //             maxLose = *iter;
    //         }
    //     }

    //     for (auto iter = this->teams.begin(); iter < this->teams.end(); iter++) {
    //         if((*iter)->scorePts - (*iter)->sufferedPts > 0){
    //             cout << (*iter)->name << " with: " <<(*iter)->scorePts << ":" <<(*iter)->sufferedPts << std::endl;
    //         }
    //     }
    // }


} // namespace name
