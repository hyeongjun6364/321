/*-----------------------------------------------------------------------
Select ����. ������ ��� �����ð� ���� �˰����� �����Ͻÿ�.

�Է�: input_data.txt
�� �Է��� ������ ���� �����Ǿ� �ִ�.
�Է� file ����
M     // ������ ���� �Է� ���̽��� ��
N k  // ù ��° ����Ʈ�� ����(N)�� k��° ���� ���� ���ϴ� �Է�
n1    // ������ ���� ù ��° �� ����Ʈ
n2
n3
...
nN
(����)
N k  // �� ��° ����Ʈ�� ����(N)�� k��° ���� ���� ���ϴ� �Է�
n1    // ������ ���� �� ��° �� ����Ʈ
n2
n3
...
nN

����:
1. ������ ���� �Է� ���̽��� ���� 100�̴�.
2. �ԷµǴ� ���� ����(N)�� [1, 100000]�̴�.
3. �ԷµǴ� k ���� ũ��� [1, N]�̴�.

����)
�Է�: input_data.txt
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

���: output_data.txt
20
70
6

������ expected_data.txt�� �־���
����� output_data.txt file�� ����ؾ� ��

�־��� �Լ����� ���α׷��� ���� �����ϴ� ���� ����� �̿��� ���� ��� ���� ���ϰ� ����
���� �Լ��� ���� �����Ͻÿ�. ���α׷��� ���� �����Ǵ� ���� �Լ�, sort()���� �̿��ϸ� �ȵ�
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
    int k = q - p + 1;//������ ����
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
