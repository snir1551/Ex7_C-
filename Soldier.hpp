#ifndef _SOLDIER_HPP
#define _SOLDIER_HPP

namespace WarGame {

    class Soldier
    {
        private:
            int _numPlayer;
            int _health;
            int _damage;

        public:
           Soldier(int numPlayer,int health, int damage);

           virtual ~Soldier()
           {

           }

           int getNumPlayer() const
           {
               return _numPlayer;
           }

           int getHealth() const
           {
               return _health;
           }

           int getDamage() const
           {
               return _damage;
           }

    };

}
#endif