#ifndef ONEVAR_SETTING_H
#define ONEVAR_SETTING_H

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

typedef enum {
    SECANT
} OnevarAlgorithm;

typedef struct {
    OnevarAlgorithm algorithm;
    // General Settings
    size_t maxiter; // maximum total number of iterations
    double tolfun; // better use 1e-12
    size_t maxjump;  // max num iter after a new best solution was found
    bool disp;
    // Learning Rate
    double delta; // fixed learning rate
    // Start Values
    double x0; // initial/start values 
    double x1; // important! x0 != x1
} OnevarSetting;

void print_onevar_setting(const OnevarSetting opt);

OnevarSetting onevar_setting_init(const OnevarAlgorithm algo);

#endif /* ONEVAR_SETTING_H */
