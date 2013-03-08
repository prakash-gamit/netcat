/* *********************************************************************** *
 *
 *       Filename:  netcat_listen.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 07 March 2013 09:52:58  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Gamit (09211014), <prakashgamit23@gmail.com>
 *   Organization:  Indian Institute of Technology, Roorkee
 *
 * ********************************************************************* */

#include "netcat_listen.h"


int sockfd;


void start_server(){
    sockfd = create_socket(o.listen);

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(o.port);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    listen(sockfd, 5);

    /* start service */
    do{
        printf("service\n");
        service();
    }while(o.keepopen);
}


void service(){
    struct sockaddr_in cliaddr;
    int clifd, clilen;
    /* accept a connection */
    clifd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);

    char sendline[MAX], recvline[MAX];
    fd_set rset;
    int maxfdp1;

    FD_ZERO(&rset);
    while(1){
        FD_SET(fileno(stdin), &rset);
        FD_SET(clifd, &rset);

        maxfdp1 = (fileno(stdin) < clifd? clifd : fileno(stdin)) + 1;

        select(maxfdp1, &rset, NULL, NULL, NULL);

        if(FD_ISSET(clifd, &rset)){
            read(clifd, recvline, MAX);

            fputs(recvline, stdout);
        }

        if(FD_ISSET(fileno(stdin), &rset)){
            if(fgets(sendline, MAX, stdin) == NULL)
                break;/* all done */

            write(clifd, sendline, strlen(sendline));
        }
    }/* while */
    
    /* close connection */
    close(clifd);
}
