#include<iostream>
#include<cstring>

using namespace std;

class Vector {
private:
	float x, y, z;
	char* _chars;
public:
	Vector() {}
	
	/*Vector(float x, float y, float z)
		:x{ x }, y{ y }, z{ z } {}
		*/

	Vector(float x, float y, float z,const char *chars)
		:x{ x }, y{ y }, z{ z }, _chars{ new char[strlen(chars)+1]} {
	
		strcpy_s(_chars, strlen(chars) + 1, chars);

	}


	Vector(Vector& v) 
		:Vector(v.x,v.y,v.z,v._chars)
	{
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
		cout << "copy" << endl;
	
	}


	~Vector() {
		delete[]_chars;
	}

	Vector& operator = (Vector& v) {

		x = v.x;
		y = v.y;
		z = v.z;
		
	
		delete[] _chars;
		_chars = new char[strlen(v._chars) + 1];
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
		return *this;

	}

	friend ostream& operator<<(ostream& os, Vector& v)

	{
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}

};







int main() {

	Vector v00{ 1,2,3,"abc"};
	Vector v01 = v00;
	Vector v02;
	v02 = v00;

	cout << v00 << endl;
	cout << v01 << endl;
	cout << v02 << endl;



}