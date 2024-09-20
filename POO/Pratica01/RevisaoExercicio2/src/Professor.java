import java.util.ArrayList;

public class Professor extends Pessoa {
    // Atributo específico da classe Professor
    private double salario;

    // ArrayList para armazenar os professores
    private static ArrayList<Professor> professores = new ArrayList<>();

    // Construtor que herda os atributos de Pessoa e define o salário
    public Professor(String nome, String cpf, double salario) {
        super(nome, cpf); // Chama o construtor da classe Pessoa
        this.salario = salario;
        professores.add(this); // Adiciona o professor à lista
    }

    // Método para obter o salário do professor
    public double getSalario() {
        return salario;
    }

    // Sobrescreve o método imprime para incluir o salário
    @Override
    public void imprime() {
        super.imprime(); // Chama o imprime() da classe Pessoa
        System.out.println("Salário: R$ " + salario);
    }

    // Método para imprimir todos os professores
    public static void imprimeTodosProfessores() {
        for (Professor professor : professores) {
            professor.imprime();
        }
    }

    // Método para obter a lista de professores
    public static ArrayList<Professor> getProfessores() {
        return professores;
    }
}
