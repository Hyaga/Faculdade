import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private static ArrayList<Pessoa> pessoas = new ArrayList<>();
    private static ArrayList<Usuario> usuarios = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int opcao = -1;

        while (opcao != 0) {
            System.out.println("\n--- Sistema de Controle de Processos Jurídicos ---");
            System.out.println("1. Cadastrar Pessoa Física");
            System.out.println("2. Cadastrar Pessoa Jurídica");
            System.out.println("3. Cadastrar Advogado");
            System.out.println("4. Cadastrar Secretária");
            System.out.println("5. Listar Pessoas");
            System.out.println("6. Listar Usuários");
            System.out.println("0. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine(); // Consumir a nova linha

            switch (opcao) {
                case 1:
                    cadastrarPessoaFisica(scanner);
                    break;
                case 2:
                    cadastrarPessoaJuridica(scanner);
                    break;
                case 3:
                    cadastrarAdvogado(scanner);
                    break;
                case 4:
                    cadastrarSecretaria(scanner);
                    break;
                case 5:
                    listarPessoas();
                    break;
                case 6:
                    listarUsuarios();
                    break;
                case 0:
                    System.out.println("Saindo do sistema...");
                    break;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        }

        scanner.close();
    }

    private static void cadastrarPessoaFisica(Scanner scanner) {
        System.out.println("\n--- Cadastro de Pessoa Física ---");
        System.out.print("Nome: ");
        String nome = scanner.nextLine();
        System.out.print("CPF: ");
        String cpf = scanner.nextLine();

        PessoaFisica pessoaFisica = new PessoaFisica(nome, cpf);
        pessoas.add(pessoaFisica);
        System.out.println("Pessoa física cadastrada com sucesso!");
    }

    private static void cadastrarPessoaJuridica(Scanner scanner) {
        System.out.println("\n--- Cadastro de Pessoa Jurídica ---");
        System.out.print("Nome: ");
        String nome = scanner.nextLine();
        System.out.print("CNPJ: ");
        String cnpj = scanner.nextLine();

        PessoaJuridica pessoaJuridica = new PessoaJuridica(nome, cnpj);
        pessoas.add(pessoaJuridica);
        System.out.println("Pessoa jurídica cadastrada com sucesso!");
    }

    private static void cadastrarAdvogado(Scanner scanner) {
        System.out.println("\n--- Cadastro de Advogado ---");
        System.out.print("Login: ");
        String login = scanner.nextLine();
        System.out.print("Senha: ");
        String senha = scanner.nextLine();
        System.out.print("Registro OAB: ");
        String registroOAB = scanner.nextLine();

        Advogado advogado = new Advogado(login, senha, registroOAB);
        usuarios.add(advogado);
        System.out.println("Advogado cadastrado com sucesso!");
    }

    private static void cadastrarSecretaria(Scanner scanner) {
        System.out.println("\n--- Cadastro de Secretária ---");
        System.out.print("Login: ");
        String login = scanner.nextLine();
        System.out.print("Senha: ");
        String senha = scanner.nextLine();
        System.out.print("Número da Carteira de Trabalho: ");
        String carteiraTrabalho = scanner.nextLine();

        Secretaria secretaria = new Secretaria(login, senha, carteiraTrabalho);
        usuarios.add(secretaria);
        System.out.println("Secretária cadastrada com sucesso!");
    }

    private static void listarPessoas() {
        System.out.println("\n--- Lista de Pessoas ---");
        if (pessoas.isEmpty()) {
            System.out.println("Nenhuma pessoa cadastrada.");
        } else {
            for (Pessoa pessoa : pessoas) {
                System.out.println("Nome: " + pessoa.getNome());
                if (pessoa instanceof PessoaFisica) {
                    System.out.println("CPF: " + ((PessoaFisica) pessoa).getCpf());
                } else if (pessoa instanceof PessoaJuridica) {
                    System.out.println("CNPJ: " + ((PessoaJuridica) pessoa).getCnpj());
                }
                System.out.println();
            }
        }
    }

    private static void listarUsuarios() {
        System.out.println("\n--- Lista de Usuários ---");
        if (usuarios.isEmpty()) {
            System.out.println("Nenhum usuário cadastrado.");
        } else {
            for (Usuario usuario : usuarios) {
                System.out.println("Login: " + usuario.getLogin());
                if (usuario instanceof Advogado) {
                    System.out.println("Registro OAB: " + ((Advogado) usuario).getRegistroOAB());
                } else if (usuario instanceof Secretaria) {
                    System.out.println("Carteira de Trabalho: " + ((Secretaria) usuario).getCarteiraTrabalho());
                }
                System.out.println();
            }
        }
    }
}
