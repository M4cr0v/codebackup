/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月03日 16时14分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _STACK_
#define _STACK_ 1

#ifdef __cplusplus
extern "C" {
#endif

void infix_to_prefix(char *Dest, const char *Src);
void infix_to_prefix_test(void);


#ifdef __cplusplus
}
#endif

#endif
