#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;


class Person {
public:
	//객체안에 char* 사용하면 포인터때문에 꼬일 수 있다..
	//한시간 삽질 했다 이거땜에...
	//안꼬이게 하려면 new해주면되나? -> 안되네.
	string name;
	int korean;
	int english;
	int math;
	Person() {
		cout << "생성자" << endl;
	}
	Person(string name, int korean, int english, int math) {
		this->name = name;
		this->korean = korean;
		this->english = english;
		this->math = math;
	}
};
bool cmp(const Person& a, const Person& b) {
	if (a.korean > b.korean)
		return 1;
	else if (a.korean == b.korean)
		if (a.english < b.english)
			return 1;
		else if (a.english == b.english)
			if (a.math > b.math)
				return 1;
			else if (a.math == b.math)
				if (a.name < b.name)
					return 1;
				else
					return 0;
			else
				return 0;
		else
			return 0;
	else
		return 0;
}
int main(void) {
	int n;
	scanf("%d", &n);
	vector<Person> v;
	char name[100];
	int t1, t2, t3;

	for (int i = 0; i < n; i++) {
		scanf("%s %d %d %d",name, &t1, &t2, &t3);
		Person a(name, t1, t2, t3);
		v.push_back(a);
	}
	sort(v.begin(), v.end(),cmp);
	for (int i = 0; i < v.size(); i++) {
		//시간초과땜에.
		//c_str은 const char*를 리턴한다.
		string a = v[i].name;
		const char* b = a.c_str();
		printf("%s\n", b);
	}
	return 0;
}
