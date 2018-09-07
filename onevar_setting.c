#include "onevar_setting.h"

void print_onevar_setting(const OnevarSetting opt){
    printf("\nSingle Variable Optimization\n");
    if(opt.algorithm == SECANT){
        printf("%35s: %s\n", "algorithm", "secant method");
        printf("%35s: %7d\n", "max total iterations [maxiter]", (int)opt.maxiter);
        printf("%35s: %7d\n", "max iter non-converge [maxjump]", (int)opt.maxjump);
        printf("%35s: %E\n", "stop function tolerance [tolfun]", opt.tolfun);
        printf("%35s: %7s\n", "display iteration [disp]", opt.disp ? "Yes" : "No");
        printf("%35s: %16.8f\n", "fixed learning rate [delta]", opt.delta);
        printf("%35s: %16.8f\n", "1st Start Value [x0]", opt.x0);
        printf("%35s: %16.8f\n", "2nd Start Value [x1]", opt.x1);
    }
    else{
        printf("No algorithm set\n");
    }
}

/* Initialize OnevarSetting struct with default values
 * */
OnevarSetting onevar_setting_init(const OnevarAlgorithm algo){
    OnevarSetting opt;

    if(algo == SECANT){
        opt.algorithm = SECANT;
        opt.maxjump = 15;  // max num iter after a new best solution was found
        opt.maxiter = 300; // maximum total number of iterations
        opt.tolfun = 1e-8; // better use 1e-12
        opt.disp = false;
        opt.delta = 0.1; // fixed learning rate
        opt.x0 = -0.33; // initial/start values 
        opt.x1 =  1.33; // important! x0 != x1
    }else{
        printf("No algorithm set\n");
        opt.algorithm = -1;
    }

    return opt; 
}
