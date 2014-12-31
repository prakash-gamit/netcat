/* *********************************************************************** *
 *
 *       Filename:  netcat_main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 06 March 2013 02:20:39  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Gamit (09211014), <prakashgamit23@gmail.com>
 *   Organization:  Indian Institute of Technology, Roorkee
 *
 * ********************************************************************* */

#include "netcat_core.h"
#include "netcat_client.h"
#include "netcat_listen.h"


/* show usage & help */
void help(char *argv[]);

/* check whether its a valid port or not */
int validate_port(char *);


int main(int argc, char *argv[]){
    /* initialize options */
    init_options();

    /* parse command line args */
    int c;
    while((c = getopt(argc, argv, ":hve:p:lku")) != -1){
        switch(c){
            case 'h': help(argv);
                      exit(EXIT_SUCCESS);

            case 'v': o.verbose = 1;
                      break;

            case 'e': o.execcommand = 1;
                      o.command = optarg;
                      break;

            case 'p': o.port = validate_port(optarg);
                      break;

            case 'l': o.listen = 1;
                      break;

            case 'k': o.keepopen = 1;
                      break;

            case 'u': o.udp = 1;
                      break;

            case ':': bye("-%c requires argument\n", optopt);

            /* case ? */
            default: bye("unknown option -%c\n", optopt);

        }/* switch */
    }/* while */

    /* do some checking */

    /* -k specified without -l */
    if(o.keepopen && !o.listen){
        bye("cannot specify -k without -l\n");
    }

    /* -p not specified with -l */
    if(o.listen && !o.port){
        bye("must specify -p with -l\n");
    }


    /* get IP-address and port in case of client mode */
    if(!o.listen && optind < argc){
        o.target = argv[optind++];

        if(optind > argc){
            bye("No port specified\n");
        }

        o.port = validate_port(argv[optind]);

    } else if(!o.listen){
        help(argv);
        exit(EXIT_FAILURE);
    }

    if(o.listen)
        start_server();
    else
        start_client();

    return 0;
}/* main() */


void help(char *argv[]){
    //TODO
    //write usage & help
    printf("example invocation:\n");
    printf("server -\n");
    printf("%s -l -p <port number> [-ekuv]\n", argv[0]);
    printf("client -\n");
    printf("%s <IP-address> <port>\n\n", argv[0]);

    printf("options:\n");
    printf("-h  show this help message\n");
    printf("-v  show verbose output\n");
    printf("-e  execute command\n");
    printf("-p  specify port number\n");
    printf("-l  start netcat in listen mode(server)\n");
    printf("-k  keep server running after disconnecting from one client.\n");
    printf("-u  use UDP instead of TCP\n");
}


int validate_port(char *p){
    int port = atoi(p);

    if(port <= 0 || port > 0xffff){
        bye("Invalid port %d\n", port);
    }

    /* return port number if its valid */
    return port;
}
