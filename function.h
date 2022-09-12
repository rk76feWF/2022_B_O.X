/*
 * File:   function.h
 * Author: rk76fewf
 *
 * Created on September 12, 2022, 4:25 PM
 */

#ifndef FUNCTION_H
#define FUNCTION_H

void setup(void);
void setIO(void);

void setUART(void);
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void);
void __attribute__((interrupt, no_auto_psv)) _U2RXInterrupt(void);
void prints(char *text);

#endif /* FUNCTION_H */
