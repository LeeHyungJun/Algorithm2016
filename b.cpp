int a;
int b;
int n = N;
vector<int> s;
while (n >= 2) {
	b = n % 2;
	n = n / 2;
	s.push_back(b);
}
s.push_back(n);

vector<int> com = s;
int cnt = 0;
for (int i = s.size() - 1; i >= 0; i--) {
	if (s[i] == 1)
		com[cnt++] = 0;
	else
		com[cnt++] = 1;
}
int res = 0;
int c = 0;
for (int i = com.size() - 1; i >= 0; i--) {
	res = res + com[i] * pow(2, c++);
}
return res;
