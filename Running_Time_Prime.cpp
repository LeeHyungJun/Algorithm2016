/**
*	file   : Running_Time_Prime.cpp
*	date   : 01.24.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : Hacker Rank
**/

#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n == 1)
        return false;
    if(n == 2)
        return true;
    for (int i = 2; i*i<=n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while(T-- > 0){
        int n = 0;
        cin >> n;
        if(isPrime(n) == 0)
            cout << "Not prime" << endl;
        else
            cout << "Prime" << endl;
    }
    return 0;
}
