/* *********************************************************************** *
 *       Filename:  wrapper.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 07 March 2013 12:40:35  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Gamit (09211014), <prakashgamit23@gmail.com>
 *   Organization:  Indian Institute of Technology, Roorkee
 *
 * ********************************************************************** */

#ifndef _WRAPPER_H_
#define _WRAPPER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


extern int Socket(int, int, int);


extern int Bind(int, const struct sockaddr *, socklen_t);


extern int Connect(int, const struct sockaddr *, socklen_t);


extern int Listen(int, int);


extern int Accept(int, struct sockaddr *, socklen_t *);


extern int Inet_pton(int, const char *, void *);


#endif
