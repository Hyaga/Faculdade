import java.util.Scanner;

public class MainExercicio02 {
	
	public static void main(String[]args)
	{
		float numero1;
		float numero2;
		float numero3;
		Calculadora objeto1;
		
		Scanner teclado = new Scanner(System.in);
		
		System.out.println("Digite o primeiro numero");
		numero1 = teclado.nextFloat();
		System.out.println("Digite o segundo numero");
		numero2 = teclado.nextFloat();
		System.out.println("Digite o terceiro numero");
		numero3 = teclado.nextFloat();
	
		objeto1 = new Calculadora(numero1,numero2,numero3);
		System.out.println("A soma dos numeros e: " + objeto1.Soma());
		System.out.println("A subtracao dos numeros e: " + objeto1.Subtracao());
		System.out.println("A media dos numeros e: " + objeto1.Media());
		System.out.println("A divisao dos numeros e: " + objeto1.Divisao());
		System.out.println("O maior numero e: " + objeto1.MaiorNumero());
	}

}
