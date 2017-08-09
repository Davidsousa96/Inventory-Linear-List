#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void printManual(){
    printf("1 - Inserir Item\n");
    printf("2 - Excluir Item\n");
    printf("3 - Listar Itens\n");
    printf("4 - Buscar Por Nome\n");
    printf("5 - Buscar Por Tipo\n");
    printf("9 - Sair\n\n");
}

void printTypes(){
    printf("0 - Arma\n");
    printf("1 - Armadura\n");
    printf("2 - Anel\n");
    printf("3 - Amuleto\n");
    printf("9 - Sair\n\n");
}

void addItem(){
    system("cls || clear");
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
    if(totalItems != 0){
        int i;
        for(i=0; i<totalItems; i++){
            printf("Nome: %s\n", item[i].name);
            printf("Descricao: %s\n", item[i].detail);
            switch(item[i].type){
            case Weapon:
                printf("Tipo: Arma\n");
                break;
            case Armor:
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
    } else {
        printf("Nao ha nenhum item no inventario.\n\n");
    }

    system("pause");
}

void nameSearch(){
    system("cls");

    if(totalItems != 0){
        char nameItem[50];
        int i, found = 0;
        printf("Digite o nome do item: ");
        scanf(" %[^\n]s\n", nameItem);
        for(i=0; i<totalItems; i++){
            if(strcmp(item[i].name, nameItem) == 0){
                printf("Nome: %s\n", item[i].name);
                printf("Descricao: %s\n", item[i].detail);
                switch(item[i].type){
                case Weapon:
                    printf("Tipo: Arma\n");
                    break;
                case Armor:
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
                found = 1;
            }
        }
        if(found == 0){
            printf("O dado não existe.\n");
        }
    } else {
        printf("Nao ha nenhum item no inventario.\n\n");
    }
    system("pause");
}

void typeSearch(){
    system("cls");

    if(totalItems != 0){
        printTypes();
        int i, typeItem;
        printf("Digite o tipo para a busca: ");
        scanf("%d", &typeItem);
        for(i=0; i<totalItems; i++){
            if(item[i].type == typeItem){
                printf("Nome: %s\n", item[i].name);
                printf("Descricao: %s\n", item[i].detail);
                printf("Quantidade: %d\n", item[i].amount);
                printf("\n");
            }
        }
    } else {
        printf("Nao ha nenhum item no inventario.\n\n");
    }

    system("pause");
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
    } while (option != 9);

    if(totalItems>=0){
        file = fopen("Inventory.dat","w");
        fwrite(&totalItems, sizeof(int), 1, file);
        fwrite(item, sizeof(Item), totalItems, file);
        fclose(file);
    }

    free(item);
    return 0;
}
