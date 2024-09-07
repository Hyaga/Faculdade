
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Solicitar a quantidade de alunos
        System.out.print("Informe a quantidade de alunos: ");
        int quantidadeDeAlunos = scanner.nextInt();

        // Instanciar a classe Disciplina
        Disciplina matematica = new Disciplina(quantidadeDeAlunos);

        // Inserir as notas dos alunos
        for (int i = 0; i < quantidadeDeAlunos; i++) {
            System.out.println("\nInsira as notas do aluno " + (i + 1) + ":");
            System.out.print("Nota 1: ");
            double nota1 = scanner.nextDouble();
            System.out.print("Nota 2: ");
            double nota2 = scanner.nextDouble();
            System.out.print("Nota 3: ");
            double nota3 = scanner.nextDouble();
            System.out.print("Nota 4: ");
            double nota4 = scanner.nextDouble();
            
            matematica.inserirNotas(i, nota1, nota2, nota3, nota4);
        }

        // Calcular a média de todos os alunos e verificar reprovados
        matematica.calcularMediaGeral();

        scanner.close();
    }
}
