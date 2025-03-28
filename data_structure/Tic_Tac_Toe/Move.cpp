#include"Move.h"
Move::Move( )
/* Post: The Move is initialized to an illegal, default value. */
{
	row = 3;
	col = 3;
}

Move::Move(int r, int c)
/* Post: The Move is initialized to the given coordinates. */
{
	row = r;
	col = c;
}