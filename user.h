/*
 * File:   user.h
 * Author: rk76fewf
 *
 * Created on September 12, 2022, 4:25 PM
 */

#ifndef USER_H
#define USER_H

#define FCY 16000000UL

// IO
#define LED1 _LATE3
#define LED2 _LATE2
#define LED3 _LATE1
#define BTN _RF3

// Moter
#define F_CYCLE (320 - 1)

// UART
typedef unsigned char data_t;
#define QUEUE_SIZE (64)
typedef struct
{
    int head;
    int num;
    data_t data[QUEUE_SIZE];
} queue_t;

// Solenoid
#define solenoid1 _LATB12
#define solenoid2 _LATB13

// HC-SR04
#define hcsr04_trig _LATF4
#define hcsr04_echo _RF5

#endif /* USER_H */
