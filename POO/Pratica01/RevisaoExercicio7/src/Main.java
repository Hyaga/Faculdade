import java.time.LocalDate;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Criando o hotel
        Hotel hotel = new Hotel("Hotel de Luxo");

        // Adicionando quartos
        hotel.adicionarQuarto(new Quarto(101, "solteiro", 150.0));
        hotel.adicionarQuarto(new Quarto(102, "casal", 250.0));
        hotel.adicionarQuarto(new Quarto(103, "solteiro", 150.0));
        hotel.adicionarQuarto(new Quarto(104, "casal", 250.0));
        hotel.adicionarQuarto(new Quarto(201, "solteiro", 250.0));
        hotel.adicionarQuarto(new Quarto(202, "casal", 350.0));
        hotel.adicionarQuarto(new Quarto(203, "casal", 450.0));
        hotel.adicionarQuarto(new Quarto(204, "Switch", 550.0));

        int opcao;
        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Listar quartos disponíveis");
            System.out.println("2. Fazer uma reserva");
            System.out.println("3. Listar reservas");
            System.out.println("4. Calcular total das reservas");
            System.out.println("5. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    hotel.listarQuartosDisponiveis();
                    break;

                case 2:
                    System.out.print("Nome do cliente: ");
                    scanner.nextLine(); // Consumir a quebra de linha
                    String nomeCliente = scanner.nextLine();
                    System.out.print("CPF do cliente: ");
                    String cpfCliente = scanner.nextLine();
                    Cliente cliente = new Cliente(nomeCliente, cpfCliente);

                    System.out.print("Número do quarto para reserva: ");
                    int numeroQuarto = scanner.nextInt();
                    System.out.print("Número de dias de reserva: ");
                    int numeroDias = scanner.nextInt();

                    LocalDate dataReserva = LocalDate.now();
                    hotel.fazerReserva(cliente, numeroQuarto, dataReserva, numeroDias);
                    break;

                case 3:
                    hotel.listarReservas();
                    break;

                case 4:
                    double totalReservas = hotel.calcularTotalReservas();
                    System.out.println("Valor total das reservas: R$ " + totalReservas);
                    break;

                case 5:
                    System.out.println("Saindo...");
                    break;

                default:
                    System.out.println("Opção inválida.");
            }

        } while (opcao != 5);

        scanner.close();
    }
}
