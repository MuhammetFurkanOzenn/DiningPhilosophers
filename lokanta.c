#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

/*

Detayli Hesap Dokumu

-- Masa 1 Hesabi --

Masa Acma : 99.90  tl
Masa Tazeleme Sayisi : 19.90*(masaTazelemeSayisi[i]) tl
Ne Kadar Pirinc Yendi : 20 *(neKadarPirincYendi[i])*2 + 19.90 (ilk pirinc tutar) tl

Total Fiyat : ...
 
*/



pthread_mutex_t lockMasa1;

int masa1_m1 = 0;
int masa1_m2 = 0;
int masa1_m3 = 0;
int masa1_m4 = 0;
int masa1_m5 = 0;
int masa1_m6 = 0;
int masa1_m7 = 0;
int masa1_m8 = 0;

pthread_mutex_t lockMasa2;
int masa2_m1 = 0;
int masa2_m2 = 0;
int masa2_m3 = 0;
int masa2_m4 = 0;
int masa2_m5 = 0;
int masa2_m6 = 0;
int masa2_m7 = 0;
int masa2_m8 = 0;
int masa2_yenileme = 0;

int masa1_yenileme = 0;

int rndNo = 500;
int rndList[500];
int neKadarPirincYendi[50]; 
int masaTazelemeSayisi[50]; 

int r, rnd, numOfPhiGroup;
int masaCounter = 1;

int i = 0;
int j = 0;
int breakTheLoop = 0;
//int masaPilav = 999999;
int masadaKalanPilav = 20; 

void *masa1(int tid){
	
	while(j < masadaKalanPilav){ //&& breakTheLoop == 0
		printf("brakloop %d\n",breakTheLoop);
		if (j < masadaKalanPilav ){
			//printf("numOfPhiGroupTh : %d \n",numOfPhiGroup);	
			rnd = rndList[i]%6;				// random number between 1-5		
			
			usleep(1000000*rnd);				// sleep for miliseconds
				
			pthread_mutex_lock (&lockMasa1);		// THREAD LOCKED
				
			r = rndList[i]%2;				// random number between 0-1 means thinkin' or eatin'
			
			if (breakTheLoop == 0){
				printf("random number : %d tid : %d i : %d masadakiPilav : %d break : %d\n ", r, tid+1, i, masadaKalanPilav, breakTheLoop);
			
			
				if (tid == 0 && r == 1){
					masa1_m1 = 1;
					masadaKalanPilav--;
				}
				if (tid == 1 && r == 1){
					masa1_m2 = 1;
					masadaKalanPilav--;
				}
				if (tid == 2 && r == 1){
					masa1_m3 = 1;
					masadaKalanPilav--;
				}
				if (tid == 3 && r == 1){
					masa1_m4 = 1;
					masadaKalanPilav--;
				}
				if (tid == 4 && r == 1){
					masa1_m5 = 1;
					masadaKalanPilav--;
				}
				if (tid == 5 && r == 1){
					masa1_m6 = 1;
					masadaKalanPilav--;
				}
				if (tid == 6 && r == 1){
					masa1_m7 = 1;
					masadaKalanPilav--;
				}
				if (tid == 7 && r == 1){
					masa1_m8 = 1;
					masadaKalanPilav--;
				}
					
				if (masa1_m1 == 1)
					printf("phi1 is true \n\n");
				if (masa1_m2 == 1)
					printf("phi2 is true \n\n");
				if (masa1_m3 == 1)
					printf("phi3 is true \n\n");
				if (masa1_m4 == 1)
					printf("phi4 is true \n\n");
				if (masa1_m5 == 1)
					printf("phi5 is true \n\n");
				if (masa1_m6 == 1)
					printf("phi6 is true \n\n");
				if (masa1_m7 == 1)
					printf("phi7 is true \n\n");
				if (masa1_m8 == 1)
					printf("phi8 is true \n\n");
			
				if ( masadaKalanPilav == 0){	// yemek yeme == 19 i == 19
					if (masa1_m1 == 1 && masa1_m2 == 1 && masa1_m3 == 1 && masa1_m4 == 1 && masa1_m5 == 1 && masa1_m6 == 1 && masa1_m7 == 1 && masa1_m8 == 1){
						printf("YEMEK BITTII\n");
						breakTheLoop = 1;
						printf("-- Masa %d Detayli Hesap Dokumu --\n", masaCounter);
						printf("Masa Acma : 99.90 tl \n");	
						printf("Masa Tazeleme Sayisi : %.2f tl \n",(19.90*masa1_yenileme));
						printf("Pirinc Fiyati : %.2f tl \n",(20*masa1_yenileme*2) + 19.90);
						printf("Toplam Fiyat : %.2f tl \n",((19.90*masa1_yenileme) + (20*masa1_yenileme*2 + 19.90) + 99.90));
						
						//degiskenleri sifirla
						//counter for each masa 
						masaCounter++;
						}
					else {
						masadaKalanPilav = 20;	//i=0;
						masa1_yenileme++;
						// pilav yineleme ++
						// masa yineleme ++
					}
					/*

					Detayli Hesap Dokumu

					-- Masa 1 Hesabi --

					Masa Acma : 99.90  tl
					Masa Tazeleme Sayisi : 19.90*(masaTazelemeSayisi[i]) tl
					Ne Kadar Pirinc Yendi : 20 *(neKadarPirincYendi[i])*2 + 19.90 (ilk pirinc tutar) tl

					Total Fiyat : ...
					 
					*/
					
					
				}
			}
				pthread_mutex_unlock (&lockMasa1);	// THREAD UNLOCKED 
				i++;
		}
		
	}
	
   	return NULL;
} 

