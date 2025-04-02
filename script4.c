//Final Project - Task 4
//Ali Abdulla A00786, Mariam Hussein A00039
//American University of Bahrain
//COSC372L - Operating Systems Lab
//December 20, 2022

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
void *printEvenNumbers(void*);
void *printAllNumbers(void*);

//Global Variables
const int MAX = 14;
int count = 1;
int thread1Print = 0, thread2Print = 0;
int thread1Increment = 1, thread2Increment = 2;
pthread_mutex_t thr;
pthread_cond_t cond;

//Main Function
int main()
{
  pthread_t thread1;
  pthread_t thread2;
  pthread_mutex_init(&thr, 0);
  pthread_cond_init(&cond, 0);
  pthread_create(&thread1, 0, &printEvenNumbers, NULL);
  pthread_create(&thread2, 0, &printAllNumbers, NULL);
  pthread_join(thread1, 0);
  pthread_join(thread2, 0);
  pthread_mutex_destroy(&thr);
  pthread_cond_destroy(&cond);
  return 0;
}

//Prints all integer numbers from 1 to until the counter is >= to MAX
//This function is to be used with the function printEvenNumbers
void *printAllNumbers(void *arg)
{
  while(count < MAX)
  {
    pthread_mutex_lock(&thr);
    while(count % 2 != 1)
      pthread_cond_wait(&cond, &thr);
    printf("%d -> ", thread1Print + thread1Increment);
    thread1Print = thread1Print + thread1Increment;
    count++;
    pthread_mutex_unlock(&thr);
    pthread_cond_signal(&cond);
  }
  pthread_exit(0);
}

//Prints all even integer numbers from 2 to until the counter is >= to MAX
//This function is to be used with the function printAllNumbers
void *printEvenNumbers(void *arg)
{
  while(count < MAX) 
  {
    pthread_mutex_lock(&thr);
    while(count % 2 != 0) 
      pthread_cond_wait(&cond, &thr);
      
    //Prevents the final number from printing an arrow
    if(count != MAX)
      printf("%d -> ", thread2Print + thread2Increment);
    else
      printf("%d\n", thread2Print + thread2Increment);
    
    thread2Print = thread2Print + thread2Increment;
    count++;
    pthread_mutex_unlock(&thr);
    pthread_cond_signal(&cond);
  }
  pthread_exit(0);
}