#include <iostream>
#include <vector>
#include <random>

using namespace std;

int partition(vector<int> &A, int l, int r) {
    int x = A[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (A[i] < x) {
            ++i;
        }
        while (A[j] > x) {
            --j;
        }
        if (i >= j) break;
        swap(A[i++], A[j--]);
    }
    return j;
}

void quickSort(vector<int> &A, int l, int r) {
    if (l < r) {
        int q = partition(A, l, r);
        quickSort(A, l, q);
        quickSort(A, q + 1, r);
    }
}

int findKMin(vector<int> &A, int k) {
    int l = 0;
    int r = A.size();
    while (true) {
        int q = partition(A, l, r);
        if (q == k) {
            return A[q];
        }
        else if (k < q) {
            r = q;
        }
        else {
            l = q + 1;
        }
    }
}

void generateVector(vector<int> &A, int n) {
    mt19937 mt(time(nullptr));
    for (int i = 0; i < n; ++i) {
        A.push_back(mt() % 1000);
    }
}

int main() {
    //vector<int> A = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> A;
    generateVector(A, 100);
    vector<int> B = A;
    quickSort(B, 0, B.size() - 1);
    int k = 10;
    findKMin(A, k) == B[k - 1] ? cout << "Right!" : cout << "Wrong T_T";
}