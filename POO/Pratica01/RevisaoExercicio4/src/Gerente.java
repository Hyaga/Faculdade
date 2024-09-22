public class Gerente extends Funcionario {
    private float salario;

    // Construtor vazio para permitir cadastro via teclado
    public Gerente() {}

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
