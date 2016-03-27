#include "kc-functions.h"
#include "menu.h"
#include "statemachine.h"

static struct menus hauptmenu={
    " Dienste",
    " Herunterfahren",
    " Verbindungen",
    " "
};

static struct menus menu1={
    " Webmin neustarten",
    " SSH Neustarten",
    " Daten neustarten",
    " Web neustarten"
};

static struct menus menu2={
    " Herunterfahren",
    " Neu Starten",
    " ",
    " "
};

static struct menus menu3={
    " eth0 neuverbinden",
    " eth1 neuverbinden",
    " DSL neuverbinden",
    " DSL trennen"
};

static struct menus menu1_1={
    " Webmin neustarten",
    " Bitte bestätigen",
    " ",
    " "
};

static struct menus menu1_2={
    " SSH Neustarten",
    " Bitte bestätigen",
    " ",
    " "
};

static struct menus menu1_3={
    " Daten neustarten",
    " Bitte bestätigen",
    " ",
    " "
};

static struct menus menu1_4={
    " Web neustarten",
    " Bitte bestätigen",
    " ",
    " "
};

static struct menus menu2_1={
    " Herunterfahren",
    " Bitte bestätigen",
    " ",
    " "
};

static struct menus menu2_2={
    " Neu starten",
    " Bitte bestätigen",
    " ",
    " "
};

static struct menus menu3_1={
    " eth0 neuverbinden",
    " Bitte bestätigen",
    " ",
    " "
};

static struct menus menu3_2={
    " eth1 neuverbinden",
    " Bitte bestätigen",
    " ",
    " "
};

static struct menus menu3_3={
    " DSL neuverbinden",
    " Bitte bestätigen",
    " ",
    " "
};

static struct menus menu3_4={
    " DSL trennen",
    " Bitte bestätigen",
    " ",
    " "
};

/*Den menu Funktionen wird die Zeilennummer
 *mitgegeben um das [>] einzubauen zu orientierung*/
void menu(const enum zeilen zeile,const enum states state){
    struct menus auswahl;
    switch(state){
        case HAUPTMENU:auswahl=hauptmenu;break;
        case MENU1:auswahl=menu1;break;
        case MENU2:auswahl=menu2;break;
        case MENU3:auswahl=menu3;break;
        case MENU1_1:auswahl=menu1_1;break;
        case MENU1_2:auswahl=menu1_2;break;
        case MENU1_3:auswahl=menu1_3;break;
        case MENU1_4:auswahl=menu1_4;break;
        case MENU2_1:auswahl=menu2_1;break;
        case MENU2_2:auswahl=menu2_2;break;
        case MENU3_1:auswahl=menu3_1;break;
        case MENU3_2:auswahl=menu3_2;break;
        case MENU3_3:auswahl=menu3_3;break;
        case MENU3_4:auswahl=menu3_4;break;
        default:return;
    }
	switch(zeile){
        case ERSTE:auswahl.zeile1[0]='>';break;
        case ZWEITE:auswahl.zeile2[0]='>';break;
        case DRITTE:auswahl.zeile3[0]='>';break;
        case VIERTE:auswahl.zeile4[0]='>';break;
    }

    sprintf(buffer,"~C"); /*Display leeren*/
    write(fd,buffer,strlen(buffer));

    if(auswahl.zeile1){
        sprintf(buffer,"%s\n",auswahl.zeile1);
        write(fd,buffer,strlen(buffer));
    }

    if(auswahl.zeile2){
        sprintf(buffer,"%s\n",auswahl.zeile2);
        write(fd,buffer,strlen(buffer));
    }

    if(auswahl.zeile3){
        sprintf(buffer,"%s\n",auswahl.zeile3);
        write(fd,buffer,strlen(buffer));
    }

    if(auswahl.zeile4){
        sprintf(buffer,"%s\n",auswahl.zeile4);
        write(fd,buffer,strlen(buffer));
    }
}
