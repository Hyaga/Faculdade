import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Empresa empresa = new Empresa("Empresa de Tecnologia");

        // Cadastro de Departamentos e Funcionários
        int opcao;
        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Cadastrar Departamento");
            System.out.println("2. Cadastrar Funcionário em um Departamento");
            System.out.println("3. Exibir Relatório de Funcionários");
            System.out.println("4. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine(); // Consumir a linha

            switch (opcao) {
                case 1:
                    System.out.print("Informe o nome do Departamento: ");
                    String nomeDepartamento = scanner.nextLine();
                    Departamento departamento = new Departamento(nomeDepartamento);
                    empresa.adicionarDepartamento(departamento);
                    System.out.println("Departamento cadastrado com sucesso.");
                    break;

                case 2:
                    System.out.print("Informe o nome do Departamento para adicionar funcionário: ");
                    String nomeDepFunc = scanner.nextLine();
                    Departamento depEncontrado = null;
                    for (Departamento dep : empresa.departamentos) {
                        if (dep.getNome().equalsIgnoreCase(nomeDepFunc)) {
                            depEncontrado = dep;
                            break;
                        }
                    }
                    if (depEncontrado != null) {
                        System.out.print("Informe o nome do Funcionário: ");
                        String nomeFuncionario = scanner.nextLine();
                        System.out.print("Informe o salário do Funcionário: ");
                        float salarioFuncionario = scanner.nextFloat();
                        scanner.nextLine(); // Consumir a linha
                        System.out.print("Informe o cargo do Funcionário: ");
                        String cargoFuncionario = scanner.nextLine();

                        Funcionario funcionario = new Funcionario(nomeFuncionario, salarioFuncionario, cargoFuncionario);
                        depEncontrado.adicionarFuncionario(funcionario);
                        System.out.println("Funcionário cadastrado com sucesso.");
                    } else {
                        System.out.println("Departamento não encontrado.");
                    }
                    break;

                case 3:
                    empresa.listarDepartamentos();
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
}
