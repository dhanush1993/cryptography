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
	
	public static void testModulusPower(int base,int exp, int mod, String result){
		double modulusPower = rsaObject.modulusPower(base, exp, mod);
		System.out.println("Parameters Passed: base="+base+", exp="+exp+", mod="+mod);
		testPrint(Double.toString(modulusPower), result);
	}
	
	public static void testLcm(int a, int b, String result){
		int lcm = rsaObject.lcm(a, b);
		System.out.println("Parameters Passed: a="+a+", b="+b);
		testPrint(Integer.toString(lcm), result);
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