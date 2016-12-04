//
//  UnitTest.hpp
//  DailyCoding
//
//  Created by limingding on 12/4/16.
//  Copyright © 2016 limingding. All rights reserved.
//

#ifndef UnitTest_h
#define UnitTest_h

#include <stdio.h>
#include <time.h>
char error_msg[256];
int  tests_number;
int  failed_number;

#define mu_assert(message, test) do { if(!(test)) {sprintf(error_msg, "[%s: ln %d] %s", __FILE__, __LINE__, message); return error_msg; }} while(0)

#define mu_run_test(test) do{ \
    fprintf(stdout, "[RUN    ]%s\n", #test); \
    clock_t tick = clock(); \
    char* message = test(); \
    tick = clock() - tick; \
    tests_number++; \
    if(message) { fprintf(stdout, "[    FAILED] %s (%d ms)\n", message, (int)tick); failed_number++; } \
    else fprintf(stdout, "[    OK] %s (%d ms)\n", #test, (int)tick); \
    }while(0)

#define mu_run_test_with_params(test, para) do{ \
fprintf(stdout, "[RUN    ]%s\n", #test); \
clock_t tick = clock(); \
char* message = test(para); \
tick = clock() - tick; \
tests_number++; \
if(message) { fprintf(stdout, "[    FAILED] %s (%d ms)\n", message, (int)tick); failed_number++; } \
else fprintf(stdout, "[    OK] %s (%d ms)\n", #test, (int)tick); \
}while(0)

#endif /* UnitTest_h */
