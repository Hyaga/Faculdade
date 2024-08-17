public class Calculadora {
	
	// Atributos
	float numero1;
	float numero2;
	float numero3;
	
	
	//Construtor
	Calculadora(float primeiro, float segundo, float terceiro)
	{
		numero1 = primeiro;
		numero2 = segundo;
		numero3 = terceiro;
	}
	

	float Soma() 
	{
		float soma;
		soma = numero1 + numero2 + numero3;
		return soma;
	}
	
	float Subtracao()
	{
		float subtracao;
		subtracao = numero1 - numero2 - numero3;
		return subtracao;
	}
	
	float Media() 
	{
		float media;
		media = numero1 * numero2 * numero3;
		return media;
	}
	
	float Divisao()
	{
		float divisao;
		divisao = (numero1/numero2)/numero3;
		return divisao;
	}
	
	float MaiorNumero() 
	{
		float MaiorNumero;
		
		if((numero1 > numero2) && (numero1 > numero3)) {
			MaiorNumero = numero1;
			return MaiorNumero;
		}else if((numero2 > numero3) && (numero2 > numero1)){
			MaiorNumero = numero2;
			return MaiorNumero;
		}else if((numero3 > numero2) && (numero3 > numero1)){
			MaiorNumero = numero3;
			return MaiorNumero;
		}
		return MaiorNumero = 0;
	}
}
