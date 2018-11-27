/*Este codigo usa el modelo de montecarlo para estimar el valor de la constante PI */
/* este codigo es original de http://stackoverflow.com/questions/17659652/calculating-pi-using-monte-carlo-method-gives-imprecise-answer*/
/* Ha sido modificado por Alejandro Parra Briones para fines academicos*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define sqr2(x) ((x)*(x))
#define frand() ((double) rand() / (RAND_MAX))

#define NUM_THREADS (atoi(argv[1]))
#define MAXLEN (atoi(argv[2]))

int i, circles = 0;
void* thread_montecarlo();
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Funcion para verificar si cayo dentro del circulo
int circumscribed(int radius)
{
	float xcoord = frand();
	float ycoord = frand(); 
	float coord = sqr2(xcoord) + sqr2(ycoord);

	return coord <= radius ? 1 : -1;
}

void* thread_montecarlo(void* arg)
{
	char **argv = (char**)arg; // Get argv from thread_arg
	while(i < MAXLEN)
	{
		pthread_mutex_lock(&mutex);
		if(circumscribed(1) > 0) // What?
			circles++;

		i++;
		pthread_mutex_unlock(&mutex);

		usleep(rand() % 3); // Sleep from 0-2 seconds
	}
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	srand(time(NULL));

	for(int t = 0; t < NUM_THREADS; t++)
		if(pthread_create( &threads[t], NULL, &thread_montecarlo, (void*) argv))
			printf("Thread creation failed: %d\n", t + 1);

	for(int t = 0; t < NUM_THREADS; t++)
		pthread_join(threads[t], NULL);

	float pi = 4 * ((float) circles/(float) MAXLEN);
	printf("After %d iterations circles is %d  PI is %2.4f : \n", MAXLEN, circles, pi);

	return 0;   
}
