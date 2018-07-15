/*
 * rsa.h
 *
 *  Created on: Jul 15, 2018
 *      Author: Dhanush
 */

#ifndef RSA_H_
#define RSA_H_

extern int primeNumber(int min,int max);
extern bool isPrime(int num);
extern int modulusPower(int base, int exp, int mod);
extern int lcm(int a, int b);
extern char *chineseRemainderAlgorithm(char encryptedMsg[], int p, int q,  int privateKey);
extern int coPrime(int a);
extern char *char2intstr(char msg[]);
extern char *strconcat(char a[], char b[]);
extern char *encrypted(char msg[], int n, int publickey);
extern char *decrypt(char encryptedMsg[],int n, int privateKey);


#endif /* RSA_H_ */
