
/*Este codigo usa el modelo de montecarlo para estimar el valor de la constante PI */
/* este codigo es original de http://stackoverflow.com/questions/17659652/calculating-pi-using-monte-carlo-method-gives-imprecise-answer*/
/* Ha sido modificado por Alejandro Parra Briones para fines academicos*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>

#define sqr2(x) ((x)*(x))
#define frand() ((double) rand() / (RAND_MAX))

#define NUM_THREADS (atoi(argv[1]))
#define MAXLEN (atoi(argv[2]))
#define SLEEP (argc == 4 && argv[3] == "sleep")

// Funcion para verificar si cayo dentro del circulo
int circumscribed(int radius)
{
	float xcoord = frand();
	float ycoord = frand(); 
	float coord = sqr2(xcoord) + sqr2(ycoord);

	return coord <= radius ? 1 : -1;
}

int main(int argc, char *argv[])
{
	int i, circles = 0;
	srand(time(NULL));

	#pragma omp parallel for num_threads(NUM_THREADS)
		for(i = 0; i < MAXLEN; i++)
		{
			#pragma omp critical
				if(circumscribed(1) > 0) // What?
					circles++;

			if(SLEEP)
				usleep(rand() % 3); // Sleep from 0-2 seconds
		}
	
	float pi = 4 * ((float) circles/(float) MAXLEN);
	printf("After %d iterations circles is %d  PI is %2.4f : \n", MAXLEN, circles, pi);

	return 0;   
}
