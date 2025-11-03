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
	
	for(i  = 0; i<n;i++)
	{
		printf("Enter name,3 sub marks of student %d\n",i+1);
		scanf("%s%d%d%d",&s[i].name,&s[i].m1,&s[i].m2,&s[i].m3);
	}
	for(i=0;i<n;i++)
	{
		s[i].total=s[i].m1+s[i].m2+s[i].m3;
		s[i].avg=s[i].total/3.0;
		
		printf("Total and avg marks of the student %d=%.2f,%.2f\n",i+1,s[i].total,s[i].avg);
		return 0;
	}
}
