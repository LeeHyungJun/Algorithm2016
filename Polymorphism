#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
	char name[100];
public:
	Employee(char* name){
		strcpy(this->name, name);
	}
	void ShowYourName() {
		cout << "name: " << name << endl;
	}
	//void virtual ShowSalaryInfo() {}
	//int virtual GetPay() {}
	void virtual ShowSalaryInfo() const = 0 {}
	int virtual GetPay() const = 0 {}
};

class Temporary : public Employee {
private:
	int workTime;
	int payPerHour;
public:
	Temporary(char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay) {}
	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() {
		return workTime*payPerHour;
	}
	void ShowSalaryInfo() {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class Permanent : public Employee {
private:
	int salary;
public:
	Permanent(char* name, int money)
		: Employee(name), salary(money) {}
	int GetPay() {
		return salary;
	}
	void ShowSalaryInfo() {
		ShowYourName();
		//Permanent의 GetPay가 호출됨.
		cout << GetPay() << endl << endl;
	}
};

class Sales : public Permanent {
private:
	int salesResult;
	double bonusRatio;
public:
	Sales(char* name, int money, double ratio)
		: Permanent(name, money), bonusRatio(ratio), salesResult(0) {}
	void AddSalesResult(int value) {
		salesResult += value;
	}
	int GetPay() {
		return Permanent::GetPay() + (int)(salesResult*bonusRatio);
	}
	//Funtion Overriding
	//Permanent의 ShowSalaryInfo가 오버라이딩 된 이유는?
	//성과급이 월급에 포함되어야 하기 때문.
	void ShowSalaryInfo() {
		ShowYourName();
		// Sales의 GetPay가 호출됨.
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler {
private:
	//Permanent* empList[50];
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler()
		: empNum(0){
	}
	//void AddEmployee(Permanent* emp)
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() {
		for(int i=0; i<empNum; i++){
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalaryInfo() {
		int sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->GetPay();
		}
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};

int main(void) {
	EmployeeHandler handler;

	//register Permanent
	handler.AddEmployee(new Permanent("Kim", 3000));
	handler.AddEmployee(new Permanent("Lee", 3500));

	//register Temporary
	Temporary* alba = new Temporary("Jung", 12);
	alba->AddWorkTime(100);
	handler.AddEmployee(alba);

	//register Sales
	Sales* seller = new Sales("Hong", 2200, 0.4);
	seller->AddSalesResult(1500);
	handler.AddEmployee(seller);

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalaryInfo();
	return 0;
}
