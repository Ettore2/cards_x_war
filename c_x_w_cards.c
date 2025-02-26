#ifndef C_X_W_CARDS


#define C_X_W_CARDS
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "genericList.c"
#include "c_x_w_field_objects.c"

#define CARD_DESCRIPTION_MAX_LENGTH 100
#define CARD_FULL_NAME_MAX_LENGTH 20
const int CARDS_BG_COLORS[] = {51,82,214};
const int CARDS_FG_COLORS[] = {0,0,0};
const int CARDS_COSTS[] = {5,7,10};
const int CARDS_BASE_REMOVE_COST = 5;
const int CARDS_INCREMENT_COST = 1;

typedef enum gameCards{
    CARD_FIGHTER_MOVE,
    CARD_FIGHTER_PUNCH,
    CARD_FIGHTER_THROW,
    CARD_FIGHTER_PUSH,
    CARD_FIGHTER_SPINING_PUNCH,
    CARD_FIGHTER_RETRIVE,
    CARD_FIGHTER_RAGE,
    CARD_FIGHTER_SPEAR_POKE,
    CARD_FIGHTER_WAKEUP_ATTACK,
    CARD_FIGHTER_KICK,
    CARD_FIGHTER_MANTRA,
    CARD_FIGHTER_ETERNAL_KATANA,
    CARD_FIGHTER_SCYTHE,
    CARD_FIGHTER_SPECIAL_PUNCH,
    CARD_FIGHTER_SCREAM,
    CARD_FIGHTER_COOL_OFF,
    CARD_FIGHTER_BLOODSHOOT,
    CARD_FIGHTER_BONE_CUTTER,
    CARD_FIGHTER_BLACK_HEART,
    CARD_FIGHTER_SURROUNDED,
    CARD_FIGHTER_MEDITATE,
    CARD_FIGHTER_CURSED_SWORD,
    CARD_ARCHER_MOVE,
    CARD_ARCHER_STAB_ATTACK,
    CARD_ARCHER_ARROW,
    CARD_ARCHER_LEAP,
    CARD_ARCHER_TO_SAFETY,
    CARD_ARCHER_WIND_DANCE,
    CARD_ARCHER_HARPOON,
    CARD_ARCHER_WIND_BLADE,
    CARD_ARCHER_CROSSBOW,
    CARD_ARCHER_CROSSBOW_RELOAD,
    CARD_ARCHER_ACROBATIC_SHOT,
    CARD_THIEF_MOVE,
    CARD_THIEF_BACKSTAB,
    CARD_THIEF_SPIN,
    CARD_THIEF_DASH,
    CARD_THIEF_JOLLY_CARD,
    CARD_THIEF_SMOKE_BOMB,
    CARD_THIEF_DAGGHER,
    CARD_THIEF_SNEEK,
    CARD_THIEF_CURVED_BLADE,
    CARD_THIEF_DISTRACTION,
    CARD_THIEF_ENRAGE,
    CARD_THIEF_FLEE,
    CARD_THIEF_CONFUSION,
    CARD_THIEF_FAST_SLASH,
    CARD_THIEF_SMOKE_GRANADE,
    CARD_THIEF_SERRATED_BLADE,
    CARD_CURSE_TIRED
}gameCards_e;
typedef enum cardsRarity{
    CARD_COMON,
    CARD_RARE,
    CARD_EPIC
}cardsRarity_e;

typedef struct card{
    int id, level;
    wchar_t *baseName, fullName[CARD_FULL_NAME_MAX_LENGTH];
    wchar_t description[CARD_DESCRIPTION_MAX_LENGTH+1];
    int ownerId;
    int *spritesIds;
    int *vals;
    int retain;
    int exhaust;
    int nonPermanent;
    int fragial;
    int giveOvercharge;
    int blockTheSlot;
    int rarity;
}card_t;

