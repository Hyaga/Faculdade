import java.util.ArrayList;

public class Departamento {
    private String nome;
    private ArrayList<Funcionario> funcionarios;

    // Construtor
    public Departamento(String nome) {
        this.nome = nome;
        this.funcionarios = new ArrayList<>();
    }

    // Adicionar funcionário ao departamento
    public void adicionarFuncionario(Funcionario funcionario) {
        funcionarios.add(funcionario);
    }

    // Listar funcionários do departamento
    public void listarFuncionarios() {
        System.out.println("Departamento: " + nome);
        for (Funcionario f : funcionarios) {
            f.exibirDados();
            System.out.println("------------------");
        }
    }

    // Retornar nome do departamento
    public String getNome() {
        return nome;
    }
}
