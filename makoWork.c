/*

Universidad Autonoma del Estado de Morelos

Rodrigo Canalizo Macías  

Estructura de Datos

Profesor: Dr. Bruno Lara 

22 / 06 / 2021

*/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

// Macros
//  - INT_MIN defines the minimum value for an int 
#define QUEUE_EMPTY INT_MIN

// Creating jewelry piece struct.
struct piece
{
 char client[50];
 char pieceType[25];
 double weight;
 char metal[10];
 int law;
};

// Creating queue struct.
struct queue
{
 int *values;
 int head, tail, inputNumber, size;
 struct piece *p;
};

// Func. declarations
void iniQueue(struct queue *q, int sizeMax);
bool queueEmpty(struct queue *q);
bool queueFull(struct queue *q);
void deleteQueue(struct queue *q);
bool enqueue(struct queue *q, int values, struct piece *p1);
struct piece* dequeue(struct queue *q);
void display (struct queue * q);

// Queue init
void iniQueue(struct queue *q, int sizeMax)
{
q->size = sizeMax;
q->values = malloc(sizeof(int) * q->size);
q->inputNumber = 0; // empezamos sin entradas
q->head = 0;
q->tail = 0;
q->p = (struct piece*)malloc(sizeof(struct piece) * q->size);
}

// Func.  to check if queue is EMPTY
bool queueEmpty(struct queue *q)
{
 return (q->inputNumber == 0);
}

// Func. to check if queue is FULL
bool queueFull(struct queue *q)
{
 return(q->inputNumber == q->size);
}

// Func. to free/destroy
void deleteQueue(struct queue *q)
{
 free(q->values);
 free(q->p);
}

// ++  Enqueue  ++
bool enqueue(struct queue *q, int values, struct piece *p1)
{
 // Check if queue is full 
 if (queueFull(q))
 {
  return false;
 }
 q->values[q->tail] = values;
 q->p[q->tail] = *p1;
 // moving tail + 1 as we added new info to queue 
 q->tail = (q-> tail + 1) % q->size;
 // input counter
 q->inputNumber++;
 return true;
}

// --  Dequeue  --
struct piece* dequeue(struct queue *q)
{
 struct piece *result;
 // Checking if queue is empty
 if (queueEmpty(q))
 {
  printf("Queue is empty.\n");
  return QUEUE_EMPTY;
 }
 result = &q->p[q->head];
 q->head = (q->head +1) % q->size;
 q->inputNumber--;
 return result;
}

// Func. to display
void display (struct queue * q){
 // vars
 int i;
 // Checking if queue is empty
 if(QUEUE_EMPTY == true)
 {
  printf("Your work list is empty\n");
  return;
 }
 printf ("The number of elements in the list are %d", q->inputNumber);
 printf ("\nThe elements of the Queue are: \n");
 for (i = 0; i<q->inputNumber; i++)
 {
  printf("Details about prodruct number: %d\n", i+1);
  printf(" %s\n %s\n %lf\n %s\n %d\n", q->p[i].client, q->p[i].pieceType, q->p[i].weight, q->p[i].metal, q->p[i].law);
 }
}

// ***  ---  MAIN  ---  ***
int main()
{
 // local vars
 int choice, add, t;

 // creating queue 
 struct queue q1;
 iniQueue(&q1, 10);

 // Infinite cycle 

 // for(;;){}
 while(420)
 {
  // Display menu
  printf ("\nWelcome to your jewelry organizer! \n");
  printf ("1 - Add Job \n");
  printf ("2 - Complete Current Job \n");
  printf ("3 - View full job list \n");
  printf ("4 - Exit \n");
  printf ("Enter the number to perform the desired action:");
  scanf ("%d", &choice);
  struct piece piece1;

  // Actions
  switch (choice)
  {
  case 1:
   printf("Enter Client name : ");
   scanf(" %s", piece1.client);
   printf("Enter piece Type : ");
   scanf(" %s", piece1.pieceType);
   printf("Enter Metal : ");
   scanf(" %s", piece1.metal);
   printf("Enter Weight : ");
   scanf(" %lf", &piece1.weight);
   printf("Enter law : ");
   scanf(" %d", &piece1.law);
   enqueue(&q1, add,&piece1);
   break;

  case 2:
   piece1 = *dequeue(&q1);
   printf("%s %s %s %lf %d",piece1.client,piece1.pieceType,piece1.metal,piece1.weight,piece1.law);
   break;

  case 3:
   display(&q1);
   break;

  case 4:
   exit(0);
  
  default:
   printf("Invalid choice ...");
   break;
  }
 }
 return(0);
}