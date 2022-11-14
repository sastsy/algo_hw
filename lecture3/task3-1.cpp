#include <iostream>
#include <vector>

using namespace std;

int count = 0;

void merge(vector<int> &A, int q, int l, int r) {
    vector<int> A1;
    vector<int> A2;
    int n1 = q - l + 1;
    int n2 = r - q;

    for (int i = l; i <= q; ++i) {
        A1.push_back(A[i]);
    }

    for (int i = q + 1; i <= r; ++i) {
        A2.push_back(A[i]);
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (A1[i] <= A2[j]) {
            A[k] = A1[i];
            ++i;
        }
        else {
            A[k] = A2[j];
            ++j;
            ::count += n1 - i;
        }
        ++k;
    }

    while (i < n1) {
        A[k] = A1[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        A[k] = A2[j];
        ++j;
        ++k;
    }
}

int MergeSort(vector<int> &A, int l, int r) {
    if (l < r) {
        int q = (r + l) / 2;
        MergeSort(A, l, q);
        MergeSort(A, q + 1, r);
        merge(A, q, l, r);
    }
}

int main() {
    vector<int> A;
    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        A.push_back(x);
    }

    MergeSort(A, 0, A.size() - 1);

    cout << ::count << "\n";

    for (int el : A) {
        cout << el << " ";
    }
}