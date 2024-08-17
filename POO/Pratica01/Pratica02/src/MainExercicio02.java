import java.util.Scanner;

public class MainExercicio02 {
	
	public static void main(String[]args)
	{
		int numero1, numero2;
		Calculadora objeto1;
		
		Scanner teclado = new Scanner(System.in);
		
		System.out.println("Digite o primeiro numero");
		numero1 = teclado.nextInt();
		System.out.println("Digite o segundo numero");
		numero2 = teclado.nextInt();
	
		objeto1 = new Calculadora(numero1,numero2);
		System.out.println("A soma dos numeros e: " + objeto1.Soma());
	}

}
