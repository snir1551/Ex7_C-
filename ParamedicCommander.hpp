#ifndef _PARAMEDIC_COMMANDER_HPP
#define _PARAMEDIC_COMMANDER_HPP
#include "Soldier.hpp"
namespace WarGame {

    class ParamedicCommander:public Soldier
    {
        // private:
        //     int damage, health_points;
        public:
            ParamedicCommander(int numPlayer);
    };

}
#endif