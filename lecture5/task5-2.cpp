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

void heapify(vector<int> &A, int k) {
    int max;
    int j;
    for (int i = (k + 2) / 3 - 1; i >= 0; --i) {
        j = i;
        max = j * 3 + 1;
        while (j * 3 + 1 <= k && A[j] < A[max]) {
            if (j * 3 + 3 <= k && A[j * 3 + 3] > A[j * 3 + 2] && A[j * 3 + 3] > A[j * 3 + 1]) {
                max = j * 3 + 3;
            }
            else if (j * 3 + 2 <= k && A[j * 3 + 2] > A[j * 3 + 3] && A[j * 3 + 2] > A[j * 3 + 1]) {
                max = j * 3 + 2;
            }
            else {
                max = j * 3 + 1;
            }
            swap(A[j], A[max]);
            j = max;
            max = j * 3 + 1;
        }
    }
}

void heapSort(vector<int> &A) {
    for (int k = A.size() - 1; k > 0; --k) {
        heapify(A, k);
        swap(A[0], A[k]);
    }
}

int main() {
    vector<int> A;
    vector<int> B;
    generateVector(A, 100000);
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
//    for (int i : A) cout << i << " ";
}