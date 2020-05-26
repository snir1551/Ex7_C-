#include "Board.hpp"
#include "Soldier.hpp"
#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <typeinfo>

using namespace WarGame;
using namespace std;



Board fillFirstBoard()
{
        Board board(8,8);

        board[{0,0}] = new Sniper(1);
        board[{0,3}] = new FootSoldier(1);
        board[{0,4}] = new FootCommander(1);
        board[{0,6}] = new Paramedic(1);
        board[{0,7}] = new ParamedicCommander(1);

        board[{7,0}] = new Sniper(2);
        board[{7,3}] = new FootSoldier(2);
        board[{7,4}] = new FootCommander(2);
        board[{7,6}] = new Paramedic(2);
        board[{7,7}] = new ParamedicCommander(2);

        return board;

}

Board fillSecondBoard()
{
        Board board(8,8);

        board[{0,0}] = new Sniper(1);
        board[{0,7}] = new FootSoldier(1);


        board[{7,0}] = new FootCommander(2);
        board[{7,7}] = new FootSoldier(2);


        return board;

}

Board fillNull()
{
        Board board(10,10);

        return board;

}

Board myGame()
{

        //Create Board (8,8)
        Board board(8,8);
        // Add soldiers for player 1:
        CHECK(!board.has_soldiers(1));
		board[{0,1}] = new FootSoldier(1);
		board[{0,3}] = new Paramedic(1);
		CHECK(board.has_soldiers(1));

		// Add soldiers for player 2:
		CHECK(!board.has_soldiers(2));
		board[{7,1}] = new FootSoldier(2);
		board[{7,3}] = new FootCommander(2);
		CHECK(board.has_soldiers(2));

        return board;

}
uint play()
{
        Board board = myGame();
        /*
            FootSoldier(1) 100 HP and 10 dmg
            Paramedic(1) 100 HP and 0 dmg

            FootSoldier(2) 100 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
        board.move(1, {0,1}, Board::MoveDIR::Right);      // FootSoldier of player 1 moves forward and attacks from {0,1} to {0,2}.
		if (!board.has_soldiers(2)) return 1;
        /*
            FootSoldier(1) 100 HP and 10 dmg
            Paramedic(1) 100 HP and 0 dmg

            FootSoldier(2) 90 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
		board.move(2, {7,1}, Board::MoveDIR::Down);    // FootSoldier of player 2 moves forward and attacks from {7,1} to {6,1}.
		if (!board.has_soldiers(1)) return 2;
        /*
            FootSoldier(1) 90 HP and 10 dmg
            Paramedic(1) 100 HP and 0 dmg

            FootSoldier(2) 90 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
		board.move(1, {0,3}, Board::MoveDIR::Up);      // Paramedic of player 1 moves forward from {0,3} to {1,3}, and all soldiers of player 1 attack.
		if (!board.has_soldiers(2)) return 1;
        /*
            FootSoldier(1) 100 HP and 10 dmg
            Paramedic(1) 100 HP and 0 dmg

            FootSoldier(2) 90 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
		board.move(2, {7,3}, Board::MoveDIR::Left);    // FootCommander of player 2 moves left from {7,3} to {7,2}, and all soldiers of player 2 attack.
		if (!board.has_soldiers(1)) return 2;
        /*
            FootSoldier(1) 100 HP and 10 dmg
            Paramedic(1) 100 HP and 0 dmg

            FootSoldier(2) 90 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
       	board.move(1, {0,2}, Board::MoveDIR::Right);    // FootSoldier of player 1 moves right from {0,2} to {0,3}, and all soldiers of player 2 attack.
		if (!board.has_soldiers(2)) return 2;
        /*
            FootSoldier(1) 90 HP and 10 dmg
            Paramedic(1) 80 HP and 0 dmg

            FootSoldier(2) 90 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
        board.move(1, {0,3}, Board::MoveDIR::Right);    // FootSoldier of player 1 moves right from {0,3} to {0,4}, and all soldiers of player 2 attack.
		if (!board.has_soldiers(2)) return 2;
        /*
            FootSoldier(1) 90 HP and 10 dmg
            Paramedic(1) 80 HP and 0 dmg

            FootSoldier(2) 80 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
        board.move(1, {0,4}, Board::MoveDIR::Up);    // FootSoldier of player 1 moves right from {0,4} to {1,4}, and all soldiers of player 2 attack.
		if (!board.has_soldiers(2)) return 2;
        /*
            FootSoldier(1) 90 HP and 10 dmg
            Paramedic(1) 80 HP and 0 dmg

            FootSoldier(2) 70 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
        board.move(2, {7,2}, Board::MoveDIR::Down);    //  FootCommander of player 2 moves left from {7,2} to {6,2}, and all soldiers of player 2 attack.
		if (!board.has_soldiers(1)) return 2;
        /*
            FootSoldier(1) 80 HP and 10 dmg
            Paramedic(1) 60 HP and 0 dmg

            FootSoldier(2) 70 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
        board.move(2, {6,2}, Board::MoveDIR::Down);    //  FootCommander of player 2 moves left from {6,2} to {5,2}, and all soldiers of player 2 attack.
		if (!board.has_soldiers(1)) return 2;
        /*
            FootSoldier(1) 70 HP and 10 dmg
            Paramedic(1) 40 HP and 0 dmg

            FootSoldier(2) 70 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
        board.move(2, {5,2}, Board::MoveDIR::Down);    //  FootCommander of player 2 moves left from {5,2} to {4,2}, and all soldiers of player 2 attack.
		if (!board.has_soldiers(1)) return 2;
        /*
            FootSoldier(1) 60 HP and 10 dmg
            Paramedic(1) 20 HP and 0 dmg

            FootSoldier(2) 70 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
        board.move(2, {4,2}, Board::MoveDIR::Down);    //  FootCommander of player 2 moves left from {4,2} to {3,2}, and all soldiers of player 2 attack.
		if (!board.has_soldiers(1)) return 2;
        /*
            FootSoldier(1) 50 HP and 10 dmg
            Paramedic(1) 0 HP and 0 dmg

            FootSoldier(2) 70 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
        board.move(2, {3,2}, Board::MoveDIR::Down);    //  FootCommander of player 2 moves left from {3,2} to {2,2}, and all soldiers of player 2 attack.
		if (!board.has_soldiers(1)) return 2;
        /*
            FootSoldier(1) 20 HP and 10 dmg
            Paramedic(1) 0 HP and 0 dmg

            FootSoldier(2) 70 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
        board.move(2, {2,2}, Board::MoveDIR::Down);    //  FootCommander of player 2 moves left from {2,2} to {1,2}, and all soldiers of player 2 attack.
		if (!board.has_soldiers(1)) return 2;
        /*
            FootSoldier(1) 0 HP and 10 dmg
            Paramedic(1) 0 HP and 0 dmg

            FootSoldier(2) 70 HP and 10dmg
            FootCommander(2) 150 HP and 20 dmg
        */
       return 0;
}


