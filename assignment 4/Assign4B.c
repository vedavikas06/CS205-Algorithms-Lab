#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<math.h>

#define MAX(a,b) (((a)>(b))?(a):(b))


long long binarydec(long long num){
long long decimal_val=0,base=1,rem;
while (num > 0)
    {
        rem = num % 10;
        decimal_val = decimal_val + rem * base;
        num = num / 10 ;
        base = base * 2;
    }
    return decimal_val;
}

int leng(long long a){
	if(a!=0){
	
	int nDig = floor(log10(abs(a))) + 1;
	return nDig;
	
}else{
	return 1;
}
	
	
}

void split(long long *a,long long *b,int ind,long long x){
	
	*a = x/pow(10,ind);
	*b = x%(long long)pow(10,ind);	
}




long long karat(long long x,long long y){
	
	if(x<10||y<10){
		return x*y;
	}
	int rem = MAX(leng(x),leng(y))/2;
	
	long long a,b,c,d;
	
	split(&a,&b,rem,x);
	
	split(&c,&d,rem,y);
	
	long long ac,bd;
	
	ac = karat(a,c);
	
	bd = karat(b,d);
	
	
	return ac*pow(10,2*rem)+(karat(a+b,c+d)-ac-bd)*pow(10,rem)+bd;
	
}




int main(){
 
 
 long long n1,n2;
 
 
 scanf("%lld",&n1);

 scanf("%lld",&n2);
 


printf("%lld\n",binarydec(n1)*binarydec(n2));
printf("%lld\n",karat(binarydec(n1),binarydec(n2)));





return 0;



}

























