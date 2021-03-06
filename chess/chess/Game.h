#ifndef GAME_H
#define GAME_H

#include <stack>

#include "Piece.h"
#include "GameP.h"
#include "Board.h"
#include "GameS.h"
#include "Move.h"

class Game
{
	
	public:
		Game();
		void setInitialPieces(PieceColor color);
		std::stack<Move> getAllLog();
		Board* getBoard();
		GameStatus* getGameStatus();
		std::vector<Move> getValidMoves(int fromRow, int fromCol);
		bool move(int fromRow, int fromCol, int toRow, int toCol);
		PieceColor getPieceColor(int fromRow, int fromCol);
		Piece* getPiece(int fromRow, int fromCol);
		bool isSquareOccupied(int fromRow, int fromCol);
		bool inCheckState();
		bool inCheckMateState();
		int getTurn();
		void nextTurn();
		PieceColor getTurnColor();
		bool promote(int row, int col, PieceType type);
	private:
		std::stack<Move> m_log;
		Gameplay* m_gameplay;
		Board* m_board;
		GameStatus* m_status;
		int m_turn;
};

#endif
