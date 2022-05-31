#include <stdio.h>
#include <time.h>

long long cache[100000000] = {0,};

int fast(int min, int max) {
    clock_t start, end;
    start = clock();
    int i;
    int max_n = 0;
    int max_len = 0;
    for (i = min; i <= max; i++) {
        long long n = i;
        int len = 1;
        while (n != 1) {
            if (n < 100000000 && cache[n - 1] != 0) {
                len += cache[n - 1] - 1;
                break;
            }
            if (n % 2 == 0) {
                n /= 2;
            }
            else {
                n = 3 * n + 1;
            }
            len++;
        }
        cache[i - 1] = len;
        if (len > max_len) {
            max_len = len;
            max_n = i;
        }
    }
    end = clock();
    double span = ((double)end - (double)start) / CLOCKS_PER_SEC;
    printf("메모이제이션 사용, %f s 소요\n", span);
    printf("최대 길이를 갖는 수: %d, 최대 길이: %d\n", max_n, max_len);
}

int slow(int min, int max) {
    clock_t start, end;
    start = clock();
    int i;
    int max_n = 0;
    int max_len = 0;
    for (i = min; i <= max; i++) {
        long long n = i;
        int len = 1;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            }
            else {
                n = 3 * n + 1;
            }
            len++;
        }
        if (len > max_len) {
            max_len = len;
            max_n = i;
        }
    }
    end = clock();
    double span = ((double)end - (double)start) / CLOCKS_PER_SEC;
    printf("메모이제이션 미사용, %f s 소요\n", span);
    printf("최대 길이를 갖는 수: %d, 최대 길이: %d\n", max_n, max_len);
}

int main(void) {
    int min, max;
    scanf_s("%d", &min);
    scanf_s("%d", &max);
    slow(min, max);
    fast(min, max);
    system("pause");
    return 0;
}