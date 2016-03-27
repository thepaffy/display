#include "kc-functions.h"
#define TERM_DEVICE "/dev/ttyS0"
#define TERM_SPEED B38400

void werte(void){
    FILE *hdd1_ptr;
    FILE *hdd2_ptr;
    FILE *isa_ptr;
    char *hdd1_befehl="hddtemp -n /dev/sda";
    char *hdd2_befehl="hddtemp -n /dev/sdb";
    char *isa_befehl="sensors";
    char hdd1temp[3];
    char hdd2temp[3];
    char isa[1000];
    int i=0,c,cputemp,fanupm;
    char *verglcpu_ptr;
    char *verglfan_ptr;

    hdd1_ptr=popen(hdd1_befehl,"r");
    hdd2_ptr=popen(hdd2_befehl,"r");
    isa_ptr=popen(isa_befehl,"r");

    if((hdd1_ptr==NULL)||(hdd2_ptr==NULL)||(isa_ptr==NULL)){
        perror("Can't open pipe!");
        exit(ENXIO);
    }else{
        fgets(hdd1temp,sizeof(hdd1temp),hdd1_ptr);  /*Einlesen der Festplattenwerte,*/
        fgets(hdd2temp,sizeof(hdd2temp),hdd2_ptr);  /*und abspeichern in den entsprechenden*/
                                                            /*Variablen.*/
        while((c=fgetc(isa_ptr))!=EOF){ /*Einlesen des "ISA"-Pipes*/
            if(c=='\n'){ /*Jedes Newline wird in ein Leerzeichen umgewandelt,*/
                isa[i]=32;  /*da sonst strstr nicht funzt!!!*/
                i++;
            }else{
                isa[i]=c;
                i++;
            }
        }
        isa[i]='\0';

        /* CPU Temperatur heraustrennen */
        verglcpu_ptr=strstr(isa,"temp1:");
        while(ispunct(*verglcpu_ptr)==0){    //Wandert bis der Doppelpunkt erreicht ist
            verglcpu_ptr++;
        }
        while(isdigit(*verglcpu_ptr)==0){    //Wandert bis der gesuchte Wert erreicht ist
            verglcpu_ptr++;
        }
        cputemp=atoi(verglcpu_ptr);         //Wert umwandeln und aufrunden
        verglcpu_ptr+=3;
        if(atoi(verglcpu_ptr)>=5){
            cputemp++;
        }
        /* Lüfter Drehzahl heruastrennen*/
        verglfan_ptr=strstr(isa,"fan1:");
        while(ispunct(*verglfan_ptr)==0){   //Selbes prinzip wie oben nur ohne runden
            verglfan_ptr++;
        }
        while(isdigit(*verglfan_ptr)==0){
            verglfan_ptr++;
        }
        fanupm=atoi(verglfan_ptr);

        /* Ausgabe der Werte */
        sprintf(buffer,"~C"); /*Display leeren, siehe Doku Seite 1 unter Steuercodes*/
        write(fd,buffer,strlen(buffer));

        sprintf(buffer,"HDD1:%s Grad C\n",hdd1temp);
        write(fd,buffer,strlen(buffer));

        sprintf(buffer,"HDD2:%s Grad C\n",hdd2temp);
        write(fd,buffer,strlen(buffer));

        sprintf(buffer,"CPU:%d Grad C\n",cputemp);
        write(fd,buffer,strlen(buffer));

        sprintf(buffer,"FAN:%d U/Min\n",fanupm);
        write(fd,buffer,strlen(buffer));

        pclose(hdd1_ptr);
        pclose(hdd2_ptr);
        pclose(isa_ptr);
    }
}

void zeit(void){
    struct tm zeit;
    time_t now;
    time(&now);
    zeit = *localtime(&now);
    sprintf(buffer,"~C"); /*Display leeren*/
    write(fd,buffer,strlen(buffer));

    strftime(buffer,sizeof(buffer),"~P104%d.%m.%Y",&zeit);  /*Geh in Zeile 2 und Spalte 5, siehe Doku Seite 1 unter Steuercodes*/
    write(fd,buffer,strlen(buffer));                        /*und gebe Datum aus*/

    strftime(buffer,sizeof(buffer),"~P205%H:%M:%S",&zeit);  /*Geh in Zeile 3 und Spalte 6*/
    write(fd,buffer,strlen(buffer));                        /*und gebe Zeit aus*/
}

void init_S0(void){
    struct termios term_attr;
    struct sigaction saio;
    if((fd=open(TERM_DEVICE, O_RDWR | O_NOCTTY | O_NONBLOCK))==-1){
        perror("Can't open device " TERM_DEVICE);
        exit(EPERM);
    }
	
	//Asyncrones Read und Write noch nicht fertig implementiert
    //install the serial handler before making the device asynchronous
    saio.sa_handler = signal_handler_IO;
    sigemptyset(&saio.sa_mask);   //saio.sa_mask = 0;
    saio.sa_flags = 0;
    saio.sa_restorer = NULL;
    sigaction(SIGIO,&saio,NULL);

    // allow the process to receive SIGIO
    fcntl(fd, F_SETOWN, getpid());
    // Make the file descriptor asynchronous (the manual page says only
    // O_APPEND and O_NONBLOCK, will work with F_SETFL...)
    fcntl(fd, F_SETFL, FASYNC);

    if(tcgetattr(fd,&term_attr)!=0){
        perror("tcgetattr failed!");
        exit(EPERM);
    }
    term_attr.c_cflag = TERM_SPEED | CS8 | CRTSCTS | CLOCAL | CREAD;
    term_attr.c_iflag = IGNPAR | IXON | IXOFF | IGNCR | INLCR;
    term_attr.c_oflag = OPOST | ONLCR;
    term_attr.c_lflag = ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOCTL | ECHOKE ;
    term_attr.c_cc[VMIN]=0;
    term_attr.c_cc[VTIME]=0;
    tcflush(fd, TCIFLUSH);
    if(tcsetattr(fd,TCSANOW,&term_attr)!=0){
        perror("tcsetattr failed!");
        exit(EPERM);
    }
    sprintf(buffer,"~K0"); /*Coursor aus, siehe Doku Seite 1 unter Steuercodes*/
    write(fd,buffer,strlen(buffer));
}

void signal_handler_IO (int status){
//    printf("received SIGIO signal.\n");
   wait_flag = FALSE;
}
