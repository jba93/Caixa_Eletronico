/**************************************************
Juliana B. Arvani      
Simulador de caixa eletrônico
**************************************************/

#include<stdio.h>
#include<locale.h> //para usar a função setlocale


int main ()
{
	setlocale(LC_ALL, "Portuguese"); //para usar caracteres especiais
     
    int notas100, notas50, notas20, notas10, notas5, notas1; /*quantidade de cada tipo de nota*/
    int saldo, n, i, opcao; /*saldo=saldo    n=quantidade de operações   i=auxiliar contador   opcao=opção de saque ou depósito*/
    int vsaque, vdeposito; /*vsaque=valor do saque   vdeposito=valor do depósito*/
     
    int nn100, nn50, nn20, nn10, nn5, nn1; /*quantidade de notas necessárias de cada valor no saque*/
    int nd100, nd50, nd20, nd10, nd5, nd1; /*quantidade de notas que serão depositadas de cada valor*/
     
    printf ("\t\t\t**Caixa eletrônico de Bora_Bora**\n\n");
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
    printf ("\t\t\t*Situação atual*\n");
	printf ("Notas de 100: %d \t Notas de 50: %d \t Notas de 20: %d\n", notas100, notas50, notas20); 
	printf ("Notas de 10:  %d \t Notas de 5:  %d \t Notas de 1:  %d\n", notas10, notas5, notas1);
    saldo = (100*notas100)+(50*notas50)+(20*notas20)+(10*notas10)+(5*notas5)+(notas1);
    printf ("\nSaldo: %d ducas\n", saldo);
    
    printf ("\nEntre com o número de operações n>0: ");
    scanf ("%d", &n);
    while (n<=0)
    {
		printf ("Número de operações inválido. Entre com o número de operações n>0: ");
     	scanf ("%d", &n);
    }
    for (i=1; i<=n; i++)
    {
	printf ("\n\n\t\t\tOperação %d.\n(0-saque | 1-depósito) Digite a opção desejada: ", i);
        scanf ("%d", &opcao); /*lê a opção desejada (saque/depósito)*/
        if (opcao!=0 && opcao!=1)
	{  /*não existe opção além de 0 para saque e de 1 para depósito*/
		while (opcao!=0 && opcao!=1)
		{
			printf ("Opção inválida. (0-saque | 1-depósito) Digite a opção desejada: ", 1); 
			scanf ("%d", &opcao);
		}
        }
        if (opcao==0)
	{
		printf ("\tSaque\n");
		printf ("Digite o valor do saque: ");
        	scanf ("%d", &vsaque);
            	while (vsaque>saldo) /*se o valor do saque for maior que o valor em caixa, o saque não poderá ser realizado*/
            	{
			printf ("Nao há dinheiro suficiente para o saque! Digite o valor do saque: ");
			scanf ("%d", &vsaque);
		}
		/*se o valor do saque for menor ou igual ao valor em caixa, a quantidade de notas começa a ser contada*/
		nn100 = nn50 = nn20 = nn10 = nn5 = nn1 = 0;
		/*contagem de notas necessárias para o saque de um valor maior ou igual a 100*/
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
			   printf ("\n**ATENÇÃO**\nNão há notas suficientes para realizar este saque. Por favor, tente novamente.\n");
			   nn1=0;
			   vsaque = 0;
		}
		else
			printf ("\nSaque de R$%d realizado com sucesso!\n", vsaque);
   
          	/*contagem de quantidade atual de notas no caixa depois do saque*/
          	notas100=notas100-nn100;
          	notas50=notas50-nn50;
         	notas20=notas20-nn20;
          	notas10=notas10-nn10;
          	notas5=notas5-nn5;
          	notas1=notas1-nn1;
          	saldo=saldo-vsaque; /*saldo atual depois do saque*/
          	
          	
          	
          	printf ("\n\t\t\t*Situação atual*\n");
		/*apresenta na tela*/
		printf ("Notas de 100: %d \t Notas de 50: %d \t Notas de 20: %d\n", notas100, notas50, notas20); 
		printf ("Notas de 10:  %d \t Notas de 5:  %d \t Notas de 1:  %d\n", notas10, notas5, notas1);
          	printf ("\nSaldo: %d ducas\n\n", saldo);
        }       
		                                                                                      
        if (opcao==1)
	{
		printf ("\tDepósito\n");
        	/*o usuário digitará a quantidade de notas de cada tipo a serem depositadas*/
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
        	
        	printf ("\nDepósito de R$%d realizado com sucesso!\n", vdeposito);
        	/*contagem atual das notas depois do depósito*/
        	notas100=notas100+nd100;
        	notas50=notas50+nd50;
         	notas20=notas20+nd20;
         	notas10=notas10+nd10;
         	notas5=notas5+nd5;
         	notas1=notas1+nd1;
         	saldo=saldo+vdeposito; /*saldo atual depois do depósito*/
         	printf ("\n\t\t\t*Situação atual*\n\n");
		
		/*apresenta na tela*/
		printf ("Notas de 100: %d \t Notas de 50: %d \t Notas de 20: %d\n", notas100, notas50, notas20); 
	     	printf ("Notas de 10:  %d \t Notas de 5:  %d \t Notas de 1:  %d\n", notas10, notas5, notas1);
         	printf ("*Saldo: %d ducas\n\n", saldo);
        }                            
    }
    system("pause");
	return 0;                                    
}                  