void *masa2(int tid){
	
	while(j < masadaKalanPilav){ //&& breakTheLoop == 0
		printf("brakloop 2 %d\n",breakTheLoop);
		if (j < masadaKalanPilav ){
			//printf("numOfPhiGroupTh : %d \n",numOfPhiGroup);	
			rnd = rndList[i]%6;				// random number between 1-5		
			
			usleep(1000000*rnd);				// sleep for miliseconds
				
			pthread_mutex_lock (&lockMasa2);		// THREAD LOCKED
				
			r = rndList[i]%2;				// random number between 0-1 means thinkin' or eatin'
			
			if (breakTheLoop == 0){
				printf("masa 2 random number : %d tid : %d i : %d masadakiPilav : %d break : %d\n ", r, tid+1, i, masadaKalanPilav, breakTheLoop);
			
			
				if (tid == 0 && r == 1){
					masa2_m1 = 1;
					masadaKalanPilav--;
				}
				if (tid == 1 && r == 1){
					masa2_m2 = 1;
					masadaKalanPilav--;
				}
				if (tid == 2 && r == 1){
					masa2_m3 = 1;
					masadaKalanPilav--;
				}
				if (tid == 3 && r == 1){
					masa2_m4 = 1;
					masadaKalanPilav--;
				}
				if (tid == 4 && r == 1){
					masa2_m5 = 1;
					masadaKalanPilav--;
				}
				if (tid == 5 && r == 1){
					masa2_m6 = 1;
					masadaKalanPilav--;
				}
				if (tid == 6 && r == 1){
					masa2_m7 = 1;
					masadaKalanPilav--;
				}
				if (tid == 7 && r == 1){
					masa2_m8 = 1;
					masadaKalanPilav--;
				}
					
				if (masa2_m1 == 1)
					printf("phi1 is true \n\n");
				if (masa2_m2 == 1)
					printf("phi2 is true \n\n");
				if (masa2_m3 == 1)
					printf("phi3 is true \n\n");
				if (masa2_m4 == 1)
					printf("phi4 is true \n\n");
				if (masa2_m5 == 1)
					printf("phi5 is true \n\n");
				if (masa2_m6 == 1)
					printf("phi6 is true \n\n");
				if (masa2_m7 == 1)
					printf("phi7 is true \n\n");
				if (masa2_m8 == 1)
					printf("phi8 is true \n\n");
			
				if ( masadaKalanPilav == 0){	// yemek yeme == 19 i == 19
					if (masa2_m1 == 1 && masa2_m2 == 1 && masa2_m3 == 1 && masa2_m4 == 1 && masa2_m5 == 1 && masa2_m6 == 1 && masa2_m7 == 1 && masa2_m8 == 1){
						printf("YEMEK BITTII\n");
						breakTheLoop = 1;
						printf("-- Masa %d Detayli Hesap Dokumu --\n", masaCounter);
						printf("Masa Acma : 99.90 tl \n");	
						printf("Masa Tazeleme Sayisi : %.2f tl \n",(19.90*masa2_yenileme));
						printf("Pirinc Fiyati : %.2f tl \n",(20*masa2_yenileme*2) + 19.90);
						printf("Toplam Fiyat : %.2f tl \n",((19.90*masa2_yenileme) + (20*masa2_yenileme*2 + 19.90) + 99.90));
						
						//degiskenleri sifirla
						//counter for each masa 
						masaCounter++;
						}
					else {
						masadaKalanPilav = 20;	//i=0;
						masa2_yenileme++;
						// pilav yineleme ++
						// masa yineleme ++
					}
					/*

					Detayli Hesap Dokumu

					-- Masa 1 Hesabi --

					Masa Acma : 99.90  tl
					Masa Tazeleme Sayisi : 19.90*(masaTazelemeSayisi[i]) tl
					Ne Kadar Pirinc Yendi : 20 *(neKadarPirincYendi[i])*2 + 19.90 (ilk pirinc tutar) tl

					Total Fiyat : ...
					 
					*/
					
					
				}
			}
				pthread_mutex_unlock (&lockMasa2);	// THREAD UNLOCKED
				i++;
		}
		
	}
   	return NULL;
} 

