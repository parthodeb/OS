#include<stdio.h>

double mstons(double a)
{
	a=a*1000000;
	return a;
}

double mstomis(double b)
{
	b=b*1000;
	return b;
}

int main()
{
double result;
double SPF;
double RPNM;
double MAT;
double EAT;
double c;
double d;
double p;


printf("Enter the value of Replace Page Not Modified(RPNM) in millisecond:\n");
scanf("%lf",&RPNM);
RPNM=mstons(RPNM);

printf("Enter the Percentage of Page Replaced Modified TIME(POPRMT) :\n");
scanf("%le",&c);
c=c*0.01;
RPNM=c*RPNM;

printf("Enter the value of Service Page Fault (SPF) in millisecond:\n");
scanf("%lf",&SPF);
SPF=mstons(SPF);

d=1-c;
SPF=d*SPF;

printf("Enter the value of Memory Access Time(MAT) in nanosecond:\n");
scanf("%lf",&MAT);

printf("Enter the value of Effective Address Time(EAT) in nanosecond:\n");
scanf("%lf",&EAT);
if(EAT>200)
{
printf("OOPS!!!\nValue of Effective Access Time is More Than 200\nTry Again\n");
}
else{
p=(EAT-MAT)/(RPNM+SPF-MAT);
p=p*100;
printf("%lf%\n",p);
return 0;
}



}