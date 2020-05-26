#ifndef _FOOT_COMMANDER_HPP
#define _FOOT_COMMANDER_HPP
#include "Soldier.hpp"
namespace WarGame {

    class FootCommander:public Soldier
    {
        // private:
        //     int damage, health_points;
        public:
            FootCommander(int numPlayer);
    };

}
#endif