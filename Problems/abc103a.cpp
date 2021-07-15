#include <iostream>
#include <vector>
using namespace std;

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main() {
    int v[3];
    for (int i = 0;i < 3;i++) cin >> v[i];
    qsort(v, 3, sizeof(int), compare_int);
    int ans = 0;
    for (int i = 1;i < 3;i++) ans += abs(v[i] - v[i - 1]);
    cout << ans << endl;
    return(0);
}
