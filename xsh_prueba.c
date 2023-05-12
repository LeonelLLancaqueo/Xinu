#include <xinu.h>

void	sndch(char);

/*------------------------------------------------------------------------
 * main  --  example of creating processes in Xinu
 *------------------------------------------------------------------------
 */
shellcmd xsh_prueba(void)
{/*
	int pidA, pidB;
	
	pidA= create(sndch, 1024, 20, "send A",1, 'A');
	pidB= create(sndch, 1024, 20, "send B",1, 'B');
	resume(pidA);
	resume(pidB);
	sleep(6);
	kill(pidA);
	kill(pidB);
	
	
	*/
	
	
}

/*
void	sndch(char ch)
{
	while( 1 ){
		putc(CONSOLE, ch);
		sleep(3);
		
		
	}
}
*/


