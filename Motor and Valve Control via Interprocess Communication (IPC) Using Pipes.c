//Motor and Valve Control via Interprocess Communication (IPC) Using Pipes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int pipe1fd[2], pipe2fd[2];
    pid_t motor_pid,valve_pid;
    char Motor_command[100], Valve_command[100];
    
    
    if(pipe(pipe1fd)==-1){
        perror("Pipe1 Failed\n");
        return 1;
    }
    
    if(pipe(pipe2fd)==-1){
        perror("Pipe2 Failed\n");
        return 1;
    }
    motor_pid=fork();
    if(motor_pid == 0)
    {
        close(pipe1fd[1]);
        read(pipe1fd[0], Motor_command, sizeof(Motor_command));
        if(strcmp(Motor_command,"MOTOR_FORWARD")==0)
            printf("Motor Process: Forward Rotation\n");
        else if(strcmp(Motor_command,"MOTOR_BACKWARD")==0)
            printf("Motor Process: Backward Rotation\n");
        else
            printf("Motor Process: Invalid command\n");
        exit(0);
    }
    else
    {
        valve_pid=fork();
        if(valve_pid == 0)
        {
            close(pipe2fd[1]);
            read(pipe2fd[0], Valve_command, sizeof(Valve_command));
            if(strcmp(Valve_command,"VALVE_ON")==0)
                printf("Valve Process: Valve Opened\n");
            else
            {
                printf("Valve Process: Invalid command\n");
            }
        }
        else
        {
            close(pipe1fd[0]);
            close(pipe2fd[0]);
            
            printf("State Machine: Enter the Command (MOTOR_BACKWARD/MOTOR_BACKWARD) : ");
            scanf("%s",Motor_command);
            printf("State Machine: Enter the Command (VALVE_ON) : ");
            scanf("%s",Valve_command);
            
            write(pipe1fd[1],Motor_command,sizeof(Motor_command));
            write(pipe2fd[1],Valve_command,sizeof(Valve_command));
            
            wait(NULL);
            wait(NULL);
        }
    }
    return 0;
}
