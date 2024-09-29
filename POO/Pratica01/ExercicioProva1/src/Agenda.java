import java.util.ArrayList;
import java.util.Scanner;


public class Agenda {
    private ArrayList<Contato> contatos;

    public Agenda() {
        contatos = new ArrayList<>();
    }

    public void cadastrarContato() {
        Scanner scanner = new Scanner(System.in);
       
        System.out.print("Cadastrar Contato\nNome: ");
        String nome = scanner.nextLine();
       
        System.out.print("Telefone: ");
        String telefone = scanner.nextLine();
       
        System.out.print("Endereço (Rua e Número): ");
        String ruaNumero = scanner.nextLine();
        System.out.print("Cidade: ");
        String nomeCidade = scanner.nextLine();
        System.out.print("Estado: ");
        String nomeEstado = scanner.nextLine();

        Endereco endereco = new Endereco(ruaNumero);
        Cidade cidade = new Cidade(nomeCidade);
        Estado estado = new Estado(nomeEstado);

        // Criando um novo contato que agora herda de Pessoa
        Contato contato = new Contato(nome, telefone, endereco, cidade, estado);
        contatos.add(contato);
        System.out.println("Contato cadastrado com sucesso!\n");
    }

    public void buscarContato() {
        Scanner scanner = new Scanner(System.in);
       
        System.out.print("Buscar Contato\nNome: ");
        String nomeBusca = scanner.nextLine();
        boolean encontrado = false;

        for (Contato contato : contatos) {
            if (contato.getNome().equalsIgnoreCase(nomeBusca)) {
                System.out.println("Contato encontrado!");
                System.out.println("Nome: " + contato.getNome());
                System.out.println("Telefone: " + contato.getTelefone());
                System.out.println("Endereço: " + contato.getEnderecoCompleto() + "\n");
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            System.out.println("Usuário não cadastrado.\n");
        }
    }

    public void imprimirAgenda() {
        System.out.println("Imprimindo Agenda:");
        for (Contato contato : contatos) {
            System.out.println("Nome: " + contato.getNome());
            System.out.println("Telefone: " + contato.getTelefone());
            System.out.println("Endereço: " + contato.getEnderecoCompleto() + "\n");
        }
    }

    public void menu() {
        Scanner scanner = new Scanner(System.in);
        int opcao;

        do {
            System.out.println("Menu:");
            System.out.println("1. Cadastrar Contato");
            System.out.println("2. Buscar Contato");
            System.out.println("3. Imprimir Agenda");
            System.out.println("4. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine(); // Limpar o buffer

            switch (opcao) {
                case 1:
                    cadastrarContato();
                    break;
                case 2:
                    buscarContato();
                    break;
                case 3:
                    imprimirAgenda();
                    break;
                case 4:
                    System.out.println("Saindo...");
                    break;
                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        } while (opcao != 4);
    }

    public static void main(String[] args) {
        Agenda agenda = new Agenda();
        agenda.menu();
    }
}