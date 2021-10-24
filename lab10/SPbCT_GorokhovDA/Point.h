#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
	void Show() const;
	double x, y;
};

#endif POINT_H
