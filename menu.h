#include "statemachine.h"

#ifndef MENU_H
#define MENU_H

struct menus{
    char zeile1[21];
    char zeile2[21];
    char zeile3[21];
    char zeile4[21];
};
void menu(const enum zeilen zeile,const enum states state);

#endif /* MENU_H */