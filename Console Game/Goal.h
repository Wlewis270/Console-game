#pragma once
class Goal
{
public:
	Goal(int r, int c);
	int get_goal_col();
	void set_goal_col(int c);
	int get_goal_row();
	void set_goal_row(int r);
private:
	int col;
	int row;

};

