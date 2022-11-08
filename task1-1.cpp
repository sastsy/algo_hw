#include <iostream>
#include <vector>

int main() {
    int n;
    int x;
    std::cin >> n;
    std::vector<int> a;

    std::cin >> x;
    a.push_back(x);

    for (int i = 1; i < n; ++i) {
        std::cin >> x;
        a.push_back(x);
        if ((a[i] < a[i - 1] && i % 2 != 0) || (a[i] > a[i - 1] && i % 2 == 0)) {
            std::swap(a[i], a[i - 1]);
        }
    }

    for (int element : a) {
        std::cout << element << " ";
    }

    return 0;
}
