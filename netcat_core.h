/* *********************************************************************** *
 *       Filename:  netcat_core.h
 *
 *    Description:  define options struct & declare global variables
 *
 *        Version:  1.0
 *        Created:  Wednesday 06 March 2013 01:31:03  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Gamit (09211014), <prakashgamit23@gmail.com>
 *   Organization:  Indian Institute of Technology, Roorkee
 *
 * ********************************************************************** */

#ifndef _NETCAT_CORE_H_
#define _NETCAT_CORE_H_


/* include standar header files */
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <strings.h>

#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>


struct options{
    /* source port to use */
    unsigned short port;

    /* is it listen mode or client mode */
    int listen;
    /* accept multiple connections in listen mode */
    int keepopen;

    /* socket is udp */
    int udp;

    /* should be verbose */
    int verbose;

    /* command is to be executed */
    int execcommand;
    /* command to execute */
    char *command;
};


/* declare global variables */

/* global options struct */
extern struct options o;

/* server address struct */
extern struct sockaddr_in servaddr;

/* socket descriptor created using socket */
extern int sockfd;


#endif
