#include "Enemy.h"

Enemy::Enemy(int r, int c)
{
    row = r;
    col = c;
}

int Enemy::get_enemy_col()
{
    return col;
}

void Enemy::set_enemy_col(int c)
{
    col = c;
}

int Enemy::get_enemy_row()
{
    return row;
}

void Enemy::set_enemy_row(int r)
{
    row = r;
}
