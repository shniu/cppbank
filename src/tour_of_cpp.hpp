

#include <iostream>

class Vector {

public:
    Vector(int s):elem{ new double[s] },sz{s} {}

	int size() {
		return sz;
	}

	double& operator[](int i) {
		return elem[i];
	}

private:

    int sz;
	double * elem;

};


enum class Color {
    red, blue, green
};

enum Traffic {
    red, blue, green
};



