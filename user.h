/*
 * File:   user.h
 * Author: rk76fewf
 *
 * Created on September 12, 2022, 4:25 PM
 */

#ifndef USER_H
#define USER_H

#define FCY 16000000UL

#define LED1 _LATE3
#define LED2 _LATE2
#define LED3 _LATE1
#define BTN _RF3

#define F_CYCLE (320 - 1)

#define solenoid1 _LATB12
#define solenoid2 _LATB13
#define hcsr04_trig _LATF4
#define hcsr04_echo _RF5
// #define solenoid5 _LATB7
// #define solenoid6 _LATB6

typedef unsigned char data_t;
#define QUEUE_SIZE (64)
typedef struct
{
    int head;
    int num;
    data_t data[QUEUE_SIZE];
} queue_t;

#endif /* USER_H */
