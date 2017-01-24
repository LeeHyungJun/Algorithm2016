/**
*	file   : String_Handle_sort.cpp
*	date   : 01.23.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : Hacker Rank
**/

#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void getOnlyGmailVector(vector<string>& sv, char* c_firstName, char* c_emailID) {
    string googler= "gmail.com";
    int i=0;
	char* ptr = strtok(c_emailID, "@");
    ptr = strtok(NULL,"@");
 
	string address(ptr);
    
    if(!address.compare(googler)){
        string s_firstName(c_firstName);
        sv.push_back(s_firstName);
    }   
}

int main() {
    vector<string> sv;
	int N;
	cin >> N;
	for (int a0 = 0; a0 < N; a0++) {
		string firstName;
		string emailID;
		cin >> firstName >> emailID;
		
    char* cfirstName = new char[firstName.length() + 1];
		char* cemailID = new char[emailID.length() + 1];
		strcpy(cfirstName, firstName.c_str());
		strcpy(cemailID, emailID.c_str());
        
		getOnlyGmailVector(sv,cfirstName, cemailID);
	}
    
    sort(sv.begin(), sv.end());
   
    for(vector<string>::iterator it=sv.begin(); it<sv.end(); it++)
        cout << *it << endl;
    
	return 0;
}
