#ifndef C_X_W_RELICS

#define C_X_W_RELICS
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "genericList.c"
#include "c_x_w_field_objects.c"
//#include "c_x_w_CARDS.c"


#define RELIC_DESCRIPTION_MAX_LENGTH 80
#define RELICS_COST 8


typedef enum gameRelics{
    RELIC_ID_WARRIOR_KIMONO,
    RELIC_ID_WARRIOR_SANDALS,
    RELIC_ID_WARRIOR_TONFA,
    RELIC_ID_WARRIOR_GRIP_TAPE,
    RELIC_ID_WARRIOR_DRAGON_EMBLEM,
    RELIC_ID_WARRIOR_SCROOL_OF_SNAKES,
    RELIC_ID_WARRIOR_BLOOD_ARTIFACT,
    RELIC_ID_WARRIOR_TRIBAL_BRACLET,
    RELIC_ID_WARRIOR_PAIN_MASK,
    RELIC_ID_WARRIOR_PUNCHING_GLOVES,
    RELIC_ID_ARCHER_BOOTS,
    RELIC_ID_ARCHER_POISON_VILE,
    RELIC_ID_ARCHER_GREEN_HAT,
    RELIC_ID_ARCHER_WAR_BOW,
    RELIC_ID_ARCHER_ARROWS_POCKET,
    RELIC_ID_THIEF_RUSTY_DAGGHER,
    RELIC_ID_MAGE_BOOK_OF_SPELLS,
    RELIC_ID_MAGE_NECRONOMICON,
    RELIC_ID_PALADIN_BLESSED_CROSS
}gameRelics_e;
typedef enum RelicsRechargeEventsIds{
    RECHARGE_ON_NEVER,
    RECHARGE_ON_TURN_END,
    RECHARGE_ON_BATTLE_END
}RelicsRechargeEventsIds_e;


typedef struct relic{
    int id;
    wchar_t *name;
    int *spritesIds;
    int counter;
    int showCounter;
    int *vals;
    int isActive;
    int heroOwnerId;
    int rechargeEventId;
    wchar_t description[RELIC_DESCRIPTION_MAX_LENGTH+1]; 
}relic_t;

