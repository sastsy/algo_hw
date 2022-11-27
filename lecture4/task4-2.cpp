#include <iostream>
#include <vector>
#include <random>
#include <math.h>
#include <chrono>

using namespace std;

void generateVector(vector<int> &A, int n) {
    mt19937 mt(time(nullptr));
    for (int i = 0; i < n; ++i) {
        A.push_back(mt() % 10000);
    }
}

int getMax(vector<int> &A) {
    int min = A[0];
    for (int i : A) {
        if (i < min) min = i;
    }
    return min;
}

int getDigit(int x, int pos) {
    return (x / (int) pow(10, pos - 1)) % 10;
}

void radixSort(vector<int> &A, int m, int k) {
    int min = getMax(A); //ищем минимальный элемент в массиве, чтобы прибавить его ко всем числам и сделать их неотрицательными,
    //при этом порядок чисел сохранится прежним
    for (int pos = 1; pos <= m; ++pos) {
        vector<int> C(k);
        vector<int> B = A;

        for (int i : A) {
            ++C[getDigit(i + (-min), pos)];
        }

        for (int i = 1; i < k; ++i) {
            C[i] += C[i - 1];
        }

        for (int i = A.size() - 1; i >= 0; --i) {
            int d = getDigit(A[i] + (-min), pos);
            B[C[d] - 1] = A[i];
            --C[d];
        }
        A = B;
    }
}

int main() {
    vector<int> A;
    generateVector(A, 10000000);
    vector<int> B = A;

    auto start = chrono::steady_clock::now();
    radixSort(A, 4, 10);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "radix sort is " << elapsed_seconds.count() << "s" << "\n";

    for (int i : A) cout << i << " ";
    cout << "\n";

    auto start2 = chrono::steady_clock::now();
    sort(B.begin(), B.end());
    auto end2 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds2 = end2 - start2;
    cout << "std sort is " << elapsed_seconds2.count() << "s";
}

