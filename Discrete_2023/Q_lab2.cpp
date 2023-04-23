#include <iostream>
#include <set>

using namespace std;

// ფუნქციას განვსაზღვრავთ აქ
int f(int x) {
    return 2 * x;
}

// ვადგენთ არის თუ არა ფუნქცია შექცევადი მოცემულ დომეინსა და კოდომეინზე.
bool is_invertible(set<int> domain, set<int> codomain) {
    set<int> image;
    for (auto x : domain) { // ციკლი დომეინების ელემენტებზე
        int y = f(x); 
        if (codomain.count(y) == 0 || image.count(y) > 0) {
            return false;
        }
        image.insert(y);
    }
    return true;
}

// დომეინისა და კოდომეინის დასაბეჭდათ
void print_sets(set<int> domain, set<int> codomain) {
    cout << "მოცემულია დომეინი: { ";
    for (auto x : domain) {
        cout << x << " ";
    }
    cout <<" }, ";

    cout << "და მოცემულია კოდომეინი: { ";
    for (auto y : codomain) {
        cout << y << " ";
    }
    cout <<" }"<< endl;
}

int main() {
    // მაგალითი 1: ფუნქცია შექცევადი მოცემულ დომეინსა და კოდომეინზე.
    set<int> domain1 = {1, 2, 3};
    set<int> codomain1 = {2, 4, 6};
    if (is_invertible(domain1, codomain1)) {
        print_sets(domain1, codomain1);
        cout << "ფუნქცია არის შექცევადი მოცემულ დომეინსა და კოდომეინზე.\n" << endl;
    } else {
        print_sets(domain1, codomain1);
        cout << "ფუნქცია არ არის შექცევადი მოცემულ დომეინსა და კოდომეინზე.\n" << endl;
    }
    
    // მაგალითი 2: ფუნქცია არ არის შექცევადი მოცემულ დომეინსა და კოდომეინზე.
    set<int> domain2 = {1, 2, 3};
    set<int> codomain2 = {2, 4};
    if (is_invertible(domain2, codomain2)) {
        print_sets(domain2, codomain2);
        cout << "ფუნქცია არის შექცევადი მოცემულ დომეინსა და კოდომეინზე.\n" << endl;
    } else {
        print_sets(domain2, codomain2);
        cout << "ფუნქცია არ არის შექცევადი მოცემულ დომეინსა და კოდომეინზე.\n" << endl;
    }
    
    return 0;
}