import java.util.*;
import java.lang.Math;
import java.util.Random;
public class RSA{

	public boolean isPrime(int num){
		if(num == 0 || num ==1){
			return false;
		}
		for(int i=2;i<=Math.ceil(Math.sqrt(num));i++){
			if(num%i==0){
				return false;
			}
		}
		return true;
	}

	public int primeNumber(int min,int max){
		if(min==0 || max==0 || max<min)
			return 0;
		if(min==max && !this.isPrime(min))
			return 0;
		for(int i=min;i<=max; i++)
		{
			if(isPrime(i))
				return i;
		}
		return 0;
	}

	public double modulusPower(int base,int exp, int mod){

	    if (base < 1 || exp < 0 || mod < 1)
        return 0;

    int result = 1;
    while (exp > 0) {
        result = (result * base) % mod;
       exp--;
    }
    return result;


	}

	public int lcm(int a, int b){

		double val;
		int k = 1;
		if(a==0 || b==0) {return 0;}
		if(a==1)return b;
		if(b==1)return a;

		while(true) {
			val = (double)(a*k)/b ;
			if (val == Math.floor(val)){
				return a*k;
		    }else {
			 k=k+1;}
	    }
	}

	public int coprime(int a){

		int k = 1,i,j=0;
        boolean flag;
        int primeNumbers[];
        primeNumbers = new int[10000];
        int numberOfPrimes = 0;
        int numberOfCoprimes = 0;
        int coprimes[];
        coprimes= new int[100];

        for(i=2;i<Math.sqrt(a);i++){
            if(isPrime(i) && a%i==0){
            primeNumbers[numberOfPrimes] = i;
            numberOfPrimes++;
        }
        }

        for(i=2;i<a;i++){
        flag = true;
        for(j=0;j<numberOfPrimes;j++){
            if(i>=primeNumbers[j] && i%primeNumbers[j]==0){
                flag = false;
                break;
            }
        }
        if(flag){
            coprimes[numberOfCoprimes] = i;
            numberOfCoprimes++;
            if(numberOfCoprimes > 100){
                break;
            }
            
        }
    }

    int result = coprimes[(int)Math.random() % numberOfCoprimes];
    return result;
	}

	public String encrypt(String msg,int n, int publicKey){

    //namratha
    if(n==0 || publicKey==0){
        return "Error n -> 0 or p -> 0";
    }else if(n < publicKey){
        return "Error n < publickey";
    }else if(n <= 255){
        return "Error n <= 255";
    }

    int number_of_digits = (int)(Math.floor(Math.log10(Math.abs (n))) + 1);
    int len = msg.length();
    String encryptedMsg = new string(len*number_of_digits);
    int temp;
    String tmpStr = new String(number_of_digits);
    String ascii = new String(number_of_digits);
    for(i=0;i<len;i++){
        ascii[0] = '\0';
        tmpStr[0] = '\0';
        temp = (int)msg[i];
        int encrypted_char = modulusPower(temp,publicKey,n);
        sprintf(ascii, "%d", encrypted_char);
        strcpy(tmpStr,ascii);
        for(j=ascii.length();j<number_of_digits;j++){
            tmpStr = strconcat("0",tmpStr);
        }
        strcat(encryptedMsg,tmpStr);
    }
	public String decrypt(String encryptedMsg,int n, int privateKey){
		String decryptedMsg = "";

		return decryptedMsg;
	}

	public String chineseRemainderTheorem(String encryptedMsg,int p, int q, int privateKey){
		String decryptedMsg = "";

		return decryptedMsg;
	}
}
