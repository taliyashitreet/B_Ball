#pragma once
#include "Team.hpp"
#include "Schedule.hpp"
#include<vector>
#include<iterator>
#include<algorithm>


namespace ariel {

    class Leauge {
    public:
        vector<Team*> teams;
        bool leaugeEnd;

        Leauge();
        Leauge(vector<Team*> teams);

        ~Leauge();

        void start();

        void fix();

      //  void printLeauge(int limit);
    };
}