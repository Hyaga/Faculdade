import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Empresa> empresas = new ArrayList<>();

        while (true) {
            System.out.println("\n--- Menu ---");
            System.out.println("1. Cadastrar Empresa");
            System.out.println("2. Cadastrar Departamento");
            System.out.println("3. Cadastrar Funcionário");
            System.out.println("4. Listar Empresas");
            System.out.println("5. Sair");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine(); // Limpa o buffer

            switch (opcao) {
                case 1:
                    // Cadastrar Empresa
                    System.out.print("Digite o nome da empresa: ");
                    String nomeEmpresa = scanner.nextLine();
                    System.out.print("Digite o CNPJ da empresa: ");
                    String cnpj = scanner.nextLine();
                    empresas.add(new Empresa(nomeEmpresa, cnpj));
                    System.out.println("Empresa cadastrada com sucesso!");
                    break;

                case 2:
                    // Cadastrar Departamento
                    System.out.print("Digite o nome da empresa onde o departamento será cadastrado: ");
                    String nomeEmpresaParaDept = scanner.nextLine();
                    Empresa empresaDept = encontrarEmpresa(empresas, nomeEmpresaParaDept);
                    if (empresaDept != null) {
                        System.out.print("Digite o nome do departamento: ");
                        String nomeDept = scanner.nextLine();
                        empresaDept.adicionarDepartamento(new Departamento(nomeDept));
                        System.out.println("Departamento cadastrado com sucesso!");
                    } else {
                        System.out.println("Empresa não encontrada!");
                    }
                    break;

                case 3:
                    // Cadastrar Funcionário
                    System.out.print("Digite o nome da empresa onde o funcionário será cadastrado: ");
                    String nomeEmpresaParaFunc = scanner.nextLine();
                    Empresa empresaFunc = encontrarEmpresa(empresas, nomeEmpresaParaFunc);
                    if (empresaFunc != null) {
                        System.out.print("Digite o nome do departamento onde o funcionário será cadastrado: ");
                        String nomeDeptParaFunc = scanner.nextLine();
                        Departamento departamentoFunc = encontrarDepartamento(empresaFunc, nomeDeptParaFunc);
                        if (departamentoFunc != null) {
                            System.out.print("Digite o nome do funcionário: ");
                            String nomeFunc = scanner.nextLine();
                            System.out.print("Digite o salário do funcionário: ");
                            double salarioFunc = scanner.nextDouble();
                            scanner.nextLine(); // Limpa o buffer
                            System.out.print("Digite a data de admissão (YYYY-MM-DD): ");
                            LocalDate dataAdmissao = LocalDate.parse(scanner.nextLine());
                            Funcionario funcionario = new Funcionario(nomeFunc, salarioFunc, dataAdmissao);
                            departamentoFunc.adicionarFuncionario(funcionario);
                            System.out.println("Funcionário cadastrado com sucesso!");
                        } else {
                            System.out.println("Departamento não encontrado!");
                        }
                    } else {
                        System.out.println("Empresa não encontrada!");
                    }
                    break;

                case 4:
                    // Listar Empresas
                    for (Empresa emp : empresas) {
                        System.out.println("\n--- Informações da Empresa: " + emp.getNome() + " ---");
                        emp.listarDepartamentosInformacao();
                    }
                    break;

                case 5:
                    // Sair
                    System.out.println("Saindo do sistema...");
                    scanner.close();
                    return;

                default:
                    System.out.println("Opção inválida! Tente novamente.");
            }
        }
    }

    private static Empresa encontrarEmpresa(ArrayList<Empresa> empresas, String nome) {
        for (Empresa empresa : empresas) {
            if (empresa.getNome().equalsIgnoreCase(nome)) {
                return empresa;
            }
        }
        return null;
    }

    private static Departamento encontrarDepartamento(Empresa empresa, String nome) {
        for (Departamento departamento : empresa.listarDepartamentos()) {
            if (departamento.getNome().equalsIgnoreCase(nome)) {
                return departamento;
            }
        }
        return null;
    }
}
