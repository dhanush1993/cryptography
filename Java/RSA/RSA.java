//package com.rsa.main;

import java.lang.Math;
import java.util.ArrayList;
public class RSA{

	public boolean isPrime(int num)throws Exception{
		if(num == 0 || num ==1){
			throw new Exception("Number cannot be 0 or 1.");
		}
		for(int i=2;i<=Math.ceil(Math.sqrt(num));i++){
			if(num%i==0 && num!=i){
				return false;
			}
		}
		return true;
	}

	public int primeNumber(int min,int max) throws Exception{
		if(min==0 || max==0)
			throw new Exception("The minimum and maximum range should be greater than zero.");
		if (max<min)
			throw new Exception("The minimum value cannot be greater than maximum value.");
		if(min==max && !isPrime(min))
			return 0;
		for(int i=min;i<=max; i++)
		{
			if(isPrime(i))
				return i;
		}
		return 0;
	}

	public double modulusPower(int base,int exp, int mod)throws Exception{

	    if (base == 0)
	    	throw new Exception("The base should not be zero");
	    if(exp < 0)
	    	throw new Exception("The Exponent cannot be less than zero");
	    if(mod < 1)
	    	throw new Exception("The Modulus cannot be less than zero");

    int result = 1;
    while (exp > 0) {
        result = (result * base) % mod;
       exp--;
    }
    return result;


	}

	public int lcm(int a, int b) throws Exception{

		double val;
		int k = 1;
		if(a==0 || b==0) {
			throw new Exception("In lcm(a,b) a and b cannot be zero");
			}
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

	public int coprime(int a) throws Exception{
		
		if(a==0) {
			throw new Exception("In coprime(a): a cannot be zero.");
		}
		int i;
        boolean flag;
        ArrayList<Integer> primeNumbers = new ArrayList<Integer>();
        ArrayList<Integer> coprimes= new ArrayList<Integer>();

			for(i=2;i<=(a);i++){
				if(isPrime(i) && a%i==0){
				primeNumbers.add(i);
			}
        }

        for(i=2;i<a;i++){
        flag = true;
			for(int primenumber:primeNumbers){
				if(i>=primenumber && i%primenumber==0){
					flag = false;
					break;
				}
			}
			if(flag==true){
				coprimes.add(i);
				if(coprimes.size() > 100){
					break;
				}

			}
		}
        int result;
        try {
        	result = coprimes.get((int)(Math.random() * Math.abs(coprimes.size()-100)));
        }catch(Exception e)
        {
        	result = 0;
        }
        return result;
	}

	public String encrypt(String msg,int n, int publicKey) throws Exception{

		//namratha
		if(n==0 || publicKey==0){
			throw new Exception("Error n -> 0 or p -> 0");
		}else if(n < publicKey){
			throw new Exception("Error n < publickey");
		}else if(n <= 255){
			throw new Exception("Error n <= 255");
		}

		int number_of_digits = (int)(Math.floor(Math.log10(Math.abs (n))) + 1);

		String encryptedMsg = " ";
		int temp;


		for(int i=0;i<msg.length();i++){
			String ascii = " ";

			temp = (int)msg.charAt(i);
			int encrypted_char = (int)modulusPower(temp,publicKey,n);
			ascii = Integer.toString(encrypted_char);

			for(int j=ascii.length();j<number_of_digits;j++){
				ascii = "0" + ascii;
			}
			encryptedMsg = encryptedMsg + ascii;
		}
		return encryptedMsg.trim();
	}
	public String decrypt(String encryptedMsg,int n, int privateKey)throws Exception{
		if(n==0 || privateKey==0){
			throw new Exception("Error n -> 0 or p -> 0");
		}else if(n < privateKey){
			throw new Exception("Error n < privateKey");
		}else if(n <= 255){
			throw new Exception("Error n <= 255");
		}

		int number_of_digits = (int)(Math.floor(Math.log10(Math.abs (n))) + 1);
		String decryptedMsg = "";
		for(int i=0;i<encryptedMsg.length()/number_of_digits;i++){
			int temp = Integer.parseInt(encryptedMsg.substring(i*number_of_digits, (i+1)*number_of_digits));
			char decrypted_char = (char)modulusPower(temp,privateKey,n);
			decryptedMsg = decryptedMsg + decrypted_char;
		}
		return decryptedMsg;
	}

	public String chineseRemainderTheorem(String encryptedMsg,int p, int q, int privateKey){
		String decryptedMsg = "";

		return decryptedMsg;
	}
}
