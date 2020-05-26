#ifndef _FOOT_SNIPER_HPP
#define _FOOT_SNIPER_HPP
#include "Soldier.hpp"
namespace WarGame {

    class Sniper:public Soldier
    {
        // private:
        //     int damage, health_points;
        public:
            Sniper(int numPlayer);
    };

}
#endif