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
	vector<int> d;
	vector<int> before;
	int n;
	int m;
	int nodeNum;
	int tmp;
public:
	Sol(vector<vector<int>> _maze, int _n, int _m) {
		this->maze = _maze;
		this->n = _n;
		this->m = _m;
	}
	void bfs() {
		q.push(pair<int,int>(1,1));
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if ((maze[x - 1][y] == 1) && (d[(x-1)*m+y] == -1)) {
				q.push(pair<int, int>(x - 1, y));
			}

		}
	}
	void printMaze() {
		for (int i = 0; i < n+2; i++) {
			for (int j = 0; j < m+2; j++) {
				cout << maze[i][j] << " ";
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
	a.printMaze();
	//a.bfs();

}
