#include <iostream>
#include <vector>
#include <random>

using namespace std;

int count = 0;

void merge(vector<int> &A, int l, int q, int r, int s) {
    vector<int> L;
    vector<int> R;
    int n1 = q - l + 1;
    int n2 = r - q;

    for (int i = l; i <= q; ++i) {
        L.push_back(A[i]);
    }

    for (int i = q + 1; i <= r; ++i) {
        R.push_back(A[i]);
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i != n1 && j != n2) {
        if (L[i] < R[j]) {
            A[k] = L[i];
            ++i;
        }
        else {
            A[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i != n1) {
        A[k] = L[i];
        ++i;
        ++k;
    }
    while (j != n2) {
        A[k] = R[j];
        ++j;
        ++k;
    }

    if (l == 0 && r == A.size() - 1) {
        int ptr1 = 0;
        int ptr2 = A.size() - 1;

        while (ptr1 != ptr2) {
            if (A[ptr1] + A[ptr2] == s) {
                ++::count;
                ++ptr1;
            }
            else if (A[ptr1] + A[ptr2] > s) --ptr2;
            else ++ptr1;
        }
    }
}

void MergeSort(vector<int> &A, int l, int r, int s) {
    if (l < r) {
        int q = (l + r) / 2;
        MergeSort(A, l, q, s);
        MergeSort(A, q + 1, r, s);
        merge(A, l, q, r, s);
    }
}

vector<int> generateVector(int n) {
    vector<int> B;
    mt19937 mt(time(nullptr));
    for (int i = 0; i < n; ++i) {
        B.push_back(mt() % 100);
    }
    return B;
}

int main() {
    unsigned int s;
    vector<int> A;
    cin >> s;
    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        A.push_back(x);
    }

    MergeSort(A, 0, A.size() - 1, 10);

    for (int el : A) cout << el << " ";
    cout << "\n";
    cout << ::count;
}