import java.util.ArrayList;

public class Empresa {
    private String nome;
    ArrayList<Departamento> departamentos;

    // Construtor
    public Empresa(String nome) {
        this.nome = nome;
        this.departamentos = new ArrayList<>();
    }

    // Adicionar departamento à empresa
    public void adicionarDepartamento(Departamento departamento) {
        departamentos.add(departamento);
    }

    // Listar departamentos e funcionários da empresa
    public void listarDepartamentos() {
        System.out.println("Empresa: " + nome);
        for (Departamento d : departamentos) {
            d.listarFuncionarios();
        }
    }

    // Retornar nome da empresa
    public String getNome() {
        return nome;
    }
}
