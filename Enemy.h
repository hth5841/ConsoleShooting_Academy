#pragma once
struct Enemy
{
	bool isAlive;
	int x;
	int y;
};

void EnemyInit();
void EnemyUpdate();
void EnemyDraw();

void EnemyMove();
void EnemyClipping();
void CreateEnemy(int x, int y);

void EnemyBulletCollision();