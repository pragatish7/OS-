PROGRAM A: SEQUENTIAL FILE ALLOCATION

C PROGRAM

#include <stdio.h>
int main()
{
int start, length, i;
printf("Enter Starting Block: ");
scanf("%d", &start);
printf("Enter File Length (Number of Blocks): ");
scanf("%d", &length);
printf("\nAllocated Blocks:\n");
for(i = 0; i < length; i++)
{
printf("%d ", start + i);
}
printf("\n");
return 0;
}

SHELL SCRIPT

#!/bin/bash
echo "Enter Starting Block:"
read start
echo "Enter File Length:"
read length
echo "Allocated Blocks:"
for ((i=0;i<length;i++))
do
echo -n "$((start+i)) "
done
echo



PROGRAM B: INDEXED FILE ALLOCATION

C PROGRAM

#include <stdio.h>
int main()
{
int n, indexBlock, blocks[20], i;
printf("Enter Index Block: ");
scanf("%d", &indexBlock);
printf("Enter Number of Blocks: ");
scanf("%d", &n);
printf("Enter Block Numbers:\n");
for(i = 0; i < n; i++)
{
scanf("%d", &blocks[i]);
}
printf("\nIndex Block : %d\n", indexBlock);
printf("Allocated Blocks : ");
for(i = 0; i < n; i++)
{
printf("%d ", blocks[i]);
}
printf("\n");
return 0;
}

SHELL SCRIPT

#!/bin/bash
echo "Enter Index Block:"
read index
echo "Enter Number of Blocks:"
read n
echo "Enter Block Numbers:"
for ((i=0;i<n;i++))
do
read block[$i]
done
echo "Index Block : $index"
echo -n "Allocated Blocks : "
for ((i=0;i<n;i++))
do
echo -n "${block[$i]} "
done
echo


PROGRAM C: LINKED FILE ALLOCATION

C PROGRAM

#include <stdio.h>
int main()
{
int n, blocks[20], i;
printf("Enter Number of Blocks: ");
scanf("%d", &n);
printf("Enter Block Numbers:\n");
for(i = 0; i < n; i++)
{
scanf("%d", &blocks[i]);
}
printf("\nLinked Allocation:\n");
for(i = 0; i < n - 1; i++)
{
printf("%d --> ", blocks[i]);
}
printf("%d --> NULL\n", blocks[n - 1]);
return 0;
}

SHELL SCRIPT
#!/bin/bash
echo "Enter Number of Blocks:"
read n
echo "Enter Block Numbers:"
for ((i=0;i<n;i++))
do
read block[$i]
done
echo "Linked Allocation:"
for ((i=0;i<n-1;i++))
do
echo -n "${block[$i]} --> "
done
echo "${block[$((n-1))]} --> NULL"
