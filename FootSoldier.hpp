#ifndef _FOOT_SOLDIER_HPP
#define _FOOT_SOLDIER_HPP
#include "Soldier.hpp"
namespace WarGame {

    class FootSoldier:public Soldier
    {
        // private:
        //     int damage, health_points;
        public:
            FootSoldier(int numPlayer);
    };

}
#endif