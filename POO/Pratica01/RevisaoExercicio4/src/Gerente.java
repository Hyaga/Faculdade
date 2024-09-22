import java.util.Date;

public class Gerente extends Funcionario {
    private float salario;

    // Construtor
    public Gerente(String nome, Date nascimento, String cpf, Endereco endereco, float salario) {
        super(nome, nascimento, cpf, endereco);
        this.salario = salario;
    }

    // Getter e Setter
    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }

    // Sobrescrita do método para exibir os dados do gerente
    @Override
    public void exibirDados() {
        super.exibirDados();
        System.out.println("Salário: R$ " + salario);
    }
}
