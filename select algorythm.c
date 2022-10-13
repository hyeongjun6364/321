/*-----------------------------------------------------------------------
Select 문제. 교재의 평균 선형시간 선택 알고리듬을 구현하시오.

입력: input_data.txt
각 입력은 다음과 같이 구성되어 있다.
입력 file 형식
M     // 선택을 위한 입력 케이스의 수
N k  // 첫 번째 리스트의 길이(N)과 k번째 작은 값을 구하는 입력
n1    // 선택을 위한 첫 번째 수 리스트
n2
n3
...
nN
(빈줄)
N k  // 두 번째 리스트의 길이(N)과 k번째 작은 값을 구하는 입력
n1    // 선택을 위한 두 번째 수 리스트
n2
n3
...
nN

조건:
1. 정렬을 위한 입력 케이스의 수는 100이다.
2. 입력되는 수의 갯수(N)는 [1, 100000]이다.
3. 입력되는 k 값의 크기는 [1, N]이다.

예시)
입력: input_data.txt
3
4 2
10
20
30
40

3 3
50
60
70

7 4
4
5
6
7
6
8
2

출력: output_data.txt
20
70
6

정답은 expected_data.txt로 주어짐
결과는 output_data.txt file로 출력해야 함

주어진 함수에는 프로그래밍 언어에서 제공하는 정렬 기법을 이용해 선택 결과 값을 구하고 있음
선택 함수를 새로 구현하시오. 프로그래밍 언어에서 제공되는 정렬 함수, sort()등을 이용하면 안됨
-----------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int comp(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b) return  1;
    if (*(int*)a < *(int*)b) return -1;
    return 0;
}
int partition(int* A, int p, int r) {
    int x = A[r];
    int i = p - 1;

    int temp;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            //SWAP(A[++i], A[j], temp);
            temp = A[j];
            A[j] = A[++i];
            A[i] = temp;
        }
    }

    temp = A[r];
    A[r] = A[i + 1];
    A[i + 1] = temp;

    //printf("i is : %d\n", i + 1);
    return i + 1;

   
}
int select_algorithm(int* A, int p,int r, int i)
{
    // remove this before editing
    //qsort(nums, N, sizeof(int), comp);
    //return(nums[k - 1]);

     //i=key value
    //N= nums's size
    if (p == r) {
        return A[p];
    }

    int q = partition(A, p, r);
    int k = q - p + 1;//원소의 개수
    if (i < k) {
        return select_algorithm(A, p, q - 1, i);

    }
    else if (i == k) {
        return A[q];
    }
    else {
        return  select_algorithm(A, q + 1, r, i - k);
    }
    //return A[k-1];
}


void compare_output(char*, char*);

int main()
{
    // DO NOT EDIT main() function

    int M, N, k, i, j;
    int kth_element;
    int nums[100000];
    clock_t start_time, end_time;

    FILE* input;
    FILE* output;

    input = fopen("input_data.txt", "r");          // input data
    output = fopen("output_data.txt", "w");        // your answer

    fscanf(input, "%i", &M);
    start_time = clock();
    for (i = 0; i < M; i++) {
        fscanf(input, "%i %i", &N, &k);
        for (j = 0; j < N; j++) {
            fscanf(input, "%i", &nums[j]);
        }

        kth_element = select_algorithm(nums, 0,N-1, k);
        fprintf(output, "%d\n", kth_element);
    }
    end_time = clock();

    // Checking answers
    fclose(input);
    fclose(output);
    printf("Elapsed time: %.2f seconds. ", ((double)(end_time - start_time)) / CLOCKS_PER_SEC);
    compare_output("output_data.txt", "expected_data.txt");
}

void compare_output(char* file1, char* file2)
{
    FILE* f1 = fopen(file1, "r");
    FILE* f2 = fopen(file2, "r");
    char line1[10000], line2[10000];
    char* s1, * s2;
    int i = 1;
    int success = 1;

    while (!feof(f1) && !feof(f2)) {
        fgets(line1, 10000, f1);
        fgets(line2, 10000, f2);
        s1 = line1;
        s2 = line2;
        while (*s1 == ' ') s1++;
        while (s1[strlen(s1) - 1] == ' ' || s1[strlen(s1) - 1] == '\n' || s1[strlen(s1) - 1] == '\r') s1[strlen(s1) - 1] = '\0';
        while (*s2 == ' ') s2++;
        while (s2[strlen(s2) - 1] == ' ' || s2[strlen(s2) - 1] == '\n' || s2[strlen(s2) - 1] == '\r') s2[strlen(s2) - 1] = '\0';
        if (strcmp(s1, s2)) {
            printf("[%i] Wrong answer: Yours=\'%s\', Expected=\'%s\'\n", i, s1, s2);
            success = 0;
            break;
        }
        i++;
    }
    if (feof(f2) && success) printf("Success!\n");
    fclose(f1);
    fclose(f2);
}
