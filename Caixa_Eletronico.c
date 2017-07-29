/**************************************************
Juliana B. Arvani      
Simulador de caixa eletr�nico
**************************************************/

#include<stdio.h>
#include<locale.h> //para usar a fun��o setlocale


int main ()
{
	setlocale(LC_ALL, "Portuguese"); //para usar caracteres especiais
     
    int notas100, notas50, notas20, notas10, notas5, notas1; /*quantidade de cada tipo de nota*/
    int saldo, n, i, opcao; /*saldo=saldo    n=quantidade de opera��es   i=auxiliar contador   opcao=op��o de saque ou dep�sito*/
    int vsaque, vdeposito; /*vsaque=valor do saque   vdeposito=valor do dep�sito*/
     
    int nn100, nn50, nn20, nn10, nn5, nn1; /*quantidade de notas necess�rias de cada valor no saque*/
    int nd100, nd50, nd20, nd10, nd5, nd1; /*quantidade de notas que ser�o depositadas de cada valor*/
     
    printf ("\t\t\t**Caixa eletr�nico de Bora_Bora**\n\n");
    printf ("Digite a quantidade inicial das seguintes notas: ");
    printf ("\nNotas de 100: ");
    scanf ("%d", &notas100);
    printf ("Notas de 50: ");
    scanf ("%d", &notas50);
    printf ("Notas de 20: ");
    scanf ("%d", &notas20);
    printf ("Notas de 10: ");
    scanf ("%d", &notas10);
    printf ("Notas de 5: ");
    scanf ("%d", &notas5);
    printf ("Notas de 1: ");
    scanf ("%d", &notas1);
    
    /*apresenta na tela o saldo e quantidades de notas*/
    printf ("\t\t\t*Situa��o atual*\n");
	printf ("Notas de 100: %d \t Notas de 50: %d \t Notas de 20: %d\n", notas100, notas50, notas20); 
	printf ("Notas de 10:  %d \t Notas de 5:  %d \t Notas de 1:  %d\n", notas10, notas5, notas1);
    saldo = (100*notas100)+(50*notas50)+(20*notas20)+(10*notas10)+(5*notas5)+(notas1);
    printf ("\nSaldo: %d ducas\n", saldo);
    
    printf ("\nEntre com o n�mero de opera��es n>0: ");
    scanf ("%d", &n);
    while (n<=0)
    {
		printf ("N�mero de opera��es inv�lido. Entre com o n�mero de opera��es n>0: ");
     	scanf ("%d", &n);
    }
    for (i=1; i<=n; i++)
	{
		printf ("\n\n\t\t\tOpera��o %d.\n(0-saque | 1-dep�sito) Digite a op��o desejada: ", i);
        scanf ("%d", &opcao); /*l� a op��o desejada (saque/dep�sito)*/
        if (opcao!=0 && opcao!=1)
		{  /*n�o existe op��o al�m de 0 para saque e de 1 para dep�sito*/
			while (opcao!=0 && opcao!=1)
			{
				printf ("Op��o inv�lida. (0-saque | 1-dep�sito) Digite a op��o desejada: ", 1); 
				scanf ("%d", &opcao);
			}
        }
        if (opcao==0)
		{
			//fprintf (imp, "Saque");
			printf ("\tSaque\n");
			printf ("Digite o valor do saque: ");
        	scanf ("%d", &vsaque);
            while (vsaque>saldo) /*se o valor do saque for maior que o valor em caixa, o saque n�o poder� ser realizado*/
            {
                printf ("Nao h� dinheiro suficiente para o saque! Digite o valor do saque: ");
                scanf ("%d", &vsaque);
            }
            /*se o valor do saque for menor ou igual ao valor em caixa, a quantidade de notas come�a a ser contada*/
            nn100 = nn50 = nn20 = nn10 = nn5 = nn1 = 0;
			/*contagem de notas necess�rias para o saque de um valor maior ou igual a 100*/
			int res100, res50, res20, res10, res5, res1;
			res100 = vsaque%100;
			res50 = (vsaque%100)%50;
			res20 = (((vsaque%100)%50)%20);
			res10 = ((((vsaque%100)%50)%20)%10);
			res5 = (((((vsaque%100)%50)%20)%10)%5);
			res1 = ((((((vsaque%100)%50)%20)%10)%5)%1);
			
       		nn100= vsaque/100;
       		if (nn100>notas100)
       		{
       			nn100=0;
       			res100 = vsaque;
			}
			
       		nn50= res100/50;
       		if (nn50>notas50)
       		{
       			nn50=0;
       			res50 = res100;
       		}	
       		
           	nn20= res50/20;
           	if (nn20>notas20)
           	{
           		nn20=0;
           		res20 = res50;
			}               	
           	
			nn10= res20/10;
           	if (nn10>notas10)
           	{
           		nn10=0;
           		res10 = res20;
			}
           	
			nn5= res10/5;
           	if (nn5>notas5)
           	{
           		nn5=0;
           		res5 = res10;
			}
       			
           	nn1= res5/1;
           	if (nn1>notas1)
           	{
			   printf ("\n**ATEN��O**\nN�o h� notas suficientes para realizar este saque. Por favor, tente novamente.\n");
			   nn1=0;
			   vsaque = 0;
			}
			else
				printf ("\nSaque de R$%d realizado com sucesso!\n", vsaque);
           		
           	//printf ("\nnn100  %d\n", nn100);
			//printf ("nn50  %d\n", nn50);
			//printf ("nn20  %d\n", nn20);
			//printf ("nn10  %d\n", nn10);
			//printf ("nn5  %d\n", nn5);
			//printf ("nn1  %d\n", nn1);
           		
          	/*contagem de quantidade atual de notas no caixa depois do saque*/
          	notas100=notas100-nn100;
          	notas50=notas50-nn50;
         	notas20=notas20-nn20;
          	notas10=notas10-nn10;
          	notas5=notas5-nn5;
          	notas1=notas1-nn1;
          	saldo=saldo-vsaque; /*saldo atual depois do saque*/
          	
          	
          	
          	printf ("\n\t\t\t*Situa��o atual*\n");
	      	/*apresenta na tela*/
		  	printf ("Notas de 100: %d \t Notas de 50: %d \t Notas de 20: %d\n", notas100, notas50, notas20); 
		  	printf ("Notas de 10:  %d \t Notas de 5:  %d \t Notas de 1:  %d\n", notas10, notas5, notas1);
          	printf ("\nSaldo: %d ducas\n\n", saldo);
        }       
		                                                                                      
        if (opcao==1)
		{
			printf ("\tDep�sito\n");
        	/*o usu�rio digitar� a quantidade de notas de cada tipo a serem depositadas*/
        	printf ("Entre com a quantidade de notas de 100: ");
        	scanf ("%d", &nd100);
        	printf ("Entre com a quantidade de notas de 50: ");
        	scanf ("%d", &nd50);
        	printf ("Entre com a quantidade de notas de 20: ");
        	scanf ("%d", &nd20);
        	printf ("Entre com a quantidade de notas de 10: ");
        	scanf ("%d", &nd10);
        	printf ("Entre com a quantidade de notas de 5: ");
        	scanf ("%d", &nd5);
        	printf ("Entre com a quantidade de notas de 1: ");
        	scanf ("%d", &nd1);
        	
        	int vdeposito;
        	vdeposito = (nd100*100) + (nd50*50) + (nd20*20) + (nd10*10) + (nd5*5) + nd1;
        	
        	printf ("\nDep�sito de R$%d realizado com sucesso!\n", vdeposito);
        	/*contagem atual das notas depois do dep�sito*/
        	notas100=notas100+nd100;
        	notas50=notas50+nd50;
         	notas20=notas20+nd20;
         	notas10=notas10+nd10;
         	notas5=notas5+nd5;
         	notas1=notas1+nd1;
         	saldo=saldo+vdeposito; /*saldo atual depois do dep�sito*/
         	printf ("\n\t\t\t*Situa��o atual*\n\n");
			/*apresenta na tela*/
			printf ("Notas de 100: %d \t Notas de 50: %d \t Notas de 20: %d\n", notas100, notas50, notas20); 
	     	printf ("Notas de 10:  %d \t Notas de 5:  %d \t Notas de 1:  %d\n", notas10, notas5, notas1);
         	printf ("*Saldo: %d ducas\n\n", saldo);
        }                            
    }
    system("pause");
	return 0;                                    
}                  
