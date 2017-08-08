#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int leng = 10;

typedef enum { Weapon, Armor, Ring, Amulet } Type;

typedef struct {
    char name[50];
    char detail[200];
    Type type;
    int amount;
    void *next;
} Item;

Item *head, *tail;

void AnulaHT()
{
	head=NULL;
	tail=NULL;
}
void Delete(char* nome){
	Item *aux, *anterior;
	aux=head;
	while(strcmp(aux->name,nome)!=0 && aux->next!=NULL){
		anterior=aux;
		aux=aux->next;
	}
	if(strcmp(aux->name,nome)==0){
		if(aux==tail){
			tail=anterior;
			tail->next=NULL;
			free(aux);
		}else if(aux==head){
			head=aux->next;
			aux->next=NULL;
			free(aux);
		}else{
			anterior->next=aux->next;
			aux->next=NULL;
			free(aux);
		}
	}else{
		printf("Esse item nao existe.\n");
	}

	
}
void Add(char* nome, char* detalhe, Type tipo, int qtd){
	Item* item;
	item = (Item*)malloc(sizeof(Item));
	
	item->amount=qtd;
	strcpy(item->detail,detalhe);
	strcpy(item->name,nome);
	item->type=tipo;
	
	if(head==NULL)
	{
		head=item;
		tail=item;
	}else{
		tail->next=item;
		tail=item;
	}
	item->next=NULL;
}
void imprimeItem(Item* i)
{
	printf("Nome: %s\n", i->name);
	printf("Detalhes: %s\n", i->detail);
	printf("Quantidade: %d\n", i->amount);
}
void inventario()
{
	if(head==NULL)
	{
		printf("Vazio\n");
	}else{
		Item *aux=head;
		while(aux!=NULL)
		{
			imprimeItem(aux);
			printf("\n");
			if(aux->next!=NULL)
				aux=aux->next;
			else break;
		}
	}
}

int main(){
	AnulaHT();
	
	/*char nome[50], detalhe[200];
	Type tipo;
	int qtd;
	
	printf("Nome?");
	scanf("%s",nome);
	scanf("%*c");
	printf("\nDetalhe?");
	scanf("%[^\n]s", detalhe);
	printf("\nTipo?(0=Weapon, 1=Armor, 2=Ring, 3=Amulet)");
	scanf("%d",&tipo);
	printf("\nQuantidade?");
	scanf("%d",&qtd);
	
	Add(nome,detalhe,tipo,qtd);
	imprimeItem(tail);*/
	Add("Batata","Frita",3,5);
	Add("Pipoca","Quente na manteiga",1,3);
    Add("mm","Quente na manteiga",1,3);
	Add("mdad","Quente na manteiga",1,3);
	Add("ddeasd","Quente na manteiga",1,3);
	inventario();
	Delete("Batata");
	inventario();
	Delete("ddeasd");
	inventario();
	Delete("mm");
	inventario();
	Delete("COCO");
    
    
	return 0;
    
}
