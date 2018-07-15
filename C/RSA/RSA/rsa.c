#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <string.h>

int primeNumber(int min,int max);
bool isPrime(int num);
int modulusPower(int base, int exp, int mod);
int lcm(int a, int b);
int coPrime(int a);
char *chineseRemainderAlgorithm(char encryptedMsg[], int p, int q,  int privateKey);
char *char2intstr(char msg[]);
char *strconcat(char a[], char b[]);
char *encrypted(char msg[], int n, int publickey);
char *decrypt(char encryptedMsg[],int n, int privateKey);

bool isPrime(int num){
    //namratha
    if(num==0 || num==1){
        return false;
    }
    for (int i = 2; i<=sqrt(num);i++){
       if ((num % i) == 0){
			return false;
       }
    }
	return true;
}




/*
    primeNumber(int min,int max)=>integer type: returns a prime number between the range min and max
    min => integer type: the lower bound
    max => integer type: the upper bound
*/
int primeNumber(int min,int max){
    //namratha
    if(min>max || max==0 || max ==1){
        return 0;
    }

 while(min <= max)
    {
        // Printing if current number is prime
        if(isPrime(min))
        {
            break;
        }

        min++;
    }
    return min;
}





/*
    modulusPower(int base, int exponent, int mod)=>integer type: returns the value (base^exp)%mod
    base => integer type: the base value
    exp => integer type: the exponent value
    mod => integer type: the modulus to be taken
*/
int modulusPower(int base, int exp, int mod){

    if (base < 1 || exp < 0 || mod < 1)
        return 0;

    int result = 1;
    while (exp > 0) {
        result = (result * base) % mod;
       exp--;
    }
    return result;

    //kaushik
}

/*
    lcm(int a,int b)=>integer type: returns the least common factor of a and b
    a => integer type: any number
    b => integer type: any number
*/
int lcm(int a,int b){
    int k=1;
    double m;
    if(a==0 || b==0){
        return 0;
    }else if(a==1){
        return b;
    }else if(b==1){
        return a;
    }
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
    int k = 1,i,j=0;
    bool flag;
    int primeNumbers[10000];
    int numberOfPrimes = 0;
    int numberOfCoprimes = 0;
    int coprimes[100];
    for(i=2;i<sqrt(a);i++){
        if(isPrime(i) && a%i==0){
            primeNumbers[numberOfPrimes] = i;
            numberOfPrimes++;
            //realloc(primeNumbers, (sizeof(int)));
        }
    }
    for(i=2;i<a;i++){
        flag=true;
        for(j=0;j<numberOfPrimes;j++){
            if(i>=primeNumbers[j] && i%primeNumbers[j]==0){
                flag=false;
                break;
            }
        }
        if(flag){
            coprimes[numberOfCoprimes] = i;
            numberOfCoprimes++;
            if(numberOfCoprimes > 100){
                break;
            }
            //realloc(coprimes, (sizeof(int)));
        }
    }

    return coprimes[rand() % numberOfCoprimes];
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
    char *msg =(char*) malloc(sizeof(encryptedMsg)/sizeof(char));

    return msg;
}

/*
    encrypt(char msg[],int n, int publicKey)=>char pointer type: returns pointer of the encrypted message
    msg => integer type: the plaintext to be encrypted
    n => integer type: value of p*q
    publicKey => integer type: public key
*/
char *encrypted(char msg[],int n, int publicKey){
    //namratha
    if(n==0 || publicKey==0){
        return "Error n -> 0 or p -> 0";
    }else if(n < publicKey){
        return "Error n < publickey";
    }else if(n <= 255){
        return "Error n <= 255";
    }

    int number_of_digits = floor(log10(abs (n))) + 1;
    int len = strlen(msg);
    char *encryptedMsg = malloc(len*number_of_digits*sizeof(char));
    encryptedMsg[0] = '\0';
    int i,j,temp;
    char *tmpStr = malloc(number_of_digits*sizeof(char));
    char *ascii = malloc(number_of_digits*sizeof(char));
    for(i=0;i<len;i++){
        ascii[0] = '\0';
        tmpStr[0] = '\0';
        temp = (int)msg[i];
        int encrypted_char = modulusPower(temp,publicKey,n);
        sprintf(ascii, "%d", encrypted_char);
        strcpy(tmpStr,ascii);
        for(j=strlen(ascii);j<number_of_digits;j++){
            tmpStr = strconcat("0",tmpStr);
        }
        strcat(encryptedMsg,tmpStr);
    }
    /*
    Assume n =3233, p =17 & msg = Hello
    convert the msg to ascii: Hello => 72,101,108,108,111
    calculate (a^p)mod(n) for each ascii value where a is the ascii value => (72^17)mod(3233) = 3000 u can use function modulusPower
    pad the output so it matches number of digits in n => 3000 has the same number of digits as 3233 if u had lets say 62 pad with two 00 => 0062
    concatenate all the padded numbers into a string and return

    */
return encryptedMsg;
}

/*
    decrypt(char encryptedMsg[],int n, int privateKey)=>char pointer type: returns pointer of the encrypted message
    n => integer type: value of p*q
    publicKey => integer type: private key
*/
char *decrypt(char encryptedMsg[],int n, int privateKey){
    //dhanush
    if(n==0 || privateKey==0){
        return "Error n -> 0 or privateKey -> 0";
    }else if(n < privateKey){
        return "Error n < privateKey";
    }else if(n <= 255){
        return "Error n <= 255";
    }
    char *msg = malloc((3*strlen(encryptedMsg))*sizeof(char));
    int i,j;
    msg = char2intstr(encryptedMsg);
    //msg = encryptedMsg;
    int number_of_digits = floor(log10(abs (n))) + 1;
    char *decryptedMsg = malloc((strlen(encryptedMsg)/number_of_digits)*sizeof(char));
    char *temp = (char *)malloc(number_of_digits*sizeof(char));
    for(i=0;i<strlen(encryptedMsg)/number_of_digits;i++){
        for(j=0;j<number_of_digits;j++){
            temp[j] = encryptedMsg[(i*number_of_digits)+j];
        }
        temp[j]='\0';
        //printf("%s\n",temp);
        int m = atoi(temp);
        //printf("%i\n",m);
        int c = modulusPower(m, privateKey, n);
        decryptedMsg[i]=(char)(c);
    }
    decryptedMsg[i]='\0';
    return decryptedMsg;
}

char *char2intstr(char* msg){
    int ascii,i,len = strlen(msg);
    char *asciiInt = malloc(3*len*sizeof(char));
    //asciiInt = "";
    char* temp = malloc(3*sizeof(char));
    for(i=0;i<len;i++){
        ascii = (int)msg[i];
        sprintf(temp, "%d", ascii);
        int m = strlen(temp);
        if(m==2){
            temp = strconcat("0",temp);
        }else if(m==1){
            temp = strconcat("00",temp);
        }
        if(i==0){
            strcpy(asciiInt,temp);
        }else{
            strcat(asciiInt,temp);
        }
        //if(i<len-1){
        //    realloc(asciiInt,3*sizeof(char));
        //}
    }
    return asciiInt;
}

char *strconcat(char *a, char *b){

    char *res = malloc((strlen(a)+strlen(b))*sizeof(char));
    strcpy(res,a);
    strcat(res,b);
    return res;
}
