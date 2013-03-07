/* *********************************************************************** *
 *       Filename:  netcat_common.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 07 March 2013 11:37:24  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Gamit (09211014), <prakashgamit23@gmail.com>
 *   Organization:  Indian Institute of Technology, Roorkee
 *
 * ********************************************************************** */

#include "netcat_core.h"
#include <strings.h>


/* @type - type of socket */
/* @return - socket descriptor */
extern int create_socket(int type);
