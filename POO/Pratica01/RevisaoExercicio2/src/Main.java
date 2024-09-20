import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int opcao;

        do {
            // Exibição do menu
            System.out.println("\n--- MENU ---");
            System.out.println("1. Inserir Professor");
            System.out.println("2. Inserir Coordenador");
            System.out.println("3. Exibir Relatório");
            System.out.println("4. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine(); // Consumir a quebra de linha após a leitura do número

            switch (opcao) {
                case 1:
                    // Inserir Professor
                    System.out.print("Informe o nome do professor: ");
                    String nomeProfessor = scanner.nextLine();
                    System.out.print("Informe o CPF do professor: ");
                    String cpfProfessor = scanner.nextLine();
                    System.out.print("Informe o salário do professor: ");
                    double salarioProfessor = scanner.nextDouble();
                    scanner.nextLine(); // Consumir a quebra de linha
                    new Professor(nomeProfessor, cpfProfessor, salarioProfessor);
                    System.out.println("Professor cadastrado com sucesso!");
                    break;

                case 2:
                    // Inserir Coordenador
                    System.out.print("Informe o nome do coordenador: ");
                    String nomeCoordenador = scanner.nextLine();
                    System.out.print("Informe o CPF do coordenador: ");
                    String cpfCoordenador = scanner.nextLine();
                    System.out.print("Informe o salário do coordenador: ");
                    double salarioCoordenador = scanner.nextDouble();
                    scanner.nextLine(); // Consumir a quebra de linha
                    System.out.print("Informe o curso da matéria que o coordenador coordena: ");
                    String cursoDaMateria = scanner.nextLine();
                    new Coordenador(nomeCoordenador, cpfCoordenador, salarioCoordenador, cursoDaMateria);
                    System.out.println("Coordenador cadastrado com sucesso!");
                    break;

                case 3:
                    // Exibir Relatório de Professores e Coordenadores
                    System.out.println("\n--- RELATÓRIO DE PROFESSORES ---");
                    if (Professor.getProfessores().isEmpty()) {
                        System.out.println("Nenhum professor cadastrado.");
                    } else {
                        Professor.imprimeTodosProfessores();
                    }

                    System.out.println("\n--- RELATÓRIO DE COORDENADORES ---");
                    if (Coordenador.getCoordenadores().isEmpty()) {
                        System.out.println("Nenhum coordenador cadastrado.");
                    } else {
                        Coordenador.imprimeTodosCoordenadores();
                    }
                    break;

                case 4:
                    // Sair do programa
                    System.out.println("Saindo do programa...");
                    break;

                default:
                    System.out.println("Opção inválida. Tente novamente.");
                    break;
            }

        } while (opcao != 4);

        scanner.close();
    }
}
