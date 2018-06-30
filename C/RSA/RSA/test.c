#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int primeNumber(int min,int max);
bool isPrime(int num);
int modulusPower(int base, int exp, int mod);
int lcm(int a, int b);
int coPrime(int a);
char *chineseRemainderAlgorithm(char encryptedMsg[], int p, int q,  int privateKey);
char *encrypt(char msg[],int n, int publicKey);
char *decrypt(char encryptedMsg[],int n, int privateKey);


void test_isPrime(int num,char* result);
void test_print(char *actual_value, char *returned_value);
char *bool2string(bool val);
void test_primeNumber(int min,int max,char* result);
void test_modulusPower(int base,int power,int mod,char* result);
void test_lcm(int a,int b,char* result);
int digits_in_num(int n);
void test_encrypt(char* msg,int n, int publicKey, char* result);

void test_isPrime(int num,char* result){
    char* isPrim;
    printf("Testing for value: %i\n",num);
    isPrim = bool2string(isPrime(num));
    test_print(result, isPrim);
}

void test_primeNumber(int min,int max,char* result){
    printf("Testing for prime numbers between %i to %i\n",min,max);
    char* num;
    if(max != 0){
        num = malloc((int)((ceil(log10(max))+1)*sizeof(char)));
    }
    sprintf(num, "%i", primeNumber(min,max));
    test_print(result,num);
}

void test_modulusPower(int base,int power,int mod,char* result){
    printf("Testing for (%i^%i)mod(%i)\n",base,power,mod);
    char* num;
    if(mod!=0){
        num = malloc((int)((ceil(log10(mod))+1)*sizeof(char)));
    }
    sprintf(num, "%i", modulusPower(base,power,mod));
    test_print(result,num);
}

void test_lcm(int a,int b,char* result){
    printf("Testing for lcm(%i,%i)\n",a,b);
    char* num;
    if(a*b != 0){
        num = malloc((int)((ceil(log10(a*b))+1)*sizeof(char)));
    }
    sprintf(num, "%i", lcm(a,b));
    test_print(result,num);

}

void test_encrypt(char* msg,int n, int publicKey, char* result){
    printf("Testing for encryption (%s,%i,%i)\n",msg,n,publicKey);
    char *encryptMsg=(char*) malloc((sizeof(msg)/sizeof(char))*digits_in_num(n));
    encryptMsg = encrypt(msg,n, publicKey);
    test_print(result,encryptMsg);
}

void test_print(char *actual_value, char *returned_value){
    printf("Actual value: %s",actual_value);
    printf("  |  ");
    printf("Returned value: %s\n",returned_value);
}

char *bool2string(bool val){
    return val?"true":"false";
}

int digits_in_num(int n){
    int count =0;
    while(n != 0)
    {
        // n = n/10
        n /= 10;
        ++count;
    }
    return count;
}