void drawRelicSprite(int x, int y, int spriteId){
    wprintf(L"\e[%d;%dH",y,x);
    switch (spriteId)
    {
    case 0:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;247m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;247m\e[38;5;247m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄\e[38;5;15m▄▄\e[48;5;15m▄\e[48;5;250m▄▄\e[48;5;15m▄\e[48;5;247m▄▄\e[38;5;247m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[38;5;15m▄\e[48;5;15m▄▄▄▄▄\e[48;5;245m\e[38;5;245m▄\e[48;5;15m\e[38;5;15m▄▄▄▄\e[48;5;247m▄\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;15m\e[38;5;250m▄\e[38;5;15m▄\e[38;5;247m▄\e[48;5;247m▄\e[48;5;15m\e[38;5;15m▄▄▄\e[48;5;245m\e[38;5;245m▄\e[48;5;15m\e[38;5;15m▄▄\e[48;5;247m\e[38;5;247m▄\e[48;5;15m▄\e[38;5;15m▄\e[38;5;250m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[48;5;15m\e[38;5;15m▄▄▄\e[48;5;245m\e[38;5;245m▄\e[48;5;15m\e[38;5;15m▄▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[48;5;15m\e[38;5;15m▄▄▄\e[48;5;245m\e[38;5;245m▄\e[48;5;15m\e[38;5;15m▄▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;247m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 1:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;247m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;247m\e[38;5;247m▄\e[38;5;88m▄\e[48;5;88m▄\e[48;5;52m\e[38;5;52m▄\e[48;5;88m\e[38;5;88m▄\e[48;5;247m▄\e[38;5;247m▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[48;5;88m\e[38;5;88m▄\e[38;5;52m▄\e[48;5;52m\e[38;5;88m▄\e[48;5;88m\e[38;5;52m▄\e[38;5;88m▄\e[48;5;247m\e[38;5;247m▄▄\e[38;5;88m▄▄▄▄▄\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[48;5;52m\e[38;5;88m▄\e[48;5;88m▄▄▄\e[48;5;52m▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;88m\e[38;5;88m▄▄▄▄▄\e[48;5;247m\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[48;5;88m\e[38;5;88m▄▄▄▄▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;88m\e[38;5;88m▄▄▄▄▄\e[48;5;247m\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[48;5;88m▄▄▄▄▄\e[48;5;247m▄▄\e[48;5;52m\e[38;5;88m▄\e[48;5;88m\e[38;5;52m▄\e[38;5;88m▄\e[38;5;52m▄\e[48;5;52m\e[38;5;88m▄\e[48;5;247m\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄▄▄▄▄\e[48;5;88m▄\e[38;5;88m▄\e[48;5;52m\e[38;5;52m▄\e[48;5;88m\e[38;5;88m▄\e[38;5;247m▄\e[48;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;247m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 2:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;247m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;247m\e[38;5;247m▄▄▄▄▄▄▄\e[38;5;52m▄▄\e[38;5;247m▄▄▄\e[38;5;52m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄▄▄▄\e[48;5;52m▄\e[38;5;52m▄▄\e[48;5;247m▄\e[48;5;52m▄▄\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄▄▄▄▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;247m▄\e[48;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄▄▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;247m▄\e[48;5;247m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;247m▄\e[48;5;247m▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;247m▄\e[48;5;247m▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;247m\e[38;5;238m▄▄\e[48;5;52m▄▄\e[48;5;247m▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 3:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;247m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;247m\e[38;5;247m▄▄▄\e[38;5;223m▄▄▄\e[38;5;247m▄▄▄▄▄▄\e[38;5;223m▄\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;223m\e[38;5;223m▄▄\e[38;5;247m▄\e[38;5;223m▄▄\e[48;5;247m▄\e[38;5;247m▄▄\e[38;5;223m▄\e[48;5;223m▄\e[38;5;247m▄\e[48;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;223m\e[38;5;223m▄▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;223m▄\e[38;5;223m▄▄▄\e[38;5;247m▄\e[48;5;247m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;223m▄\e[38;5;223m▄\e[48;5;247m▄\e[38;5;247m▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[38;5;223m▄\e[48;5;223m▄\e[38;5;247m▄\e[48;5;247m▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[48;5;223m\e[38;5;223m▄▄\e[38;5;247m▄\e[48;5;247m▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;247m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 4:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;247m▄▄\e[38;5;196m▄\e[38;5;247m▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;247m\e[38;5;247m▄\e[48;5;196m\e[38;5;196m▄▄\e[48;5;247m▄\e[38;5;247m▄▄▄\e[38;5;196m▄▄▄\e[48;5;196m▄\e[38;5;247m▄\e[48;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;196m\e[38;5;196m▄▄▄▄\e[48;5;247m\e[38;5;247m▄\e[48;5;196m\e[38;5;196m▄▄\e[38;5;15m▄\e[38;5;196m▄\e[38;5;247m▄\e[48;5;247m▄\e[38;5;196m▄\e[48;5;196m▄\e[48;5;247m\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;196m\e[38;5;196m▄▄▄▄▄▄▄▄▄▄▄\e[38;5;247m▄\e[48;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;196m\e[38;5;196m▄▄\e[38;5;247m▄\e[48;5;247m▄\e[48;5;196m\e[38;5;196m▄▄▄▄\e[38;5;247m▄\e[48;5;247m▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;196m\e[38;5;196m▄\e[48;5;247m\e[38;5;247m▄▄▄\e[48;5;196m\e[38;5;196m▄▄▄▄\e[48;5;247m\e[38;5;247m▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄▄\e[48;5;196m▄\e[38;5;196m▄▄▄\e[48;5;247m▄▄\e[38;5;247m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;247m\e[38;5;238m▄▄▄▄▄▄▄\e[48;5;196m▄▄▄▄▄▄\e[48;5;247m▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 5:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;247m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;247m\e[38;5;247m▄\e[48;5;88m\e[38;5;88m▄\e[48;5;245m\e[38;5;245m▄▄▄▄▄▄▄▄▄▄\e[48;5;88m\e[38;5;88m▄\e[48;5;247m\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄▄\e[38;5;22m▄▄\e[38;5;246m▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;246m\e[38;5;246m▄\e[38;5;22m▄\e[48;5;22m\e[38;5;246m▄▄▄▄▄▄▄\e[48;5;246m▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;22m▄▄▄▄▄▄\e[48;5;246m\e[38;5;22m▄\e[38;5;246m▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;246m\e[38;5;246m▄\e[48;5;22m▄▄▄▄▄▄▄\e[48;5;246m▄▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[48;5;88m\e[38;5;88m▄\e[48;5;245m\e[38;5;245m▄▄▄▄▄▄▄▄▄▄\e[48;5;88m\e[38;5;88m▄\e[48;5;247m\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;247m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 6:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;247m▄▄▄\e[38;5;220m▄▄▄▄▄▄\e[38;5;247m▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;220m\e[38;5;220m▄\e[48;5;247m\e[38;5;247m▄▄\e[38;5;220m▄▄\e[38;5;247m▄▄\e[48;5;220m▄\e[48;5;247m\e[38;5;220m▄\e[38;5;247m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[48;5;220m\e[38;5;220m▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;220m▄\e[48;5;247m\e[38;5;220m▄\e[38;5;247m▄\e[48;5;220m▄\e[48;5;247m\e[38;5;220m▄▄\e[48;5;220m\e[38;5;247m▄\e[48;5;247m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[48;5;220m\e[38;5;220m▄\e[48;5;247m\e[38;5;247m▄▄▄\e[48;5;220m\e[38;5;220m▄\e[48;5;247m\e[38;5;247m▄\e[48;5;220m\e[38;5;220m▄\e[48;5;160m\e[38;5;160m▄▄\e[48;5;220m\e[38;5;220m▄\e[48;5;247m\e[38;5;247m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;220m▄\e[48;5;247m\e[38;5;220m▄\e[48;5;220m\e[38;5;247m▄\e[48;5;247m▄\e[38;5;220m▄\e[48;5;220m\e[38;5;160m▄\e[48;5;160m▄▄\e[48;5;220m▄\e[48;5;247m\e[38;5;220m▄\e[38;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄▄\e[48;5;220m\e[38;5;220m▄\e[48;5;160m\e[38;5;160m▄▄▄▄▄▄\e[48;5;220m\e[38;5;220m▄\e[48;5;247m\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄▄▄\e[48;5;220m▄\e[48;5;160m\e[38;5;220m▄\e[38;5;160m▄▄\e[38;5;220m▄\e[48;5;220m\e[38;5;247m▄\e[48;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;247m\e[38;5;238m▄▄▄▄▄▄▄▄\e[48;5;220m▄▄\e[48;5;247m▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 7:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;247m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;247m\e[38;5;247m▄▄▄\e[38;5;124m▄\e[48;5;124m▄\e[48;5;88m▄\e[48;5;124m▄\e[38;5;88m▄▄\e[38;5;124m▄\e[48;5;247m▄\e[38;5;247m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[38;5;124m▄\e[48;5;88m▄\e[48;5;124m\e[38;5;247m▄\e[48;5;247m▄▄▄▄▄▄\e[48;5;124m▄\e[48;5;88m\e[38;5;124m▄\e[48;5;247m▄\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[48;5;124m\e[38;5;124m▄\e[38;5;88m▄\e[48;5;247m\e[38;5;247m▄▄▄▄▄▄▄▄\e[48;5;88m\e[38;5;124m▄\e[48;5;124m\e[38;5;88m▄\e[48;5;247m\e[38;5;247m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[48;5;124m\e[38;5;88m▄\e[38;5;124m▄\e[48;5;247m\e[38;5;247m▄▄▄▄▄▄\e[38;5;124m▄\e[48;5;124m\e[38;5;88m▄\e[38;5;247m▄\e[48;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;88m▄\e[48;5;124m\e[38;5;124m▄\e[48;5;88m▄\e[48;5;247m\e[38;5;52m▄▄\e[48;5;124m\e[38;5;124m▄\e[48;5;88m▄\e[48;5;124m\e[38;5;247m▄\e[48;5;247m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[38;5;52m▄\e[48;5;52m\e[38;5;247m▄▄\e[48;5;247m\e[38;5;52m▄\e[38;5;247m▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;247m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 8:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;247m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;247m\e[38;5;247m▄▄▄\e[38;5;15m▄▄\e[48;5;15m▄▄▄▄\e[48;5;247m▄▄\e[38;5;247m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;15m\e[38;5;15m▄▄\e[38;5;0m▄▄\e[38;5;15m▄▄\e[38;5;0m▄▄\e[38;5;15m▄▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;15m\e[38;5;15m▄▄\e[48;5;0m\e[38;5;0m▄\e[38;5;160m▄\e[48;5;15m\e[38;5;15m▄▄\e[48;5;0m\e[38;5;160m▄\e[38;5;0m▄\e[48;5;15m\e[38;5;15m▄▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;15m\e[38;5;15m▄▄▄\e[48;5;160m\e[38;5;160m▄\e[48;5;15m\e[38;5;15m▄▄\e[48;5;160m\e[38;5;160m▄\e[48;5;15m\e[38;5;15m▄▄▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;15m▄\e[38;5;15m▄\e[38;5;160m▄\e[48;5;160m\e[38;5;0m▄\e[48;5;15m▄▄\e[48;5;160m▄\e[48;5;15m\e[38;5;160m▄\e[38;5;15m▄\e[38;5;247m▄\e[48;5;247m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[48;5;160m\e[38;5;160m▄\e[48;5;15m\e[38;5;15m▄▄▄▄\e[48;5;160m\e[38;5;160m▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;247m\e[38;5;238m▄▄▄▄\e[48;5;160m▄\e[48;5;247m▄▄▄▄\e[48;5;160m▄\e[48;5;247m▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 9:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;247m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;247m\e[38;5;247m▄\e[38;5;52m▄\e[38;5;88m▄\e[48;5;52m\e[38;5;52m▄▄▄▄▄▄▄▄\e[48;5;247m\e[38;5;247m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄\e[48;5;52m\e[38;5;52m▄\e[48;5;88m▄\e[48;5;52m▄▄▄▄▄▄▄▄\e[48;5;247m\e[38;5;247m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄\e[48;5;52m▄\e[38;5;52m▄▄▄▄▄▄▄▄\e[48;5;247m\e[38;5;247m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[48;5;88m\e[38;5;88m▄▄▄▄▄▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[48;5;88m\e[38;5;88m▄▄▄▄▄▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[48;5;88m\e[38;5;52m▄▄▄▄▄▄\e[48;5;247m\e[38;5;247m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;247m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 10:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;246m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄\e[48;5;52m\e[38;5;88m▄▄▄▄▄▄▄\e[48;5;246m\e[38;5;246m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄\e[38;5;52m▄▄▄▄\e[38;5;246m▄▄\e[48;5;88m▄\e[38;5;88m▄▄▄▄▄\e[48;5;246m\e[38;5;246m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄\e[48;5;88m\e[38;5;88m▄▄▄▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[48;5;88m\e[38;5;88m▄▄▄▄\e[48;5;246m\e[38;5;246m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄\e[48;5;88m\e[38;5;88m▄▄▄▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[48;5;88m\e[38;5;88m▄▄▄▄\e[48;5;246m\e[38;5;246m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄\e[48;5;88m\e[38;5;88m▄▄▄▄▄\e[48;5;246m▄\e[38;5;246m▄▄\e[48;5;52m▄▄▄▄\e[48;5;246m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄\e[48;5;88m\e[38;5;52m▄▄▄▄▄▄▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;246m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 11:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;246m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄\e[38;5;15m▄\e[48;5;52m\e[38;5;52m▄▄\e[48;5;246m\e[38;5;15m▄\e[38;5;246m▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄\e[48;5;15m\e[38;5;15m▄\e[48;5;246m\e[38;5;46m▄▄\e[48;5;15m\e[38;5;15m▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄\e[48;5;15m\e[38;5;15m▄\e[48;5;46m\e[38;5;46m▄▄\e[48;5;15m\e[38;5;15m▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄\e[48;5;15m\e[38;5;15m▄\e[48;5;46m\e[38;5;46m▄▄\e[48;5;15m\e[38;5;15m▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄\e[48;5;15m\e[38;5;15m▄\e[48;5;46m\e[38;5;46m▄▄\e[48;5;15m\e[38;5;15m▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄\e[48;5;15m▄▄\e[48;5;246m▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;246m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 12:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;246m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄▄▄▄▄▄\e[38;5;196m▄\e[48;5;196m▄\e[48;5;246m\e[38;5;246m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄▄▄▄▄\e[48;5;196m\e[38;5;52m▄\e[48;5;52m\e[38;5;196m▄\e[48;5;196m\e[38;5;246m▄\e[48;5;246m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄▄\e[38;5;46m▄\e[48;5;46m▄▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄\e[38;5;46m▄▄\e[48;5;46m▄▄▄▄▄▄\e[48;5;246m▄\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄\e[48;5;46m▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;246m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;246m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 13:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;246m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄▄\e[38;5;88m▄▄\e[48;5;88m▄\e[38;5;246m▄\e[38;5;222m▄\e[38;5;246m▄\e[48;5;246m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[38;5;52m▄\e[48;5;88m▄\e[48;5;52m\e[38;5;246m▄\e[48;5;88m▄\e[48;5;246m▄\e[38;5;222m▄\e[48;5;222m\e[38;5;246m▄\e[48;5;246m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄\e[48;5;88m\e[38;5;52m▄\e[48;5;52m\e[38;5;246m▄\e[48;5;246m▄▄\e[38;5;222m▄\e[48;5;222m\e[38;5;246m▄\e[48;5;246m▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;88m\e[38;5;88m▄\e[38;5;246m▄\e[48;5;246m▄\e[38;5;222m▄\e[48;5;222m\e[38;5;246m▄\e[48;5;246m▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄\e[48;5;88m\e[38;5;88m▄\e[38;5;246m▄\e[48;5;246m\e[38;5;222m▄\e[48;5;222m\e[38;5;246m▄\e[48;5;246m▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄\e[48;5;88m\e[38;5;88m▄\e[48;5;222m\e[38;5;246m▄\e[48;5;246m▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;246m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 14:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;246m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[48;5;15m\e[38;5;15m▄\e[48;5;246m\e[38;5;88m▄\e[48;5;15m\e[38;5;15m▄\e[48;5;253m\e[38;5;253m▄\e[48;5;246m\e[38;5;88m▄\e[48;5;253m\e[38;5;253m▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[38;5;52m▄\e[48;5;88m▄\e[48;5;246m▄▄\e[48;5;88m▄\e[48;5;246m▄\e[38;5;246m▄\e[38;5;124m▄\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[48;5;52m\e[38;5;52m▄▄▄▄▄▄\e[48;5;124m\e[38;5;246m▄\e[48;5;246m▄\e[48;5;52m\e[38;5;52m▄\e[48;5;246m\e[38;5;246m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[48;5;52m\e[38;5;52m▄▄▄▄▄▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;52m\e[38;5;52m▄\e[48;5;246m\e[38;5;246m▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[48;5;52m\e[38;5;52m▄▄▄▄▄▄\e[48;5;246m\e[38;5;124m▄\e[48;5;124m\e[38;5;246m▄\e[48;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[48;5;52m▄\e[38;5;52m▄▄▄▄\e[38;5;246m▄\e[48;5;246m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;246m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 15:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;246m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄▄▄▄\e[38;5;240m▄\e[48;5;239m\e[38;5;239m▄\e[38;5;240m▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄▄\e[38;5;240m▄\e[48;5;240m\e[38;5;239m▄\e[48;5;239m▄▄\e[48;5;240m\e[38;5;246m▄\e[48;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[38;5;52m▄\e[38;5;239m▄\e[48;5;239m▄▄\e[38;5;240m▄\e[48;5;240m\e[38;5;246m▄\e[48;5;246m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄\e[38;5;88m▄\e[48;5;88m▄\e[48;5;52m▄\e[48;5;239m\e[38;5;52m▄\e[48;5;240m\e[38;5;246m▄\e[48;5;246m▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄\e[38;5;88m▄\e[48;5;88m▄▄▄\e[38;5;246m▄\e[48;5;52m▄\e[48;5;246m▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄\e[48;5;88m\e[38;5;88m▄▄\e[38;5;246m▄\e[48;5;246m▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;246m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 16:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;246m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;246m\e[38;5;246m▄▄\e[38;5;52m▄\e[48;5;88m\e[38;5;251m▄▄▄▄▄▄▄▄\e[38;5;88m▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;52m\e[38;5;52m▄\e[48;5;88m\e[38;5;88m▄▄▄\e[38;5;11m▄\e[38;5;88m▄▄▄\e[48;5;251m\e[38;5;251m▄\e[48;5;88m\e[38;5;88m▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;52m\e[38;5;52m▄\e[48;5;88m\e[38;5;88m▄\e[38;5;11m▄\e[48;5;11m\e[38;5;88m▄\e[48;5;88m▄\e[48;5;11m▄\e[48;5;88m\e[38;5;11m▄\e[38;5;88m▄\e[48;5;251m\e[38;5;251m▄\e[48;5;88m\e[38;5;88m▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;52m\e[38;5;52m▄\e[48;5;88m\e[38;5;88m▄▄\e[48;5;11m▄▄▄\e[48;5;88m▄▄\e[48;5;251m\e[38;5;251m▄\e[48;5;88m\e[38;5;88m▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;52m\e[38;5;52m▄\e[48;5;88m\e[38;5;88m▄\e[38;5;11m▄\e[48;5;11m\e[38;5;88m▄\e[48;5;88m▄\e[48;5;11m▄\e[48;5;88m\e[38;5;11m▄\e[38;5;88m▄\e[48;5;251m\e[38;5;251m▄\e[48;5;88m\e[38;5;88m▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;52m\e[38;5;52m▄\e[48;5;88m\e[38;5;88m▄▄▄\e[48;5;11m▄\e[48;5;88m▄▄▄\e[48;5;251m\e[38;5;246m▄\e[48;5;246m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;246m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 17:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;246m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;246m\e[38;5;246m▄▄\e[38;5;53m▄\e[48;5;54m\e[38;5;251m▄▄▄▄▄▄▄▄\e[38;5;54m▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;53m\e[38;5;53m▄\e[48;5;54m\e[38;5;54m▄▄▄\e[38;5;3m▄\e[38;5;54m▄▄▄\e[48;5;251m\e[38;5;251m▄\e[48;5;54m\e[38;5;54m▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;53m\e[38;5;53m▄\e[48;5;54m\e[38;5;3m▄\e[38;5;54m▄\e[48;5;3m▄\e[48;5;54m▄\e[48;5;3m▄\e[48;5;54m▄\e[38;5;3m▄\e[48;5;251m\e[38;5;251m▄\e[48;5;54m\e[38;5;54m▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;53m\e[38;5;53m▄\e[48;5;54m\e[38;5;54m▄\e[48;5;3m\e[38;5;3m▄\e[48;5;54m\e[38;5;54m▄\e[48;5;3m\e[38;5;3m▄\e[48;5;54m\e[38;5;54m▄\e[48;5;3m\e[38;5;3m▄\e[48;5;54m\e[38;5;54m▄\e[48;5;251m\e[38;5;251m▄\e[48;5;54m\e[38;5;54m▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;53m\e[38;5;53m▄\e[48;5;3m\e[38;5;54m▄\e[48;5;54m▄\e[38;5;3m▄\e[38;5;54m▄\e[38;5;3m▄\e[38;5;54m▄\e[48;5;3m▄\e[48;5;251m\e[38;5;251m▄\e[48;5;54m\e[38;5;54m▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;53m\e[38;5;53m▄\e[48;5;54m\e[38;5;54m▄▄▄\e[48;5;3m▄\e[48;5;54m▄▄▄\e[48;5;251m\e[38;5;246m▄\e[48;5;246m▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;246m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    case 18:
        wprintf(L"\e[48;5;0m\e[38;5;238m▄\e[48;5;238m\e[38;5;246m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;238m▄\e[1B\e[16D\e[48;5;238m▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄\e[48;5;220m\e[38;5;220m▄▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;220m\e[38;5;220m▄▄▄▄▄▄▄▄▄▄\e[48;5;246m\e[38;5;246m▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄\e[48;5;220m\e[38;5;220m▄▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄\e[38;5;220m▄\e[48;5;220m▄▄\e[48;5;246m▄\e[38;5;246m▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄\e[48;5;220m\e[38;5;220m▄▄▄▄\e[48;5;246m\e[38;5;246m▄▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D▄\e[48;5;246m\e[38;5;246m▄▄▄▄\e[38;5;220m▄\e[48;5;220m▄▄▄▄\e[48;5;246m▄\e[38;5;246m▄▄▄▄\e[48;5;238m\e[38;5;238m▄\e[1B\e[16D\e[38;5;0m▄\e[48;5;246m\e[38;5;238m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;238m\e[38;5;0m▄");
    break;
    }
}
void drawRelic(int x, int y, relic_t *relic){
    drawRelicSprite(x,y,relic->id);
}
void updateRelicDescription(relic_t *relic){
    relic->description[0] = '\0';
    wchar_t *str = relic->description;
    int *values = relic->vals;

    switch (relic->id)
    {
    case RELIC_ID_WARRIOR_KIMONO:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"heal %d at the end of every battle",values[0]);
        break;
    case RELIC_ID_WARRIOR_SANDALS:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"gain %d mana when perfectly killing an enemy",values[0]);
        break;
    case RELIC_ID_WARRIOR_TONFA:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"every turn if the first card played kills an enemy gain a shield");
        break;
    case RELIC_ID_WARRIOR_GRIP_TAPE:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"if an attack card kills an enemy do not discard the card");
        break;
    case RELIC_ID_WARRIOR_DRAGON_EMBLEM:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"once por turn when you exhaust a card gain %d mana",values[0]);
        break;
    case RELIC_ID_WARRIOR_SCROOL_OF_SNAKES:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"enemies that damage you gain %d poison if they don't have poison",values[0]);
        break;
    case RELIC_ID_WARRIOR_BLOOD_ARTIFACT:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"when on half life or less gain %d move evety turn",values[0]);
        break;
    case RELIC_ID_WARRIOR_TRIBAL_BRACLET:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"gain %d move every %d turns",values[0],values[1]);
        break;
    case RELIC_ID_WARRIOR_PAIN_MASK:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"gain %d strength and %d stress every turn",values[0],values[1]);
        break;
    case RELIC_ID_WARRIOR_PUNCHING_GLOVES:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"every every time you directly kill an enemy lose %d stress",values[0]);
        break;
    case RELIC_ID_ARCHER_POISON_VILE:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"all ranged attacks also deal %d poison",values[0]);
        break;
    case RELIC_ID_ARCHER_BOOTS:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"start every battle with 3 more moves",values[0]);
        break;
    case RELIC_ID_ARCHER_GREEN_HAT:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"deal %d more dmg while at the center of the field",values[0]);
        break;
    case RELIC_ID_ARCHER_WAR_BOW:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"every projectile spawned give %d move",values[0]);
        break;
    case RELIC_ID_ARCHER_ARROWS_POCKET:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"every time you would get hit by your own projectile negate the damage and gain %d mana",values[0]);
        break;
    case RELIC_ID_THIEF_RUSTY_DAGGHER:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"deal %d more damage if you attack an enemy behind you",values[0]);
        break;
    case RELIC_ID_MAGE_BOOK_OF_SPELLS:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"once for turn gain %d mana if you play %d skills in the same turn",values[0],values[1]);
        break;
    case RELIC_ID_MAGE_NECRONOMICON:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"when you exhaust a card deal %d dmg to a random enemy",values[0]);
        break;
    case RELIC_ID_PALADIN_BLESSED_CROSS:
        swprintf(str,RELIC_DESCRIPTION_MAX_LENGTH,L"deal %d more dmg if you have a shield",values[0]);
        break;
    }

}
void initializeRelic(relic_t *relic, int relicId){
    relic->id = relicId;
    relic->description[0] = '\0';
    relic->isActive = 1;
    relic->rechargeEventId = RECHARGE_ON_NEVER;
    relic->showCounter = 0;

    if(relic->vals != NULL){
        free(relic->vals);
    }
    if(relic->spritesIds != NULL){
        free(relic->spritesIds);
    }

    switch (relicId)
    {
    case RELIC_ID_WARRIOR_KIMONO:
        relic->heroOwnerId = FIELD_OBJECT_ID_FIGHTER_HERO;
        relic->name = L"kimono";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 0;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        break;
    case RELIC_ID_WARRIOR_SANDALS:
        relic->heroOwnerId = FIELD_OBJECT_ID_FIGHTER_HERO;
        relic->name = L"sandals";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 1;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        break;
    case RELIC_ID_WARRIOR_TONFA:
        relic->heroOwnerId = FIELD_OBJECT_ID_FIGHTER_HERO;
        relic->name = L"tonfa";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 2;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        relic->rechargeEventId = RECHARGE_ON_TURN_END;
        break;
    case RELIC_ID_WARRIOR_GRIP_TAPE:
        relic->heroOwnerId = FIELD_OBJECT_ID_FIGHTER_HERO;
        relic->name = L"grip tape";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 3;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        break;
    case RELIC_ID_WARRIOR_DRAGON_EMBLEM:
        relic->heroOwnerId = FIELD_OBJECT_ID_FIGHTER_HERO;
        relic->name = L"dragon emblem";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 4;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        relic->rechargeEventId = RECHARGE_ON_TURN_END;
        break;
    case RELIC_ID_WARRIOR_SCROOL_OF_SNAKES:
        relic->heroOwnerId = FIELD_OBJECT_ID_FIGHTER_HERO;
        relic->name = L"scrool of snakes";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 5;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        break;
    case RELIC_ID_WARRIOR_BLOOD_ARTIFACT:
        relic->heroOwnerId = FIELD_OBJECT_ID_FIGHTER_HERO;
        relic->name = L"blood artifact";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 6;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        break;
    case RELIC_ID_WARRIOR_TRIBAL_BRACLET:
        relic->heroOwnerId = FIELD_OBJECT_ID_FIGHTER_HERO;
        relic->name = L"tribal bracelet";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 7;
        relic->vals = malloc(sizeof(int)*3);
        relic->vals[0] = 1;
        relic->vals[1] = 4;
        relic->vals[2] = 0;
        break;
    case RELIC_ID_WARRIOR_PAIN_MASK:
        relic->heroOwnerId = FIELD_OBJECT_ID_FIGHTER_HERO;
        relic->name = L"pain mask";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 8;
        relic->vals = malloc(sizeof(int)*2);
        relic->vals[0] = 1;
        relic->vals[1] = 1;
        break;
    case RELIC_ID_WARRIOR_PUNCHING_GLOVES:
        relic->heroOwnerId = FIELD_OBJECT_ID_FIGHTER_HERO;
        relic->name = L"punching gloves";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 9;
        relic->vals = malloc(sizeof(int)*2);
        relic->vals[0] = 1;
        break;
    case RELIC_ID_ARCHER_BOOTS:
        relic->heroOwnerId = FIELD_OBJECT_ID_ARCHER_HERO;
        relic->name = L"boots";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 10;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 3;
        break;
    case RELIC_ID_ARCHER_POISON_VILE:
        relic->heroOwnerId = FIELD_OBJECT_ID_ARCHER_HERO;
        relic->name = L"poison vile";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 11;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        break;
    case RELIC_ID_ARCHER_GREEN_HAT:
        relic->heroOwnerId = FIELD_OBJECT_ID_ARCHER_HERO;
        relic->name = L"green hat";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 12;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        break;
    case RELIC_ID_ARCHER_WAR_BOW:
        relic->heroOwnerId = FIELD_OBJECT_ID_ARCHER_HERO;
        relic->name = L"war bow";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 13;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        break;
    case RELIC_ID_ARCHER_ARROWS_POCKET:
        relic->heroOwnerId = FIELD_OBJECT_ID_ARCHER_HERO;
        relic->name = L"arrow's pocket";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 14;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        break;
    case RELIC_ID_THIEF_RUSTY_DAGGHER:
        relic->heroOwnerId = FIELD_OBJECT_ID_THIEF_HERO;
        relic->name = L"rusty daggher";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 15;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        break;
    case RELIC_ID_MAGE_BOOK_OF_SPELLS:
        relic->heroOwnerId = FIELD_OBJECT_ID_MAGE_HERO;
        relic->name = L"booK of spells";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 16;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        relic->rechargeEventId = RECHARGE_ON_TURN_END;
        break;
    case RELIC_ID_MAGE_NECRONOMICON:
        relic->heroOwnerId = FIELD_OBJECT_ID_MAGE_HERO;
        relic->name = L"necronomicon";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 17;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        break;
    case RELIC_ID_PALADIN_BLESSED_CROSS:
        relic->heroOwnerId = FIELD_OBJECT_ID_PALADIN_HERO;
        relic->name = L"blessed cross";
        relic->spritesIds = malloc(sizeof(int));
        relic->spritesIds[0] = 18;
        relic->vals = malloc(sizeof(int));
        relic->vals[0] = 1;
        break;
    }

    updateRelicDescription(relic);
}
relic_t * createRelic(int relicId){
    relic_t * relic = malloc(sizeof(relic_t));
    relic->spritesIds = NULL;
    relic->vals = NULL;
    initializeRelic(relic,relicId);
    return relic;
}
void destroyRelic(relic_t *relic){
    free(relic->spritesIds);
    free(relic->vals);
    free(relic);
}
relic_t * getHeroDefaultRelic(int heroId){
    switch(heroId){
        case FIELD_OBJECT_ID_FIGHTER_HERO:
            return createRelic(RELIC_ID_WARRIOR_KIMONO);
            break;
        case FIELD_OBJECT_ID_ARCHER_HERO:
            return createRelic(RELIC_ID_ARCHER_BOOTS);
            break;
        case FIELD_OBJECT_ID_THIEF_HERO:
            return createRelic(RELIC_ID_THIEF_RUSTY_DAGGHER);
            break;
        case FIELD_OBJECT_ID_MAGE_HERO:
            return createRelic(RELIC_ID_MAGE_BOOK_OF_SPELLS);
            break;
        case FIELD_OBJECT_ID_PALADIN_HERO:
            return createRelic(RELIC_ID_PALADIN_BLESSED_CROSS);
            break;
    }
    return NULL;
}
genericListNode_t * getHeroRelicsPool(int heroId){
    genericListNode_t *listHead = NULL;
    switch(heroId){
        case FIELD_OBJECT_ID_FIGHTER_HERO:
            genList_AddStart(&listHead,genList_createNode(createRelic(RELIC_ID_WARRIOR_SANDALS)));
            genList_AddStart(&listHead,genList_createNode(createRelic(RELIC_ID_WARRIOR_TONFA)));
            genList_AddStart(&listHead,genList_createNode(createRelic(RELIC_ID_WARRIOR_GRIP_TAPE)));
            genList_AddStart(&listHead,genList_createNode(createRelic(RELIC_ID_WARRIOR_DRAGON_EMBLEM)));
            genList_AddStart(&listHead,genList_createNode(createRelic(RELIC_ID_WARRIOR_SCROOL_OF_SNAKES)));
            genList_AddStart(&listHead,genList_createNode(createRelic(RELIC_ID_WARRIOR_BLOOD_ARTIFACT)));
            genList_AddStart(&listHead,genList_createNode(createRelic(RELIC_ID_WARRIOR_TRIBAL_BRACLET)));
            genList_AddStart(&listHead,genList_createNode(createRelic(RELIC_ID_WARRIOR_PAIN_MASK)));
            genList_AddStart(&listHead,genList_createNode(createRelic(RELIC_ID_WARRIOR_PUNCHING_GLOVES)));
            break;
        case FIELD_OBJECT_ID_ARCHER_HERO:
        
            break;
        case FIELD_OBJECT_ID_THIEF_HERO:
        
            break;
        case FIELD_OBJECT_ID_MAGE_HERO:
        
            break;
        case FIELD_OBJECT_ID_PALADIN_HERO:
        
            break;
    }
    return listHead;
}



#endif