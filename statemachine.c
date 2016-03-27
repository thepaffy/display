#include "kc-functions.h"
#include "statemachine.h"
#include "menu.h"
#define LINKS '1'
#define RECHTS '2'
#define OBEN '3'
#define UNTEN '4'

static unsigned short zaehler=1;
static enum states state=WERTE;
static enum zeilen zeile=ERSTE;


void processEvent(char taste){
    switch(state){
        case WERTE:
            werte();
            sleep(1);
            if((taste=='-')||(taste==LINKS)){
                if(zaehler==10){
                    zaehler=1;
                    state=ZEIT;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                state=HAUPTMENU;
            }
            break;

        case ZEIT:
            zeit();
            sleep(1);
            if((taste=='-')||(taste==LINKS)){
                if(zaehler==10){
                    zaehler=1;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                state=HAUPTMENU;
            }
            break;

        case HAUPTMENU:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==OBEN){
                    if(zeile==1){
                        zeile=3;
                    }else{
                        zeile--;
                    }
                }else if(taste==UNTEN){
                    if(zeile==3){
                        zeile=1;
                    }else{
                        zeile++;
                    }
                }else if(taste==RECHTS){
                    switch(zeile){
                        case ERSTE:
                            state=MENU1;
                            break;

                        case ZWEITE:
                            state=MENU2;
                            break;

                        case DRITTE:
                            state=MENU3;;
                            break;
                        default:return;
                    }
                    zeile=ERSTE;
                }else if(taste==LINKS){
                    zeile=ERSTE;
                    state=WERTE;
                }
            }
            break;

        case MENU1:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==OBEN){
                    zeile--;
                }else if(taste==UNTEN){
                    zeile++;
                }else if(taste==RECHTS){
                    switch(zeile){
                        case ERSTE:
                            state=MENU1_1;
                            break;

                        case ZWEITE:
                            state=MENU1_2;
                            break;

                        case DRITTE:
                            state=MENU1_3;
                            break;

                        case VIERTE:
                            state=MENU1_4;
                            break;
                    }
                    zeile=ERSTE;
                }else if(taste==LINKS){
                    zeile=ERSTE;
                    state=HAUPTMENU;
                }
            }
            break;

        case MENU2:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==OBEN){
                    zeile--;
                }else if(taste==UNTEN){
                    zeile++;
                }else if(taste==RECHTS){
                    switch(zeile){
                        case ERSTE:
                            state=MENU2_1;
                            break;

                        case ZWEITE:
                            state=MENU2_2;
                            break;
                        default:return;
                    }
                    zeile=ERSTE;
                }else if(taste==LINKS){
                    zeile=ERSTE;
                    state=HAUPTMENU;
                }
            }
            break;

        case MENU3:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==OBEN){
                    zeile--;
                }else if(taste==UNTEN){
                    zeile++;
                }else if(taste==RECHTS){
                    switch(zeile){
                        case ERSTE:
                            state=MENU3_1;
                            break;

                        case ZWEITE:
                            state=MENU3_2;
                            break;

                        case DRITTE:
                            state=MENU3_3;
                            break;

                        case VIERTE:
                            state=MENU3_4;
                            break;
                    }
                    zeile=ERSTE;
                }else if(taste==LINKS){
                    zeile=ERSTE;
                    state=HAUPTMENU;
                }
            }
            break;

        case MENU1_1:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==RECHTS){
                    system("/etc/init.d/webmin restart");
                    state=HAUPTMENU;
                }if(taste==LINKS){
                    state=MENU1;
                }
            }
            break;

        case MENU1_2:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==RECHTS){
                    system("/etc/init.d/ssh restart");
                    state=HAUPTMENU;
                }else if(taste==LINKS){
                    state=MENU1;
                }
            }
            break;

        case MENU1_3:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==RECHTS){
                    system("/etc/init.d/proftpd restart");
                    system("/etc/init.d/nfs-kernel-server restart");
                    system("initctl restart smbd");
                    state=HAUPTMENU;
                }else if(taste==LINKS){
                    state=MENU1;
                }
            }
            break;

        case MENU1_4:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==RECHTS){
                    system("/etc/init.d/apache2 restart");
                    system("initctl mysql restart");
                    state=HAUPTMENU;
                }else if(taste==LINKS){
                    state=MENU1;
                }
            }
            break;

        case MENU2_1:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==RECHTS){
                    system("halt");
                }else if(taste==LINKS){
                    state=MENU2;
                }
            }
            break;

        case MENU2_2:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==RECHTS){
                    system("reboot");
                }else if(taste==LINKS){
                    state=MENU2;
                }
            }
            break;

        case MENU3_1:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==RECHTS){
                    system("ifdown eth0");
                    system("ifup eth0");
                    state=HAUPTMENU;
                }else if(taste==LINKS){
                    state=MENU3;
                }
            }
            break;

        case MENU3_2:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==RECHTS){
                    system("ifdown eth1");
                    system("ifup eth1");
                    state=HAUPTMENU;
                }else if(taste==LINKS){
                    state=MENU3;
                }
            }
            break;
			
        case MENU3_3:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==RECHTS){
                    system("poff");
                    system("pon dsl-provider");
                    state=HAUPTMENU;
                }else if(taste==LINKS){
                    state=MENU3;
                }
            }
            break;

        case MENU3_4:
            menu(zeile,state);
            sleep(1);
            if(taste=='-'){
                if(zaehler==30){
                    zaehler=1;
                    zeile=ERSTE;
                    state=WERTE;
                }else{
                    zaehler++;
                }
            }else{
                zaehler=1;
                if(taste==RECHTS){
                    system("poff");
                    state=HAUPTMENU;
                }else if(taste==LINKS){
                    state=MENU3;
                }
            }
            break;
    }
}
