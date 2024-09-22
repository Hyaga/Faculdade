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

    public String getNome() {
        return nome;
    }

    public void adicionarDepartamento(Departamento departamento) {
        departamentos.add(departamento);
    }

    public ArrayList<Departamento> listarDepartamentos() {
        return departamentos; // Retorna a lista de departamentos
    }

    public void listarDepartamentosInformacao() {
        if (departamentos.isEmpty()) {
            System.out.println("Nenhum departamento cadastrado.");
        } else {
            for (Departamento dept : departamentos) {
                System.out.println("Departamento: " + dept.getNome());
                dept.listarFuncionarios(); // Imprime os funcionários do departamento
            }
        }
    }
}
