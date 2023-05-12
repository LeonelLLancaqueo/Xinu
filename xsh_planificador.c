#include <xinu.h>

struct process{
    int pid;
    int burst;
    int delay;
};

void    sndch(char);
void    planificar(struct process arrPr[]);



shellcmd xsh_planificador(void){
    int pidPlanificador;
	struct process a,b,c;
	//Creamos los 4 procesos


    struct process arrProcess[]={
        {create(sndch, 1024, 20, "send A",1, 'A'), 100, 0},
        {create(sndch, 1024, 20, "send B",1, 'B'), 20, 0},
        {create(sndch, 1024, 20, "send C",1, 'C'), 30, 0}
    };

    pidPlanificador = create(planificar, 1024, 30, "Planificador",1, arrProcess);
	resume(pidPlanificador);
}

void planificar(struct process arrPr[]){
    int i=0;
    int pidAux;

    while(1){
        struct process prAux= arrPr[i]; 
        pidAux= prAux.pid; //pid actual
        chprio(pidAux, 25);
        i++;
        if(i == 3){ //reseteamos i para que vuelva a iterar las estructuras
            i=0;
        }
        resume(pidAux);
        sleepms(prAux.burst); //lo dormimos una rafaga de ms al planificador
        suspend(pidAux); //suspendimos al proceso
        chprio(pidAux, 20); // volvemos a reestablecer su prioridad
    }
}/*
void planificarPorPrioridad(struct process arrPr[]){
    int i=0;
    int pidAux;

    while(1){
        struct process prAux= arrPr[i]; 
        pidAux= prAux.pid; //pid actual
        chprio(pidAux, 25);
        i++;
        if(i == 3){ //reseteamos i para que vuelva a iterar las estructuras
            i=0;
        }
        resume(pidAux);
        sleepms(prAux.burst); //lo dormimos una rafaga de ms al planificador
        suspend(pidAux); //suspendimos al proceso
        chprio(pidAux, 20); // volvemos a reestablecer su prioridad
    }
    
}*/

/*
void BurstSort(struct process arr[]){

    int i=0;
    int pidAux;
    int rafaga[]= {120,60,20};

    while(1){
        pidAux= arrPid[i]; //pid actual
        chprio(pidAux, 25);
        i++;
        if(i == 3){ //reseteamos i para que vuelva a iterar las estructuras
            i=0;
        }
        resume(pidAux);
        sleepms(rafaga[i]); //lo dormimos una rafaga de ms al planificador
        suspend(pidAux); //suspendimos al proceso
        chprio(pidAux, 20); // volvemos a reestablecer su prioridad
    }

    process new_current_Queqe[sizeof(arr)];
    new_current_Queqe[0]= arr[0];
    for(int i=0; i<sizeof(new_current_Queqe); i++ ){
        process prAux= 
    }

}*/


void	sndch(char ch){
while( 1 ){
    putc(CONSOLE, ch);
    
    }
}
