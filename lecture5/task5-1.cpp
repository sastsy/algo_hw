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
    int new_j;
    for (int i = ((k + 1) / 2) - 1; i >= 0; --i) {
        j = i;
        max = j * 2 + 1;
        while (j * 2 + 1 <= k && A[j] < A[max]) {
            if (j * 2 + 2 <= k && A[j * 2 + 2] > A[j * 2 + 1]) {
                max = j * 2 + 2;
                new_j = j * 2 + 2;
            }
            else {
                max = j * 2 + 1;
                new_j = j * 2 + 1;
            }
            swap(A[j], A[max]);
            j = new_j;
            max = j * 2 + 1;
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
//    for (int i : A) cout << i << " ";

}