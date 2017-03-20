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

/*
 * Complete the function below.
 */

int cnt = 0;

void dfs(int start, vector<string> adj) {
    int n = adj.size();
	stack<int> s;
	vector<int> visit(n, -1);
    vector<int> cycleCheck;
	//시작노드 지정
	s.push(start);
    visit[start] = 1;
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		for (int i = 0; i < n; i++) {
			if (adj[cur][i] == 1 && visit[i] == -1) {
				s.push(i);
			}
		}
		visit[cur] = 1;
        cycleCheck.push_back(cur);
		cout << cur << " ";
	}
    if(cycleCheck[0] == cycleCheck[cycleCheck.size()-1])
        cnt++;
	cout << endl;
}

int zombieCluster(vector < string > zombies) {

    int n = zombies.size();
    for(int i=0; i < n; i++){
        dfs(i, zombies);
    }
    return cnt;
}


int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    
    int _zombies_size = 0;
    cin >> _zombies_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _zombies;
    string _zombies_item;
    for(int _zombies_i=0; _zombies_i<_zombies_size; _zombies_i++) {
        getline(cin, _zombies_item);
        _zombies.push_back(_zombies_item);
    }
    
    res = zombieCluster(_zombies);
    fout << res << endl;
    
    fout.close();
    return 0;
}

