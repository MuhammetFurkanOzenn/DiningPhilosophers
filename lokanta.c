#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

/*

Detayli Hesap Dokumu

-- Masa 1 Hesabi --

Masa Acma : 99.90 + 19.90 (ilk pirinc tutar) tl
Masa Tazeleme Sayisi : 19.90*(masaTazelemeSayisi[i]) tl
Ne Kadar Pirinc Yendi : 20 *(neKadarPirincYendi[i]) tl

Total Fiyat : ...
 
*/



pthread_mutex_t lockMasa1;
int masa1_m1 = 0;

int rndNo = 50;
int rndList[50];
int neKadarPirincYendi[50]; 
int masaTazelemeSayisi[50]; 

int r, rnd;
int i = 0;
int masaPilav = 13;
 

void *masa1(int tid){
	
	while(i < masaPilav){
		if (i < masaPilav){
				
			rnd = rndList[i]%6;				// random number between 1-5		
			
			usleep(1000000*rnd);				// sleep for miliseconds
				
		pthread_mutex_lock (&lockMasa1);		// THREAD LOCKED
				
			r = rndList[i]%2;				// random number between 0-1 means thinkin' or eatin'
			
			printf("random number : %d\n", r);
			
			if (tid == 0 && r == 1)
				masa1_m1 = 1;
			if (masa1_m1 == 1)
				printf("tid : %d is true \n\n",tid);
			
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
	srand(time(NULL));
	for (int i = 0 ; i < rndNo ; i++ ){
		rndList[i] = (rand() % rndNo);
	}
	
	
	
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
