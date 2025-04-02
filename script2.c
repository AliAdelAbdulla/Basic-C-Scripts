//Final Project - Task 2
//Ali Abdulla A00786, Mariam Hussein A00039
//American University of Bahrain
//COSC372L - Operating Systems Lab
//December 20, 2022
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

int main(void)
{
    // Variables to get the system's current time
    time_t systemCurrentTime = time(NULL);
    struct tm *localTime = localtime(&systemCurrentTime);

    if (localTime == NULL) {
        perror("localtime");
        return 1;
    }
    
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        // Child process prints the day of the week
        printf("Today's Day of the Week is: %.3s\n", asctime(localTime));
    }
    else {
        // Parent process prints the full date
        printf("Today's Date : %02d %s %d\n", localTime->tm_mday, 
               asctime(localTime) + 4, 1900 + localTime->tm_year);
    }
    
    return 0;
}
