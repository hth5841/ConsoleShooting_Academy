#include "include.h"
Enemy enemys[D_ENEMY_MAX];
void EnemyInit()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		enemys[i].x = 0;
		enemys[i].y = 0;
		enemys[i].isAlive = false;
	}
}
void EnemyUpdate()
{
	
	EnemyMove();
	EnemyClipping();
	EnemyBulletCollision();
}
void EnemyDraw()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive)
			DrawChar(enemys[i].x, enemys[i].y, '|', RED);
		
	}
}

void EnemyMove()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
		if (enemys[i].isAlive)
			enemys[i].y++;
}

void EnemyClipping()
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
		if (enemys[i].isAlive && enemys[i].y > 30)
			enemys[i].isAlive = false;
}

void CreateEnemy(int x, int y)
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive == false)
		{
			enemys[i].x = x;
			enemys[i].y = y;
			enemys[i].isAlive = true;
			break;
		}
	}
}

void EnemyBulletCollision()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullets[i].isAlive)
		{
			for (int j = 0; j < D_ENEMY_MAX; j++)
			{
				if (enemys[j].isAlive)
				{
					if (bullets[i].isAlive && bullets[i].x == enemys[j].x  && (bullets[i].y + 1 == enemys[j].y || bullets[i].y == enemys[i].y))
					{
						CreateEffect(enemys[j].x, enemys[j].y);
						bullets[i].isAlive = false;
						enemys[j].isAlive = false;
						break;
					}
				}
			}
		}
	}
}
