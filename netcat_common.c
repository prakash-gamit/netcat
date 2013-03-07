/* *********************************************************************** *
 *
 *       Filename:  netcat_common.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 07 March 2013 11:40:53  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Gamit (09211014), <prakashgamit23@gmail.com>
 *   Organization:  Indian Institute of Technology, Roorkee
 *
 * ********************************************************************* */

#include "netcat_common.h"


int create_socket(int type){
    int sockettype = SOCK_STREAM;

    /* if -u flag is specified on command line for udp */
    if(type){
        sockettype = SOCK_DGRAM;
    }

    int fd = Socket(AF_INET, sockettype, 0);

    return fd;
}
