public class Calculadora {
	
	// Atributos
	float numero1;
	float numero2;
	
	
	//Construtor
	Calculadora(float primeiro, float segundo)
	{
		numero1 = primeiro;
		numero2 = segundo;
	}
	

	float Soma() 
	{
		float soma;
		soma = numero1 + numero2;
		return soma;
	}
	
	float Subtracao()
	{
		float subtracao;
		subtracao = numero1 - numero2;
		return subtracao;
	}
	
	float Media() 
	{
		float media;
		media = numero1 * numero2;
		return media;
	}
	
	float Divisao()
	{
		float divisao;
		divisao = numero1/numero2;
		return divisao;
	}
}
