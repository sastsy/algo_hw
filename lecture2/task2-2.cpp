#include <iostream>
#include <vector>

int main() {
    int n;
    int k;
    int q;
    std::cin >> n;
    std::cin >> k;
    std::cin >> q;

    std::vector<int> a;
    std::vector<int> map(k + 1, 0);

    int x;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        a.push_back(x);
        map[x] += 1;
    }

    for (int i = 1; i <= k; ++i) {
        map[i] += map[i - 1];
    }

    int l;
    int r;
    for (int i = 0; i < q; ++i) {
        std::cin >> l >> r;
        std::cout << map[r] - map[l] + 1 << "\n";
    }
    return 0;
}