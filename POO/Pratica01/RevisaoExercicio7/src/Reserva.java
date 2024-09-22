import java.time.LocalDate;

public class Reserva {
    private Cliente cliente;
    private Quarto quarto;
    private LocalDate dataReserva;
    private int numeroDias;

    // Construtor
    public Reserva(Cliente cliente, Quarto quarto, LocalDate dataReserva, int numeroDias) {
        this.cliente = cliente;
        this.quarto = quarto;
        this.dataReserva = dataReserva;
        this.numeroDias = numeroDias;
        quarto.reservar(); // Marca o quarto como reservado
    }

    // Getters
    public Cliente getCliente() {
        return cliente;
    }

    public Quarto getQuarto() {
        return quarto;
    }

    public LocalDate getDataReserva() {
        return dataReserva;
    }

    public int getNumeroDias() {
        return numeroDias;
    }

    public double calcularValorReserva() {
        return numeroDias * quarto.getPrecoDiaria();
    }
}
