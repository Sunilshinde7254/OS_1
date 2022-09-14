 #include<stdio.h>

/* Declaration of structure */
struct student
{

 int roll;
 char name[30];
 char sex;
 float marks;
}s;

int main()
{
 /* Declaration of array of structure */
 struct student s[2];
 float max;
 int i,n;
 
 printf("Enter n:\n");
 scanf("%d",&n);
 for(i=0;i< 5;i++)
 {
  printf("Enter name, roll and marks of student:\n");
  scanf("%s%d%f",s[i].name, &s[i].roll, &s[i].marks);
 }
 max = s[0].marks;
 for(i=0;i<2; i++)
  {
  	if(max > s[i].marks)
  	{
	  max = s[i].marks;
    }
}

 printf("Student obtaing highest marks is:\n");
 //printf("Name: %s\n", name);
 //printf("Roll: %d\n", roll);
 printf("Marks: %0.2f\n", max);
 return 0;
}