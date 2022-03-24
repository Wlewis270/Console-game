#pragma once
class Enemy
{
public:
	Enemy(int r, int c);
	int get_enemy_col();
	void set_enemy_col(int c);
	int get_enemy_row();
	void set_enemy_row(int r);
private:
	int col;
	int row;
};

