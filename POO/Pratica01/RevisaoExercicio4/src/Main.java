import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ArrayList<Funcionario> funcionarios = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        // Opções do menu
        int opcao;
        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Cadastrar Vendedor");
            System.out.println("2. Cadastrar Gerente");
            System.out.println("3. Exibir Relatório de Funcionários");
            System.out.println("4. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine(); // Consumir a linha após o número

            switch (opcao) {
                case 1:
                    Vendedor vendedor = new Vendedor();
                    cadastrarFuncionario(vendedor, scanner);
                    System.out.print("Informe a equipe do vendedor: ");
                    vendedor.setEquipe(scanner.nextLine());
                    System.out.print("Informe o salário do vendedor: ");
                    vendedor.setSalario(scanner.nextFloat());
                    scanner.nextLine(); // Consumir a linha
                    funcionarios.add(vendedor);
                    break;

                case 2:
                    Gerente gerente = new Gerente();
                    cadastrarFuncionario(gerente, scanner);
                    System.out.print("Informe o salário do gerente: ");
                    gerente.setSalario(scanner.nextFloat());
                    scanner.nextLine(); // Consumir a linha
                    funcionarios.add(gerente);
                    break;

                case 3:
                    System.out.println("\n--- RELATÓRIO DE FUNCIONÁRIOS ---");
                    for (Funcionario f : funcionarios) {
                        f.exibirDados();
                        System.out.println("--------------------");
                    }
                    break;

                case 4:
                    System.out.println("Saindo...");
                    break;

                default:
                    System.out.println("Opção inválida.");
            }
        } while (opcao != 4);

        scanner.close();
    }

    // Método para cadastrar dados comuns a todos os funcionários
    public static void cadastrarFuncionario(Funcionario funcionario, Scanner scanner) {
        System.out.print("Informe o nome: ");
        funcionario.setNome(scanner.nextLine());

        // Ignorando o nascimento por ser uma implementação simples (usando a data atual como exemplo)
        funcionario.setNascimento(new Date());

        System.out.print("Informe o CPF: ");
        funcionario.setCpf(scanner.nextLine());

        // Cadastro do endereço
        Endereco endereco = new Endereco();
        System.out.print("Informe a rua: ");
        endereco.setRua(scanner.nextLine());
        System.out.print("Informe o número: ");
        endereco.setNumero(scanner.nextInt());
        scanner.nextLine(); // Consumir a linha
        System.out.print("Informe o bairro: ");
        endereco.setBairro(scanner.nextLine());
        System.out.print("Informe o CEP: ");
        endereco.setCep(scanner.nextLine());

        // Cadastro da cidade e estado
        Cidade cidade = new Cidade();
        System.out.print("Informe a cidade: ");
        cidade.setNome(scanner.nextLine());

        Estado estado = new Estado();
        System.out.print("Informe o estado: ");
        estado.setNome(scanner.nextLine());
        System.out.print("Informe a sigla do estado: ");
        estado.setSigla(scanner.nextLine());

        cidade.setEstado(estado);
        endereco.setCidade(cidade);
        funcionario.setEndereco(endereco);
    }
}
