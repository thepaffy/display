#include <stdio.h>      /* für ausgaben, datei und pipe arbeit */
#include <stdlib.h>     /* für atoi, exit */
#include <time.h>       /* für Funktionen in zeit.c */
#include <string.h>     /* für strstr */
#include <ctype.h>      /* für ispunct, isdigit */
#include <unistd.h>     /* für sleep */
#include <errno.h>      /* für die Errornummern*/
#include <termios.h>    /* serielle Schnitstelle */
#include <fcntl.h>      /* für read, write, open*/
#include <sys/signal.h>
#include <sys/types.h>

#define FALSE 0
#define TRUE 1

#ifndef KCFUNCTIONS_H
#define KCFUNCTIONS_H

extern int fd;
extern char buffer[22];
extern int wait_flag;
void werte(void);
void zeit(void);
void init_S0(void);
void signal_handler_IO (int status);

#endif /* KCFUNCTIONS_H */