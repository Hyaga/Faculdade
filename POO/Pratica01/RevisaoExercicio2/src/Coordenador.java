import java.util.ArrayList;

public class Coordenador extends Pessoa {
    // Atributo específico da classe Coordenador
    private String cursoDaMateria;
    private double salario;

    // ArrayList para armazenar os coordenadores
    private static ArrayList<Coordenador> coordenadores = new ArrayList<>();

    // Construtor que herda os atributos de Pessoa e define o salário e o curso
    public Coordenador(String nome, String cpf, double salario, String cursoDaMateria) {
        super(nome, cpf); // Chama o construtor da classe Pessoa
        this.salario = salario;
        this.cursoDaMateria = cursoDaMateria;
        coordenadores.add(this); // Adiciona o coordenador à lista
    }

    // Método para obter o curso da matéria
    public String getCurso() {
        return cursoDaMateria;
    }

    // Método para obter o salário do coordenador
    public double getSalario() {
        return salario;
    }

    // Sobrescreve o método imprime para incluir o salário e o curso
    @Override
    public void imprime() {
        super.imprime(); // Chama o imprime() da classe Pessoa
        System.out.println("Salário: R$ " + salario);
        System.out.println("Curso da Matéria: " + cursoDaMateria);
    }

    // Método para imprimir todos os coordenadores
    public static void imprimeTodosCoordenadores() {
        for (Coordenador coordenador : coordenadores) {
            coordenador.imprime();
        }
    }

    // Método para obter a lista de coordenadores
    public static ArrayList<Coordenador> getCoordenadores() {
        return coordenadores;
    }
}
