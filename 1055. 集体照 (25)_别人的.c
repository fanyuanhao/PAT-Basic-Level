#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//keypoint: imitate the arithmetic process, if array a[] is a decreased order, so 
// for every line, a[m/2] which is the biggest in this line is in the 'm/2' postion.
// and the odd label-case data is placed in the left of a[m/2].
// namely: analogue: for a 5 numbers, the output order is a[3], a[1], a[0], a[2], a[4].
//Notice: if Amy's height equals Tim, Amy is in the front;

typedef struct students
{
	char name[9];
	int height;
}student;
int cmpdec(const void *a, const void *b);
void nameprintf(student *s, int m);

int main()
{
	int n, row, i;
	scanf("%d %d", &n, &row);
	student *ar = (student *)malloc(sizeof(student)* n);
	int k = n / row;

	for (i = 0; i < n; i++)
		scanf("%s %d", ar[i].name, &ar[i].height);

	qsort(ar, n, sizeof(ar[0]), cmpdec);
	int rest = n % row;
	
	for (i = 0; i < n; i++)
		printf("%s %d\n", ar[i].name, &ar[i].height);	
	
	if (rest == 0)	// no surplus data;
	{
		for (i = 0; i < n; i += k)
			nameprintf(ar + i, k);
	}
	else
	{
		nameprintf(ar, (k+rest));		// print the most line's data first;
		for (i = (k + rest); i < n; i += k)
			nameprintf(ar + i, k);
	}
	free(ar);

	return 0;
}

int cmpdec(const void *a, const void *b)	// compare function, qsort() need it;
{
	student *c = (student *)a;
	student *d = (student *)b;

	if (c->height != d->height)				//order by height;
		return((d->height) - (c->height));
	else
		return(strcmp(c->name, d->name));	//order by the alphabetic if height is equal;
}

void nameprintf(student *s, int m)		//print each line;
{
	int i;
	int start = (m % 2 == 0) ? (m - 1) : (m - 2);	// find the first label-case, look at my keypoint if you are confused;
	for (i = start; i > 0; i -= 2)		// printf the odd label-case data;
		printf("%s ", s[i].name);
	for (i = 0; i < m; i += 2)			// printf the even;
	{
		printf("%s", s[i].name);
		if (i == m - 1 || i == m - 2)
			printf("\n");
		else
			printf(" ");
	}
}
