#ifndef _SNIPER_COMMANDER_HPP
#define _SNIPER_COMMANDER_HPP
#include "Soldier.hpp"
namespace WarGame {

    class SniperCommander:public Soldier
    {
        // private:
        //     int damage, health_points;
        public:
            SniperCommander(int numPlayer);
    };

}
#endif