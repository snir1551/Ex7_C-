#include "Board.hpp"
#include <stdexcept>
namespace WarGame {
    

    Soldier*& Board::operator[](std::pair<int,int> location)
    {
        if(location.first > board.size() || location.first < 0 || location.second > board.size() || location.second < 0 )
        {
            throw std::invalid_argument("Illegal location");
        }
        // else if(board[location.first][location.second] != nullptr)
        // {
        //     throw std::invalid_argument("another soldier in location");
        // }
        return board[location.first][location.second];
    }

    Soldier* Board::operator[](std::pair<int,int> location) const
    {
        if(location.first > board.size() || location.first < 0 || location.second > board.size() || location.second < 0 )
        {
            throw std::invalid_argument("Illegal location");
        }
        else if(board[location.first][location.second] != nullptr)
        {
            throw std::invalid_argument("another soldier in location");
        }
        return board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
    {
        if(source.first > board.size() || source.first < 0 || source.second > board.size() || source.second < 0 )
        {
            throw std::invalid_argument("Illegal location");
        }
        if(board[source.first][source.second] == nullptr)
        {
            throw std::invalid_argument("in the source location not exist player to move");
        }
        if(board[source.first][source.second]->getNumPlayer() != player_number)
        {
            throw std::invalid_argument("already another player in the source location");
        }
        
        int targetRow, targetCol;
        switch(direction)
        {
            case MoveDIR::Up:
                targetRow = source.first + 1;
                targetCol = source.second;
                break;
            case MoveDIR::Down:
                targetRow = source.first - 1;
                targetCol = source.second;
                break;
            case MoveDIR::Right:
                targetRow = source.first;
                targetCol = source.second + 1;
                break;
            case MoveDIR::Left:
                targetRow = source.first;
                targetCol = source.second - 1;
                break;
        }
        if(targetRow > board.size() || targetRow < 0 || targetCol > board.size() || targetCol < 0 || board[targetRow][targetCol] != nullptr)
        {
            throw std::invalid_argument("exist player in the location target move");
        }
        board[targetRow][targetCol] = board[source.first][source.second];
        board[source.first][source.second] = nullptr;
    }

    bool Board::has_soldiers(uint player_number) const
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] != nullptr && board[i][j]->getNumPlayer() == player_number)
                {
                    return true;
                }
            }
        }
        return false;
    }

}