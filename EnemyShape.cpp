#include "include.h"
EnemyShape enemyshape;

void EnemyShapeInit()
{
	enemyshape.x = 60;
	enemyshape.y = 5;
	enemyshape.body = 'M'; 
}

void EnemyShapeUpdate()
{
	EnemyShapeMove();
	EnemyShapeClipping();
	CreateEnemy(enemyshape.x, enemyshape.y);
}

void EnemyShapeDraw()
{
	DrawChar(enemyshape.x, enemyshape.y, enemyshape.body, RED);
}

void EnemyShapeMove()
{
	int random[3] = {-1, 0,1 };
	enemyshape.x += random[rand() % 3 - 1];
}

void EnemyShapeClipping()
{

	if (enemyshape.x > 119)
		enemyshape.x = 119;

	if (enemyshape.x < 0)
		enemyshape.x = 0;

	if (enemyshape.y > 29)
		enemyshape.y = 29;

	if (enemyshape.y < 0)
		enemyshape.y = 0;
}
