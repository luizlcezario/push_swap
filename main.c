
#include <unistd.h>

int main(void){
	int teste = 237612;

	write(1, &(teste % 10 + 48), 4);
	write(1, &(teste % 100 + 48), 4);
	write(1, &(teste % 1000 + 48), 4);

}

