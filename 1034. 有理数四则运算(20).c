#include <stdio.h>
long long gcd(long long a,long long b);
void print(long long a,long long b);
long long abs1(long long a);
int main(){
	long long a1,b1,a2,b2,a3,b3;
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
	//加法 
	a3=a1*b2+a2*b1;
	b3=b1*b2;
	print(a1,b1); 
	printf(" + ");//前后加空格 
	print(a2,b2);
	printf(" = ");
	print(a3,b3);
	printf("\n"); 
	//减法
	a3=a1*b2-a2*b1;
	print(a1,b1);
	printf(" - ");
	print(a2,b2);
	printf(" = ");
	print(a3,b3);
	printf("\n");
	//乘法
	a3=a1*a2;
	print(a1,b1);
	printf(" * ");
	print(a2,b2);
	printf(" = ");
	print(a3,b3);
	printf("\n");
	//除法
	a3=a1*b2;
	b3=b1*a2;
	if(b3<0){
		a3=0-a3;
		b3=0-b3;
	}
	print(a1,b1);
	printf(" / ");
	print(a2,b2);
	printf(" = ");
	print(a3,b3);
	printf("\n");
	
	return 0;
}
void print(long long a,long long b){
	if(b==0){
		printf("Inf");
	}else{
		long long gt,c,d;
		gt=gcd(a,b);
		a/=gt;
		b/=gt;
		c=a/b;
		d=a%b;
		if(a<0){
			printf("(");
		}
		if(a==0){
			printf("0");
		}else if(c==0){
			printf("%lld/%lld",a,b);
		}else if(d==0){
			printf("%lld",c);
		}else{
			d=abs1(d);
			printf("%lld %lld/%lld",c,d,b);
		}
		
		if(a<0){
			printf(")");
		}
	}
}


long long gcd(long long a,long long b){
	a=abs1(a);
	b=abs1(b);
	if(b!=0){
		return gcd(b,a%b);//一定要return 
	}else{
		return a;
	}
}
//abs函数返回值类型和参数类型都是int所以不能直接调用abs函数 
long long abs1(long long a){
	if(a<0){
		a=0-a;
	}
	return a;
}
