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
