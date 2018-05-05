#include<stdio.h>
#include<stdbool.h>
struct student 
{
	bool all_three;
	bool pen ;
	bool paper;
	bool question_paper;
	
};
int main()
{
	struct student stu[3];
	stu[0].pen=1;				
	stu[1].paper=1;				
	stu[2].question_paper=1;
	int ch1,ch2;int i=0;
	printf("\nMenu: \n\t1.pen\t\t2.paper\t\t3.question paper \n\n");				
	while(stu[0].all_three==0||stu[1].all_three==0||stu[2].all_three==0)
	{
		
		if(i==0){printf("\nEnter the two things which teacher is placing on the shared table :- \n\tch1= ");}
		else{printf("\nEnter the next two things which teacher is placing on the shared table :- \n\tch1= ");}
		scanf("%d",&ch1);
		
		printf("\tch2= ");
		scanf("%d",&ch2);
		if((ch1==1 && ch2==2||ch2==1 && ch1==2) && stu[2].all_three==0)
		{
			stu[2].all_three=1;
			printf("Student 'THREE(3)' has completed the task\n");
			i++;
		}
		else if((ch1==2 && ch2==3||ch2==2 && ch1==3) &&stu[0].all_three==0)
		{
			stu[0].all_three=1;
			printf("Student 'ONE(1)' has completed the task\n");
			i++;
		}
		else if((ch1==1 && ch2==3||ch2==1 && ch1==3) &&stu[1].all_three==0)
		{
			stu[1].all_three=1;
			printf("Student 'SECOND(2)' has completed the task\n");
			i++;
		}
		else
		{
			printf("\t----Error---\n try again\n");

			//printf("These things you already shared and the reguarding student already compleated the task \n OR Wrong choices ");
		}
		
	}
	printf("All students have completed the task");
	return 0;
}
