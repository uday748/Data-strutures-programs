#include<stdio.h>
struct student
{
	char name[20];
	int m1,m2,m3;
	float total,avg;
	
}s;
int main()
{
	int n,i;
	printf("Enter how many students");
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the name,enter the marks of three subjects %d\n",i+1);
		scanf("%s%d%d%d\n",&s[i].name,&s[i].m1,&s[i].m2,&s[i].m3);
		
	}for(i=0;i<n;i++)
	{
		s[i].total = s[i].m1 + s[i].m2 + s[i].m3;
		s[i].avg = s[i].total/3.0;
		printf("Total and average marks of the student %d=%.2f %.2f",i+1,s[i].total,s[i].avg);
	}
}
