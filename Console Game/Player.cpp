#include "Player.h"

Player::Player(int r, int c)
{
	row = r;
	col = c;
}

int Player::get_player_col()
{
	return col;
}

void Player::set_player_col(int c)
{
	col = c;
}

int Player::get_player_row()
{
	return row;
}

void Player::set_player_row(int r)
{
	row = r;
}
