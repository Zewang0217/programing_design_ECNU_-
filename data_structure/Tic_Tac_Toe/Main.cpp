#include"iostream.h"

#include"Board.h"

int look_ahead(const Board &game, int depth, Move &recommended)

/* Pre: Board game represents a legal game position.

Post: An evaluation of the game , based on looking ahead depth moves, is returned.

The best move that can be found for the mover is recorded as Move

recommended .

Uses: The classes Stack ,Board , and Move , together with function look_ahead

recursively. */

{

	if (game.done( ) || depth == 0)

		return game.evaluate( );

	else {

		MyStack<Move> moves;

		game.legal_moves(moves);

		int value, best_value = game.worst_case( );

		while (!moves.empty( )) {

			Move try_it, reply;

			moves.top(try_it);

			Board new_game = game;

			new_game.play(try_it);

			value = look_ahead(new_game, depth - 1, reply);

			if (game.better(value, best_value)) {

				// try_it is the best move yet found

				// to first, the value(10-moves_done  +) better when it is bigger

				// to second, the value(moves_done-10  -) better when it is smaller

				best_value = value;

				recommended = try_it;

			}

			moves.pop( );

		}

		return best_value;

	}

}



void main(){

	Board game;

	Move recommended;

	int x,y;

	int i=9;

	game.instructions();

	while(!game.done()){
		
		 //for man

		cout<<"Your turn:"<<endl;

		cout<<"X:";

		cin>>x;

		cout<<"Y:";

		cin>>y;

        Move me(x,y);

		game.play(me);

		game.print();
	    
		if(game.done()) break;

		
		//for computer1
		look_ahead(game, i-1, recommended);

		game.play(recommended);

		cout<<"Computer1:"<<endl;

		game.print();

		
		//for computer2

		//look_ahead(game, i, recommended);

		//game.play(recommended);

		//cout<<"Computer2:"<<endl;

		//game.print();


       
		i--;

	}

	if(game.the_winner()==2) cout<<"Game over with computer win."<<endl;

	else if (game.the_winner()==1) cout<<"Game over with you win."<<endl;//impossible when i=9

    else cout<<"Game over with a draw."<<endl;//only when you go (1,1) at first step.

}