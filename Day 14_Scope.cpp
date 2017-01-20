#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
      vector<int> elements;
  	public:
  	  int maximumDifference;
      int differ;

    Difference(vector<int> a)
        : maximumDifference(0), differ(0){
        elements = a;
    }
    void computeDifference(){
        for(int i=0; i<elements.size(); i++){
            for(int j= i + 1; j<elements.size(); j++){
                differ = abs(elements[i] - elements[j]);
                if(differ > maximumDifference)
                    maximumDifference = differ;
            }
        }
    }
}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}
