import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ArrayList<Funcionario> funcionarios = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        // Exemplo de cadastro
        Estado estado = new Estado("São Paulo", "SP");
        Cidade cidade = new Cidade("São Paulo", estado);
        Endereco endereco = new Endereco("Rua da Paz", 123, "Centro", "01000-000", cidade);

        // Cadastrar Vendedores
        Vendedor vendedor1 = new Vendedor("João", new Date(), "123.456.789-00", endereco, "Equipe A", 3000.0f);
        funcionarios.add(vendedor1);

        Vendedor vendedor2 = new Vendedor("Maria", new Date(), "987.654.321-00", endereco, "Equipe B", 3500.0f);
        funcionarios.add(vendedor2);

        // Cadastrar Gerente
        Gerente gerente = new Gerente("Carlos", new Date(), "321.654.987-00", endereco, 6000.0f);
        funcionarios.add(gerente);

        // Relatório de Funcionários
        System.out.println("\n--- RELATÓRIO DE FUNCIONÁRIOS ---");
        for (Funcionario f : funcionarios) {
            f.exibirDados();
            System.out.println("--------------------");
        }

        scanner.close();
    }
}
