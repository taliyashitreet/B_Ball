#include "doctest.h"
#include "sources/Leauge.hpp"
using namespace ariel;
TEST_CASE("TEAM"){
    std::vector<Team*> allTeams;
    CHECK_THROWS(allTeams.push_back(new Team("",0)));
    CHECK_THROWS(allTeams.push_back(new Team("\r",0)));
    CHECK_THROWS(allTeams.push_back(new Team("\n",0)));
    CHECK_THROWS(allTeams.push_back(new Team("\t",0)));
    CHECK_THROWS(allTeams.push_back(new Team("\r",0)));
    CHECK_THROWS(allTeams.push_back(new Team(" ",0)));
    CHECK_NOTHROW(allTeams.push_back(new Team("NOY",0.9)));
    CHECK_NOTHROW(allTeams.push_back(new Team("TALIYA",0.1)));
    CHECK_NOTHROW(allTeams.push_back(new Team("TAL",0.2)));
    CHECK_NOTHROW(allTeams.push_back(new Team("ROEE",0.3)));
    CHECK_NOTHROW(allTeams.push_back(new Team("RONI",0.005)));
    CHECK_NOTHROW(allTeams.push_back(new Team("ROTEM",1)));
    CHECK_NOTHROW(allTeams.push_back(new Team("ADI",0.4)));
    CHECK_NOTHROW(allTeams.push_back(new Team("YOSSI",0.8)));
    CHECK_NOTHROW(allTeams.push_back(new Team("RACHEL",0.77)));
    CHECK_NOTHROW(allTeams.push_back(new Team("DANIEL",0.123456)));
    CHECK_THROWS(allTeams.push_back(new Team("YAEL",-1)));
    CHECK_THROWS(allTeams.push_back(new Team("LIHI",1.1)));

}
TEST_CASE("LEAUGE"){
    std::vector<Team*> allTeams;
    CHECK_NOTHROW(allTeams.push_back(new Team("NOY",0.9)));
    CHECK_NOTHROW(allTeams.push_back(new Team("TALIYA",0.1)));
    CHECK_NOTHROW(allTeams.push_back(new Team("TAL",0.2)));
    CHECK_NOTHROW(allTeams.push_back(new Team("ROEE",0.3)));
    CHECK_NOTHROW(allTeams.push_back(new Team("RONI",0.005)));
    CHECK_NOTHROW(allTeams.push_back(new Team("ROTEM",1)));
    CHECK_NOTHROW(allTeams.push_back(new Team("ADI",0.4)));
    CHECK_NOTHROW(allTeams.push_back(new Team("YOSSI",0.8)));
    CHECK_NOTHROW(allTeams.push_back(new Team("RACHEL",0.77)));
    CHECK_NOTHROW(allTeams.push_back(new Team("DANIEL",0.123456)));
    Leauge* l = new Leauge(allTeams);
  //  CHECK(l->_teams.size()==20);
    
}