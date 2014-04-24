#ifndef _POINT_H
#define _POINT_H
class Point{
public:
	int x;
	int y;
	static Point Lerp(Point from, Point to, float t);
};

class PointF{
public:
	float x;
	float y;
	static PointF Lerp(PointF from, PointF to, float t);
};
#endif