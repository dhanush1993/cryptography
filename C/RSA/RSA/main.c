/*
Authors: Dhanush, Kaushik, Namratha, Mahendra
Algorithm : https://simple.wikipedia.org/wiki/RSA_algorithm

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <string.h>
//#include "test.c"
#include "rsa.h"



int main()
{
    /*

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
    test_modulusPower(INT_MAX,2,3010,"2199");
    test_modulusPower(0,5,5,"0");
    test_modulusPower(5,0,5,"1");
    test_modulusPower(5,25,1,"0");
    printf("----------------------------------------------\n");
    printf("--------Testing function lcm---------\n");
    printf("----------------------------------------------\n");
    test_lcm(5,25,"25");
    test_lcm(23002,1000,"11501000");
    test_lcm(0,5,"0");
    test_lcm(5,1,"5");
    printf("----------------------------------------------\n");
    printf("--------Testing function encrypt---------\n");
    printf("----------------------------------------------\n");
    test_encrypt("Hello",25,5,"Error - n > 255");
    test_encrypt("Hello",300,1000,"Error - n > publicKey");
    test_encrypt("Hello",300,0,"Error - publicKey != 0");
    test_encrypt("Hello",3233,17,"30001313074507452185");
    printf("----------------------------------------------\n");
    char *msg = decrypt("30001313074507452185",3233,413);
    printf("%s",msg);
    */

    //test_encrypt("Hello",2773,179,"30001313074507452185");

    int min,max,p,q,n,totient,e,d,k=0;
    double m;
    srand ( time(NULL) );
    p = rand()%10;
    q = 50+rand()%50;
    while(n <= 255){
        while(!isPrime(p) || p > 100 || p<10)
            p = primeNumber(floor(rand()%100),floor(rand()%100));
        while(!isPrime(q) || q > 100 || q<10)
            q = primeNumber(floor(rand()%100),floor(rand()%100));
        if(!isPrime(p) || p==0){
            printf("Error: Sorry p is not a prime number\n");
            exit(0);
        }
        if(!isPrime(q) || q==0){
            printf("Error: Sorry q is not a prime number\n");
            exit(0);
        }
        n = p*q;
    }

    totient = lcm((p-1),(q-1));
    e = coPrime(totient);
    printf("Public key pair is (n,e)=(%i,%i)\n",n,e);
    if(e==0){
        printf("Public key cannot be 0\n");
        exit(0);
    }
    k = ((e*e)-1)/totient;
    while(true){
        k = k+1;
        m = (double)(1+(k*totient))/e;
        if(ceil(m)==floor(m)){
            break;
        }
    }
    d = floor(m);
    printf("Private key is %i\n",d);
    int sharedN,sharedE;
    printf("Enter the n value of the shared public key\n");
    scanf("%i",&sharedN);
    printf("Enter the e value of the shared public key\n");
    scanf("%i",&sharedE);
    int cmd = 0;
    while(cmd == 0){
        printf("Enter 1 to Encrypt or 2 to Decrypt\n");
        scanf("%i",&cmd);
        if(cmd == 1){
            char msg[255];
            printf("Please enter the message to encrypt:\n");
            scanf("%s",&msg);
            printf("The encrypted message is: %s\n",encrypted(msg,sharedN, sharedE));
            cmd =0;
        }else if(cmd == 2){
            char msg[255];
            printf("Please enter the message to decrypt:\n");
            scanf("%s",&msg);
            printf("The decrypted message is: %s\n",decrypt(msg,n, d));
            cmd =0;
        }
    }

    return 0;
}

/*
    isPrime(int num)=> boolean type: returns true if num is a prime number else returns false
    num => integer type: the value to check
*/


