//package com.rsa.main;
import java.util.Arrays;
class Test{
	static RSA rsaObject;
	public static void main(String[] args){
		rsaObject = new RSA();
		System.out.println("************************************************************************\n**************************Testing IsPrime*******************************\n************************************************************************");
		testIsPrime(15,"false");
		testIsPrime(11,"true");
		testIsPrime(0,"false");
		testIsPrime(1,"false");
		System.out.println("\n************************************************************************\n*************************Testing PrimeNumber****************************\n************************************************************************");
		testPrimeNumber(10,15,"11");
		testPrimeNumber(8,10,"0");
		testPrimeNumber(0,0,"0");
		testPrimeNumber(0,1,"0");
		System.out.println("\n************************************************************************\n*************************Testing modulusPower****************************\n************************************************************************");
		testModulusPower(5,25,10,"5.0");
		testModulusPower(23002,1000,3010,"1106.0");
		testModulusPower(0,5,5,"0.0");
		testModulusPower(5,0,5,"1.0");
		testModulusPower(5,25,1,"0.0");
		System.out.println("\n************************************************************************\n*****************************Testing lcm*********************************\n************************************************************************");
		testLcm(5,25,"25");
		testLcm(23002,1000,"11501000");
		testLcm(0,5,"0");
		testLcm(5,1,"5");
		System.out.println("\n************************************************************************\n*****************************Testing CoPrime*********************************\n************************************************************************");
		testCoPrime(25,new int[]{1, 2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14, 16, 17, 18, 19, 21, 22, 23, 24});
		testCoPrime(0,new int[]{0});
		testCoPrime(1,new int[]{0});
		testCoPrime(10,new int[]{1, 3, 7, 9});
		System.out.println("\n************************************************************************\n*****************************Testing Encrypt*********************************\n************************************************************************");
		testEncrypt("Hello",25,5,"Error n <= 255");
	    testEncrypt("Hello",300,1000,"Error n < publickey");
	    testEncrypt("Hello",300,0,"Error n -> 0 or p -> 0");
	    testEncrypt("Hello",3233,17,"30001313074507452185");
	    System.out.println("\n************************************************************************\n*****************************Testing Decrypt*********************************\n************************************************************************");
		testDecrypt("30001313074507452185",25,5,"Error n <= 255");
	    testDecrypt("30001313074507452185",300,1000,"Error n < private");
	    testDecrypt("30001313074507452185",300,0,"Error n -> 0 or p -> 0");
	    testDecrypt("30001313074507452185",3233,413,"Hello");
	}
	
	public static void testIsPrime(int num,String result){
		boolean isPrime = false;
		try {
			isPrime = rsaObject.isPrime(num);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
		}finally {
		System.out.println("Parameters Passed: num="+num);
		testPrint(Boolean.toString(isPrime), result);
		}
	}
	
	public static void testPrimeNumber(int min,int max,String result){
		int primeNumber = 0;
		try {
			primeNumber = rsaObject.primeNumber(min, max);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());;
		}finally {
			System.out.println("Parameters Passed: min="+min+", max="+max);
			testPrint(Integer.toString(primeNumber), result);
		}
	}
	
	public static void testModulusPower(int base,int exp, int mod, String result){
		double modulusPower = 0.0;
		try {
			modulusPower = rsaObject.modulusPower(base, exp, mod);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
			
		}finally {
			System.out.println("Parameters Passed: base="+base+", exp="+exp+", mod="+mod);
			testPrint(Double.toString(modulusPower), result);
		}
	}
	
	public static void testLcm(int a, int b, String result){
		int lcm = 0;
		try {
			lcm = rsaObject.lcm(a, b);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
		}finally {
			System.out.println("Parameters Passed: a="+a+", b="+b);
			testPrint(Integer.toString(lcm), result);
		}
	}
	
	public static void testCoPrime(int a, int ans[])
	{
		int coprime = 0;
		try {
			coprime = rsaObject.coprime(a);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.out.println(e.getMessage());
		}
		finally {
			boolean found = false;
			int i;
			System.out.println("Parameters Passed: a="+a);
			for(i=0;i<ans.length;i++){
				if(ans[i] == coprime){
					found = true;
					break;
				}
			}
			if(found){
				testPrint(Integer.toString(coprime),Integer.toString(ans[i]));
			}else{
				testPrint(Integer.toString(coprime),"The returned value should be one among: "+Arrays.toString(ans));
			}
		}
	}
	
	public static void testEncrypt(String msg,int n, int publicKey, String ans)
	{
		String encMsg = "";
		try {
			encMsg = rsaObject.encrypt(msg, n, publicKey);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			encMsg = e.getMessage();
		}finally {
			System.out.println("Parameters Passed: msg="+msg+" ,n="+n+" ,publicKey="+publicKey);
			testPrint(encMsg, ans);
		}
	}
	
	public static void testDecrypt(String encMsg,int n, int privateKey, String ans)
	{
		String decMsg = "";
		try {
			decMsg = rsaObject.decrypt(encMsg, n, privateKey);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			decMsg = e.getMessage();
		}finally {
		System.out.println("Parameters Passed: msg="+encMsg+" ,n="+n+" ,publicKey="+privateKey);
		testPrint(decMsg, ans);
		}
	}
	
	public static void testPrint(String returned,String actual){
		System.out.println("---------------------------------------------------");
		System.out.print("Actual Result: "+actual+"   |   Returned Result: "+returned+"  >>>>  ");
		if(returned.equals(actual))
			System.out.println("(Passed)");
		else
			System.out.println("(Failed)");
		System.out.println("---------------------------------------------------");
		
	}
}