void drawCardSprite(int x, int y, int spriteId){
    wprintf(L"\e[%d;%dH",y,x);
    switch (spriteId){
        case 0:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄\e[38;5;4m▄\e[48;5;4m▄\e[48;5;39m▄\e[38;5;39m▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄\e[38;5;4m▄\e[48;5;4m▄▄▄▄▄\e[48;5;39m▄\e[38;5;39m▄▄▄▄\e[1B\e[16D▄▄▄\e[38;5;4m▄\e[48;5;4m▄▄▄▄▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄\e[1B\e[16D▄▄▄\e[48;5;4m▄\e[38;5;4m▄▄▄▄▄\e[48;5;39m▄\e[38;5;39m▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄\e[48;5;4m▄\e[38;5;4m▄▄▄▄\e[48;5;39m▄\e[38;5;39m▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄\e[48;5;4m▄\e[38;5;4m▄▄▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        case 1:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄\e[38;5;21m▄▄\e[38;5;20m▄▄\e[38;5;39m▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄\e[48;5;21m\e[38;5;21m▄▄\e[48;5;20m\e[38;5;20m▄\e[38;5;21m▄\e[48;5;21m▄\e[38;5;20m▄\e[48;5;39m▄\e[38;5;39m▄▄▄\e[1B\e[16D▄▄▄▄▄▄\e[48;5;21m\e[38;5;21m▄▄▄▄\e[48;5;20m\e[38;5;20m▄\e[38;5;21m▄\e[48;5;21m▄\e[48;5;39m\e[38;5;39m▄▄▄\e[1B\e[16D\e[38;5;17m▄\e[38;5;39m▄▄▄\e[38;5;17m▄\e[48;5;17m▄\e[48;5;21m▄\e[38;5;21m▄▄▄▄\e[38;5;27m▄\e[48;5;27m▄\e[48;5;39m\e[38;5;39m▄▄▄\e[1B\e[16D\e[48;5;17m\e[38;5;17m▄▄\e[48;5;39m▄\e[48;5;17m▄▄▄▄\e[38;5;39m▄\e[48;5;27m\e[38;5;27m▄\e[48;5;39m\e[38;5;39m▄\e[48;5;27m▄\e[38;5;27m▄\e[48;5;39m\e[38;5;39m▄▄▄▄\e[1B\e[16D\e[48;5;17m▄\e[38;5;17m▄▄▄▄\e[38;5;39m▄\e[48;5;39m▄▄\e[38;5;27m▄\e[38;5;39m▄\e[48;5;27m\e[38;5;27m▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄\e[38;5;27m▄\e[38;5;39m▄▄\e[48;5;27m\e[38;5;27m▄\e[48;5;39m\e[38;5;39m▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄\e[48;5;27m▄\e[48;5;39m▄▄▄▄▄▄");
        break;
        case 2:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄\e[38;5;63m▄▄▄\e[38;5;39m▄\e[38;5;196m▄\e[48;5;196m▄\e[48;5;39m▄\e[38;5;39m▄\e[1B\e[16D▄▄▄▄▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄▄\e[48;5;39m▄▄▄▄\e[48;5;196m\e[38;5;196m▄▄▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D▄▄▄▄\e[48;5;63m\e[38;5;63m▄\e[48;5;39m\e[38;5;39m▄▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄▄▄\e[48;5;39m▄▄\e[48;5;196m▄\e[48;5;39m▄▄\e[1B\e[16D▄▄▄\e[48;5;63m\e[38;5;63m▄\e[48;5;39m\e[38;5;39m▄▄\e[48;5;63m\e[38;5;63m▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄\e[48;5;63m▄\e[48;5;39m▄▄\e[48;5;63m▄\e[48;5;39m▄▄▄▄▄▄▄▄▄\e[1B\e[16D\e[48;5;17m\e[38;5;17m▄▄▄\e[48;5;39m▄\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D\e[48;5;17m\e[38;5;17m▄▄▄▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        case 3:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄\e[38;5;21m▄▄\e[38;5;39m▄▄▄▄\e[38;5;63m▄\e[38;5;39m▄▄▄▄\e[38;5;196m▄▄\e[38;5;39m▄▄\e[1B\e[16D\e[48;5;17m\e[38;5;17m▄\e[48;5;21m\e[38;5;21m▄▄▄▄\e[48;5;39m▄\e[38;5;63m▄\e[48;5;63m▄▄\e[48;5;39m▄\e[38;5;39m▄\e[48;5;196m\e[38;5;196m▄▄▄▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D\e[48;5;17m\e[38;5;17m▄\e[48;5;21m\e[38;5;21m▄▄▄▄▄\e[48;5;63m\e[38;5;63m▄▄▄▄▄\e[48;5;196m\e[38;5;196m▄▄▄▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D\e[48;5;17m\e[38;5;17m▄\e[48;5;21m\e[38;5;39m▄▄▄▄\e[48;5;63m▄▄\e[38;5;63m▄▄\e[38;5;39m▄\e[48;5;39m▄\e[48;5;196m▄\e[38;5;196m▄▄\e[38;5;39m▄\e[48;5;39m▄\e[1B\e[16D\e[48;5;17m▄\e[48;5;39m▄▄▄▄▄▄\e[48;5;63m▄\e[48;5;39m▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        case 4:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄\e[38;5;63m▄\e[38;5;39m▄▄\e[38;5;63m▄\e[38;5;39m▄▄▄▄▄▄▄▄\e[38;5;63m▄\e[38;5;39m▄\e[1B\e[16D▄▄▄\e[38;5;63m▄\e[38;5;39m▄▄\e[48;5;63m▄\e[48;5;39m▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄▄▄\e[1B\e[16D▄▄▄\e[48;5;63m▄\e[48;5;39m▄\e[48;5;63m▄\e[48;5;39m\e[38;5;63m▄\e[38;5;39m▄▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄▄\e[1B\e[16D▄▄▄▄\e[38;5;63m▄\e[38;5;39m▄▄▄▄\e[38;5;63m▄\e[38;5;39m▄\e[38;5;63m▄\e[38;5;39m▄▄▄▄\e[1B\e[16D▄▄▄▄▄\e[48;5;63m▄\e[48;5;39m▄▄\e[48;5;63m▄\e[48;5;39m▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄\e[48;5;63m▄\e[48;5;39m\e[38;5;63m▄▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄\e[48;5;20m\e[38;5;20m▄\e[48;5;21m\e[38;5;21m▄\e[48;5;20m\e[38;5;20m▄\e[48;5;21m\e[38;5;21m▄\e[48;5;20m\e[38;5;20m▄\e[48;5;21m\e[38;5;21m▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄\e[48;5;20m▄\e[48;5;21m\e[38;5;21m▄▄▄▄▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄");
        break;
        case 5:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄\e[38;5;63m▄\e[48;5;63m▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄\e[38;5;63m▄\e[48;5;63m▄▄▄▄▄▄▄▄▄▄▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D▄\e[38;5;63m▄\e[48;5;63m▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D▄\e[48;5;63m▄\e[38;5;63m▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D▄▄▄\e[48;5;63m▄\e[38;5;63m▄▄▄▄▄▄▄▄▄▄▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D▄▄▄▄▄\e[48;5;63m▄\e[38;5;63m▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        case 6:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄\e[48;5;196m▄\e[48;5;39m▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄\e[48;5;196m▄\e[48;5;39m▄▄\e[38;5;160m▄\e[48;5;160m▄\e[48;5;39m\e[38;5;39m▄\e[48;5;196m▄\e[48;5;39m▄▄▄▄\e[1B\e[16D▄▄▄▄\e[38;5;160m▄\e[48;5;160m▄\e[48;5;39m▄\e[38;5;39m▄\e[48;5;160m\e[38;5;160m▄▄\e[48;5;39m\e[38;5;39m▄\e[38;5;160m▄\e[38;5;39m▄▄▄▄\e[1B\e[16D▄▄▄\e[38;5;160m▄\e[48;5;160m▄▄▄▄▄▄\e[48;5;39m▄\e[48;5;160m▄▄\e[48;5;39m\e[38;5;39m▄▄▄\e[1B\e[16D▄▄▄\e[48;5;160m\e[38;5;160m▄▄▄\e[38;5;196m▄\e[48;5;196m▄▄\e[48;5;160m▄\e[38;5;160m▄▄▄\e[48;5;39m\e[38;5;39m▄▄▄\e[1B\e[16D▄▄▄\e[48;5;160m\e[38;5;160m▄▄\e[48;5;196m\e[38;5;196m▄\e[38;5;208m▄\e[48;5;208m▄▄\e[48;5;196m▄\e[38;5;196m▄\e[48;5;160m\e[38;5;160m▄▄\e[48;5;39m\e[38;5;39m▄▄▄\e[1B\e[16D▄▄▄\e[48;5;160m▄\e[38;5;160m▄\e[48;5;196m▄\e[48;5;208m\e[38;5;196m▄▄▄▄\e[48;5;196m\e[38;5;160m▄\e[48;5;160m▄\e[38;5;39m▄\e[48;5;39m▄▄▄\e[1B\e[16D▄▄▄▄▄\e[48;5;160m▄▄▄▄▄▄\e[48;5;39m▄▄▄▄▄");
        break;
        case 7:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄\e[38;5;63m▄▄\e[48;5;63m\e[38;5;39m▄\e[38;5;8m▄▄\e[48;5;8m\e[38;5;63m▄\e[1B\e[16D\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄\e[38;5;8m▄\e[48;5;8m▄▄▄\e[38;5;39m▄\e[48;5;63m\e[38;5;63m▄\e[1B\e[16D\e[48;5;39m\e[38;5;39m▄▄▄▄\e[38;5;63m▄\e[38;5;39m▄\e[48;5;63m▄\e[48;5;39m▄▄\e[38;5;52m▄\e[48;5;8m▄\e[38;5;8m▄▄\e[38;5;39m▄\e[48;5;39m▄▄\e[1B\e[16D▄▄▄\e[48;5;63m▄\e[48;5;39m▄▄▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;39m▄\e[48;5;39m▄▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄\e[1B\e[16D▄▄▄▄▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄\e[48;5;63m▄\e[48;5;39m▄▄▄\e[1B\e[16D▄▄▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄▄▄▄\e[1B\e[16D▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D\e[48;5;52m\e[38;5;52m▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        case 8:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D\e[38;5;63m▄\e[48;5;63m\e[38;5;21m▄▄▄▄\e[48;5;39m\e[38;5;39m▄▄\e[48;5;63m▄▄▄\e[48;5;39m▄\e[48;5;63m▄▄\e[48;5;39m▄\e[48;5;63m▄\e[48;5;39m▄\e[1B\e[16D\e[48;5;63m\e[38;5;63m▄\e[48;5;21m\e[38;5;21m▄▄▄▄▄▄▄▄▄\e[48;5;17m\e[38;5;17m▄▄▄▄▄▄\e[1B\e[16D\e[48;5;63m\e[38;5;63m▄\e[48;5;21m\e[38;5;21m▄▄▄▄▄▄▄▄▄\e[48;5;17m\e[38;5;17m▄▄▄▄▄▄\e[1B\e[16D\e[48;5;39m\e[38;5;39m▄\e[48;5;63m▄\e[48;5;21m\e[38;5;63m▄▄▄\e[48;5;39m\e[38;5;39m▄\e[38;5;63m▄▄\e[38;5;39m▄▄\e[48;5;17m\e[38;5;17m▄▄▄▄▄▄\e[1B\e[16D\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄\e[38;5;63m▄▄▄\e[38;5;39m▄\e[38;5;63m▄▄\e[38;5;39m▄\e[38;5;63m▄\e[38;5;39m▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        case 9:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄▄▄\e[38;5;63m▄▄\e[38;5;39m▄▄▄\e[1B\e[16D▄▄\e[48;5;63m▄\e[48;5;39m▄\e[48;5;63m▄▄\e[48;5;39m▄\e[48;5;63m▄▄▄\e[48;5;39m\e[38;5;21m▄\e[48;5;21m▄\e[48;5;52m\e[38;5;52m▄\e[48;5;63m\e[38;5;63m▄\e[48;5;39m\e[38;5;39m▄▄\e[1B\e[16D\e[38;5;63m▄▄\e[38;5;39m▄\e[38;5;17m▄\e[48;5;21m\e[38;5;21m▄▄▄▄▄▄▄▄\e[48;5;52m\e[38;5;52m▄\e[48;5;63m\e[38;5;63m▄\e[48;5;39m\e[38;5;39m▄▄\e[1B\e[16D▄\e[38;5;17m▄\e[48;5;17m▄▄▄\e[48;5;21m▄\e[38;5;21m▄▄▄▄▄▄\e[48;5;52m\e[38;5;52m▄\e[48;5;63m\e[38;5;63m▄\e[48;5;39m\e[38;5;39m▄▄\e[1B\e[16D\e[48;5;17m\e[38;5;17m▄▄▄▄▄▄\e[38;5;39m▄\e[48;5;21m▄▄▄▄\e[38;5;63m▄\e[48;5;52m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄▄\e[1B\e[16D\e[48;5;17m\e[38;5;17m▄▄▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄\e[38;5;63m▄\e[38;5;39m▄\e[38;5;63m▄▄\e[38;5;39m▄▄▄▄\e[1B\e[16D\e[48;5;17m\e[38;5;17m▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        case 10:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄\e[38;5;63m▄\e[48;5;21m\e[38;5;21m▄▄\e[48;5;39m\e[38;5;63m▄\e[38;5;39m▄▄▄▄▄▄\e[1B\e[16D▄▄\e[38;5;17m▄▄\e[48;5;63m\e[38;5;39m▄▄\e[48;5;39m▄▄▄▄\e[48;5;63m▄\e[48;5;39m\e[38;5;63m▄▄\e[38;5;39m▄▄▄\e[1B\e[16D▄▄\e[48;5;17m▄\e[38;5;63m▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄\e[48;5;19m\e[38;5;19m▄▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D▄▄▄\e[48;5;63m\e[38;5;63m▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄▄\e[1B\e[16D▄▄▄▄\e[48;5;63m\e[38;5;63m▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄\e[38;5;20m▄▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄▄▄\e[1B\e[16D▄▄▄▄▄\e[48;5;18m\e[38;5;18m▄▄\e[48;5;39m\e[38;5;63m▄▄\e[48;5;63m\e[38;5;39m▄\e[48;5;20m▄▄\e[48;5;39m▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        case 11:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄\e[38;5;14m▄\e[38;5;158m▄\e[38;5;39m▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄▄▄\e[38;5;14m▄\e[48;5;14m▄\e[38;5;158m▄\e[48;5;158m\e[38;5;39m▄\e[48;5;39m▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄\e[38;5;14m▄\e[48;5;14m▄\e[38;5;158m▄\e[48;5;158m\e[38;5;39m▄\e[48;5;39m▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄\e[38;5;14m▄\e[48;5;14m▄\e[38;5;158m▄\e[48;5;158m\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄\e[1B\e[16D▄▄▄\e[38;5;52m▄\e[38;5;39m▄\e[38;5;14m▄\e[48;5;14m▄\e[38;5;158m▄\e[48;5;158m\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄\e[38;5;88m▄\e[48;5;52m▄\e[48;5;14m\e[38;5;52m▄\e[48;5;158m\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄\e[38;5;88m▄\e[48;5;88m▄▄\e[38;5;39m▄\e[48;5;39m▄\e[48;5;52m▄\e[48;5;39m▄▄▄▄▄▄▄▄▄\e[1B\e[16D\e[48;5;88m\e[38;5;88m▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        case 12:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄\e[38;5;8m▄\e[38;5;39m▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄\e[48;5;8m▄\e[38;5;8m▄▄\e[48;5;39m▄\e[48;5;52m▄\e[38;5;52m▄\e[48;5;39m\e[38;5;39m▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄\e[38;5;52m▄\e[48;5;52m▄\e[48;5;8m▄\e[38;5;8m▄▄\e[48;5;39m▄\e[38;5;39m▄\e[1B\e[16D▄▄▄▄▄▄▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;39m▄\e[48;5;39m▄▄\e[48;5;8m▄\e[38;5;8m▄▄\e[1B\e[16D\e[48;5;39m\e[38;5;39m▄▄▄▄▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄\e[48;5;8m\e[38;5;8m▄▄\e[1B\e[16D\e[48;5;39m\e[38;5;39m▄▄▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄\e[38;5;8m▄\e[48;5;8m▄▄\e[1B\e[16D\e[48;5;39m\e[38;5;39m▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄▄▄\e[48;5;8m\e[38;5;8m▄▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D\e[48;5;52m\e[38;5;52m▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        case 13:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄\e[38;5;220m▄▄\e[48;5;220m▄▄\e[48;5;39m▄▄\e[38;5;39m▄▄▄▄▄\e[1B\e[16D▄\e[38;5;220m▄▄\e[48;5;220m▄▄\e[38;5;21m▄▄\e[38;5;20m▄▄\e[38;5;21m▄▄\e[38;5;220m▄▄\e[48;5;39m▄▄\e[38;5;39m▄\e[1B\e[16D\e[48;5;220m▄\e[38;5;220m▄▄\e[48;5;20m\e[38;5;20m▄▄\e[48;5;21m\e[38;5;21m▄▄\e[48;5;20m▄▄\e[48;5;21m▄▄\e[48;5;20m\e[38;5;20m▄▄\e[48;5;220m\e[38;5;220m▄▄\e[38;5;39m▄\e[1B\e[16D\e[48;5;39m▄▄\e[48;5;220m▄\e[48;5;20m\e[38;5;20m▄▄\e[48;5;21m\e[38;5;21m▄▄▄▄▄▄▄▄\e[48;5;220m\e[38;5;39m▄\e[48;5;39m▄▄\e[1B\e[16D▄▄▄▄\e[48;5;20m\e[38;5;21m▄\e[48;5;21m▄▄▄▄▄▄▄▄\e[48;5;39m\e[38;5;39m▄▄▄\e[1B\e[16D▄▄▄\e[48;5;220m\e[38;5;220m▄\e[48;5;21m▄\e[38;5;21m▄▄▄▄▄▄▄\e[38;5;220m▄\e[48;5;220m▄\e[48;5;39m\e[38;5;39m▄▄\e[1B\e[16D▄▄\e[48;5;220m\e[38;5;220m▄▄\e[38;5;39m▄\e[48;5;21m\e[38;5;21m▄▄▄▄▄▄▄\e[48;5;220m\e[38;5;39m▄\e[38;5;220m▄▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D▄▄\e[48;5;220m▄\e[48;5;39m▄▄\e[48;5;21m\e[38;5;21m▄▄▄▄▄▄▄\e[48;5;39m\e[38;5;39m▄▄\e[48;5;220m▄\e[48;5;39m▄");
        break;
        case 14:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄\e[38;5;27m▄\e[48;5;27m\e[38;5;39m▄\e[48;5;39m▄▄\e[38;5;27m▄\e[48;5;27m\e[38;5;39m▄▄▄▄\e[48;5;39m\e[38;5;27m▄\e[38;5;39m▄▄\e[48;5;27m▄\e[48;5;39m\e[38;5;27m▄\e[38;5;39m▄\e[1B\e[16D\e[48;5;27m▄\e[48;5;39m▄▄▄▄▄\e[38;5;27m▄▄▄▄\e[38;5;39m▄▄▄▄▄\e[48;5;27m▄\e[1B\e[16D\e[48;5;39m▄▄▄▄\e[48;5;27m▄▄\e[48;5;39m▄▄▄▄\e[48;5;27m▄▄\e[48;5;39m▄▄▄▄\e[1B\e[16D\e[38;5;27m▄\e[48;5;27m\e[38;5;39m▄\e[48;5;39m▄▄▄▄\e[38;5;27m▄▄▄▄\e[38;5;39m▄▄▄▄\e[48;5;27m▄\e[48;5;39m\e[38;5;27m▄\e[1B\e[16D\e[38;5;39m▄▄\e[38;5;27m▄\e[38;5;39m▄▄\e[48;5;27m▄\e[48;5;39m▄▄▄▄\e[48;5;27m▄\e[48;5;39m▄▄\e[38;5;27m▄\e[38;5;39m▄▄\e[1B\e[16D\e[38;5;27m▄\e[48;5;27m\e[38;5;39m▄\e[48;5;39m▄▄\e[38;5;21m▄▄▄▄▄▄▄▄\e[38;5;39m▄▄\e[48;5;27m▄\e[48;5;39m\e[38;5;27m▄\e[1B\e[16D\e[38;5;39m▄▄▄\e[48;5;21m\e[38;5;21m▄▄▄▄▄▄▄▄▄▄\e[48;5;39m\e[38;5;39m▄▄▄\e[1B\e[16D▄▄▄\e[48;5;21m\e[38;5;21m▄▄▄▄▄▄▄▄▄▄\e[48;5;39m\e[38;5;39m▄▄▄");
        break;
        case 15:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄\e[38;5;63m▄\e[38;5;39m▄▄\e[38;5;63m▄\e[38;5;39m▄▄▄▄▄▄\e[38;5;63m▄\e[38;5;39m▄▄\e[38;5;63m▄\e[38;5;39m▄\e[1B\e[16D▄▄\e[48;5;63m▄\e[48;5;39m\e[38;5;63m▄▄\e[48;5;63m\e[38;5;39m▄▄\e[48;5;39m\e[38;5;63m▄▄\e[48;5;63m\e[38;5;39m▄▄\e[48;5;39m\e[38;5;63m▄▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄▄\e[1B\e[16D▄\e[48;5;63m▄\e[48;5;39m\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m\e[38;5;63m▄\e[48;5;63m▄\e[48;5;39m\e[38;5;39m▄\e[48;5;63m\e[38;5;63m▄▄\e[48;5;39m\e[38;5;39m▄\e[48;5;63m\e[38;5;63m▄\e[48;5;39m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄\e[1B\e[16D▄▄\e[48;5;63m▄\e[48;5;39m\e[38;5;63m▄▄▄\e[48;5;63m▄\e[38;5;39m▄▄\e[38;5;63m▄\e[48;5;39m▄▄▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄▄\e[1B\e[16D▄▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄▄▄\e[38;5;63m▄\e[48;5;39m▄▄\e[48;5;63m▄\e[38;5;39m▄▄▄\e[48;5;39m\e[38;5;63m▄\e[38;5;39m▄▄\e[1B\e[16D▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[38;5;63m▄\e[48;5;39m\e[38;5;39m▄\e[48;5;63m\e[38;5;63m▄▄\e[48;5;39m\e[38;5;39m▄\e[48;5;63m\e[38;5;63m▄\e[38;5;39m▄\e[48;5;39m\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m\e[38;5;63m▄\e[38;5;39m▄\e[1B\e[16D▄▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄▄\e[48;5;39m\e[38;5;63m▄▄\e[48;5;63m\e[38;5;39m▄▄\e[48;5;39m\e[38;5;63m▄▄\e[48;5;63m\e[38;5;39m▄▄\e[48;5;39m\e[38;5;63m▄\e[38;5;39m▄▄\e[1B\e[16D▄\e[48;5;63m▄\e[48;5;39m▄▄\e[48;5;63m▄\e[48;5;39m▄▄▄▄▄▄\e[48;5;63m▄\e[48;5;39m▄▄\e[48;5;63m▄\e[48;5;39m▄");
        break;
        case 16:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄\e[48;5;196m\e[38;5;196m▄▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄\e[48;5;196m\e[38;5;196m▄▄▄▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄\e[48;5;196m\e[38;5;196m▄▄▄▄▄▄\e[48;5;39m\e[38;5;39m▄▄▄▄▄\e[1B\e[16D▄▄▄▄\e[38;5;196m▄\e[48;5;196m▄▄▄\e[38;5;15m▄\e[38;5;196m▄▄\e[48;5;39m▄\e[38;5;39m▄▄▄▄\e[1B\e[16D▄▄▄▄\e[48;5;196m\e[38;5;196m▄▄▄▄▄\e[48;5;15m▄\e[48;5;196m▄▄\e[48;5;39m\e[38;5;39m▄▄▄▄\e[1B\e[16D▄▄▄▄\e[48;5;196m\e[38;5;160m▄\e[38;5;196m▄▄▄▄▄▄\e[38;5;160m▄\e[48;5;39m\e[38;5;39m▄▄▄▄\e[1B\e[16D▄▄▄▄▄\e[48;5;160m▄▄▄▄▄▄\e[48;5;39m▄▄▄▄▄");
        break;
        case 17:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄\e[38;5;8m▄\e[48;5;8m▄▄\e[48;5;250m\e[38;5;250m▄\e[48;5;39m▄\e[38;5;39m▄▄\e[1B\e[16D▄▄▄▄▄▄▄\e[38;5;8m▄\e[48;5;8m▄▄▄▄▄\e[48;5;250m▄\e[38;5;250m▄\e[48;5;39m▄\e[1B\e[16D\e[38;5;39m▄▄▄▄▄\e[38;5;8m▄\e[48;5;8m▄▄▄▄▄▄▄▄▄\e[48;5;250m\e[38;5;250m▄\e[1B\e[16D\e[48;5;39m\e[38;5;39m▄▄▄\e[38;5;8m▄\e[48;5;8m▄▄▄▄▄▄▄▄▄▄\e[48;5;250m\e[38;5;250m▄▄\e[1B\e[16D\e[48;5;39m\e[38;5;39m▄▄▄▄\e[48;5;8m\e[38;5;52m▄\e[38;5;8m▄▄▄▄▄▄▄\e[38;5;250m▄\e[48;5;250m▄\e[38;5;39m▄\e[48;5;39m▄\e[1B\e[16D▄▄\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;39m▄\e[48;5;8m▄\e[38;5;8m▄▄▄\e[38;5;250m▄\e[48;5;250m▄\e[38;5;39m▄\e[48;5;39m▄▄▄\e[1B\e[16D\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄\e[48;5;8m▄\e[48;5;250m\e[38;5;250m▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄\e[1B\e[16D\e[48;5;52m▄▄\e[48;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        case 18:
            wprintf(L"\e[48;5;39m\e[38;5;52m▄\e[48;5;52m▄▄\e[38;5;39m▄▄\e[48;5;39m\e[38;5;52m▄\e[38;5;39m▄▄▄▄\e[38;5;52m▄\e[48;5;52m\e[38;5;39m▄▄\e[38;5;52m▄▄\e[48;5;39m▄\e[1B\e[16D\e[48;5;52m▄▄\e[48;5;39m▄\e[38;5;234m▄▄\e[38;5;39m▄▄▄▄▄▄\e[38;5;234m▄▄\e[38;5;52m▄\e[48;5;52m▄▄\e[1B\e[16D\e[48;5;39m\e[38;5;39m▄\e[48;5;52m\e[38;5;234m▄\e[48;5;234m▄▄\e[48;5;15m▄\e[48;5;234m\e[38;5;15m▄\e[38;5;234m▄\e[48;5;39m▄▄\e[48;5;234m▄▄▄\e[38;5;15m▄\e[38;5;234m▄\e[48;5;52m▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D▄\e[48;5;234m\e[38;5;234m▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;15m▄\e[48;5;234m▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D▄\e[48;5;234m▄\e[38;5;234m▄▄▄▄▄▄▄▄▄▄▄▄\e[38;5;39m▄\e[48;5;39m▄\e[1B\e[16D▄▄\e[48;5;234m▄\e[38;5;234m▄▄▄▄▄▄▄▄▄▄\e[38;5;39m▄\e[48;5;39m▄▄\e[1B\e[16D▄▄▄▄\e[48;5;234m▄\e[38;5;234m▄▄▄▄▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄\e[48;5;234m▄▄▄▄\e[48;5;39m▄▄▄▄▄▄");
        break;
        case 19:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄\e[38;5;1m▄▄\e[38;5;39m▄▄▄\e[1B\e[16D▄\e[48;5;1m\e[38;5;1m▄▄\e[48;5;39m\e[38;5;63m▄\e[38;5;39m▄▄\e[48;5;1m\e[38;5;1m▄▄\e[48;5;39m\e[38;5;39m▄▄▄\e[48;5;1m\e[38;5;63m▄\e[38;5;39m▄\e[48;5;39m▄▄▄\e[1B\e[16D▄▄▄▄\e[48;5;63m▄\e[48;5;39m\e[38;5;63m▄\e[38;5;39m▄\e[48;5;63m\e[38;5;63m▄\e[48;5;39m▄▄\e[48;5;63m\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄\e[1B\e[16D▄▄\e[48;5;1m\e[38;5;1m▄▄\e[48;5;39m\e[38;5;63m▄▄\e[48;5;63m\e[38;5;21m▄\e[48;5;21m▄▄\e[48;5;63m▄\e[48;5;39m\e[38;5;63m▄▄▄\e[48;5;1m\e[38;5;1m▄▄\e[48;5;39m\e[38;5;39m▄\e[1B\e[16D▄▄▄▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄\e[48;5;21m\e[38;5;63m▄\e[38;5;21m▄▄\e[38;5;63m▄\e[48;5;63m▄\e[48;5;39m▄\e[38;5;1m▄▄\e[38;5;39m▄▄\e[1B\e[16D\e[38;5;1m▄▄\e[48;5;63m\e[38;5;39m▄▄\e[48;5;39m▄\e[38;5;63m▄\e[48;5;63m\e[38;5;39m▄▄\e[38;5;63m▄\e[48;5;39m▄\e[38;5;39m▄▄\e[48;5;1m▄▄\e[48;5;39m▄▄\e[1B\e[16D\e[48;5;1m▄▄\e[48;5;39m▄▄\e[48;5;1m\e[38;5;1m▄▄\e[48;5;39m\e[38;5;39m▄▄\e[48;5;63m\e[38;5;63m▄\e[48;5;39m\e[38;5;39m▄\e[48;5;63m▄\e[48;5;39m\e[38;5;1m▄▄\e[38;5;39m▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄\e[48;5;1m\e[38;5;1m▄▄\e[48;5;39m\e[38;5;39m▄\e[48;5;1m▄▄\e[48;5;39m▄▄▄");
            break;
        case 20:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄\e[48;5;21m▄\e[48;5;39m\e[38;5;21m▄▄\e[38;5;39m▄▄▄▄▄▄\e[38;5;21m▄▄\e[48;5;21m\e[38;5;39m▄\e[48;5;39m▄▄\e[1B\e[16D▄▄▄\e[48;5;21m▄\e[48;5;39m▄\e[38;5;21m▄▄\e[48;5;21m\e[38;5;39m▄▄\e[48;5;39m\e[38;5;21m▄▄\e[38;5;39m▄\e[48;5;21m▄\e[48;5;39m▄▄▄\e[1B\e[16D▄▄\e[38;5;21m▄\e[48;5;21m\e[38;5;39m▄▄\e[48;5;39m▄▄\e[38;5;21m▄▄\e[38;5;39m▄▄\e[48;5;21m▄▄\e[48;5;39m\e[38;5;21m▄\e[38;5;39m▄▄\e[1B\e[16D▄▄\e[48;5;21m▄\e[48;5;39m\e[38;5;21m▄▄\e[38;5;39m▄▄\e[48;5;21m▄▄\e[48;5;39m▄▄\e[38;5;21m▄▄\e[48;5;21m\e[38;5;39m▄\e[48;5;39m▄▄\e[1B\e[16D▄▄▄\e[38;5;21m▄\e[38;5;39m▄\e[48;5;21m▄▄\e[48;5;39m\e[38;5;21m▄▄\e[48;5;21m\e[38;5;39m▄▄\e[48;5;39m▄\e[38;5;21m▄\e[38;5;39m▄▄▄\e[1B\e[16D▄▄\e[38;5;21m▄\e[48;5;21m\e[38;5;39m▄▄\e[48;5;39m▄▄▄▄▄▄\e[48;5;21m▄▄\e[48;5;39m\e[38;5;21m▄\e[38;5;39m▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        case 21:
            wprintf(L"\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄\e[38;5;56m▄\e[48;5;56m▄\e[48;5;93m\e[38;5;93m▄\e[1B\e[16D\e[48;5;39m\e[38;5;39m▄▄▄▄▄▄▄▄▄▄▄\e[38;5;56m▄\e[48;5;56m▄\e[38;5;93m▄\e[48;5;93m\e[38;5;39m▄\e[48;5;39m▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄\e[38;5;56m▄\e[48;5;56m▄\e[38;5;93m▄\e[48;5;93m\e[38;5;39m▄\e[48;5;39m▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄\e[38;5;56m▄\e[48;5;56m▄\e[38;5;93m▄\e[48;5;93m\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄\e[38;5;56m▄\e[48;5;56m▄\e[38;5;93m▄\e[48;5;93m\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄▄\e[1B\e[16D▄▄\e[48;5;53m▄\e[48;5;39m\e[38;5;53m▄\e[48;5;56m\e[38;5;56m▄\e[38;5;93m▄\e[48;5;93m\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄\e[38;5;54m▄\e[48;5;54m▄▄\e[48;5;53m\e[38;5;39m▄\e[48;5;39m\e[38;5;53m▄\e[38;5;39m▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D\e[48;5;54m\e[38;5;54m▄▄\e[38;5;39m▄\e[48;5;39m▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
        default:
            wprintf(L"\e[48;5;1m\e[38;5;1m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄\e[38;5;2m▄\e[48;5;2m▄▄▄▄▄▄\e[48;5;1m\e[38;5;1m▄▄▄▄▄\e[1B\e[16D▄▄▄▄\e[48;5;2m\e[38;5;2m▄▄\e[48;5;1m\e[38;5;1m▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄\e[48;5;2m\e[38;5;2m▄▄\e[48;5;1m\e[38;5;1m▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄\e[48;5;2m\e[38;5;2m▄▄\e[48;5;1m\e[38;5;1m▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄\e[48;5;2m\e[38;5;2m▄▄\e[48;5;1m\e[38;5;1m▄▄▄▄▄▄▄▄▄▄\e[1B\e[16D▄▄▄▄\e[48;5;2m▄\e[38;5;2m▄▄▄▄▄▄\e[48;5;1m\e[38;5;1m▄▄▄▄▄\e[1B\e[16D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄");
        break;
    }
}
void drawCard(int x, int y, card_t *card){

    wprintf(L"\e[%d;%dH",y,x);
    switch (card->rarity){
        case CARD_COMON:
            wprintf(L"\e[48;5;0m\e[38;5;0m▄▄\e[38;5;51m▄\e[48;5;51m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m▄\e[38;5;0m▄▄\e[1B\e[20D▄\e[48;5;51m\e[38;5;51m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;0m▄\e[1B\e[20D\e[48;5;51m\e[38;5;51m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D\e[48;5;0m\e[38;5;0m▄\e[48;5;51m\e[38;5;51m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;0m▄\e[1B\e[20D▄▄\e[48;5;51m▄\e[38;5;51m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[38;5;0m▄\e[48;5;0m▄▄");
            break;
        case CARD_RARE:
            wprintf(L"\e[48;5;0m\e[38;5;0m▄▄\e[38;5;82m▄\e[48;5;82m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m▄\e[38;5;0m▄▄\e[1B\e[20D▄\e[48;5;82m\e[38;5;82m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;0m▄\e[1B\e[20D\e[48;5;82m\e[38;5;82m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D\e[48;5;0m\e[38;5;0m▄\e[48;5;82m\e[38;5;82m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;0m▄\e[1B\e[20D▄▄\e[48;5;82m▄\e[38;5;82m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[38;5;0m▄\e[48;5;0m▄▄");
            break;
        case CARD_EPIC:
            wprintf(L"\e[48;5;0m\e[38;5;0m▄▄\e[38;5;214m▄\e[48;5;214m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m▄\e[38;5;0m▄▄\e[1B\e[20D▄\e[48;5;214m\e[38;5;214m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;0m▄\e[1B\e[20D\e[48;5;214m\e[38;5;214m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[1B\e[20D\e[48;5;0m\e[38;5;0m▄\e[48;5;214m\e[38;5;214m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m\e[38;5;0m▄\e[1B\e[20D▄▄\e[48;5;214m▄\e[38;5;214m▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[38;5;0m▄\e[48;5;0m▄▄");
            break;
    }
    drawCardSprite(x+2,y+4,card->spritesIds[0]);

    int length = 0;
    while(card->fullName[length] != L'\0'){
        length++;
    }

    wprintf(L"\e[%d;%dH\e[38;5;%dm\e[48;5;%dm%ls",y+2,x+(20-length)/2,CARDS_FG_COLORS[card->rarity],CARDS_BG_COLORS[card->rarity],card->fullName);
}
void destroyCard(card_t *card);
card_t * createCard(int cardId);
void updateCardDescription(card_t *card){
    card->description[0] = '\0';
    wchar_t *str = card->description;
    int *values = card->vals;
    card_t *cardTmp;
    card->fullName[0] = '\0';

    switch (card->id)
    {
        case CARD_FIGHTER_MOVE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"gain %d move",values[0]);
            break;
        case CARD_FIGHTER_PUNCH:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"deal %d dmg fw",values[0]);
            break;
        case CARD_FIGHTER_THROW:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"throw an enemy fw");
            break;
        case CARD_FIGHTER_PUSH:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"push an enemy fw");
            break;
        case CARD_FIGHTER_SPINING_PUNCH:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"deal %d dmg fw and bw",values[0]);
            break;
        case CARD_FIGHTER_RETRIVE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"move bw %d",values[0]);
            break;
        case CARD_FIGHTER_RAGE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"gain %d strength",values[0]);
            break;
        case CARD_FIGHTER_SPEAR_POKE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"deal %d dmg 1 cell fw and %d dmg 2 cells fw",values[0],values[0]*2);
            break;
        case CARD_FIGHTER_WAKEUP_ATTACK:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"turn and deal %d dmg fw",values[0]);
            break;
        case CARD_FIGHTER_KICK:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"move fw, deal %d dmg fw, push the enemy fw",values[0]);
            break;
        case CARD_FIGHTER_MANTRA:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"gain %d move and %d mana, block",values[0],values[1]);
            break;
        case CARD_FIGHTER_ETERNAL_KATANA:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"deal %d dmg fw, discard a random card instead of this one",values[0]);
            break;
        case CARD_FIGHTER_SCYTHE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"deal %d dmg fw and %d dmg bw",values[0],values[0]*2);
            break;
        case CARD_FIGHTER_SPECIAL_PUNCH:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"fw remove the targhet shield, deal %d dmg fw",values[0]);
            break;
        case CARD_FIGHTER_SCREAM:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"%d dmg to all, gain %d stress",values[0],values[1]);
            break;
        case CARD_FIGHTER_COOL_OFF:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"lose %d stress and strength, gain %d mana",values[0],values[1]);
            break;
        case CARD_FIGHTER_BLOODSHOOT:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"gain %d strength, %d stress, %d mana, copy %d",values[0],values[1],values[2],values[3]);
            break;
        case CARD_FIGHTER_BONE_CUTTER:
            cardTmp = createCard(values[3]);
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"deal %d dmg fw or bw, add %d bleeding, add %d %s tired to your discard pile",values[0],values[1],values[2],cardTmp->baseName);
            destroyCard(cardTmp);
            break;
        case CARD_FIGHTER_BLACK_HEART:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"gain %d mana and stress",values[0]);
            break;
        case CARD_FIGHTER_SURROUNDED:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"gain %d mana and stress tor every enemy on the field",values[0]);
            break;
        case CARD_FIGHTER_MEDITATE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"lose %d stress, gain %d mana",values[0],values[1]);
            break;
        case CARD_FIGHTER_CURSED_SWORD:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"deal %d dmg, increase the dmg by %d this combat, take %d dmg if in hand at the end of the turn",values[3],values[0],values[2]);
            break;
        case CARD_ARCHER_MOVE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"gain %d move and %d mana",values[0],values[1]);
            break;
        case CARD_ARCHER_STAB_ATTACK:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"move %d fw, deal %d dmg fw",values[1],values[0]);
            break;
        case CARD_ARCHER_ARROW:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"shoot fw an arrow that deal %d dmg",values[0]);
            break;
        case CARD_ARCHER_LEAP:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"jump %d fw",values[0]);
            break;
        case CARD_ARCHER_TO_SAFETY:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"dash bw");
            break;
        case CARD_ARCHER_WIND_DANCE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"gain %d move. courege: gain %d move",values[0],values[0]);
            break;
        case CARD_ARCHER_HARPOON:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"fw grab an enemy and pull it to you");
            break;
        case CARD_ARCHER_WIND_BLADE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"%d dmg fw, if it damages gain 1 move",values[0],values[0]);
            break;
        case CARD_ARCHER_CROSSBOW:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"shoot fw an arrow that deal %d dmg, transform in crossbow reload",values[0]);
            break;
        case CARD_ARCHER_CROSSBOW_RELOAD:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"transform into crossbow");
            break;
        case CARD_ARCHER_ACROBATIC_SHOT:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"move fw, shoot a %d dmg arrw bw",values[0]);
            break;
        case CARD_THIEF_MOVE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"move fw, gain %d move",values[0]);
            break;
        case CARD_THIEF_BACKSTAB:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"deal %d dmg bw",values[0]);
            break;
        case CARD_THIEF_SPIN:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"turn, gain %d move",values[0]);
            break;
        case CARD_THIEF_DASH:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"dash bw, deal %d dmg bw",values[0]);
            break;
        case CARD_THIEF_JOLLY_CARD:
            cardTmp = createCard(values[0]);
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"copy the effect of the last played card %Ls",cardTmp->id == -1 ? L"" : cardTmp->baseName);
            destroyCard(cardTmp);
            break;
        case CARD_THIEF_SMOKE_BOMB:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"teleport bw behind the first enemy");
            break;
        case CARD_THIEF_DAGGHER:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"throw a %d dmg daggher fw",values[0]);
            break;
        case CARD_THIEF_SNEEK:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"gain %d move, gain %d move if in your hand at the end of theturn",values[0],values[0]);
            break;
        case CARD_THIEF_CURVED_BLADE:
            cardTmp = createCard(values[1]);
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"deal %d dmg fw, add a %Ls to your discard pile",values[0],cardTmp->baseName);
            destroyCard(cardTmp);
            break;
        case CARD_THIEF_DISTRACTION:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"change all enemies intents to wait");
            break;
        case CARD_THIEF_ENRAGE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"lose all move, gains %d times the ammount in streangth",values[0]);
            break;
        case CARD_THIEF_FLEE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"gain %d move for every enemy on the field, gain a shield",values[0]);
            break;
        case CARD_THIEF_CONFUSION:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"turn all, gain %d mana",values[1]);
            break;
        case CARD_THIEF_FAST_SLASH:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"deal %d dmg fw +%d dmg for every move consumed this turn",values[1],values[0]);
            break;
        case CARD_THIEF_SMOKE_GRANADE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"set an emey action to wait");
            break;
        case CARD_THIEF_SERRATED_BLADE:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"deal %d dmg fw to an enemy, give him %d bleeding",values[1],values[0]);
            break;
        case CARD_CURSE_TIRED:
            swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L"do nothing");
            break;

        if(card->exhaust)swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L". exhaust");
        if(card->nonPermanent)swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L". temporary");
        if(card->fragial)swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L". fragial");
        if(card->retain)swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L". retain");
        if(card->giveOvercharge)swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L". gain overcharge");
        if(card->blockTheSlot)swprintf(str,CARD_DESCRIPTION_MAX_LENGTH,L". block the slot");
    }

    if(card->level == 0){
        swprintf(card->fullName,CARD_FULL_NAME_MAX_LENGTH,L"%ls",card->baseName);
    }else{
        swprintf(card->fullName,CARD_FULL_NAME_MAX_LENGTH,L"%ls %d",card->baseName,card->level);
    }
    
}
void initializeCardLevel(card_t *card, int cardId,int cardLevel){
    card->id = cardId;
    card->level = cardLevel;
    card->description[0] = '\0';
    card->retain = 0;
    card->exhaust = 0;
    card->nonPermanent = 0;
    card->fragial = 0;
    card->giveOvercharge = 0;
    card->blockTheSlot = 0;

    card->rarity = 0;//tmp

    if(card->vals != NULL){
        free(card->vals);
    }
    if(card->spritesIds != NULL){
        free(card->spritesIds);
    }

    switch (cardId)
    {
        case CARD_FIGHTER_MOVE:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"move";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 0;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_FIGHTER_PUNCH:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"punch";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 1;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_FIGHTER_THROW:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"throw";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 2;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_FIGHTER_PUSH:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"push";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 3;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_FIGHTER_SPINING_PUNCH:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"spinning punch";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 4;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_FIGHTER_RETRIVE:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"retrive";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 5;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_FIGHTER_RAGE:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"rage";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 6;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_FIGHTER_SPEAR_POKE:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"spear poke";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 7;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_FIGHTER_WAKEUP_ATTACK:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"wakeup attack";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 8;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_FIGHTER_KICK:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"kick";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 9;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_FIGHTER_MANTRA:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"mantra";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 10;
            card->vals = malloc(sizeof(int)*2);
            card->vals[0] = 2;
            card->vals[1] = 1;
            break;
        case CARD_FIGHTER_ETERNAL_KATANA:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"eternal katana";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 11;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 3;
            break;
        case CARD_FIGHTER_SCYTHE:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"scythe";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 12;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_FIGHTER_SPECIAL_PUNCH:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"special punch";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 13;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 2;
            break;
        case CARD_FIGHTER_SCREAM:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"scream";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 14;
            card->vals = malloc(sizeof(int)*2);
            card->vals[0] = 1;
            card->vals[1] = 2;
            break;
        case CARD_FIGHTER_COOL_OFF:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"cool off";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 15;
            card->vals = malloc(sizeof(int)*2);
            card->vals[0] = 2;
            card->vals[1] = 1;
            card->giveOvercharge = 1;
            break;
        case CARD_FIGHTER_BLOODSHOOT:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"bloodshoot";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 16;
            card->vals = malloc(sizeof(int)*2);
            card->vals[0] = 1;
            card->vals[1] = 2;
            break;
        case CARD_FIGHTER_BONE_CUTTER:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"bone cutter";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 17;
            card->vals = malloc(sizeof(int)*4);
            card->vals[0] = 3;
            card->vals[1] = 1;
            card->vals[2] = 1;
            card->vals[3] = CARD_CURSE_TIRED;
            break;
        case CARD_FIGHTER_BLACK_HEART:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"black heart";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 18;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 4;
            break;
        case CARD_FIGHTER_SURROUNDED:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"surrounded";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 19;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_FIGHTER_MEDITATE:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"meditare";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 20;
            card->vals = malloc(sizeof(int)*2);
            card->vals[0] = 1;
            card->vals[1] = 1;
            break;
        case CARD_FIGHTER_CURSED_SWORD:
            card->ownerId = FIELD_OBJECT_ID_FIGHTER_HERO;
            card->baseName = L"cursed sword";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 21;
            card->vals = malloc(sizeof(int)*4);
            card->vals[0] = 1;
            card->vals[1] = 2;
            card->vals[2] = 1;
            card->vals[3] = 2;
            break;
        case CARD_ARCHER_MOVE:
            card->ownerId = FIELD_OBJECT_ID_ARCHER_HERO;
            card->baseName = L"move";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 22;
            card->vals = malloc(sizeof(int)*2);
            card->vals[0] = 1;
            card->vals[1] = 1;
            card->giveOvercharge = 1;
            break;
        case CARD_ARCHER_STAB_ATTACK:
            card->ownerId = FIELD_OBJECT_ID_ARCHER_HERO;
            card->baseName = L"stab attack";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 23;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            card->vals[1] = 1;
            break;
        case CARD_ARCHER_ARROW:
            card->ownerId = FIELD_OBJECT_ID_ARCHER_HERO;
            card->baseName = L"arrow";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 24;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_ARCHER_LEAP:
            card->ownerId = FIELD_OBJECT_ID_ARCHER_HERO;
            card->baseName = L"leap";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 25;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_ARCHER_TO_SAFETY:
            card->ownerId = FIELD_OBJECT_ID_ARCHER_HERO;
            card->baseName = L"to safety";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 26;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_ARCHER_WIND_DANCE:
            card->ownerId = FIELD_OBJECT_ID_ARCHER_HERO;
            card->baseName = L"wind dance";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 27;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_ARCHER_HARPOON:
            card->ownerId = FIELD_OBJECT_ID_ARCHER_HERO;
            card->baseName = L"harpoon";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 28;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_ARCHER_WIND_BLADE:
            card->ownerId = FIELD_OBJECT_ID_ARCHER_HERO;
            card->baseName = L"wind blade";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 29;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_ARCHER_CROSSBOW:
            card->ownerId = FIELD_OBJECT_ID_ARCHER_HERO;
            card->baseName = L"crossbow";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 30;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_ARCHER_CROSSBOW_RELOAD:
            card->ownerId = FIELD_OBJECT_ID_ARCHER_HERO;
            card->baseName = L"crossbow reload";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 31;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_ARCHER_ACROBATIC_SHOT:
            card->ownerId = FIELD_OBJECT_ID_ARCHER_HERO;
            card->baseName = L"acrobatic shot";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 32;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_THIEF_MOVE:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"move";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 33;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_THIEF_BACKSTAB:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"backstab";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 34;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_THIEF_SPIN:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"spin";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 35;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 2;
            break;
        case CARD_THIEF_DASH:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"dash";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 36;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_THIEF_JOLLY_CARD:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"jolly card";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 37;
            card->vals = malloc(sizeof(int));
            card->vals[0] = -1;
            break;
        case CARD_THIEF_SMOKE_BOMB:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"smoke bomb";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 38;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_THIEF_DAGGHER:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"daggher";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 39;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_THIEF_SNEEK:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"sneek";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 40;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            break;
        case CARD_THIEF_CURVED_BLADE:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"curved blade";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 41;
            card->vals = malloc(sizeof(int)*2);
            card->vals[0] = 3;
            card->vals[1] = CARD_CURSE_TIRED;
            break;
        case CARD_THIEF_DISTRACTION:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"distraction";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 42;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            card->exhaust = 1;
            break;
        case CARD_THIEF_ENRAGE:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"enrage";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 43;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 2;
            break;
        case CARD_THIEF_FLEE:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"flee";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 44;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            card->exhaust = 1;
            break;
        case CARD_THIEF_CONFUSION:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"confusion";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 45;
            card->vals = malloc(sizeof(int)*2);
            card->vals[0] = 1;
            card->vals[1] = 1;
            break;
        case CARD_THIEF_FAST_SLASH:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"fast slash";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 46;
            card->vals = malloc(sizeof(int)*2);
            card->vals[0] = 1;
            card->vals[1] =0;
            break;
        case CARD_THIEF_SMOKE_GRANADE:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"smoke granade";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 47;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            card->exhaust = 1;
            break;
        case CARD_THIEF_SERRATED_BLADE:
            card->ownerId = FIELD_OBJECT_ID_THIEF_HERO;
            card->baseName = L"serrated blade";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 48;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            card->vals[0] = 1;
            break;
        case CARD_CURSE_TIRED:
            card->ownerId = FIELD_OBJECT_ID_CURSE;
            card->baseName = L"tired";
            card->spritesIds = malloc(sizeof(int));
            card->spritesIds[0] = 49;
            card->vals = malloc(sizeof(int));
            card->vals[0] = 1;
            card->exhaust = 1;
            card->fragial = 1;
            card->nonPermanent = 1;
            break;

    }

    card->vals[0] += cardLevel;
    updateCardDescription(card);


}
void initializeCard(card_t *card, int cardId){
    initializeCardLevel(card,cardId,0);
}
void setCardLevel(card_t *card, int newLevel){
    card->vals[0] += newLevel - card->level;
    card ->level = newLevel;
    updateCardDescription(card);
}
card_t * createCardLevel(int cardId,int level){
    card_t * card = malloc(sizeof(card_t));
    card->vals = NULL;
    card->spritesIds = NULL;
    initializeCardLevel(card,cardId,level);
    return card;

}
card_t * createCard(int cardId){
    return createCardLevel(cardId, 0);
}
void destroyCard(card_t *card){
    free(card->spritesIds);
    free(card->vals);
    free(card);
}
genericListNode_t * getHeroDefaultDeck(int heroId){
    genericListNode_t * listHead = NULL;
    switch(heroId){
        case FIELD_OBJECT_ID_FIGHTER_HERO:
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_MOVE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_MOVE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_MOVE)));

            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUSH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_THROW)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_SPINING_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_RETRIVE)));
            break;
        case FIELD_OBJECT_ID_ARCHER_HERO:
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_ARCHER_ARROW)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_ARCHER_ARROW)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_ARCHER_ARROW)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_ARCHER_MOVE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_ARCHER_MOVE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_ARCHER_MOVE)));
            
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_ARCHER_STAB_ATTACK)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_ARCHER_TO_SAFETY)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_ARCHER_TO_SAFETY)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_ARCHER_LEAP)));
            break;
        case FIELD_OBJECT_ID_THIEF_HERO:
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_THIEF_BACKSTAB)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_THIEF_BACKSTAB)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_THIEF_BACKSTAB)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_THIEF_MOVE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_THIEF_MOVE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_THIEF_MOVE)));

            genList_AddStart(&listHead,genList_createNode(createCard(CARD_THIEF_DAGGHER)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_THIEF_DAGGHER)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_THIEF_SPIN)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_THIEF_SPIN)));
            break;
        case FIELD_OBJECT_ID_MAGE_HERO:
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_MOVE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_MOVE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_MOVE)));

            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_SPINING_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUSH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_THROW)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_RETRIVE)));
            break;
        case FIELD_OBJECT_ID_PALADIN_HERO:
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_MOVE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_MOVE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_MOVE)));

            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_SPINING_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUSH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_THROW)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_RETRIVE)));
            break;
    }
    return listHead;
}
genericListNode_t * getHeroCardsPool(int heroId){
    genericListNode_t *listHead = NULL;
    switch(heroId){
        case FIELD_OBJECT_ID_FIGHTER_HERO:
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_MOVE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_THROW)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_PUSH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_SPINING_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_RETRIVE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_RAGE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_SPEAR_POKE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_WAKEUP_ATTACK)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_KICK)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_MANTRA)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_ETERNAL_KATANA)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_SCYTHE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_SPECIAL_PUNCH)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_SCREAM)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_COOL_OFF)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_BLOODSHOOT)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_BONE_CUTTER)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_BLACK_HEART)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_SURROUNDED)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_MEDITATE)));
            genList_AddStart(&listHead,genList_createNode(createCard(CARD_FIGHTER_CURSED_SWORD)));
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