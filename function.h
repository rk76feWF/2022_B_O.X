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

// Moter
void setMoter(void);
void moter(int num, double power);

// UART (メインボードとの通信)
void setUART(void);
void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void);
int enqueue(queue_t *que, data_t enq_data);
int dequeue(queue_t *que, data_t *deq_data);
void prints(char *text);
void __delay_UART(int d);
void controller(void);

// Encoder
void setEncoder(void);
void __attribute__((interrupt, no_auto_psv)) _IC1Interrupt(void);

// HC-SR04 (超音波センサ)
void setHCSR04(void);
void __attribute__((interrupt, no_auto_psv)) _IC2Interrupt(void);

#endif /* FUNCTION_H */
