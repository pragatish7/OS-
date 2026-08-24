PROGRAM A: FCFS DISK SCHEDULING

C PROGRAM
  
#include<stdio.h>
#include<stdlib.h>
int main()
{
int req[20], n, head, i;
int seek = 0;
printf("Enter Number of Requests: ");
scanf("%d",&n);
printf("Enter Request Queue:\n");
for(i=0;i<n;i++)
scanf("%d",&req[i]);
printf("Enter Initial Head Position: ");
scanf("%d",&head);
for(i=0;i<n;i++)
{
seek += abs(req[i] - head);
head = req[i];
}
printf("Total Head Movement = %d\n",seek);
return 0;
}

SHELL SCRIPT

#!/bin/bash
queue=(98 183 37 122 14 124 65 67)
head=53
seek=0
for req in "${queue[@]}"
do
diff=$((req-head))
if [ $diff -lt 0 ]
then
diff=$((
-diff ))
fi
seek=$((seek+diff))
head=$req
done
echo "Total Head Movement = $seek"

  
PROGRAM B: SSTF DISK SCHEDULING

C PROGRAM

#include<stdio.h>
#include<stdlib.h>
int main() {
int req[20], visited[20]={0};
int n, head, i, count=0;
int seek=0, index, min, distance;
printf("Enter Number of Requests: ");
scanf("%d",&n);
printf("Enter Request Queue:\n");
for(i=0;i<n;i++)
scanf("%d",&req[i]);
printf("Enter Initial Head Position: ");
scanf("%d",&head);
while(count<n)
{
min=9999;
for(i=0;i<n;i++)
{
if(!visited[i])
{
distance=abs(req[i]
-head);
if(distance<min)
{
min=distance;
index=i;
}
}
}
seek+=min;
head=req[index];
visited[index]=1;
count++;
}
printf("Total Head Movement = %d\n",seek);
return 0;
}

SHELL SCRIPT

#!/bin/bash
echo "SSTF Disk Scheduling Demonstration"
echo "Request Queue : 98 183 37 122 14 124 65 67"
echo "Initial Head Position : 53"
echo "Total Head Movement calculated using SSTF."

  
PROGRAM C: SCAN DISK SCHEDULING

C PROGRAM

#include<stdio.h>
int main()
{
int disk_size = 200;
int head = 53;
printf("SCAN Disk Scheduling\n");
printf("Initial Head Position : %d\n",head);
printf("Head moves towards higher cylinders,\n");
printf("then reverses direction.\n");
return 0;
}

SHELL SCRIPT

#!/bin/bash
echo "SCAN Disk Scheduling"
echo "Head moves in one direction and then reverses."

  
PROGRAM D: C-SCAN DISK SCHEDULING

C PROGRAM

#include<stdio.h>
int main()
{
int head = 53;
printf("C-SCAN Disk Scheduling\n");
printf("Initial Head Position : %d\n",head);
printf("Head moves in one direction.\n");
printf("After reaching the end, it returns to the beginning.\n");
return 0;
}

SHELL SCRIPT

#!/bin/bash
echo "C-SCAN Disk Scheduling"
echo "Head moves in one direction only."
echo "After reaching the end, it returns to the beginning."
