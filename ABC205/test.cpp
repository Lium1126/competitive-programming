#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
//    std::vector<int> v = {3, 1, 4, 6, 5};
    std::vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(5);
    v.push_back(9);

    // 4以上の要素を二分探索で検索
    decltype(v)::iterator it = std::lower_bound(v.begin(), v.end(), 4);
    if (it != v.end()) {
        std::size_t pos = std::distance(v.begin(), it);
        std::cout << *it << " pos=" << pos << std::endl;
    }
    return 0;
}