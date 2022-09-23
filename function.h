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
void setPWM(void);

void setUART(void);
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void);
void __attribute__((interrupt, no_auto_psv)) _U2RXInterrupt(void);
void prints(char *text);

void setIC(void);
void __attribute__((interrupt, no_auto_psv)) _IC1Interrupt(void);

void moter(int num, double power);

int enqueue(queue_t *que, data_t enq_data);
int dequeue(queue_t *que, data_t *deq_data);

void setHCSR04(void);
void __attribute__((interrupt, no_auto_psv)) _IC2Interrupt(void);
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void);

#endif /* FUNCTION_H */
