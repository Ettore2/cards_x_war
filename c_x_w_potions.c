#ifndef C_X_W_POTIONS

#define C_X_W_POTIONS
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct potion{
    int id;
    wchar_t *name;
    int spriteId;
    int val;
}potion_t;

void initializePotion(potion_t *potion, int potionId){
    potion->id = potionId;

    switch (potionId)
    {
    default:
        break;
    }


}
potion_t * createPotion(int potionId){
    potion_t * potion = malloc(sizeof(potion_t));
    initializePotion(potion,potionId);
    return potion;
}
void destroyPotion(potion_t *potion){
    free(potion);
}


#endif