int strtoint( char* charnums)
{
 int number=0;
 int index=0;
 
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            break;
         }
 }
 return number;
}

void nextIteration (){
	masadaKalanPilav = 20;
	masa2_yenileme = 0;
	breakTheLoop = 0;
	i=0;
	numOfPhiGroup--;
	masa1_m1 = 0;
	masa1_m2 = 0;
	masa1_m3 = 0;
	masa1_m4 = 0;
	masa1_m5 = 0;
	masa1_m6 = 0;
	masa1_m7 = 0;
	masa1_m8 = 0;
}

int main (int argc, char **argv){  
	
	int threadSayi = 8;
	pthread_t tids[threadSayi];
	void * status;
	char phiGroup[20];
	srand(time(NULL));
	
	printf("Kac grup filozofun gelecegini giriniz : ");
	scanf("%s",&phiGroup);
	printf("temp :: %s\n",phiGroup);
	numOfPhiGroup = strtoint(phiGroup);
	printf("\numOfPhiGroup : %d \n",numOfPhiGroup);
	for (int i = 0 ; i < rndNo ; i++ ){
		rndList[i] = (rand() % rndNo);
	}
	
	void * status2;
	int ss = 1;
	while (numOfPhiGroup > 0){
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
		
		nextIteration();
		
		/*
		printf("\n\nmasa1 bitti\n\n");
		sleep(5);
		// masa2 threadleri
		if (pthread_mutex_init (&lockMasa2, NULL) != 0 ){
			printf("\nmutex init error!\n");
			return 1;
		}
		
		for (int i = 0 ; i < threadSayi ; ++i){
			pthread_create(tids+i, NULL, masa2, i);
		}
		
		for (int i = 0 ; i < threadSayi ; ++i){
			pthread_join(tids[i], &status2);
		}
		
		pthread_mutex_destroy(&lockMasa2); 
		nextIteration();
		*/
	}
	exit(0);
	return 0;
}
