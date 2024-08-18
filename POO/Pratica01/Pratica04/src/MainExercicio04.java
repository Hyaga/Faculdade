import java.util.Scanner;

public class MainExercicio04 {
	
	public static void main(String[]args) {
		
		Scanner teclado = new Scanner(System.in);	
		String nome;
		
		float nota1,nota2,nota3;
		
		
		System.out.println("Digite o nome do Aluno");
		nome = teclado.next();
		System.out.println("Digite a primeira nota do aluno");
		nota1 = teclado.nextFloat();
		System.out.println("Digite a segunda nota do aluno");
		nota2 = teclado.nextFloat();
		System.out.println("Digite a terceira nota do aluno");
		nota3 = teclado.nextFloat();
		
		Aluno objetoAluno;
		objetoAluno = new Aluno(nome,nota1,nota2,nota3);
		
		System.out.println("Aluno: " + objetoAluno.ImprimirNomeAluno() + " esta de " + objetoAluno.imprimirResultadoFinal());
	
	
	
	}
}
