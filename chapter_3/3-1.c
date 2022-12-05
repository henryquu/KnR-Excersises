#include <stdio.h>
#include <time.h>

int binsearch1(int, int[], int);
int binsearch2(int, int[], int);


int main() {
    clock_t start, end;
    int v[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 14, 15, 16, 17, 20, 21, 22, 23, 24};
    int n = sizeof(v) / sizeof(v[0]);

    start = clock();
    for (int i = 0; i < 10000000; i++)
        binsearch1(5, v, n);
    end = clock();
    double elapsed = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Binary with 2 tests: %f seconds\n", elapsed);

    
    start = clock();
    for (int i = 0; i < 10000000; i++)
        binsearch2(5, v, n);
    end = clock();
    elapsed = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Binary with 1 test: %f seconds\n", elapsed);
}


int binsearch1(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1; 
}

int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high && v[mid] != x) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid;
    }

    if (v[mid] == x)
        return mid;
    return -1; 
}