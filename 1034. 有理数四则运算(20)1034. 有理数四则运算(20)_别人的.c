#include <stdio.h>
#include <math.h>
//keypoint:be patient;
// function: gcd(), get two number's the greatest common divisor;
// abs1(): get the positive number;
// use long long int, or testpoint 1/2 can not pass;

long long gcd(long long a, long long b);
void printfraction(long long a, long long b);
long long abs1(long long a);

int main()
{
	long long a1, a2, b1, b2, a3, b3;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	
	a3 = a1*b2 + a2*b1;		// a * b may exceed the greatest int number , so use long long int;
	b3 = b1*b2;

	printfraction(a1, b1);
	printf(" + ");
	printfraction(a2, b2);
	printf(" = ");
	printfraction(a3, b3);
	printf("\n");

	long long m1 = a1*b2 - a2*b1;

	printfraction(a1, b1);
	printf(" - ");
	printfraction(a2, b2);
	printf(" = ");
	printfraction(m1, b3);
	printf("\n");

	long long mul1 = a1 * a2;

	printfraction(a1, b1);
	printf(" * ");
	printfraction(a2, b2);
	printf(" = ");
	printfraction(mul1, b3);
	printf("\n");

	long long div1 = a1 * b2;
	long long div2 = b1 * a2;
	if (div2 < 0)				// assure div2 is positive;
	{
		div1 = 0 - div1;
		div2 = abs1(div2);
	}

	printfraction(a1, b1);
	printf(" / ");
	printfraction(a2, b2);
	printf(" = ");
	printfraction(div1, div2);
	printf("\n");

	return 0;
}

long long gcd(long long a, long long b)		//this method should be remembered;
{
	a = abs1(a);
	b = abs1(b);
	if (b != 0)
		return gcd(b, a%b);
	else
		return a;
}

void printfraction(long long a, long long b)
{

	if (b == 0)
		printf("Inf");

	if (b != 0)
	{
		long long c, gt, d;
		gt = gcd(a, b);
		a /= gt;
		b /= gt;
		d = a % b;
		c = a / b;

		if (a < 0)
			printf("(");

		if (a == 0)
			printf("0");
		else if (d == 0)
			printf("%lld", c);
		else if (c == 0)
			printf("%lld/%lld", a, b);
		else
			printf("%lld %lld/%lld", c, abs1(d), b);

		if (a < 0)
			printf(")");
	}
}

long long abs1(long long a)
{
	if (a < 0)
		a = 0 - a;
	return a;
}
