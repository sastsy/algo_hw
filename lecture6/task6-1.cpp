#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

void generateVector(vector<int> &A, int n) {
    mt19937 mt(time(nullptr));
    for (int i = 0; i < n; ++i) {
        A.push_back(mt() % 1000);
    }
}

void getTimeSTDSort(vector<int> V) {
    auto start = chrono::steady_clock::now();
    sort(V.begin(), V.end());
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "STD sort is " << elapsed_seconds.count() << "s";
    cout << "\n";
}


int partition(vector<int> &A, int l, int r, int &j, int &i) {
    int x = A[r];
    i = l;
    j = r - 1;
    int a = l - 1;
    int b = r;

    while (i <= j) {
        while (A[i] < x) {
            ++i;
        }
        while (A[j] > x) {
            --j;
        }
        if (i >= j) break;
        swap(A[i], A[j]);

        if (A[i] == x) {
            ++a;
            swap(A[a], A[i]);
        }
        ++i;
        if (A[j] == x) {
            --b;
            swap(A[b], A[j]);
        }
        --j;
    }
    swap(A[i], A[r]);
    j = i - 1;
    ++i;

    for (int k = l; k <= a; ++k, --j) {
        swap(A[k], A[j]);
    }
    for (int k = r - 1; k >= b; --k, ++i) {
        swap(A[k], A[i]);
    }
}

void quickSort(vector<int> &A, int l, int r) {
    if (l < r) {
        int j;
        int i;
        partition(A, l, r, j, i);
        quickSort(A, l, j);
        quickSort(A, i, r);
    }
}

void getTimeQuickSort(vector<int> V) {
    auto start = chrono::steady_clock::now();
    quickSort(V, 0, V.size() - 1);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "Quick sort is " << elapsed_seconds.count() << "s";
    cout << "\n";
}

int main() {
    vector<int> A1;
    vector<int> A2;
    generateVector(A1, 10000000);
    A2 = A1;
    getTimeQuickSort(A1);
    getTimeSTDSort(A2);

    vector<int> B1;
    vector<int> B2;
    generateVector(B1, 100000000);
    B2 = B1;
    getTimeQuickSort(B1);
    getTimeSTDSort(B2);
}