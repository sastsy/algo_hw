#include <iostream>
#include <vector>
#include <random>
#include <chrono>

bool isSmooth(int n) {
    int x = n;
    for (int i = 2; i <= 3; ++i) {
        while (x % i == 0) {
            x /= i;
        }
    }
    return x == (int) 1;
}

std::vector<int> smoothSeqGenerator(int n) {
    std::vector<int> a;
    for (int i = 1; i < n; ++i) {
        if (isSmooth(i)) a.push_back(i);
    }
    return a;
}

std::vector<int> shellSort(std::vector<int> k, std::vector<int> h) {
    std::vector<int> s = k;
    for (int gap = h.size() - 1; gap > 0; --gap) {
        for (int i = h[gap]; i < s.size(); ++i) {
            int temp = s[i];
            int j;
            for (j = i; j >= h[gap] && s[j - h[gap]] > temp; j-= h[gap]) {
                s[j] = s[j - h[gap]];
            }
            s[j] = temp;
        }
    }
    return s;
}

int main() {
    std::mt19937 mt(time(nullptr));

    for (int i = 1000; i <= 1000000; i *= 10) {
        std::vector<int> ex;
        for (int j = 0; j < i; ++j) {
            ex.push_back(mt());
        }

        auto start1 = std::chrono::steady_clock::now();
        std::vector<int> ex2 = shellSort(ex, smoothSeqGenerator(ex.size()));
        auto end1 = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end1 - start1;
        std::cout << "ShellSort on " << i << " is " << elapsed_seconds.count() << " s.\n";

        auto start2 = std::chrono::steady_clock::now();
        std::sort(ex.begin(), ex.end());
        auto end2 = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
        std::cout << "Built-in sort on " << i << " is " << elapsed_seconds2.count() << " s.\n";
    }
    return 0;
}

