#pragma once
#include<iostream>
#include "Team.hpp"
namespace ariel{
    class Game
    {
    private:
        Team* home;
        Team* guest;
        int homeRand;
        int guestRand;
    public:
        Game(Team* home, Team* out)
        : home(home), guest(out) {
            this->guestRand=0;
            this->homeRand =0;
        }
        ~Game(){}

        void randResult(){
            this->homeRand = 55 + (rand()%(100-55+1));
            this->guestRand = 50+ (rand()%(100-50+1));
            this->homeRand += (int)(this->home->ability * 10); // ability can increse in maximum 10 points
            this->guestRand += (int)(this->guest->ability * 10);
            this->home->scorePts+=(homeRand);
            this->home->sufferedPts+=(guestRand);
            this->guest->scorePts+=(guestRand);
            this->guest->sufferedPts+=(homeRand);
        }

        Team* GameMove(){

            randResult();
            if(homeRand > guestRand){
                winningTeam(*this->home,*this->guest);
                return this->home;
            }
            else if(guestRand > homeRand){
                winningTeam(*this->guest,*this->home);
                return this->guest;
            }
            else{
                return GameMove();
            }  

        }
        

        void winningTeam(Team &win, Team &lose){
                win.teamStatus = true;
                win.winSpree_curr+=1;
                 win.loseSpree_curr = 0;
                 win.wins+=1;
                if ( win.winSpree_curr >  win.winSpree_max){
                     win.winSpree_max =  win.winSpree_curr;
                }
                lose.teamStatus =false;
                lose.loseSpree_curr+=1;
                lose.loses+=1;
                lose.winSpree_curr=0;
                if(lose.loseSpree_curr > lose.loseSpree_max){
                    lose.loseSpree_max = lose.loseSpree_curr;
                }
        }


        };
    }