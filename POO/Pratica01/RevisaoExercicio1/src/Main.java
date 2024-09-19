import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Criar um ArrayList para armazenar as pessoas
        
        ArrayList<Pessoa> pessoas = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            System.out.println("\nCadastro da pessoa " + (i + 1) + ":");

            
            System.out.print("Informe o nome da faculdade onde a pessoa trabalha: ");
            String nomeFaculdade = scanner.nextLine();
            Faculdade faculdade = new Faculdade(nomeFaculdade);

            // Solicitar os dados da pessoa
            System.out.print("Informe o nome da pessoa: ");
            String nomePessoa = scanner.nextLine();

            System.out.print("Informe o dia de nascimento da pessoa: ");
            int diaNascimento = scanner.nextInt();

            System.out.print("Informe o mês de nascimento da pessoa: ");
            int mesNascimento = scanner.nextInt();

            System.out.print("Informe o ano de nascimento da pessoa: ");
            int anoNascimento = scanner.nextInt();
            scanner.nextLine(); 

            
            Pessoa pessoa = new Pessoa(nomeFaculdade,nomePessoa, diaNascimento, mesNascimento, anoNascimento);

            // Adicionar a pessoa ao ArrayList
            pessoas.add(pessoa);
        }

        // Exibir os dados de todas as pessoas armazenadas no ArrayList
        System.out.println("\nInformações das pessoas cadastradas:");
        for (Pessoa pessoa : pessoas) {
            System.out.println("Nome: " + pessoa.getNome());
            System.out.println("Idade: " + pessoa.getIdadeAtual() + " anos");
            System.out.println("Faculdade onde trabalha: " + pessoa.getNomeFaculdade());
            System.out.println("----------------------");
        }

        scanner.close();
    }
}