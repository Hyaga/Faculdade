import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {
        // Criando empresas
        Empresa empresa1 = new Empresa("Tech Solutions", "12.345.678/0001-90");
        Empresa empresa2 = new Empresa("Innovative Services", "98.765.432/0001-00");

        // Criando departamentos
        Departamento ti1 = new Departamento("T.I");
        Departamento ti2 = new Departamento("Desenvolvimento");
        Departamento hr = new Departamento("Recursos Humanos");

        // Adicionando funcionários ao departamento T.I da empresa 1
        ti1.adicionarFuncionario(new Funcionario("Alice", 3000, LocalDate.of(2022, 1, 15)));
        ti1.adicionarFuncionario(new Funcionario("Bob", 3200, LocalDate.of(2021, 6, 22)));

        // Adicionando funcionários ao departamento de Desenvolvimento da empresa 1
        ti2.adicionarFuncionario(new Funcionario("Carlos", 3500, LocalDate.of(2020, 3, 30)));

        // Adicionando funcionários ao departamento de Recursos Humanos da empresa 1
        hr.adicionarFuncionario(new Funcionario("Diana", 4000, LocalDate.of(2019, 5, 10)));

        // Adicionando departamentos à empresa 1
        empresa1.adicionarDepartamento(ti1);
        empresa1.adicionarDepartamento(ti2);
        empresa1.adicionarDepartamento(hr);

        // Repetindo o processo para a empresa 2
        Departamento ti3 = new Departamento("T.I");
        Departamento marketing = new Departamento("Marketing");

        ti3.adicionarFuncionario(new Funcionario("Eve", 3300, LocalDate.of(2022, 2, 15)));
        marketing.adicionarFuncionario(new Funcionario("Frank", 2800, LocalDate.of(2021, 7, 19)));

        empresa2.adicionarDepartamento(ti3);
        empresa2.adicionarDepartamento(marketing);

        // Listando informações das empresas
        System.out.println("\n--- Informações da Empresa 1 ---");
        empresa1.listarDepartamentos();

        System.out.println("\n--- Informações da Empresa 2 ---");
        empresa2.listarDepartamentos();
    }
}
