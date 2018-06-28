/*
Authors: Dhanush, Kaushik, Namratha, Mahendra
Algorithm : https://simple.wikipedia.org/wiki/RSA_algorithm

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "test.c"
bool isPrime(int num);
int primeNumber(int min,int max);
int modulusPower(int base, int exp, int mod);
int lcm(int a, int b);
int coPrime(int a);
char *chineseRemainderAlgorithm(char encryptedMsg[], int p, int q,  int privateKey);
char *encrypt(char msg[],int n, int publicKey);
char *decrypt(char encryptedMsg[],int n, int privateKey);


int main()
{
    printf("----------------------------------------------\n");
    printf("----------Testing function isPrime------------\n");
    printf("----------------------------------------------\n");
    test_isPrime(15,"false");
    test_isPrime(11,"true");
    test_isPrime(1,"false");
    test_isPrime(0,"false");
    printf("----------------------------------------------\n");
    printf("--------Testing function primeNumber----------\n");
    printf("----------------------------------------------\n");
    test_primeNumber(10,11,"11");
    test_primeNumber(3,100,"3");
    test_primeNumber(8,10,"0");
    test_primeNumber(0,1,"0");
    test_primeNumber(0,2,"2");
    printf("----------------------------------------------\n");
    printf("--------Testing function modulusPower---------\n");
    printf("----------------------------------------------\n");
    test_modulusPower(5,25,10,"5");
    test_modulusPower(23002,1000,3010,"1106");
    test_modulusPower(0,5,5,"0");
    test_modulusPower(5,0,5,"1");
    test_modulusPower(5,25,1,"0");
    /*
    char *msg = "Hello World";
    int min,max,p,q,n,totient,e,d,k=0;
    double m;
    p = 61;   //later replace p with p = primeNumber(min,max);
    q = 53;   //later replace q with q = primeNumber(min,max);
    if(!isPrime(p) || p==0){
        printf("Error: Sorry p is not a prime number\n");
        exit(0);
    }else{
        printf("p is a prime number\n");
    }
    if(!isPrime(q) || q==0){
        printf("Error: Sorry q is not a prime number\n");
        exit(0);
    }else{
        printf("q is a prime number\n");
    }
    n = p*q;
    totient = lcm((p-1),(q-1));
    printf("Totient should be 780 your answer is %i\n",totient);
    e = coPrime(totient);
    printf("Error: Public key is %i\n",e);
    if(e==0){
        printf("Public key cannot be 0\n");
        exit(0);
    }
    while(true){
        k = k+1;
        m = (double)(1+(k*totient))/e;
        if(ceil(m)==floor(m)){
            break;
        }
    }
    d = floor(m);
    printf("Private key is %i\n",d);
    */

    return 0;
}

/*
    isPrime(int num)=> boolean type: returns true if num is a prime number else returns false
    num => integer type: the value to check
*/
bool isPrime(int num){
    //namratha
    return true;
}

/*
    primeNumber(int min,int max)=>integer type: returns a prime number between the range min and max
    min => integer type: the lower bound
    max => integer type: the upper bound
*/
int primeNumber(int min,int max){
    //namratha
    return 0;
}

/*
    modulusPower(int base, int exponent, int mod)=>integer type: returns the value (base^exp)%mod
    base => integer type: the base value
    exp => integer type: the exponent value
    mod => integer type: the modulus to be taken
*/
int modulusPower(int base, int exp, int mod){
    //kaushik
    return 0;
}

/*
    lcm(int a,int b)=>integer type: returns the least common factor of a and b
    a => integer type: any number
    b => integer type: any number
*/
int lcm(int a,int b){
    int k=1;
    double m;
    while(true){
        m = (double)(a*k)/b;
        if(m==floor(m)){
            break;
        }else{
            k = k+1;
        }
    }

    return a*k;
}

/*
    coPrime(int a)=>integer type: returns the coprime of a randomly picked between 1 and a
    a => integer type: any number
*/
int coPrime(int a){
    //dhanush
    return 0;
}

/*
    chineseRemainderAlgorithm(char encryptedMsg[], int p, int q,  int privateKey)=>char pointer type: implements the chinese remainder theorem
    (please see: https://en.wikipedia.org/wiki/RSA_(cryptosystem)#Using_the_Chinese_remainder_algorithm)
    encryptedMsg => integer type: the base value
    p => integer type: prime number
    q => integer type: prime number
    privateKey => integer type: private key
*/
char *chineseRemainderAlgorithm(char encryptedMsg[], int p, int q,  int privateKey){
    //kaushik
    char *msg = malloc(sizeof(encryptedMsg)/sizeof(char));

    return *msg;
}

/*
    encrypt(char msg[],int n, int publicKey)=>char pointer type: returns pointer of the encrypted message
    msg => integer type: the plaintext to be encrypted
    n => integer type: value of p*q
    publicKey => integer type: public key
*/
char *encrypt(char msg[],int n, int publicKey){
    //namratha
    char *encryptedMsg = malloc(sizeof(msg)/sizeof(char));

    return *encryptedMsg;
}

/*
    decrypt(char encryptedMsg[],int n, int privateKey)=>char pointer type: returns pointer of the encrypted message
    n => integer type: value of p*q
    publicKey => integer type: private key
*/
char *decrypt(char encryptedMsg[],int n, int privateKey){
    //dhanush
    char *msg = (char *)malloc(sizeof(encryptedMsg)/sizeof(char));

    return *msg;
}
