#include "include.h"
/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area



*/

int RectangleArea(int A, int B, int C, int D)
{
	int length = C - A;
	int width = D - B;
	return length*width;
}
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int area1 = RectangleArea(A, B, C, D);
	int area2 = RectangleArea(E, F, G, H);
	int left = max(A, E);
	int right = min(C, G);
	int up = min(D, H);
	int down = max(B, F);
	int area3 = 0;
	if (left < right && down < up)
	{
		area3 = RectangleArea(left, down, right, up);
	}
	return area1 + area2 - area3;
}