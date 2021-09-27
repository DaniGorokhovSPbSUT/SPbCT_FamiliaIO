#pragma once

#include "Point.h"

class Triangle {
public:
	Triangle(Point _v1, Point _v2, Point _v3, const char* id);
	Triangle(const char*);
	~Triangle();
	Point Get_v1() const;
	Point Get_v2() const;
	Point Get_v3() const;
	char* GetName() const;
	void Show() const;
	void ShowSideAndArea() const;
	static int count;
private:
	char* objId;
	char* name;
	Point v1, v2, v3;
	double a, b, c;
};

