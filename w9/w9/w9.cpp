#include<iostream>
#include <algorithm>
#include<math.h>
using namespace std;

class Shape
{
public:
	virtual int get_vertex(Shape* p) { return -1; };
	virtual double get_peri(Shape* p) = 0;
	virtual double get_area(Shape* p) = 0;
};

class Rectangle :public Shape
{
public:
	Rectangle(int len, int wid) {
		length = len;
		width = wid;
	}
	Rectangle(int a, int b, int c, int d) {
		x1 = a; y1 = b; x2 = c; y2 = d;
		length = x2 - x1; width = y1 - y2;
	}
	int get_vertex(Shape* p) {
		return 4;
	}
	double get_peri(Shape* p) {//算周长
		double peri;
		peri = 2 * (length + width);
		return peri;
	}
	double get_area(Shape* p) {//面积
		double area;
		area = length * width;
		return area;
	}
	void set_len(int len) {
		length = len;
	}
	void set_wid(int wid) {
		width = wid;
	}//设置函数
	int check_overlap(const Rectangle& rec);
	void adjust(int tar_area);
private:
	double length;
	double width;
	double x1;
	double y1;
	double x2;
	double y2;
		
};
void Rectangle::adjust(int tar_area) {
	double n = sqrt(tar_area);
	for (length = 1; length < tar_area; length++) {
		for (width = 1; width < length; width++) {
			if (tar_area == length * width) {
				cout << x1 + length << ',' << y1 + width << endl;
				break;
			}
		}
	}
}
int Rectangle::check_overlap(const Rectangle& rec) {
	int lap_area;
	int x[5] = { x1,x2,rec.x1,rec.x2, };
	int y[5] = { y1,y2,rec.y1,rec.y2, };
	if (
		x2 > rec.x1 &&
		rec.x2 > x1 &&
		y2 < rec.y1 &&
		rec.y2 < y1
		) {
		sort(x, x + 4);
		sort(y, y + 4);
		lap_area = (x[2] - x[1])*(y[2] - y[1]);
		return lap_area;
	}
	else return -1;
}

class Circle:public Shape
{
public:
	int get_vertex(Shape* p) {
		return 0;
	}
	double get_peri(Shape* p) {//算周长
		double peri;
		peri = 6.28*radi;
		return peri;
	}
	double get_area(Shape* p) {//面积
		double area;
		area = 3.14*radi*radi;
		return area;
	}
	void set_rad(double rad) {
		radi = rad;
	}
private:
	double radi;
};
int main() {
	Rectangle rec(3,5);rec.set_len(3); rec.set_wid(5);
	Circle cir; cir.set_rad(3);
	int test1 = rec.get_vertex(&rec);
	cout << test1 << endl;//一个矩形的顶点数
	int test2 = cir.get_vertex(&rec);
	cout << test2 << endl;//一个圆的顶点数
	double rec_peri;
	rec_peri = rec.get_peri(&rec);
	cout << rec_peri << endl;//矩形周长;
	double rec_area;
	rec_area = rec.get_area(&rec);
	cout << rec_area << endl;//矩形面积
	int cir_peri;
	cir_peri = cir.get_peri(&cir);
	cout << cir_peri << endl;//圆周长
	int cir_area;
	cir_area = cir.get_area(&cir);
	cout << cir_area << endl;//圆面积
	/*--------------------------------------------------------------------------*/
	Rectangle rc1(0, 3, 3, 0);
	Rectangle rc2(1, 1, 4, 0);
	cout<<rc1.check_overlap(rc2);
}