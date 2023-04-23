#include<iostream>
#include<map>
#include<functional>
#include<set>
#include<vector>
using namespace std;

// # 1 
bool reflex(const set<int>& A, const set<pair<int, int>>&R) {
    for (auto a = A.begin(); a != A.end(); a++)
        if (R.find(make_pair(*a, *a)) == R.end()) return false;
    return true;
}
bool simetr(const set<pair<int, int>>& R) { 
    for (auto a = R.begin(); a != R.end(); a++)
        if (R.find(make_pair(a->second, a->first)) == R.end()) return
false;
    return true;
}
bool tranz(const set<pair<int, int>>& R) {
    for (auto i = R.begin(); i != R.end(); i++)
        for (auto j = R.begin(); j!= R.end(); j++)
        if (i->second== j->first)
            if (R.find(make_pair(i->first, j->second)) == R.end())
            return false;
    return true;
}
void ekvivalentoba(){
    vector<int> v;
    for (int i = 1; i <= 10; i++)
        v.push_back(i);
    set<int> A(v.begin(),v.end());
    set<pair<int, int>> R;
    for (auto a = A.begin(); a != A.end(); a++)
        for (auto b = A.begin(); b != A.end(); b++)
            if ((*a - *b) % 3 == 0)
                R.insert(make_pair(*a, *b));
    cout << "R={";
        for (auto it = R.begin(); it != R.end(); it++)
        cout << "(" << it->first << " ," << it->second << ") , " << " ";
        cout <<"}\n"<< endl;
        if (reflex(A, R) && (simetr( R))&&(tranz(R))) cout << "R mimarteba ekvivalentobis mimartebaa!\n";
        else cout << " R mimarteba ar aris ekvivalentobis mimarteba!\n";
    
} 

// # 2
void disjunctive() {
    multimap<bool, bool> m{ { 0,0 },{ 0,1 },{ 1,0 },{ 1,1 } };
    map<pair<int, int>, int> mm;
    mm[{0, 0}] = 0; mm[{0, 1}] = 1; mm[{1, 0}] = 1; mm[{1, 1}] = 1;
    cout << "DNF=";
    auto t = --m.end();
    for (auto i = m.begin(); i != m.end(); i++)
        if (mm[*i] == 1) {
            t = i;
        }
    for (auto i = m.begin(); i != m.end(); i++)
    {
        bool x = i->first, y = i->second;
        if (mm[*i] == 1) {
            if (x == 0) cout << "!x";
            else cout << "x";
            if (y == 0) cout << "!y";
            else cout << "y";
            if (i != t)
                cout << " V ";
        }
    }
    cout << endl;
}


// # 3
void  hexadecimal(int n) {
    if (n < 16) {
        cout << n; return;
    }
    hexadecimal(n / 16);
    cout << n % 16;
}
void print_hexadecimal(){
    cout << "shemoitanet n=";
    int n;
    cin >> n;
    cout << endl;
    cout << "ricxvi " << n << " tvlis  16-obit sistemashi aris: " << endl;
    hexadecimal(n);
    cout << endl;
}

int main()
{
    ekvivalentoba();
    cout << endl;
    disjunctive();
    cout << endl;
	print_hexadecimal();
	return 0;
}