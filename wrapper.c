/* *********************************************************************** *
 *
 *       Filename:  wrapper.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 07 March 2013 12:44:15  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Gamit (09211014), <prakashgamit23@gmail.com>
 *   Organization:  Indian Institute of Technology, Roorkee
 *
 * ********************************************************************* */

#include "wrapper.h"
#include "netcat_core.h"


int Socket(int family, int type, int protocol){
    int fd = socket(family, type, protocol);

    if(fd == -1){
        die("socket");
    }

    return fd;
}


int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int status = bind(sockfd, addr, addrlen);

    if(status == -1)
        die("bind");

    return status;
}


int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int status = connect(sockfd, addr, addrlen);

    if(status == -1)
        die("connect");

    return status;
}


int Listen(int sockfd, int backlog){
    int status = listen(sockfd, backlog);

    if(status == -1)
        die("listen");
    
    return status;
}


int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
    int clifd = accept(sockfd, addr, addrlen);

    if(clifd == -1)
        die("accept");

    return clifd;
}
