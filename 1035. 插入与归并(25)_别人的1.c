#include <stdio.h>
#include <stdlib.h>

//thought: judge the insertion sort first, if not, check merge sort;

int cmpinc(const void *a, const void *b);
void mergesort(int *a, int *b, int n);

int main()
{
	int n, i, s = 1;
	scanf("%d", &n);
	int *primitive = (int *)malloc(sizeof(int) * n);
	int *process = (int *)malloc(sizeof(int) * n);
	
	for (i = 0; i < n; i++)
		scanf("%d", &primitive[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &process[i]);
	for (i = 0; process[i] <= process[i+1]; i++);		// it is ordered before process[t];
	int t = i + 1;
	
	for (i = t; process[i] == primitive[i] && i < n; i++);	// judge if the rest is same from process[t];
	if (i == n)
	{
		printf("Insertion Sort\n");
		qsort(process, t + 1, sizeof(process[0]), cmpinc);
		for (i = 0; i < n - 1; i++)
			printf("%d ", process[i]);
		printf("%d\n", process[n - 1]);
	}
	else
	{
		printf("Merge Sort\n");
		mergesort(primitive, process, n);

		for (i = 0; i < n - 1; i++)
			printf("%d ", primitive[i]);
		printf("%d\n", primitive[n - 1]);
	}

	return 0;
}

int cmpinc(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

void mergesort(int *a, int *b, int n)				// here I wrote the merge algrithm, you can use qsort();
{
	int i, j, k = 0, flag = 0;
	int left_min, left_max, right_min, right_max;
	int *temp = (int *)malloc(sizeof(int)* n);

	for (i = 1; i < n && flag == 0; i *= 2)
	{
		for (j = 0; j < n; j++)						// check which step is equal, if step 'i' is right, so just merge once.
		{
			flag = 1;
			if (a[j] != b[j])
			{
				flag = 0;
				break;
			}
		}
		for (left_min = 0; left_min < n - i; left_min = right_max)		//merge algorithm, if puzzled, please learn 'Merge' algorithm first;
		{
			left_max = right_min = left_min + i;
			right_max = right_min + i;

			if (right_max > n)
				right_max = n;

			while (left_min < left_max && right_min < right_max)
			{
				if (a[left_min] < a[right_min])
					temp[k++] = a[left_min++];
				else
					temp[k++] = a[right_min++];
			}

			while (left_min < left_max)
				a[--right_min] = a[--left_max];

			while (k > 0)
				a[--right_min] = temp[--k];
		}
	}
	
	free(temp);
}
