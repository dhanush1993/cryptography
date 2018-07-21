//package com.rsa.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class RSAStart {

	public static void main(String[] args) throws NumberFormatException, IOException {
		int p=0,q=0,n=0;
		RSA rsa= new RSA();
		InputStreamReader reader = new InputStreamReader(System.in);
		BufferedReader breader = new BufferedReader(reader);
		while(n<999) {
			try {
				p=rsa.primeNumber((int)Math.ceil(Math.random()*100), (int)Math.ceil(Math.random()*1000));
			} catch (Exception e) {
				continue;
			}
			
			try {
				q=rsa.primeNumber((int)Math.ceil(Math.random()*100), (int)Math.ceil(Math.random()*500));
			} catch (Exception e) {
				continue;
			}
			
			n = p*q;
		}
		
		int totient = 0;
		try {
			totient = rsa.lcm((p-1),(q-1));
		} catch (Exception e1) {
			// TODO Auto-generated catch block
			System.out.println(e1.getMessage());
			System.exit(0);
		}
	    int e = 0;
		try {
			e = rsa.coprime(totient);
		} catch (Exception e1) {
			// TODO Auto-generated catch block
			System.out.println(e1.getMessage());
			System.exit(0);
		}
	    System.out.println("Public key pair is (n,e)=("+n+","+e+")");
	    int k = ((e*e)-1)/totient;
	    double m;
	    while(true){
	        k = k+1;
	        m = (double)(1+(k*totient))/e;
	        if(Math.ceil(m)==Math.floor(m)){
	            break;
	        }
	    }
	    int d = (int) Math.floor(m);
	    System.out.println("Private key is "+d);
	    int sharedN = 0,sharedE = 0;
	    System.out.println("Enter the n value of the shared public key\n");
	    sharedN = Integer.parseInt(breader.readLine());
	    System.out.println("Enter the e value of the shared public key\n");
	    sharedE = Integer.parseInt(breader.readLine());
	    int cmd = 0;
	    
	    while(cmd == 0){
	    	System.out.println("Enter 1 to Encrypt, 2 to Decrypt or 3 to quit\n");
	        cmd = Integer.parseInt(breader.readLine());
	        if(cmd == 1){
	            System.out.println("Please enter the message to encrypt:\n");
	            String msg = breader.readLine().trim();
	            try {
					System.out.println("The encrypted message is: "+rsa.encrypt(msg,sharedN, sharedE));
				} catch (Exception e1) {
					// TODO Auto-generated catch block
					System.out.println(e1.getMessage());;
				}
	            cmd =0;
	        }else if(cmd == 2){
	            System.out.println("Please enter the message to decrypt:\n");
	            String msg = breader.readLine().trim();
	            try {
					System.out.println("The decrypted message is: "+rsa.decrypt(msg,n, d));
				} catch (Exception e1) {
					// TODO Auto-generated catch block
					System.out.println(e1.getMessage());
				}
	            cmd =0;
	        }
	        else if(cmd == 3) {
	        	break;
	        }
	    }

	}

}
