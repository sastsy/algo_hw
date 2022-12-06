#include <iostream>
#include <vector>

using namespace std;

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

int main() {
    vector<int> A = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
    quickSort(A, 0, A.size() - 1);
    for (int el : A) cout << el << " ";
}