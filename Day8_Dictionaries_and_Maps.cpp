#include <cmath>
#include <map>
#include <sstream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    cin.ignore();
    string name = "";
    
    map<string, int> phoneBook;
    
    for(int i=0; i < n; i++ ){
        string input_Line;
        stringstream ss;
        
        string tmpStr;
        int tmpInt;
        
        getline(cin, input_Line);
        ss << input_Line;  // == ss.str(input);

        ss >> tmpStr;
        ss >> tmpInt;

        phoneBook.insert(map<string,int>::value_type(tmpStr,tmpInt));
    }
    
    while(getline(cin, name)){
        map<string, int>::iterator findIter = phoneBook.find(name);
        if(findIter != phoneBook.end())
            cout << name << "=" << findIter->second << endl;
        else
            cout << "Not found" << endl;
    }
 
    return 0;
}
