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

void heapify(vector<int> &A, int i, int len) {
    bool done = false;
    while (!done) {
        int max = i;
        int l = 3 * i + 1;
        int mid = 3 * i + 2;
        int r = 3 * i + 3;

        if (l < len && A[max] < A[l]) {
            max = l;
        }
        if (mid < len && A[max] < A[mid]) {
            max = mid;
        }
        if (r < len && A[max] < A[r]) {
            max = r;
        }

        if (max == i) {
            done = true;
        }

        swap(A[max], A[i]);
        i = max;
    }
}

void buildHeap(vector<int> &A) {
    for (int i = (A.size() + 2) / 3 - 1; i >= 0; --i) {
        heapify(A, i, A.size());
    }
}

void heapSort(vector<int> &A) {
    int len = A.size();
    buildHeap(A);
    for (int k = A.size() - 1; k > 0; --k) {
        swap(A[0], A[k]);
        --len;
        heapify(A, 0, len);
    }
}

int main() {
    vector<int> A;
    vector<int> B;
    generateVector(A, 10000000);
    B = A;

    auto start1 = chrono::steady_clock::now();
    heapSort(A);
    auto end1 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds1 = end1 - start1;
    cout << "Heap sort is " << elapsed_seconds1.count() << "s";

    cout << "\n";

    auto start2 = chrono::steady_clock::now();
    sort(B.begin(), B.end());
    auto end2 = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds2 = end2 - start2;
    cout << "STD sort is " << elapsed_seconds2.count() << "s";
}