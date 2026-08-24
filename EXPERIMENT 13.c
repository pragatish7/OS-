PROGRAM A: SEQUENTIAL FILE ORGANIZATION

C PROGRAM

#include <stdio.h>
struct student
{
int regno;
char name[20];
};
int main()
{
FILE *fp;
struct student s;
fp = fopen("student.dat", "w");
printf("Enter Register Number: ");
scanf("%d", &s.regno);
printf("Enter Name: ");
scanf("%s", s.name);
fprintf(fp, "%d %s\n", s.regno, s.name);
fclose(fp);
fp = fopen("student.dat", "r");
fscanf(fp, "%d %s", &s.regno, s.name);
printf("\nRecord Details\n");
printf("Register Number : %d\n", s.regno);
printf("Name : %s\n", s.name);
fclose(fp);
return 0;
}

SHELL SCRIPT

#!/bin/bash
echo "Enter Register Number:"
read regno
echo "Enter Name:"
read name
echo "$regno $name" > student.txt
echo "Contents of File"
cat student.txt

  
PROGRAM B: DIRECT (RANDOM) FILE ORGANIZATION

C PROGRAM

#include <stdio.h>
struct student
{
int regno;
char name[20];
};
int main()
{
FILE *fp;
struct student s;
fp = fopen("random.dat", "wb+");
printf("Enter Register Number: ");
scanf("%d", &s.regno);
printf("Enter Name: ");
scanf("%s", s.name);
fwrite(&s, sizeof(s), 1, fp);
rewind(fp);
fread(&s, sizeof(s), 1, fp);
printf("\nRecord Found\n");
printf("Reg No : %d\n", s.regno);
printf("Name : %s\n", s.name);
fclose(fp);
return 0;
}

SHELL SCRIPT

#!/bin/bash
echo "Enter Record:"
read rec
echo "$rec" > random.txt
echo "Random Access Record"
sed -n '1p' random.txt

  
PROGRAM C: INDEXED FILE ORGANIZATION

C PROGRAM

#include <stdio.h>
struct student
{
int regno;
char name[20];
};
int main()
{
struct student s[3];
int key, i;
printf("Enter 3 Student Records\n");
for(i=0;i<3;i++)
{
scanf("%d %s",&s[i].regno,s[i].name);
}
printf("Enter Register Number to Search: ");
scanf("%d",&key);
for(i=0;i<3;i++)
{
if(s[i].regno==key)
{
printf("\nRecord Found\n");
printf("Reg No : %d\n",s[i].regno);
printf("Name : %s\n",s[i].name);
return 0;
}
}
printf("Record Not Found\n");
return 0;
}


SHELL SCRIPT

#!/bin/bash
echo "Enter Student Records"
echo "101 Arun" > index.txt
echo "102 Kumar" >> index.txt
echo "103 Ravi" >> index.txt
echo "Enter Register Number to Search:"
read key
grep "^$key" index.txt
  
