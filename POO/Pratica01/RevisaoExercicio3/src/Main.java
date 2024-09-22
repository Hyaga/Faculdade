import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Agenda agenda = new Agenda();
        int opcao;

        do {
            // Exibição do menu
            System.out.println("\n--- MENU ---");
            System.out.println("1. Cadastrar Contato");
            System.out.println("2. Buscar Contato");
            System.out.println("3. Imprimir Agenda");
            System.out.println("4. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine(); // Consumir a quebra de linha após o número

            switch (opcao) {
                case 1:
                    // Cadastrar Contato
                    System.out.print("Informe o nome do contato: ");
                    String nome = scanner.nextLine();
                    System.out.print("Informe o telefone do contato: ");
                    String telefone = scanner.nextLine();
                    agenda.cadastrarContato(nome, telefone);
                    break;

                case 2:
                    // Buscar Contato
                    System.out.print("Informe o nome do contato que deseja buscar: ");
                    String nomeBusca = scanner.nextLine();
                    agenda.buscarContato(nomeBusca);
                    break;

                case 3:
                    // Imprimir Agenda
                    agenda.imprimirAgenda();
                    break;

                case 4:
                    // Sair
                    System.out.println("Saindo da agenda...");
                    break;

                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }

        } while (opcao != 4);

        scanner.close(); // Fechar o scanner
    }
}
