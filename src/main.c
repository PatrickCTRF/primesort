/* Primesort
 * Baguio loco que vai imprimir na tela só as entradas não primas que receber.
 */

#include <stdio.h>
#include <stdlib.h>

/* 
  1 se for primo, 0 se não for
*/
int ehPrimo(int n){

	int i = 0;
	
	if(n<=1) return 0;//1 e 0 não são primos.
	
	if(n<=3) return 1;//2 e 3 são primos
	
	for(i=2;i*i<=n;i++){	/*Só precisamos verificar até a raiz quadradado número se ele é primo, pois os números maiores terão sido 								complementarmente verificados*/
		if(n%i == 0) return 0;
		
	}
	
	return 1;//Se chegou até aqui, o número é primo.
	
}

int main() {

	FILE *terminal = NULL;
	int n_entrada = 0;//Variável que gaurda o número vindo da entrada.


	terminal = popen("sort -nr","w");	/*"w" significa que iremos PRIMEIRO escrever no arquivo de saída e DEPOIS este será submetido ao 											"sort" antes de ser impresso. Se fosse "r", primeiro o diretório atual seria submetido ao "sort" e 											depois receberíamos esse resultado escrito no arquivo.*/

  
	if(terminal == NULL){//Este caso DIFICILMENTE irá acontecer nos testes. É apenas para o programa nao quebrar caso a entrada dê erro.
  		printf("ERRO RECEBENDO A ENTRADA\n");
  		return 1;
	}
	
	while(scanf(" %d", &n_entrada) != EOF && n_entrada != -1){//Vamos continuar com a leitura até o final do arquivo.
		
		if(!ehPrimo(n_entrada)) fprintf(terminal, "%d\n", n_entrada);///Aqui nós imprimiremos somente os números NÃO primos.
		
	}
	
	pclose(terminal);//É quando fechamos que o conteúdo é escrito na saída, no caso, o terminal.

	return 0;
}
