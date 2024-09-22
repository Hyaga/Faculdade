public class Vendedor extends Funcionario {
    private String equipe;
    private float salario;

    // Construtor vazio para permitir cadastro via teclado
    public Vendedor() {}

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
