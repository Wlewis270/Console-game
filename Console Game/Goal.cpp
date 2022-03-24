#include "Goal.h"

Goal::Goal(int r, int c)
{
	row = r;
	col = c;
}

int Goal::get_goal_col()
{
	return col;
}

void Goal::set_goal_col(int c)
{
	col = c;
}

int Goal::get_goal_row()
{
	return row;
}

void Goal::set_goal_row(int r)
{
	row = r;
}
