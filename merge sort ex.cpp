#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
int sorted[MAX];
void merge(int* nums, int left, int m,int right) {
	int i = left;
	int j = m + 1;
	int k = left;

	while (i <= m && j <= right) {
		if (nums[i] < nums[j]) {
			sorted[k] = nums[i];
			i++;
			k++;
		}
		else {
			sorted[k] = nums[j];
			j++;
			k++;
		}
	}
	if (i > m ) {
		for (int x = j; x <= right; x++) {
			sorted[k] = nums[x];
			k++;
		}
	}
	else if (j > right) {
		for (int x =i; x <= right; x++) {
			sorted[k] = nums[x];
			k++;
		}
	}
	for (int x = left; x <= right; x++) {
		nums[x] = sorted[x];
	}
	
}
void mergesort(int *nums,int N,int left, int right) {
	
	if (left < right) {
		int m = left + right / 2;
		mergesort(nums, N, left, m);
		mergesort(nums, N, m + 1, right);
		merge(nums, left, m,right);
	}
	
}
int main() {
	int nums[] = { 3,13,654,765,2,34,56,2 };
	int N=sizeof(nums) / sizeof(int);
	mergesort(nums, N, 0, N - 1);
	for (int i = 0; i < N; i++) {
		printf("%d", sorted[i]);
	}
}