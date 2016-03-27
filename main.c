#include "kc-functions.h"
#include "statemachine.h"
char buffer[22];        //Buffer auf den sprintf und strftime zum Formatieren schreiben
                        //und von dem write ließt um auf fd zu schreiben.
int fd;                 //Filediscriptor [fd] für die serielle Schnittstelle
int wait_flag=TRUE;

int main(void)
{
    char taste;
    printf("Debug");
    init_S0();
    printf("Debug1");
    while(1)
    {
        if(wait_flag==FALSE)
        {
            read(fd,&taste,1);
            wait_flag=TRUE;
            sprintf(buffer,"%c",taste);
            write(fd,buffer,strlen(buffer));
        }
        else
        {
            taste='-';
        }
        printf("Debug2");
        processEvent(taste);
    }
}
