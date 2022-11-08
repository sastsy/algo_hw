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
    std::vector<int> map(k, 0);

    int x;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        a.push_back(x);
        map[x] += 1;
    }

    int l;
    int r;
    for (int i = 0; i < q; ++i) {
        std::cin >> l >> r;
        int count = 0;
        for (int j = l; j <= r; ++j) {
            count += map[j];
        }
        std::cout << count << "\n";
    }
    return 0;
}