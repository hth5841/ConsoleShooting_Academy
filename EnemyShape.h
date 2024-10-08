#pragma once

struct EnemyShape
{
	int x;
	int y;
	char body;
};

void EnemyShapeInit();
void EnemyShapeUpdate();
void EnemyShapeDraw();

void EnemyShapeMove();
void EnemyShapeClipping();