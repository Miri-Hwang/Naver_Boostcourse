#include <stdio.h>
#define SIZE 500000
int main(int arge, char *argv[])
{
    int n;
    int sum_without_K = 0;
    scanf("%d", &n);
    // 1부터 N의 숫자중 K가 빠진 배열
    int partArr[SIZE];
    int lengthOfPartArr = n - 1;
    for (int i = 0; i < lengthOfPartArr; i++)
    {
        scanf("%d", &partArr[i]);
    }
    // TODO: n과 partArr를 이용하여, K를 구하라

    // 1부터 N까지의 합
    long long sum_including_K = (long long)n * (n + 1) * 0.5;

    // 배열의 합
    for (int i = 0; i < lengthOfPartArr; i++)
    {
        sum_without_K += partArr[i];
    }

    // K = 1부터 N까지의 합 - 파일 내 숫자의 합
    long long K = sum_including_K - sum_without_K;
    printf("K = %lld", K);
    return 0;
}