#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
using namespace std;

int f(int x) {
	return 4 * x - 7;
}
int g(int x) {
	return x * x;
}
bool sureqcia(map <int, int> m, set<int> codom) {
	set<int> s;
	for (auto i = m.begin(); i != m.end(); i++)
		s.insert(i->second);
	return (s.size() == codom.size());//adarebs m asaxvis mnishvnelobebis raodenobas codomeinis zomas.
}
void function_sureqcia() {

	set<int> dom{ -1,-2,1,2 };
	set<int> codomf{ -11,-15,-3,1 };
	set<int> codomg{ 1,4,-4 };
	map<int, int> mf, mg;
	cout << "dom={";
	for (auto i = dom.begin(); i != dom.end(); i++) {
		cout << *i << ",";
	}
	cout << "}\n" << endl;
	cout << "codomf={";
	for (auto i = codomf.begin(); i != codomf.end(); i++) {
		cout << *i << ",";
	}
	cout << "}\n" << endl;
	cout << "codomg={";
	for (auto i = codomg.begin(); i != codomg.end(); i++) {
		cout << *i << ",";
	}
	cout << "}\n" << endl;
	for (auto i = dom.begin(); i != dom.end(); i++) {
		mf[*i] = f(*i); //vqmnit wyvilebis simravles, (i, f(i)), sadac i dom-is elementia
	}
	cout << "mf: ";
	for (auto i = mf.begin(); i != mf.end(); i++)
		cout << "(" << i->first << ";" << i->second << "), ";
	cout << endl;
	if (sureqcia(mf, codomf)) cout << " f sureqciaa \n";
	else cout << "f ar aris sureqcia \n";
	for (auto i = dom.begin(); i != dom.end(); i++) {
		mg[*i] = g(*i); //vqmnit wyvilebis simravles, (i, g(i)), sadac i dom-is elementia
	}
	cout << endl;
	cout << "mg: ";
	for (auto i = mg.begin(); i != mg.end(); i++)
		cout << "(" << i->first << ";" << i->second << "), ";
	cout << endl;
	if (sureqcia(mg, codomg)) cout << "g sureqciaa \n";
	else cout << "g ar aris sureqcia \n";

}

void function_set() {
	//set_fname,set_lname სიმრავლის შექმნა განაცხადით, set_container ცარიელი სიმრავლის შექმნა
	set<string> set_fname{ "r","o","m","a" };
	set<string> set_lname{ "g","r","i","g","a","l","a","s", "h","v","i","l","i" };
	set<string> set_container;
	cout << "set set_fname: " << endl;
	for (auto i = set_fname.begin(); i != set_fname.end(); i++)
		cout << " " << *i << " ";
	cout << endl;
	cout << "set set_lname: " << endl;
	for (auto j = set_lname.begin(); j != set_lname.end(); j++)
		cout <<" "<< *j << " ";
	cout << endl;

	for (auto i = set_fname.begin(); i != set_fname.end(); i++) {
		// set_lname-ის ის ელემენტი, რომელიც set_fname სიმრავლეშიც არის, დაემატება set_container სიმრავლეს
		if (set_lname.find(*i) != set_lname.end())
			(set_container.insert(*i));
	}
	if (set_container.empty())
		cout << "The intersection of sets set_fname and set_lname is empty set. " << endl;
	else {
			cout << "The intersection of sets set_fname and set_lname is: " << endl;
		for (auto k = set_container.begin(); k != set_container.end(); k++)
			cout << " " << *k << " ";
		cout << endl;
	}

}
void function_vec() {

	vector<string> vec_fname{ "r","o","m","a" }; //iqmneba string tipis vectori saxelad vec_fname
	vector<string> vec_lname{ "g","r","i","g","a","l","a","s", "h","v","i","l","i" }; //iqmneba string tipis vectori saxelad vec2

	//valagebt zrdis mixedvit vectoris elementebs
	sort(vec_fname.begin(), vec_fname.end());
	sort(vec_lname.begin(), vec_lname.end());

	vector<string> vec_intersection; //vsqmnit axal string tipis veqtors saxelad vec_intersection
	set_intersection(vec_fname.begin(), vec_fname.end(), vec_lname.begin(), vec_lname.end(), back_inserter(vec_intersection));
	cout << "The intersection of sets vec_fname and vec_lname is set:" << endl;
	for (auto n : vec_intersection)
		cout << n << ' ';
	cout << endl;

}

int main()
{
	// function_vec(); 
	// function_set();
	function_sureqcia();
	return 0;
}