#include <iostream>
#include <string>
#include <iomanip>

#include "Triangle.h"
#include "Point.h"

using namespace std;

Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* id) {
	char buf[16];

	objId = id;

	count++;

	sprintf_s(buf, "Треугольник %d", count);

	name = buf;

	a = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
	b = sqrt((v2.x - v3.x) * (v2.x - v3.x) + (v2.y - v3.y) * (v2.y - v3.y));
	c = sqrt((v1.x - v3.x) * (v1.x - v3.x) + (v1.y - v3.y) * (v1.y - v3.y));

	// Debug output.
	cout << "Constructor_1 for: " << objId << " (" << buf << ")" << endl;
}
Triangle::Triangle(const char* id) {
	char buf[16];

	objId = id;

	count++;

	sprintf_s(buf, "Треугольник %d", count);

	name = buf;

	a = b = c = 0;

	// Debug output.
	cout << "Constructor_2 for: " << objId << " (" << buf << ")" << endl;
}

Triangle::~Triangle() {
	cout << "Desctructor for: " << objId << endl;
}

// TODO explore const statement.
void Triangle::Show() const {
	cout << name << ":";

	v1.Show();
	v2.Show();
	v3.Show();

	cout << endl;
}

void Triangle::ShowSideAndArea() const {
	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));

	cout << name << ":";
	cout.precision(4);
	cout << "a = " << setw(5) << a;
	cout << "b = " << setw(5) << b;
	cout << "c = " << setw(5) << c;
}

