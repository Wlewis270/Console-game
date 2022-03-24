#pragma once
class Player
{
public:
	Player(int r, int c);
	int get_player_col();
	void set_player_col(int c);
	int get_player_row();
	void set_player_row(int r);
private:
	int col;
	int row;
	
};

