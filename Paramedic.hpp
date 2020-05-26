#ifndef _PARAMEDIC_HPP
#define _PARAMEDIC_HPP
#include "Soldier.hpp"
namespace WarGame {

    class Paramedic:public Soldier
    {
        // private:
        //     int damage, health_points;
        public:
            Paramedic(int numPlayer);
    };

}
#endif