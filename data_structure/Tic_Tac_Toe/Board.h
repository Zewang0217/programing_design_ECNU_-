#include"Move.h"
#include"MyStack.cpp"
class Board {
public:
	Board( );
	bool done( ) const;
	void print( ) const;
	void instructions( ) const;
	bool better(int value, int old_value) const;
	void play(Move try_it);
	int worst_case( ) const;
	int evaluate( ) const;
	int legal_moves(MyStack<Move> &moves) const;
	int the_winner( ) const;
private:
	int squares[3][3];
	int moves_done;
};