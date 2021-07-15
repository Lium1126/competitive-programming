#include <iostream>
using namespace std;

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main() {
    int a[3];
    for (int i = 0;i < 3;i++) {
        cin >> a[i];
    }
    qsort(a, 3, sizeof(int), compare_int);

    cout << a[1] << endl;

    return(0);
}
