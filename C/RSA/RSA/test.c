#include <stdio.h>
#include <stdlib.h>
bool isPrime(int num);
void test_isPrime(int num,char* result);
void test_print(char *actual_value, char *returned_value);
char *bool2string(bool val);
void test_primeNumber(int min,int max,char* result);
void test_modulusPower(int base,int power,int mod,char* result);
void test_isPrime(int num,char* result){
    char* isPrim;
    printf("Testing for value: %i\n",num);
    isPrim = bool2string(isPrime(num));
    test_print(result, isPrim);
}

void test_primeNumber(int min,int max,char* result){
    printf("Testing for prime numbers between %i to %i\n",min,max);
    char num[(int)((ceil(log10(max))+1)*sizeof(char))];
    sprintf(num, "%i", primeNumber(min,max));
    test_print(result,num);
}

void test_modulusPower(int base,int power,int mod,char* result){
    printf("Testing for (%i^%i)mod(%i)\n",base,power,mod);
    char num[(int)((ceil(log10(mod))+1)*sizeof(char))];
    sprintf(num, "%i", modulusPower(base,power,mod));
    test_print(result,num);
}

void test_print(char *actual_value, char *returned_value){
    printf("Actual value: %s",actual_value);
    printf("  |  ");
    printf("Returned value: %s\n",returned_value);
}

char *bool2string(bool val){
    return val?"true":"false";
}
