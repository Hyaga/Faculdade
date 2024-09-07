import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Criar um vetor de 5 objetos da classe Empregado
        Empregado[] empregados = new Empregado[5];

        // Inserir os dados de cada empregado
        for (int i = 0; i < empregados.length; i++) {
            System.out.println("\nInsira os dados do empregado " + (i + 1) + ":");

            System.out.print("Nome: ");
            String nome = scanner.nextLine();

            System.out.print("CPF: ");
            String cpf = scanner.nextLine();

            System.out.print("Salário: ");
            float salario = scanner.nextFloat();
            scanner.nextLine(); // Consumir a quebra de linha deixada pelo nextDouble()

            // Criar o objeto Empregado e armazená-lo no vetor
            empregados[i] = new Empregado(nome, salario,cpf);
        }

        // Exibir os dados de todos os empregados
        System.out.println("\nDados dos empregados cadastrados:");
        for (Empregado empregado : empregados) {
            empregado.exibirDados();
            System.out.println("----------------------");
        }

        scanner.close();
    }
}
