
#include <stdio.h>
#include <iostream>

struct A {
    int num;
};

struct B {
    int num;
	char type;
	int age;
};


int main(int argc, char** argv) {

    struct A a;
	a.num = 1;

	char* temp1 = (char *) &(a.num);
	temp1 = temp1 + 4;
	*temp1 = 'a';

	int* temp2 = (int *) &(a.num);
	temp2 = temp2 + 2;
	*temp2 = 100;

	struct B* b = (struct B*) (&a);

	// std::cout << b->num << std::endl;
	// std::cout << b->type << std::endl;
	// std::cout << b->age << std::endl;
	printf("%d:%c:%d\n", b->num, b->type, b->age);

	return 0;

}

