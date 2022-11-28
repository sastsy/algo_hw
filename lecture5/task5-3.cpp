#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

void generateVector(vector<int> &A, int n) {
    mt19937 mt(time(nullptr));
    for (int i = 0; i < n; ++i) {
        A.push_back(mt() % 100);
    }
}

void heapify(vector<int> &A, int k) {
    int min;
    int j;
    for (int i = ((k + 1) / 2) - 1; i >= 0; --i) {
        j = i;
        min = j * 2 + 1;
        while (j * 2 + 1 <= k && A[j] > A[min]) {
            if (j * 2 + 2 <= k && A[j * 2 + 2] < A[j * 2 + 1]) {
                min = j * 2 + 2;
            }
            else {
                min = j * 2 + 1;
            }
            swap(A[j], A[min]);
            j = min;
            min = j * 2 + 1;
        }
    }
}

int findKMin(vector<int> &A, int k) {
    int ans;
    for (int i = A.size() - 1; i >= A.size() - k && i > 0; --i) {
        heapify(A, i);
        ans = A[0];
        swap(A[0], A[i]);
    }
    return k == A.size() ? A[0] : ans;
}

int main() {
    vector<int> A;
    int k;
    generateVector(A, 10);
    cin >> k;
    for (int i : A) cout << i << " ";
    cout << "\n";
    cout << findKMin(A, k);
}