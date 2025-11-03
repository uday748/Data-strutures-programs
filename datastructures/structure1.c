#include<stdio.h>
struct student
{
	char name[20];
	int rno;
    struct dob
    {
    	int day,month,year;
	}d;
}s;
int main()
{
	printf("Enter name Roll NO and date of birth(day month year)\n");
	scanf("%s%d%d%d%d",&s.name,&s.rno,&s.d.day,&s.d.month,&s.d.year);
	printf("name=%s\nrno=%d\nDate of birth = %d - %d - %d\n",s.name,s.rno,s.d.day,s.d.month,s.d.year);
	return 0;
}
