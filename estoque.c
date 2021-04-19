/*
	Name: Controle de Estoque
	Copyright: 1º Periodo
	Author: Grupo 9(Amanda Maia
					André Oliveira
					Arielle kellen
					Breno Angelo
					Camilo Italo
					J Albert
					João Victor Barbosa
					Mateus Carvalho)
	Date: 16/05/19 13:39
	Description: Controle de Estoque
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int op,opP,qtd,lim,tax,tip;
	char ti[13],nome[30];
	float prc,prcT,t,fim;
void TelaPrincipal(){
	printf("--------------------------------\n");
	printf("|     CONTROLE DE ESTOQUE      |\n");
	printf("--------------------------------\n");
	printf("| 1- Cadastro                  |\n");
	printf("--------------------------------\n");
	printf("| 2- Estoque                   |\n");
	printf("--------------------------------\n");
	printf("| 3- Venda                     |\n");
	printf("--------------------------------\n");
	printf("| 4- Imprimir                  |\n");
	printf("--------------------------------\n");
	printf("| 5- Sair                      |\n");
	printf("--------------------------------\n");
	printf("Informe a opcao a seguir:\n");
	scanf("%d",&op);
}

 Cadastro(){
	do{
		printf("--------------------------------\n");
		printf("|           CADASTRO           |\n");
		printf("--------------------------------\n");
		printf("| 1- Inserir Produto           |\n");
		printf("--------------------------------\n");
		printf("| 2- Editar  Produto           |\n");
		printf("--------------------------------\n");
		printf("| 3- Imprimir Produto          |\n");
		printf("--------------------------------\n");
		printf("| 4- Sair                      |\n");
		printf("--------------------------------\n");
		scanf("%d",&opP);
		switch(opP){
			case 1:{
				system("cls");
				Tipo();
				break;
			}
			case 2:{
				system("cls");
				ImprimirP();
				system("pause");
				Tipo();
				break;
			}
			case 3:{
				system("cls");
				ImprimirP();
				break;
			}
		}system("cls");
	}while(opP!=4);
}


int Tipo(){
	printf("--------------------------------\n");
	printf("|             TIPO             |\n");
	printf("--------------------------------\n");
	printf("| 1- Perecivel                 |\n");
	printf("--------------------------------\n");
	printf("| 2- Nao Perecivel             |\n");
	printf("--------------------------------\n");
	scanf("%d",&tip);
	switch(tip){
		case 1:{
			system("cls");
			printf("A quantidade maxima para esse tipo de produto e 50\n");
			Inserir();		
			break;	
		}
		case 2:{
			system("cls");
				Inserir();
				break;
		}
	}
}
int Inserir(){
	
	printf("Nome do produto:\n");
	scanf("%s", &nome);
	printf("porcentangem de reajuste do produto:  \n");
	scanf("%d", &tax);
}
	
int ImprimirP(){
	if(tip!=2){
		strcpy(ti," Perecivel  ");
	}
	else{
		strcpy(ti,"Nao Perecivel");
	}
	printf("Tipo do produto:                       %s\n",ti);
	printf("Nome do produto:                       %s\n",nome);
	printf("porcentangem de reajuste do produto:   %d\n",tax);
	printf("Preco do produto:                      %.2f\n",prc);
	printf("Preco total:                           %.2f\n",t);
	system("pause");
	system("cls");
}

int Estoque(){
	do{
		printf("--------------------------------\n");
		printf("|            ESTOQUE           |\n");
		printf("--------------------------------\n");
		printf("| 1- Inserir Quantidade        |\n");
		printf("--------------------------------\n");
		printf("| 2- Editar  Quantidade        |\n");
		printf("--------------------------------\n");
		printf("| 3- Imprimir Quantidade       |\n");
		printf("--------------------------------\n");
		printf("| 4- Sair                      |\n");
		printf("--------------------------------\n");
		scanf("%d",&opP);
		switch(opP){
			case 1:{
				system("cls");
				InserirQ();
				break;
			}
			case 2:{
				system("cls");
				ImprimirQ();
				system("pause");
				InserirQ();
				break;
			}
			case 3:{
				system("cls");
				ImprimirQ();
				break;
			}
		}system("cls");
	}while(opP!=4);
}


int InserirQ(){
	do{
	
		printf("  PRODUTOS\n");
		printf("--------------------------------\n");
		printf("  1- %s                         \n",nome);
		printf("--------------------------------\n");
		printf("  2- Sair                       \n");
		printf("--------------------------------\n");
		scanf("%d",&opP);
		switch(opP){
			case 1:{
				if(tip!=2){
					system("cls");
					printf("A quantidade maxima para esse tipo de produto e 50\n");
					printf("Quantidade atual: %d\n", qtd);
					lim=50-qtd;
					printf("Limite de compra: %d\n", lim);
					InserirP();		
					break;
				}
				else{
					system("cls");
					InserirP();		
					break;
				}	
			}
		}
	}while(opP!=2);
}
int InserirP(){
	printf("Nome do produto:      %s\n",nome);
	
	printf("Quantidade do produto:\n");
	scanf("%d", &qtd);
	
	printf("Preco do produto:\n");
	scanf("%f", &prc);
	t=(prc*qtd);
	prcT=(prc+(tax*prc)/100);
	printf("Preco total:          %.2f\n",t);
	system("pause");
	system("cls");
}

int ImprimirQ(){
	if(tip=1){
		strcpy(ti,"Perecivel");
	}
	else{
		strcpy(ti,"Nao Perecivel");
	}
	printf("Tipo do produto:             %s\n",ti);
	printf("Nome do produto:             %s\n",nome);
	printf("Quantidade do produto:       %i\n",qtd);
	printf("Preco do produto:            %.2f\n",prc);
	printf("Preco total:                 %.2f\n",t);
	system("pause");
	system("cls");
}

int Venda(){
	do{
		printf("PRODUTOS DISPONIVEIS            \n");
		printf("--------------------------------\n");
		printf(" 1- %s                          \n",nome );
		printf("--------------------------------\n");
		printf(" 2- Sair                        \n");
		printf("--------------------------------\n");
		scanf("%d",&opP);
		switch(opP){
			case 1:{
				system("cls");
				printf("Quantidade atual: %d\n", qtd);
				printf("Quantitade comprada:\n");
				scanf("%d",&lim);
				printf("Preco a pagar:   %.2f\n",prcT*lim);
				
				qtd=(qtd-lim);
				printf("Quantidade restante: %d\n", qtd);	
				fim=prcT*qtd;
				t=(prc*qtd);
				break;
				
			}system("cls");
		}
	}while(opP!=2);
	system("cls");
}

int Imprimir(){
	printf("Nome do produto:             %s\n",nome);
	printf("Quantidade do produto:       %i\n",qtd);
	printf("Preco do produto:            %.2f\n",prc);
	printf("Preco total:                 %.2f\n",t);
	printf("Preco do produto para venda: %.2f\n",prcT);
	printf("Preco total de venda:        %.2f\n",fim);
	system("pause");
}
	
int main()
{
	do{
		TelaPrincipal();
		opP=0;
		switch(op){
			case 1:{
				system("cls");
				Cadastro();
				break;
			}
			case 2:{
				system("cls");
				Estoque();
				break;

			}
			case 3:{
				system("cls");
				Venda();
				break;

			}
			case 4:{
				system("cls");
				Imprimir();
				break;	
			}
	
		}
	}while (op!=5);
}

