
#include <xinu.h>
#define ASCII_ESC 27

void    planificar_carrera(int arrPr []), mutex_init(), mutex_lock(), mutex_unlock(), mostrar_distancia();
void corredor_a(), corredor_b(), muestra_carrera();

int vel_a = 0;
int vel_b = 0;
int distancia=0;


sid32 sem3;
int pidSem2;

void mutex_init2(){
    sem3= semcreate(1);
}
void mutex_lock2(int pid){
    pidSem2= pid;
    wait(sem3);
}
void mutex_unlock2(int pid){
   // if(pid == pidSem2){
        signal(sem3);
    //}
}

void mostrar_distancia(){
	
	//printf("distancia: %d",distancia);
	
}

void corredor_a()
{
	while(1) {

		vel_a++;

		distancia++;

	}

}

void corredor_b()
{

	while(1) {
		vel_b++;
		
		distancia++;

	}
}

shellcmd xsh_carrera(void){

	mutex_init2();
    int arrProcess[]={
        create(corredor_a, 1024, 20, "corredor_A",0),
        create(corredor_b, 1024, 20, "corredor_B",0),
    };
	resume(create(muestra_carrera, 1024, 20, "muestra_carrera ",0));
	resume(create(mostrar_distancia, 1024, 20, "mostrar_distancia",0));

	resume(create(planificar_carrera, 1024, 20, "Planificador",1, arrProcess));

	for(;;);
	
}

void planificar_carrera(int arrPr[]){
    char opcion;
	int estadoPA=0, estadoPB=0;
	int pidAux;

	control(0,TC_MODER,0,0);
	
    while(1){

    printf(	"opciones: \n 1 - iniciar/suspender proceso a \n 2 - iniciar/suspender proceso b \n 5 - matar a \n 6 - matar b \n");
	opcion= (char)getchar(); //testear
	printf("\n opcion elegida:  %c \n", opcion);


	   if(opcion == '1'){
			pidAux= arrPr[0];
			if(estadoPA == 0){
				
				estadoPA=1;
				
				resume(pidAux);
			
			}else{
				estadoPA=0;
				suspend(arrPr[0]);
			}
			
	   }else{
			
			if(opcion == '2'){
				pidAux= arrPr[1];
				if(estadoPB == 0){
					estadoPB=1;
					resume(pidAux);
				}else{
					estadoPB=0;
					suspend(pidAux);
				}
			}else{
				if(opcion == '5'){
					kill(arrPr[0]);
				}else{
					if(opcion == '6'){
						kill(arrPr[1]);
					}
				}
			}
	   }
    }

	control(0,TC_MODEC,0,0);
}

void muestra_carrera() 
{
	/* limpiar toda la pantalla */
	printf( "%c[2J", ASCII_ESC );

	while(1) {
		

		/* Nos posicionamos en la fila 5 columna 10 */
    		printf( "%c[5;10f", ASCII_ESC );
    		printf( "Velocidad corredor A: %d \n", vel_a);

		/* Nos posicionamos en la fila 6 columna 10 */
    		printf( "%c[6;10f", ASCII_ESC );
    		printf( "Velocidad corredor B: %d \n", vel_b);

		sleepms(50);
	}


}

