import java.sql.Date;

public class Vendedor extends Funcionario {
    private String equipe;
    private float salario;

    // Construtor
    public Vendedor(String nome, java.util.Date date, String cpf, Endereco endereco, String equipe, float salario) {
        super(nome, date, cpf, endereco);
        this.equipe = equipe;
        this.salario = salario;
    }

    // Getters e Setters
    public String getEquipe() {
        return equipe;
    }

    public void setEquipe(String equipe) {
        this.equipe = equipe;
    }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }

    // Sobrescrita do método para exibir os dados do vendedor
    @Override
    public void exibirDados() {
        super.exibirDados();
        System.out.println("Equipe: " + equipe);
        System.out.println("Salário: R$ " + salario);
    }
}
