#include"Board.h"
#include"iostream.h"
Board :: Board( )
/* Post: TheBoard is initialized as empty. */
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			squares[i][j] = 0;
	moves_done = 0;
}

void Board :: instructions( ) const
{
	cout<<"This is a Tic-Tac-Toe game. Wait for computer going..."<<endl;
}

void Board :: print( ) const
{
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			cout <<" "<< squares[i][j];
		cout<< " " <<endl;
	}
	cout<<endl;
}

void Board :: play(Move try_it)
/* Post: The Move try_it is played on theBoard . */
{
	squares[try_it.row][try_it.col] = moves_done%2 + 1;
	moves_done++;
}

int Board :: the_winner( ) const
/* Post: Return either a value of 0 for a position where neither player has won, a value
of 1 if the first player has won, or a value of 2 if the second player has won. */
{
	int i;
	for (i = 0; i < 3; i++)
		if (squares[i][0] &&squares[i][0] == squares[i][1] && squares[i][0] == squares[i][2])
			return squares[i][0];
	for (i = 0; i < 3; i++)
		if (squares[0][i] &&squares[0][i] == squares[1][i] && squares[0][i] == squares[2][i])
			return squares[0][i];
	if (squares[0][0] &&squares[0][0] == squares[1][1] && squares[0][0] == squares[2][2])
		return squares[0][0];
	if (squares[0][2] &&squares[0][2] == squares[1][1] && squares[2][0] == squares[0][2])
		return squares[0][2];
	return 0;
}

bool Board :: done( ) const
/* Post: Return true if the game is over; either because a player has already won or
because all nine squares have been filled. */
{
	return moves_done == 9 || the_winner( ) > 0;
}

int Board :: legal_moves(MyStack<Move>  &moves) const
/* Post: The parameterStack moves is set up to contain all possible legal moves on
theBoard . */
{
	int count = 0;
	while (!moves.empty( )) moves.pop( );
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (squares[i][j] == 0) {
				Move can_play(i, j);
				moves.push(can_play);
				count++;
			}
	return count;
}

int Board :: evaluate( ) const
/* Post: Return either a value of 0 for a position where neither player has won, a positive
value between 1 and 9 if the first player has won, or a negative value between
- 1 and - 9 if the second player has won, */
{
	int winner = the_winner( );
	if (winner == 1) return 10 - moves_done;  //for first player 1
	else if (winner == 2) return moves_done - 10;  //for second player 2
	else return 0;
}

bool Board :: better(int value, int old_value) const
{
    
	if(moves_done%2) return value<old_value;  // for second player 2
	else return value>old_value;  // for first player 1

}

int Board :: worst_case( ) const
{
	if(moves_done%2)return 1;  //for second player 2
	else return -1;  //for first player 1
}


