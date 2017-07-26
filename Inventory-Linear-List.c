#include <stdio.h>
const int leng = 10;

typedef enum { Weapon, Armor, Ring, Amulet } Type;

typedef struct {
    char name[50];
    char detail[200];
    Type type;
    int amount;
} Item;

int main(){
    //Variable Declarations
    Item item[leng];

    printf("O tamanho do inventario e: %d", (sizeof(item)/sizeof(Item)));
    return 0;
}
