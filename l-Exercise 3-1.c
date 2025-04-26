#include <stdio.h>

int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (low < n && v[low] == x)
        return low;
    else
        return -1;
}

int main() {
    int v[] = { 2, 4, 6, 8, 10, 12 };
    int n = 6;
    int x = 10;

    int index = binsearch(x, v, n);
    if (index != -1)
        printf("num %d is found at pos: %d\n", x, index);
    else
        printf("%d not found\n", x);

    return 0;
}
