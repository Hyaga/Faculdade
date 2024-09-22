import java.time.LocalDate;

public class Funcionario {
    private String nome;
    private double salario;
    private LocalDate dataAdmissao;

    public Funcionario(String nome, double salario, LocalDate dataAdmissao) {
        this.nome = nome;
        this.salario = salario;
        this.dataAdmissao = dataAdmissao;
    }

    // Getters
    public String getNome() {
        return nome;
    }

    public double getSalario() {
        return salario;
    }

    public LocalDate getDataAdmissao() {
        return dataAdmissao;
    }

    // Método para aplicar aumento
    public void aplicarAumento(double percentual) {
        salario += salario * (percentual / 100);
    }

    @Override
    public String toString() {
        return "Nome: " + nome + ", Salário: R$ " + String.format("%.2f", salario) + ", Data de Admissão: " + dataAdmissao;
    }
}
