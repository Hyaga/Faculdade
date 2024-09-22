import java.util.ArrayList;

public class Departamento {
    private String nome;
    private ArrayList<Funcionario> funcionarios;

    public Departamento(String nome) {
        this.nome = nome;
        this.funcionarios = new ArrayList<>();
    }

    public String getNome() {
        return nome;
    }

    public void adicionarFuncionario(Funcionario funcionario) {
        // Aumento de 10% se o departamento for T.I
        if (this.nome.equalsIgnoreCase("T.I")) {
            funcionario.setSalario(funcionario.getSalario() * 1.1);
        }
        funcionarios.add(funcionario);
    }

    public void listarFuncionarios() {
        if (funcionarios.isEmpty()) {
            System.out.println("Nenhum funcionário cadastrado.");
        } else {
            for (Funcionario func : funcionarios) {
                System.out.println("Funcionário: " + func.getNome() + ", Salário: " + func.getSalario());
            }
        }
    }
}
