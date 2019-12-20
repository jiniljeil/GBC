#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void* ThreadFn_sum (void * param);
typedef struct ThreadInfo
{
int threadldx; //the index of current thread 
int noThread; //number of threads
int *data; //array
int size;
int result;
}ThreadInfo;

int main(int argc , char * argv[]){
 
 
 int i ,totalsum=0;
 int size = atoi(argv[1]);
 int noThread = atoi(argv[2]); //2-1
 int *data;
 ThreadInfo *Thr;
 pthread_t *tid;

 tid = (pthread_t*)malloc(sizeof(pthread_t)*noThread); //2-2 
 Thr = (ThreadInfo*)malloc(sizeof(ThreadInfo)*noThread); //2-3
 data =(int*) malloc(sizeof(int)*size); //2-4
 
 for(i =0;i<size;i++){ //2-5
 data[i] = i ;
 }

 for(i=0;i<noThread;i++){
 Thr[i].threadldx = i;
 Thr[i].noThread = noThread;
 Thr[i].data = data;
 Thr[i].size =size ; 
 }  // 2-6a

 for(i=0;i<noThread; i++){
 pthread_create(&tid[i], NULL, ThreadFn_sum, &Thr [i] ); // 2-6b
 }

 for(i=0;i<noThread;i++){
 pthread_join(tid[i],NULL); //2-7a
 }

 for(i=0;i<noThread;i++){
 totalsum += Thr[i].result; //2-7b
 }

 printf("total sum = %d \n",totalsum); // 2-8
 printf("total sum(formula) = %d \n",size*(size-1)/2); // 2-9

 return 0;
}

void* ThreadFn_sum (void * param){ 
 int i;
 struct ThreadInfo *Thr;
 Thr =(struct ThreadInfo *)param;
 
 int partialSum =0 ;
 for(i=(*Thr).threadldx; i< (*Thr).size; i+= (*Thr).noThread){
  partialSum += (*Thr).data[i]; 
 }
 (*Thr).result = partialSum;
 printf("partial sum of thread %d=%d\n",(*Thr).threadldx,partialSum);
 
 return 0;
}
