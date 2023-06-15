#include <iostream>
#include <set>
#include <tuple>
#include <map>
using namespace std;
typedef tuple<bool, bool, bool> cvladebi;
void CNF(map<cvladebi, bool> F) {
	cout << "f funqciis CNF aris:\n";
	cout << "f(x,y,z) = ";
	bool an = false; // ბოლო ფრჩხილის მერე რომ არ დაიწეროს 'V'
	for (auto x = F.begin(); x != F.end(); x++)
		if ((*x).second) {
			if (an)cout << "&";
			else an = true;

			cvladebi r = (*x).first;
			cout << "(";
			if (get<0>(r))cout << "xV";
			else cout << "!xV";
			if (get<1>(r))cout << "!yV";
			else cout << "yV";
			if (get<2>(r))cout << "!z";
			else cout << "z";
			cout << ")";
		}
}
int main() {
	map<cvladebi, bool>F{
	{ { 0,0,0 },0 },
	{ { 0,0,1 },0 },
	{ { 0,1,0 },0 },
	{ { 0,1,1 },1 },
	{ { 1,0,0 },1 },
	{ { 1,0,1 },0 },
	{ { 1,1,0 },1 },
	{ { 1,1,1 },1 }
	};
	CNF(F);
	cout << endl;
}