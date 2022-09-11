#include <iostream>
#include <ctime>
#include <stack>
using namespace std;

class Memento {
	int x, y, z;
	Memento(int x, int y, int z) :
			x { x }, y { y }, z { z } {
	}
	friend class Point3D;
};

class Point3D {
	int x, y, z;
	stack<Memento*> mementos;
public:
	Point3D() {
		x = -10 + (rand() % 21);
		y = -10 + (rand() % 21);
		z = -10 + (rand() % 21);
	}
	void makeMemento() {
		this->mementos.push(new Memento(this->x, this->y, this->z));
	}
	void shuffle() {
		x = -10 + (rand() % 21);
		y = -10 + (rand() % 21);
		z = -10 + (rand() % 21);
	}

	void reset() {
		this->x = this->mementos.top()->x;
		this->y = this->mementos.top()->y;
		this->z = this->mementos.top()->z;
		this->mementos.pop();
	}

	void show() {
		printf("(%3d, %3d, %3d  )\n", x, y, z);
	}
};

int main() {
	srand(time(0));
	Point3D point;
	point.makeMemento();
	point.show();
	point.shuffle();
	point.show();
	point.reset();
	point.show();
	return 0;
}
