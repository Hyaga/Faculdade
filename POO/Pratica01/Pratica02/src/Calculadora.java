public class Calculadora {
	
	// Atributos
	int numero1;
	int numero2;
	
	
	//Construtor
	Calculadora(int n1, int n2)
	{
		numero1 = n1;
		numero2 = n2;
	}
	
	int Soma() 
	{
		int soma;
		soma = numero1 + numero2;
		return soma;
	}
	
}
