PROGRAM 1: IPC USING PIPE
  
C PROGRAM

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
int main()
{
int fd[2];
pid_t pid;
char message[] = "Hello from Child Process";
char buffer[100];
pipe(fd);
pid = fork();
if(pid == 0)
{
close(fd[0]);
write(fd[1], message, strlen(message)+1);
close(fd[1]);
exit(0);
}
else
{
wait(NULL);
close(fd[1]);
read(fd[0], buffer, sizeof(buffer));
printf("Message received from child: %s\n", buffer);
close(fd[0]);
}
return 0;
}

SHELL SCRIPT

#!/bin/bash
echo "Hello from Child Process" | cat
Alternative Shell Script
#!/bin/bash
(
echo "Message from Child Process"
) | while read msg
do
echo "Parent Received: $msg"
done

