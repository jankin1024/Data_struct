#include <iostream>
#include "Vector.cpp"
#include "Vector.h"
using namespace std;

int t[15];
int search(int e, Rank lo, Rank hi) {
    int mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (t[mid] <= e)
            lo = mid;
        else
            hi = mid;
    }
    return t[lo] == e ? lo : -1;
}

int main() {
    // int test[15] = {1, 2, 1, 3, 8, 4, 8, 7, 6, 5, 4};
    // Vector<int> vec(test, 10);
    // for (int i = 0; i < vec.size(); i++) cout << vec._elem[i] << "\t";
    // cout << endl;
    // // cout << vec.max(2, 6) << endl;
    // // vec.bubbleSort(0, 10);
    // for (int i = 0; i < vec.size(); i++) cout << vec._elem[i] << "\t";
    // cout << endl;

    for (int i = 0; i < 15; i++) {
        t[i] = i;
    }
    int x;
    for (int i = 0; i < 10; i++) {
        cin >> x;
        cout << search(x, 0, 7) << endl;
    }
}