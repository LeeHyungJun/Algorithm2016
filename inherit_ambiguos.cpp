#include <iostream>
using namespace std;

class SuperA {
public:
	void super() {
		cout << "A" << endl;
	}
};
class SuperB {
public:
	void super() {
		cout << "B" << endl;
	}
};
class sub : SuperA, SuperB{
public:
	void prob(){
		super();
	}
};

int main() {
	sub s;
	s.prob();
	return 0;
}
