import java.util.ArrayList;

public class Departamento {
    private String nome;
    private ArrayList<Funcionario> funcionarios;

    public Departamento(String nome) {
        this.nome = nome;
        this.funcionarios = new ArrayList<>();
    }

    // Adicionar funcionário
    public void adicionarFuncionario(Funcionario funcionario) {
        if (nome.equalsIgnoreCase("T.I")) {
            funcionario.aplicarAumento(10); // Aumento de 10% se o departamento for T.I
        }
        funcionarios.add(funcionario);
    }

    // Listar funcionários
    public void listarFuncionarios() {
        System.out.println("Funcionários do departamento " + nome + ":");
        for (Funcionario f : funcionarios) {
            System.out.println(f);
        }
    }
}
