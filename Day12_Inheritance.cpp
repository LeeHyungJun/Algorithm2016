/**
    @file   : Day12_Inheritance.cpp
    @date   : 01.18.2017
    @author : Hyungjun Lee
    @mail   : hjlee1765@gmail.com
    @refer  : Hacker Rank
*/

#include <iostream>
#include <vector>

using namespace std;

class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}	
};

class Student : public Person{
	private:
		vector<int> testScores;
        	int len;
        	int sum;
        	int avg;
	public:
        	Student(string fName, string lName, int id, vector<int> s);
        	char calculate();      
};

Student :: Student(string fName, string lName, int id, vector<int> s)
    :Person(fName, lName, id){
        testScores = s;
        this -> len = s.size();
        this -> sum = 0;
        this -> avg = 0;
    }

char Student :: calculate(){
    for(int i = 0; i < len; i++)
        sum += testScores[i];
    avg = sum/len;
    
    if( avg >= 90 && avg <= 100)
        return 'O';
    if( avg >= 80 && avg < 90)
        return 'E';
    if( avg >= 70 && avg < 80)
        return 'A';
    if( avg >= 55 && avg < 70)
        return 'P';
    if( avg >= 40 && avg < 55)
        return 'D';
    else
        return 'T';
}

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}
