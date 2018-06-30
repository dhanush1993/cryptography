import java.math.*;
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
		
		return 0;
	}
	
	public int lcm(int a, int b){
		
		return 0;
	}
	
	public int coprime(int a){
		
		return 0;
	}
	
	public String encrypt(String msg,int n, int publicKey){
		String encryptedMsg = "";
		
		return encryptedMsg;
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
		testModulusPower(5,25,10,"5");
		testModulusPower(23002,1000,3010,"1106");
		testModulusPower(0,5,5,"0");
		testModulusPower(5,0,5,"1");
		testModulusPower(5,25,1,"0");
	}
	
	public static void testIsPrime(int num,String result){
		boolean isPrime = rsaObject.isPrime(num);
		System.out.println("Parameters Passed: num="+num);
		testPrint(Boolean.toString(isPrime), result);
	}
	
	public static void testPrimeNumber(int min,int max,String result){
		int primeNumber = rsaObject.primeNumber(min, max);
		System.out.println("Parameters Passed: min="+min+", max="+max);
		testPrint(Integer.toString(primeNumber), result);
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