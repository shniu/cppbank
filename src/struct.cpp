
#include "struct.hpp"

namespace struct_ns {

struct A {
    int num;
};

struct B {
    int num;
	char type;
	int age;
};


void test() {
    
	printf("struct_ns test \n");

    struct A a;
	a.num = 1;

	char* temp1 = (char *) (&(a.num));
	temp1 = temp1 + 4;
	*temp1 = 'a';

	int* temp2 = (int *) (&(a.num));
	temp2 = temp2 + 2;
	*temp2 = 100;

	struct B* b = (struct B*) (&a);

	// std::cout << b->num << std::endl;
	// std::cout << b->type << std::endl;
	// std::cout << b->age << std::endl;
	printf("%d:%c:%d\n", b->num, b->type, b->age);

}


} /// end struct_ns
