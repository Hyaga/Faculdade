public class Quarto {
    private int numero;
    private String tipo; // "solteiro" ou "casal"
    private boolean reservado;
    private double precoDiaria;

    // Construtor
    public Quarto(int numero, String tipo, double precoDiaria) {
        this.numero = numero;
        this.tipo = tipo;
        this.precoDiaria = precoDiaria;
        this.reservado = false;
    }

    // Getters e Setters
    public int getNumero() {
        return numero;
    }

    public String getTipo() {
        return tipo;
    }

    public boolean isReservado() {
        return reservado;
    }

    public void reservar() {
        this.reservado = true;
    }

    public void liberar() {
        this.reservado = false;
    }

    public double getPrecoDiaria() {
        return precoDiaria;
    }
}
