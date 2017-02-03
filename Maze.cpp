/**
*	file   : Maze.cpp
*	date   : 02.03.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BackJoon_2178
**/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

class Sol {
private:
	vector<vector<int>> maze;
	queue<pair<int,int>> q;
	vector<vector<int>> d;
	//vector<pair<int,int>> before;
	int n;
	int m;
	int nodeNum;
	int tmp;
	int x, y;
public:
	Sol(vector<vector<int>> _maze, int _n, int _m) {
		this->maze = _maze;
		this->n = _n;
		this->m = _m;
		for (int i = 0; i < n+2; i++) {
			d.push_back(vector<int>(m + 2,-1));
			//before.push_back(pair<int,int>(0,0));
		}
	}
	int bfs() {
		//cout << "1,1" << endl;
		d[1][1] = 0;
		//before.push_back(pair<int, int>(a, b));
		q.push(pair<int,int>(1,1));
		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();

			check(x - 1 , y		);
			check(x		, y + 1	);
			check(x + 1	, y		);
			check(x		, y-1	);
		}
		return d[n][m];
	}

	void check(int a, int b) {
		if ((maze[a][b] == 1) && (d[a][b] == -1)) {
			//cout << a << "," << b << endl;
			d[a][b] = d[x][y] + 1;
			//before.push_back(pair<int, int>(a, b));
			q.push(pair<int, int>(a, b));
		}
	}
	void printMaze() {
		for (int i = 0; i < n+2; i++) {
			for (int j = 0; j < m+2; j++) {
				//cout << maze[i][j] << " ";
				cout << d[i][j] << " ";
			}cout << endl;
		}

	}

};
int main(void) {
	int n, m;
	string str;
	int tmp;
	int graphNum;
	cin >> n >> m;
	cin.ignore();
	vector<vector<int>> maze(n+2,vector<int>(m+2));
	
	for (int i = 1; i < n+1; i++) {
		getline(cin, str);
		for (int j = 1; j < m+1; j++) {
			maze[i][j] = (int)str[j-1] - 48;
		}
	}

	Sol a(maze,n,m);
	//a.printMaze();
	cout << a.bfs()+1 << endl;

}
