#include <stdio.h>  // printf
#include "onevar_setting.h"

int main()
{
    // Example 1
    OnevarSetting opt;
    opt.maxjump = 15;  // max num iter after a new best solution was found
    opt.maxiter = 300; // maximum total number of iterations
    opt.tolfun = 1e-8; // better use 1e-12
    opt.disp = true;
    opt.delta = 0.1; // fixed learning rate
    opt.x0 = -0.33; // initial/start values 
    opt.x1 =  1.33; // important! x0 != x1
    print_onevar_setting(opt);

    // Example 2
    OnevarSetting opt2 = onevar_setting_init(SECANT);
    print_onevar_setting(opt2);

	return 0;
}
