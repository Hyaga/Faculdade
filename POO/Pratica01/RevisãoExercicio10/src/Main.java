import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Pergunta ao usuário quantas pessoas serão inseridas
        System.out.println("Quantas pessoas você deseja inserir?");
        int numeroPessoas = scanner.nextInt();
        scanner.nextLine();  // Consome a nova linha

        // Cria uma lista de PessoaIMC
        PessoaIMC[] pessoas = new PessoaIMC[numeroPessoas];

        // Loop para ler os dados de cada pessoa
        for (int i = 0; i < numeroPessoas; i++) {
            System.out.println("Insira o tipo de pessoa (H para Homem, M para Mulher):");
            char tipo = scanner.nextLine().toUpperCase().charAt(0);

            System.out.println("Insira o nome da pessoa:");
            String nome = scanner.nextLine();

            System.out.println("Insira o peso da pessoa (em kg):");
            double peso = scanner.nextDouble();

            System.out.println("Insira a altura da pessoa (em metros):");
            double altura = scanner.nextDouble();
            scanner.nextLine();  // Consome a nova linha

            // Cria a instância correta baseado no tipo de pessoa
            if (tipo == 'H') {
                pessoas[i] = new Homem(nome, peso, altura);
            } else if (tipo == 'M') {
                pessoas[i] = new Mulher(nome, peso, altura);
            }
        }

        // Exibe o relatório completo das pessoas
        System.out.println("\nRelatório de IMC das pessoas:");
        for (PessoaIMC pessoa : pessoas) {
            System.out.println("Nome: " + pessoa.getNome());
            System.out.println("Peso: " + pessoa.getPeso() + " kg");
            System.out.println("Altura: " + pessoa.getAltura() + " m");
            System.out.printf("IMC: %.2f\n", pessoa.calculaIMC());
            System.out.println(pessoa.resultadoIMC());
            System.out.println("------------------------");
        }

        scanner.close();
    }
}