#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int x = 12, y = 4, z = 5;
    vector<int> S1, S2, S3;
    
    //დავბეჭდოთ x, y, z
    cout <<"x:"<< x <<";  y:"<< y <<";  z:"<< z <<";"<<endl;

    //ვთქვათ S1 არის 47-ზე ნაკლები x-ის ჯერადი ნატურალური რიცხვების სიმრავლე
    for (int i = x; i < 47; i += x){
        S1.push_back(i);
    }
    
    //დავბეჭდოთ S1
    cout <<"S1 : [ " ;
    for (int i = 0; i < S1.size(); i++){
        cout << S1[i] << " ";
    }
    cout <<" ]"<< endl;

    //S2 - 58-ზე ნაკლები y-ის ჯერადი ნატურალური რიცხვების სიმრავლე
    for (int i = y; i < 58; i += y){
        S2.push_back(i);
    }
    
    //დავბეჭდოთ S2
    cout <<"S2 : [ " ;
    for (int i = 0; i < S2.size(); i++){
        cout << S2[i] << " ";
    }
    cout <<" ]"<< endl;

    //S3 - 35-ზე ნაკლები z-ის ჯერადი ნატურალური რიცხვების სიმრავლეა
    for (int i = z; i < 35; i += z){
        S3.push_back(i);
    }
    
    //დავბეჭდოთ S3
    cout <<"S3 : [ " ;
    for (int i = 0; i < S3.size(); i++){
        cout << S3[i] << " ";
    }
    cout <<" ]"<< endl;

    // რომელიც იპოვის (S1 ∪ S2) ∖ S3 სიმრავლეს.
    // ჯერ ვიპოვნოთ გაერთიანება  (S1 ∪ S2)
    vector<int> S_union;
    for (int i = 0; i < S1.size(); i++){
        S_union.push_back(S1[i]);
    }
    for (int i = 0; i < S2.size(); i++){
        if(find(S_union.begin(), S_union.end(), S2[i]) == S_union.end()){
            S_union.push_back(S2[i]);
        }
    }

    // ვბეჭდავთ (S1 ∪ S2) გაერთიანებას
    cout <<"(S1 ∪ S2) : [ " ;
    for (int i = 0; i < S_union.size(); i++){
        cout << S_union[i] << " ";
    }
    cout <<" ]"<< endl;

    // შემდეგ ვპოულობთ ორი სიმრალის სხვაობას (S1 ∪ S2) ∖ S3.
    vector<int> S_difference;
    for ( int i = 0; i < S_union.size(); i++){
        if(find(S3.begin(), S3.end(), S_union[i]) == S3.end()) {
            S_difference.push_back(S_union[i]);
        }
    }

    // ვბეჭდავთ (S1 ∪ S2) / S3 სიმრავლეების სხვაობას;
    cout <<"(S1 ∪ S2) / S3 : [ " ;
    for (int i = 0; i < S_difference.size(); i++){
        cout << S_difference[i] << " ";
    }
    cout <<" ]" ;

}