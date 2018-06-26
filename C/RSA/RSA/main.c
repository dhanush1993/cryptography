#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPrime(int num);
int primeNumber(int min,int max);
int modulusPower(int base, int exp, int mod);
char *chineseRemainderAlgorithm(char encryptedMsg[], int p, int q,  int privateKey);
char *encrypt(char msg[],int n, int publicKey);
char *decrypt(char encryptedMsg[],int n, int privateKey);
int main()
{
    return 0;
}

/*
    isPrime(int num)=> boolean type: returns true if num is a prime number else returns false
    num => integer type: the value to check
*/
bool isPrime(int num){

    return true;
}

/*
    primeNumber(int min,int max)=>integer type: returns a prime number between the range min and max
    min => integer type: the lower bound
    max => integer type: the upper bound
*/
int primeNumber(int min,int max){

    return 0;
}

/*
    modulusPower(int base, int exponent, int mod)=>integer type: returns the value (base^exp)%mod
    base => integer type: the base value
    exp => integer type: the exponent value
    mod => integer type: the modulus to be taken
*/
int modulusPower(int base, int exp, int mod){

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
    char *encryptedMsg = malloc(sizeof(msg)/sizeof(char));

    return *encryptedMsg;
}

/*
    decrypt(char encryptedMsg[],int n, int privateKey)=>char pointer type: returns pointer of the encrypted message
    n => integer type: value of p*q
    publicKey => integer type: private key
*/
char *decrypt(char encryptedMsg[],int n, int privateKey){
    char *msg = (char *)malloc(sizeof(encryptedMsg)/sizeof(char));

    return *msg;
}
