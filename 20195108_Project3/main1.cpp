#include<iostream>
using namespace std;

class Vector {
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}
	
	Vector operator+(Vector v) const {
		return Vector{ x + v.x,y + v.y,z + v.z };

	}

	Vector operator-(Vector v) const {
		return Vector{ x - v.x,y - v.y,z - v.z };

	}


	void print(){
		cout << x << " " << y << " " << z << endl;

	}
	Vector operator-() {
		return Vector(-x, -y, -z);
	}
	Vector operator+() {
		return Vector(+x, +y, +z);
	}



	float operator*(const Vector& v)const {
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}
	Vector operator*(float n) {
		return Vector{ x * n,y * n,z * n };
	
	}

	Vector operator/(float n) {
		return Vector{ x / n,y / n,z / n };

	}


	Vector& operator++() {
		++x;
		++y;
		++z;
		return *this;
	
	}

	Vector& operator++(int) {
	
		Vector temp = *this;
		++x;
		++y;
		++z;
		return temp;

	}
	

};	


int main() {
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };
	Vector v2 = v0 + v1; // 이항연산자 +
	v2.print();
	Vector v3 = -v1; // 단항 연산자 -
	v3.print();
	
	float v4 = v0 * v1;
	cout << v4 << endl;

	Vector v5 = v1 * 3.0f; // 이항연산자 *
	v5.print();
	Vector v6 =++v1; // 전위 연산자 ++
	v6.print();
	Vector v7 =v1++; //// 후위 연산자 ++
	v7.print();
	v1.print();

	Vector v8 = v1 - v0; // // 이항연산자 -
	v8.print();
	Vector v9 =v1 / 3.0f; // 이항연산자 /
	v9.print();
	
	Vector v10 = +v1; // 단항 연산자 +
	v10.print();



}