TEST_CASE("Board Test")
{
    

    SUBCASE("operator for putting soldiers on the game-board during initialization(operator[])")
    {
            Board board1 = fillFirstBoard();

            CHECK(board1[{0,1}] == nullptr);
            CHECK(board1[{0,2}] == nullptr);
            CHECK(board1[{0,5}] == nullptr);
            CHECK(board1[{1,0}] == nullptr);
            CHECK(board1[{1,1}] == nullptr);
            CHECK(board1[{1,2}] == nullptr);
            CHECK(board1[{1,3}] == nullptr);
            CHECK(board1[{1,4}] == nullptr);
            CHECK(board1[{1,5}] == nullptr);
            CHECK(board1[{1,6}] == nullptr);
            CHECK(board1[{1,7}] == nullptr);
            CHECK(board1[{2,0}] == nullptr);
            CHECK(board1[{2,1}] == nullptr);
            CHECK(board1[{2,2}] == nullptr);
            CHECK(board1[{2,3}] == nullptr);
            CHECK(board1[{2,4}] == nullptr);
            CHECK(board1[{2,5}] == nullptr);
            CHECK(board1[{2,6}] == nullptr);
            CHECK(board1[{2,7}] == nullptr);
            CHECK(board1[{3,0}] == nullptr);
            CHECK(board1[{3,1}] == nullptr);
            CHECK(board1[{3,2}] == nullptr);
            CHECK(board1[{3,3}] == nullptr);
            CHECK(board1[{3,4}] == nullptr);
            CHECK(board1[{3,5}] == nullptr);
            CHECK(board1[{3,6}] == nullptr);
            CHECK(board1[{3,7}] == nullptr);
            CHECK(board1[{4,0}] == nullptr);
            CHECK(board1[{4,1}] == nullptr);
            CHECK(board1[{4,2}] == nullptr);
            CHECK(board1[{4,3}] == nullptr);
            CHECK(board1[{4,4}] == nullptr);
            CHECK(board1[{4,5}] == nullptr);
            CHECK(board1[{4,6}] == nullptr);
            CHECK(board1[{4,7}] == nullptr);
            CHECK(board1[{5,0}] == nullptr);
            CHECK(board1[{5,1}] == nullptr);
            CHECK(board1[{5,2}] == nullptr);
            CHECK(board1[{5,3}] == nullptr);
            CHECK(board1[{5,4}] == nullptr);
            CHECK(board1[{5,5}] == nullptr);
            CHECK(board1[{5,6}] == nullptr);
            CHECK(board1[{5,7}] == nullptr);
            CHECK(board1[{6,0}] == nullptr);
            CHECK(board1[{6,1}] == nullptr);
            CHECK(board1[{6,2}] == nullptr);
            CHECK(board1[{6,3}] == nullptr);
            CHECK(board1[{6,4}] == nullptr);
            CHECK(board1[{6,5}] == nullptr);
            CHECK(board1[{6,6}] == nullptr);
            CHECK(board1[{6,7}] == nullptr);
            CHECK(board1[{7,1}] == nullptr);
            CHECK(board1[{7,2}] == nullptr);
            CHECK(board1[{7,5}] == nullptr);



            //player 1
            CHECK(dynamic_cast<Sniper*>(board1[{0,0}]));
            CHECK(dynamic_cast<FootSoldier*>(board1[{0,3}]));
            CHECK(dynamic_cast<FootCommander*>(board1[{0,4}]));
            CHECK(dynamic_cast<Paramedic*>(board1[{0,6}]));
            CHECK(dynamic_cast<ParamedicCommander*>(board1[{0,7}]));

            //player 2
            CHECK(dynamic_cast<Sniper*>(board1[{7,0}]));
            CHECK(dynamic_cast<FootSoldier*>(board1[{7,3}]));
            CHECK(dynamic_cast<FootCommander*>(board1[{7,4}]));
            CHECK(dynamic_cast<Paramedic*>(board1[{7,6}]));
            CHECK(dynamic_cast<ParamedicCommander*>(board1[{7,7}]));

            //-----------------------------------------------//

            Board board2 = fillSecondBoard();

            CHECK(board2[{0,1}] == nullptr);
            CHECK(board2[{0,2}] == nullptr);
            CHECK(board2[{0,3}] == nullptr);
            CHECK(board2[{0,4}] == nullptr);
            CHECK(board2[{0,5}] == nullptr);
            CHECK(board2[{0,6}] == nullptr);
            CHECK(board2[{0,2}] == nullptr);
            CHECK(board2[{0,5}] == nullptr);
            CHECK(board2[{1,0}] == nullptr);
            CHECK(board2[{1,1}] == nullptr);
            CHECK(board2[{1,2}] == nullptr);
            CHECK(board2[{1,3}] == nullptr);
            CHECK(board2[{1,4}] == nullptr);
            CHECK(board2[{1,5}] == nullptr);
            CHECK(board2[{1,6}] == nullptr);
            CHECK(board2[{1,7}] == nullptr);
            CHECK(board2[{2,0}] == nullptr);
            CHECK(board2[{2,1}] == nullptr);
            CHECK(board2[{2,2}] == nullptr);
            CHECK(board2[{2,3}] == nullptr);
            CHECK(board2[{2,4}] == nullptr);
            CHECK(board2[{2,5}] == nullptr);
            CHECK(board2[{2,6}] == nullptr);
            CHECK(board2[{2,7}] == nullptr);
            CHECK(board2[{3,0}] == nullptr);
            CHECK(board2[{3,1}] == nullptr);
            CHECK(board2[{3,2}] == nullptr);
            CHECK(board2[{3,3}] == nullptr);
            CHECK(board2[{3,4}] == nullptr);
            CHECK(board2[{3,5}] == nullptr);
            CHECK(board2[{3,6}] == nullptr);
            CHECK(board2[{3,7}] == nullptr);
            CHECK(board2[{4,0}] == nullptr);
            CHECK(board2[{4,1}] == nullptr);
            CHECK(board2[{4,2}] == nullptr);
            CHECK(board2[{4,3}] == nullptr);
            CHECK(board2[{4,4}] == nullptr);
            CHECK(board2[{4,5}] == nullptr);
            CHECK(board2[{4,6}] == nullptr);
            CHECK(board2[{4,7}] == nullptr);
            CHECK(board2[{5,0}] == nullptr);
            CHECK(board2[{5,1}] == nullptr);
            CHECK(board2[{5,2}] == nullptr);
            CHECK(board2[{5,3}] == nullptr);
            CHECK(board2[{5,4}] == nullptr);
            CHECK(board2[{5,5}] == nullptr);
            CHECK(board2[{5,6}] == nullptr);
            CHECK(board2[{5,7}] == nullptr);
            CHECK(board2[{6,0}] == nullptr);
            CHECK(board2[{6,1}] == nullptr);
            CHECK(board2[{6,2}] == nullptr);
            CHECK(board2[{6,3}] == nullptr);
            CHECK(board2[{6,4}] == nullptr);
            CHECK(board2[{6,5}] == nullptr);
            CHECK(board2[{6,6}] == nullptr);
            CHECK(board2[{6,7}] == nullptr);
            CHECK(board2[{7,1}] == nullptr);
            CHECK(board2[{7,2}] == nullptr);
            CHECK(board2[{7,5}] == nullptr);
            CHECK(board2[{7,2}] == nullptr);
            CHECK(board2[{7,3}] == nullptr);
            CHECK(board2[{7,4}] == nullptr);
            CHECK(board2[{7,5}] == nullptr);
            CHECK(board2[{7,6}] == nullptr);

            //player 1
            CHECK(dynamic_cast<Sniper*>(board2[{0,0}]));
            CHECK(dynamic_cast<FootSoldier*>(board2[{0,7}]));

            //player 2
            CHECK(dynamic_cast<FootCommander*>(board2[{7,0}]));
            CHECK(dynamic_cast<FootSoldier*>(board2[{7,7}]));


    }

    SUBCASE("Check Move")
    {
        /* start game

            Sniper 100 HP and 50 dmg
            FootSoldier 100 HP and 10 dmg

            FootCommander 150 HP and 20 dmg
            FootSoldier 100 HP and 10 dmg
        */
        Board board1 = fillSecondBoard();
        CHECK(board1.has_soldiers(1));
        CHECK(board1.has_soldiers(2));
        board1.move(1, {0,0}, Board::MoveDIR::Up); //Sniper 50 dmg to FootCommander
        /*
            Sniper 100 HP and 50 dmg
            FootSoldier 100 HP and 10 dmg

            FootCommander 100 HP and 20 dmg
            FootSoldier 100 HP and 10 dmg
        */
        board1.move(2, {7,7}, Board::MoveDIR::Down); //FootSoldier 10 dmg to FootSoldier
        /*
            Sniper 100 HP and 50 dmg
            FootSoldier 90 HP and 10 dmg

            FootCommander 100 HP and 20 dmg
            FootSoldier 100 HP and 10 dmg
        */
        board1.move(1, {6,7}, Board::MoveDIR::Down); //Sniper 50 dmg to FootCommander
        /*
            Sniper 100 HP and 50 dmg
            FootSoldier 90 HP and 10 dmg

            FootCommander 50 HP and 20 dmg
            FootSoldier 100 HP and 10 dmg
        */
        board1.move(2, {7,0}, Board::MoveDIR::Down); //FootCommander 20 dmg to Sniper and 10 dmg to FootSoldier
        /*
            Sniper 80 HP and 50 dmg
            FootSoldier 80 HP and 10 dmg

            FootCommander 50 HP and 20 dmg
            FootSoldier 100 HP and 10 dmg
        */
        board1.move(2, {0,7}, Board::MoveDIR::Down); //FootSoldier 10 dmg to FootSoldier
        /*
            Sniper 80 HP and 50 dmg
            FootSoldier 70 HP and 10 dmg

            FootCommander 50 HP and 20 dmg
            FootSoldier 100 HP and 10 dmg
        */
        board1.move(1, {5,0}, Board::MoveDIR::Up); //Sniper 50 dmg to FootSoldier
        /*
            Sniper 80 HP and 50 dmg
            FootSoldier 70 HP and 10 dmg

            FootCommander 50 HP and 20 dmg
            FootSoldier 50 HP and 10 dmg
        */
        board1.move(1, {5,1}, Board::MoveDIR::Right); //Sniper 50 dmg to FootCommander
        /*
            Sniper 80 HP and 50 dmg
            FootSoldier 70 HP and 10 dmg

            FootCommander died
            FootSoldier 50 HP and 10 dmg
        */
       CHECK(board1[{6,0}] == nullptr);
       CHECK(board1.has_soldiers(2));
        board1.move(1, {5,2}, Board::MoveDIR::Right); //Sniper 50 dmg to FootSoldier
        /*
            Sniper 80 HP and 50 dmg
            FootSoldier 70 HP and 10 dmg

            FootCommander died
            FootSoldier died
        */
       CHECK(board1[{6,7}] == nullptr);
       CHECK(board1.has_soldiers(1));
       CHECK(!board1.has_soldiers(2));


    }

    SUBCASE("Check exist player")
    {
        Board board1 = fillNull();

        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                CHECK(board1[{i,j}] == nullptr);
            }
        }

        CHECK(!board1.has_soldiers(1));
        CHECK(!board1.has_soldiers(2));

        board1[{0,0}] = new FootSoldier(1);
        board1[{0,3}] = new FootSoldier(1);
        board1[{0,4}] = new FootCommander(1);
        board1[{0,6}] = new Paramedic(1);
        board1[{0,7}] = new FootCommander(1);

        CHECK(board1.has_soldiers(1));
        CHECK(!board1.has_soldiers(2));

        board1[{9,0}] = new Sniper(2);
        board1[{9,3}] = new FootSoldier(2);
        board1[{9,4}] = new FootCommander(2);
        board1[{9,6}] = new Paramedic(2);
        board1[{9,7}] = new ParamedicCommander(2);

        CHECK(board1.has_soldiers(1));
        CHECK(board1.has_soldiers(2));

        CHECK(board1[{0,1}] == nullptr);
        CHECK(board1[{0,2}] == nullptr);
        CHECK(board1[{0,5}] == nullptr);
        CHECK(board1[{1,0}] == nullptr);
        CHECK(board1[{1,1}] == nullptr);
        CHECK(board1[{1,2}] == nullptr);
        CHECK(board1[{1,3}] == nullptr);
        CHECK(board1[{1,4}] == nullptr);
        CHECK(board1[{1,5}] == nullptr);
        CHECK(board1[{1,6}] == nullptr);
        CHECK(board1[{1,7}] == nullptr);
        CHECK(board1[{2,0}] == nullptr);
        CHECK(board1[{2,1}] == nullptr);
        CHECK(board1[{2,2}] == nullptr);
        CHECK(board1[{2,3}] == nullptr);
        CHECK(board1[{2,4}] == nullptr);
        CHECK(board1[{2,5}] == nullptr);
        CHECK(board1[{2,6}] == nullptr);
        CHECK(board1[{2,7}] == nullptr);
        CHECK(board1[{3,0}] == nullptr);
        CHECK(board1[{3,1}] == nullptr);
        CHECK(board1[{3,2}] == nullptr);
        CHECK(board1[{3,3}] == nullptr);
        CHECK(board1[{3,4}] == nullptr);
        CHECK(board1[{3,5}] == nullptr);
        CHECK(board1[{3,6}] == nullptr);
        CHECK(board1[{3,7}] == nullptr);
        CHECK(board1[{4,0}] == nullptr);
        CHECK(board1[{4,1}] == nullptr);
        CHECK(board1[{4,2}] == nullptr);
        CHECK(board1[{4,3}] == nullptr);
        CHECK(board1[{4,4}] == nullptr);
        CHECK(board1[{4,5}] == nullptr);
        CHECK(board1[{4,6}] == nullptr);
        CHECK(board1[{4,7}] == nullptr);
        CHECK(board1[{5,0}] == nullptr);
        CHECK(board1[{5,1}] == nullptr);
        CHECK(board1[{5,2}] == nullptr);
        CHECK(board1[{5,3}] == nullptr);
        CHECK(board1[{5,4}] == nullptr);
        CHECK(board1[{5,5}] == nullptr);
        CHECK(board1[{5,6}] == nullptr);
        CHECK(board1[{5,7}] == nullptr);
        CHECK(board1[{6,0}] == nullptr);
        CHECK(board1[{6,1}] == nullptr);
        CHECK(board1[{6,2}] == nullptr);
        CHECK(board1[{6,3}] == nullptr);
        CHECK(board1[{6,4}] == nullptr);
        CHECK(board1[{6,5}] == nullptr);
        CHECK(board1[{6,6}] == nullptr);
        CHECK(board1[{6,7}] == nullptr);
        CHECK(board1[{7,1}] == nullptr);
        CHECK(board1[{7,2}] == nullptr);
        CHECK(board1[{7,5}] == nullptr);
        CHECK(board1[{7,2}] == nullptr);
        CHECK(board1[{7,3}] == nullptr);
        CHECK(board1[{7,4}] == nullptr);
        CHECK(board1[{7,5}] == nullptr);
        CHECK(board1[{7,6}] == nullptr);
        CHECK(board1[{8,0}] == nullptr);
        CHECK(board1[{8,1}] == nullptr);
        CHECK(board1[{8,2}] == nullptr);
        CHECK(board1[{8,3}] == nullptr);
        CHECK(board1[{8,4}] == nullptr);
        CHECK(board1[{8,5}] == nullptr);
        CHECK(board1[{8,6}] == nullptr);
        CHECK(board1[{8,7}] == nullptr);
        CHECK(board1[{9,1}] == nullptr);
        CHECK(board1[{9,2}] == nullptr);
        CHECK(board1[{9,5}] == nullptr);

        CHECK(board1.has_soldiers(1));
        CHECK(board1.has_soldiers(2));




    }
}
TEST_CASE("MyGame")
{
        uint theWinner = play();
        CHECK(theWinner == 2);
}
