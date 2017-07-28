#include "Global_functions.h"

int MovePosition(float *x, float *y, float x1, float y1, float v)
{
	float cosa = 0;
	float sina = 0;

	float c = (float)sqrt((*x - x1)*(*x - x1) + (*y - y1)*(*y - y1));

	cosa = (x1 - *x) / c;
	sina = (y1 - *y) / c;

	if (c < v)
	{
		*x = x1;
		*y = y1;
		return 0;
	}
	else
	{
		*x = *x + v * cosa;
		*y = *y + v * sina;
		return 1;
	}



}