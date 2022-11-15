#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

// 1) Сортировка вставкой сортирует n/m последовательностей за время тета от n*m,
// Так как всего их количество n/m, а сортировка вставкой на каждом подмассиве имеет оценку
// сложности m^2, соответственно, имея таких n/m штук, общая сложность составит n/m*m^2=n*m.

void InsertionSort(vector<int> &A, int iter, int m) {
    for (int i = iter; i < iter + m; ++i) {
        int j = i;
        while (j > iter && A[j] < A[j - 1]) {
            swap(A[j], A[j - 1]);
            --j;
        }
    }
}

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

void SubarrayInsertionSort(vector<int> &A, int m) {
    for (int i = 0; i <= A.size() - m; i += m) {
        InsertionSort(A, i, m);
    }

    for (int curr_size = m; curr_size < A.size(); curr_size *= 2) {
        for (int left_start = 0; left_start < A.size() - 1; left_start += 2 * curr_size) {
            int mid;
            left_start + curr_size - 1 > A.size() - 1 ? mid = A.size() - 1 : mid = left_start + curr_size - 1;
            int right_end;
            left_start + 2 * curr_size - 1 > A.size() - 1 ? right_end = A.size() - 1 : right_end = left_start + 2 * curr_size - 1;

            merge(A, mid, left_start, right_end);
        }
    }
//    for (int i = m - 1; i <= A.size() - m - 1; i += m) {
//        merge(A, i, m);
//    }
}

vector<int> generateVector(int n) {
    mt19937 mt(time(nullptr));
    vector<int> B;

    for (int i = 0; i < n; ++i) {
        B.push_back((mt() % 100) + 100);
    }

    return B;
}

int main() {
    for (int i = 1000; i <= 10000000; i *= 10) {
        vector<int> A = generateVector(i);

        int min_m = -1;
        int min_s = -1;

        for (int m = 2; m < (i / 2); ++m) {
            vector<int> C = A;

            auto start = chrono::steady_clock::now();
            SubarrayInsertionSort(C, m);
            auto end = chrono::steady_clock::now();
            chrono::duration<double> seconds = end - start;

            if (seconds.count() < min_s or min_s == -1) {
                min_s = seconds.count();
                min_m = m;
            }
        }
        cout << "Best m for " << i << " elements is " << min_m << " with the time of " << min_s << "\n";
    }
}

