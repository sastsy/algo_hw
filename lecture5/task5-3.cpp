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
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < len && A[max] < A[l]) {
            max = l;
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

void buildHeap(vector<int> &A, int len) {
    for (int i = (len + 1) / 2 - 1; i >= 0; --i) {
        heapify(A, i, len);
    }
}

void heapSort(vector<int> &A) {
    int len = A.size();
    buildHeap(A, A.size());
    for (int k = A.size() - 1; k > 0; --k) {
        swap(A[0], A[k]);
        --len;
        heapify(A, 0, len);
    }
}

void findKMin(vector<int> &A, int k) {
    buildHeap(A, k);
    for (int i = k; i < A.size(); ++i) {
        if (A[i] < A[0]) {
            swap(A[i], A[0]);
            heapify(A, 0, k);
        }
    }
}

int main() {
    vector<int> A;
    generateVector(A, 10000000);
    vector<int> B;
    B = A;
    int k;

    cin >> k;

    findKMin(A, k);
    heapSort(B);

    if (B[k - 1] == A[0]) cout << "Correct!";
    else cout << "Wrong T_T";
}