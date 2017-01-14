/**
    @file   : Day10_binary_number.cpp
    @date   : 01.14.2017
    @author : Hyungjun Lee
    @mail   : hjlee1765@gmail.com
    @refer  : Hacker Rank
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void making_binary_vector(int n, vector<int>& v){
    int quotient = n;
    while (quotient > 1) {
		v.push_back(quotient % 2);
		quotient = quotient / 2;
	}
	v.push_back(quotient);
}

int get_consecutive_number(vector<int>& v){
    int max=0, cnt=0;
    for(int i; i<v.size(); i++){
        if(v[i] == 1)
            cnt++;
        else{                   //v[i] == 0
            if(max < cnt)
                max = cnt;
            cnt = 0;
        }
    }
    //if last part is maximum consecutive 1's section 
    if(max < cnt)
        max = cnt;
    return max;
}

int main() {
	int n=0, quotient=0, result=0;
	vector <int> reminderVector;
	cin >> n;
	
    //Change "base-10 integer" to "binary"
    //put the binary in the Vector.
    making_binary_vector(n, reminderVector);
    
    //Count the consecutive 1's in the Vector. 
    result = get_consecutive_number(reminderVector);
   
    //Print the result.
    cout << result;
    
	return 0;
}
