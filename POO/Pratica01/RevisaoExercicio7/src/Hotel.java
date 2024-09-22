import java.time.LocalDate;
import java.util.ArrayList;

public class Hotel {
    private String nome;
    private ArrayList<Quarto> quartos;
    private ArrayList<Reserva> reservas;

    // Construtor
    public Hotel(String nome) {
        this.nome = nome;
        this.quartos = new ArrayList<>();
        this.reservas = new ArrayList<>();
    }

    // Adicionar um quarto ao hotel
    public void adicionarQuarto(Quarto quarto) {
        quartos.add(quarto);
    }

    // Listar quartos disponíveis
    public void listarQuartosDisponiveis() {
        System.out.println("Quartos disponíveis:");
        for (Quarto quarto : quartos) {
            if (!quarto.isReservado()) {
                System.out.println("Quarto nº " + quarto.getNumero() + " - Tipo: " + quarto.getTipo() + " - Diária: R$ " + quarto.getPrecoDiaria());
            }
        }
    }

    // Fazer uma reserva
    public void fazerReserva(Cliente cliente, int numeroQuarto, LocalDate dataReserva, int numeroDias) {
        for (Quarto quarto : quartos) {
            if (quarto.getNumero() == numeroQuarto && !quarto.isReservado()) {
                Reserva reserva = new Reserva(cliente, quarto, dataReserva, numeroDias);
                reservas.add(reserva);
                System.out.println("Reserva realizada com sucesso para o quarto nº " + numeroQuarto);
                return;
            }
        }
        System.out.println("Quarto nº " + numeroQuarto + " não está disponível.");
    }

    // Listar reservas feitas
    public void listarReservas() {
        if (reservas.isEmpty()) {
            System.out.println("Não há reservas.");
        } else {
            for (Reserva reserva : reservas) {
                System.out.println("Cliente: " + reserva.getCliente().getNome() + " - Quarto nº " + reserva.getQuarto().getNumero() +
                                   " - Data da reserva: " + reserva.getDataReserva() + " - Nº de dias: " + reserva.getNumeroDias() +
                                   " - Valor total: R$ " + reserva.calcularValorReserva());
            }
        }
    }

    // Calcular o total das reservas
    public double calcularTotalReservas() {
        double total = 0;
        for (Reserva reserva : reservas) {
            total += reserva.calcularValorReserva();
        }
        return total;
    }
}
