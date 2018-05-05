#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int s1[5], s2[5],s3[5],t[10];
void heldResources(int r);
void heldResourcesStudent(int p);
int main()
{
	printf("\t --Welcome--");
	printf("\nCodes For Resources :-     '1'-for Pen\t'2'- for paper\t'3'-for QuestionPaper\n");
	printf("\nEnter the Resources held by student 1:- \t");
	scanf("%d",&s1[0]);
	heldResourcesStudent(1);
	heldResources(s1[0]);
	printf("\nEnter the Resources held by student 2:- \t");
	scanf("%d",&s2[0]);
	heldResourcesStudent(2);
	heldResources(s2[0]);
	printf("\nEnter the Resources held by student 3:- \t");
	scanf("%d",&s3[0]);
	heldResourcesStudent(3);
	heldResources(s3[0]);
}
void heldResources(int r)
{
	switch(r)
	{
		case 1:
			printf("Held Resources : Pen\n");
			break;
		case 2:
			printf("Held Resources : Paper\n");
			break;
		case 3:
			printf("Held Resources : Question Paper\n");
			break;
		default:
			printf("\n\t end student 3");			
			break;
	}
}

void heldResourcesStudent(int p)
{
	switch(p)
	{
		case 1:
			printf("\nStudent Process 1:-\n");	
			
			break;
		case 2:
			printf("\nStudent Process 2:-\n");
			
			break;
		case 3:
			printf("\nStudent Process 3:-\n");
			
			break;
	}
}


void teacher()
{

}