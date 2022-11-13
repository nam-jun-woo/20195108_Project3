#include<iostream>
#include<cstring>
using namespace std;

class Vector {
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}

	friend ostream& operator<<(ostream& os, Vector& v)

	{
		os << v.x<<" " << v.y<<" " << v.z;
		return os;
	}

	friend istream& operator>>(istream& is, Vector& v) {
	
		is >> v.x >> v.y >> v.z;
		return is;
	}
	Vector operator = (Vector& v) {
	
		x = v.x;
		y= v.y;
		z= v.z;
		return *this;
	}

};



int main() {
	
	Vector v0{ 1,2,3 };
	cout << v0 << endl;
	 
	Vector v1;
	cin >> v1;
	cout << v1 << endl;
	
	
	
}
