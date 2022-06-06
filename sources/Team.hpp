#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace ariel
{
    class Team
    {
    private:
    public:
        string name;
        double ability;
        int wins;
        int loses;
        int winSpree_curr;
        int winSpree_max;
        int loseSpree_curr;
        int loseSpree_max;
        bool teamStatus;
        double score;
        int scorePts;
        int sufferedPts;
        Team(string teamName, double teamAbility)
        {
            if (teamName == "\t" || teamName == "\n" || teamName.empty() || teamName == " " || teamName == "\r")
            {
                throw invalid_argument("Invalid team name\n");
            }
            if (teamAbility < 0 || teamAbility > 1)
            {
                throw invalid_argument("Invalid talent range(Must be in range of [0,1])\n");
            }
            this->name = teamName;
            this->ability = teamAbility;
            this->winSpree_max = 0;
            this->winSpree_curr = 0;
            this->loseSpree_curr = 0;
            this->loseSpree_max = 0;
            this->wins = 0;
            this->loses = 0;
            this->scorePts = 0;
            this->sufferedPts = 0;
        }
        ~Team()
        {
        }
        bool operator==(const Team &other) const
        {
            return name == other.name;
        }

        bool operator!=(const Team &other) const
        {
            return name != other.name;
        }
    };
}