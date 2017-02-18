#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//function 'scanf' and 'sprintf' to deal with the strings;


int main()
{
	int n, i, len, cnt, flag, j;
	float sum, t;
	char te[105], test[105];
	sum = 0;
	cnt = 0;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%s", test);
		len = strlen(test);
		flag = 0;
		sscanf(test, "%f", &t);	//translate string to a float t;
		sprintf(te, "%.2f", t);		//translate t with two digit fraction to a string 'te';

		for (j = 0; j < len; j++)	//if te equals test, it means it's valid;
		{
			if (test[j] != te[j])
			{
				flag = 1;
				break;
			}
		}

		if (flag == 1 || t > 1000 || t < -1000)
			printf("ERROR: %s is not a legal number\n", test);
		else
		{
			sum += t;
			cnt++;
		}
	}

	if (cnt == 0)
		printf("The average of 0 numbers is Undefined\n");
	else if (cnt == 1)
		printf("The average of %d number is %.2f\n", cnt, sum);
	else
		printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);

	return 0;
}
