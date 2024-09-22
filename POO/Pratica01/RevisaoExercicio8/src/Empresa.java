import java.util.ArrayList;

public class Empresa {
    private String nome;
    private String cnpj;
    private ArrayList<Departamento> departamentos;

    public Empresa(String nome, String cnpj) {
        this.nome = nome;
        this.cnpj = cnpj;
        this.departamentos = new ArrayList<>();
    }

    // Adicionar departamento
    public void adicionarDepartamento(Departamento departamento) {
        departamentos.add(departamento);
    }

    // Listar departamentos e seus funcionários
    public void listarDepartamentos() {
        System.out.println("Departamentos da empresa " + nome + ":");
        for (Departamento d : departamentos) {
            d.listarFuncionarios();
        }
    }
}
