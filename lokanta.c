#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t lockMasa1;
int masa1_m1 =0;

int r, rnd;
int i = 0;
int masaPilav = 13;

void *masa1(int tid){
	
	while(i < masaPilav){
		if (i < masaPilav){
			
			srand(time(NULL));	
			rnd = (rand() % 5 *i % 5)+1;			// random number between 1-5		
			//printf("\nrnd ::: %d \n\n",rnd);
			usleep(1000000*rnd);				// sleep for miliseconds
				
			pthread_mutex_lock (&lockMasa1);	// THREAD LOCKED
			
			srand(time(NULL));	
			r = (rand() % 200 *i % 200)+1;		// random number between 0-1 means thinkin' or eatin'
			printf("random number : %d\n", r);
			
			if (tid == 0)
				masa1_m1 += 100;
			printf("index i : %d tid : %d \n", i, tid);
			
			pthread_mutex_unlock (&lockMasa1);	// THREAD UNLOCKED
			i++;
		}
		
	}
	printf("masa1 m1 : %d \n",masa1_m1 );	
   	return NULL;
} 

int main (int argc, char **argv){  
	
	int threadSayi = 8;
	pthread_t tids[threadSayi];
	void * status;
	
	if (pthread_mutex_init (&lockMasa1, NULL) != 0 ){
		printf("\nmutex init error!\n");
		return 1;
	}
	
	for (int i = 0 ; i < threadSayi ; ++i){
		pthread_create(tids+i, NULL, masa1, i);
	}
	
	for (int i = 0 ; i < threadSayi ; ++i){
		pthread_join(tids[i], &status);
	}
	
	pthread_mutex_destroy(&lockMasa1);  
	exit(0);
	return 0;
}
