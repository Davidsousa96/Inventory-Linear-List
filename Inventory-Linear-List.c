#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int leng = 15;

typedef enum { Weapon, Armor, Ring, Amulet } Type;

typedef struct {
    char name[50];
    char detail[200];
    Type type;
    int amount;
} Item;

Item *item;
int totalItems;
FILE *file;

/*void Delete(char* nome){

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
void imprimeItem(Item* i){

	printf("Nome: %s\n", i->name);
	printf("Detalhes: %s\n", i->detail);
	printf("Quantidade: %d\n", i->amount);
}
void inventario(){
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
}*/

void addItem(){
    system("cls");
    printf("Nome: ");
    scanf(" %[^\n]s", item[totalItems].name);
    printf("Descricao: ");
    scanf(" %[^\n]s", item[totalItems].detail);
    printf("Tipo: ");
    scanf(" %d", &item[totalItems].type);
    printf("Quantidade: ");
    scanf(" %d", &item[totalItems].amount);
    totalItems++;
}

void allSearch(){
    system("cls");
    int i;
    for(i=0; i<totalItems; i++){
        printf("Nome: %s\n", item[i].name);
        printf("Descricao: %s\n", item[i].detail);
        switch(item[i].type){
        case Armor:
            printf("Tipo: Arma\n");
            break;
        case Weapon:
            printf("Tipo: Armadura\n");
            break;
        case Ring:
            printf("Tipo: Anel\n");
            break;
        case Amulet:
            printf("Tipo: Amuleto\n");
            break;
        }
        printf("Quantidade: %d\n", item[i].amount);
        printf("\n");
    }
    system("pause");
}

void nameSearch(){
}

void typeSearch(){
}

void printManual(){
    printf("1 - Inserir Item\n");
    printf("2 - Excluir Item\n");
    printf("3 - Listar Itens\n");
    printf("4 - Buscar Item Por Nome\n");
    printf("5 - Buscar Tipo\n");
    printf("0 - Sair\n\n");
}

void printTypes(){
    printf("1 - Arma\n");
    printf("2 - Armadura\n");
    printf("3 - Anél\n");
    printf("4 - Amuleto\n");
    printf("0 - Sair\n\n");
}

int main(){

    int option;

    file = fopen("Inventory.dat","r");

    if(file == NULL){
        totalItems = 0;
        item = (Item *)malloc(sizeof(Item) * leng);
    } else {
        fread(&totalItems, sizeof(int), 1, file);
        item = (Item *)malloc(sizeof(Item) * leng);
        fread(item, sizeof(Item), totalItems, file);
        fclose(file);
    }

    do {
        system("cls");
        printManual();
        scanf("%d", &option);
        switch(option){
            case 1:
                addItem();
            break;
            case 2:
            break;
            case 3:
                allSearch();
            break;
            case 4:
                nameSearch();
            break;
            case 5:
                typeSearch();
            break;
        }
    } while (option != 0);

    if(totalItems>0){
        file = fopen("Inventory.dat","w");
        fwrite(&totalItems, sizeof(int), 1, file);
        fwrite(item, sizeof(Item), totalItems, file);
        fclose(file);
    }

    free(item);
    return 0;
}
