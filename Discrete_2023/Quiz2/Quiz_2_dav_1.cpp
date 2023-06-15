#include<iostream>
#include<set>
#include<vector>
using namespace std;

bool reflex(const set<int>& A, const set<pair<int, int>>&R) {
	for (auto a = A.begin(); a != A.end(); a++)
		if (R.find(make_pair(*a, *a)) == R.end()) return false;
	return true;
}
bool simetr(const set<pair<int, int>>& R) {
	for (auto a = R.begin(); a != R.end(); a++)
		if (R.find(make_pair(a->second, a->first)) == R.end())
			return false;
	return true;
}
bool tranz(const set<pair<int, int>>& R) {
	for (auto i = R.begin(); i != R.end(); i++)
		for (auto j = R.begin(); j != R.end(); j++)
			if (i->second == j->first)
				if (R.find(make_pair(i->first, j->second)) == R.end())
					return false;
	return true;
}
int main() {
	vector<int> v;
	for (int i = 1; i <= 10; i++)
		v.push_back(i);
	set<int> A(v.begin(), v.end());
	set<pair<int, int>> R;
	for (auto a = A.begin(); a != A.end(); a++)
		for (auto b = A.begin(); b != A.end(); b++)
			if ((*a - *b) % 7 == 0)
				R.insert(make_pair(*a, *b));
	cout << "R={";
	for (auto it = R.begin(); it != R.end(); it++)
		cout << "(" << it->first << "," << it->second << ")," << " ";
	cout << "}\n" << endl;
	for (auto it = R.begin(); it != R.end(); it++)
		cout << "(" << it->first << " ," << it->second << ") , " << " ";
	cout << "}\n" << endl;
	if (reflex(A, R) && (simetr(R)) && (tranz(R))) cout << "R mimarteba ekvivalentobis mimartebaa!\n";
	else cout << " R mimarteba ar aris ekvivalentobis mimarteba!\n";

}