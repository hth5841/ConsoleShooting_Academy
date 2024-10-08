#include "include.h"
#include "Effect.h"

Effect effect[D_EFFECT_MAX];

char effectShape[3][3][3] =
{
	{
		{' ',' ',' '},
		{' ','*',' '},
		{' ',' ',' '}
	},
	{
		{' ','*',' '},
		{'*','*','*'},
		{' ','*',' '}
	},
	{
		{'*',' ','*'},
		{' ','*',' '},
		{'*',' ','*'}
	}
};

void EffectInit()
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		effect[i].index = 0;
		effect[i].indexUpdateTime = 0;
		effect[i].x = 0;
		effect[i].y = 0;
		effect[i].isAlive = false;
	}
}

void EffectDraw()
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (effect[i].isAlive == true)
		{

			DrawChar(effect[i].x - 1, effect[i].y - 1, effectShape[effect[i].index][0][0], BLUE);
			DrawChar(effect[i].x, effect[i].y - 1, effectShape[effect[i].index][0][1], BLUE);
			DrawChar(effect[i].x + 1, effect[i].y - 1, effectShape[effect[i].index][0][2], BLUE);

			DrawChar(effect[i].x - 1, effect[i].y, effectShape[effect[i].index][1][0], BLUE);
			DrawChar(effect[i].x, effect[i].y, effectShape[effect[i].index][1][1], BLUE);
			DrawChar(effect[i].x + 1, effect[i].y, effectShape[effect[i].index][1][2], BLUE);

			DrawChar(effect[i].x - 1, effect[i].y + 1, effectShape[effect[i].index][2][0], BLUE);
			DrawChar(effect[i].x, effect[i].y + 1, effectShape[effect[i].index][2][1], BLUE);
			DrawChar(effect[i].x + 1, effect[i].y + 1, effectShape[effect[i].index][2][2], BLUE);

		}
	}
}

void EffectUpdate()
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (effect[i].isAlive && effect[i].indexUpdateTime < GetTickCount())
		{
			effect[i].indexUpdateTime = GetTickCount() + 300;
			effect[i].index++;
			if (effect[i].index >= 3)
			{
				effect[i].isAlive = false;
			}

		}
	}
}

void CreateEffect(int x, int y)
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (effect[i].isAlive == false)
		{
			effect[i].isAlive = true;
			effect[i].x = x;
			effect[i].y = y;
			effect[i].index = 0;
			effect[i].indexUpdateTime = GetTickCount() + 300;
			break;
		}
	}
}
