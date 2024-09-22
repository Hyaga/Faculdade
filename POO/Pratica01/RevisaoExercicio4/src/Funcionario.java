import java.util.Date;

public class Funcionario {
    private String nome;
    private Date nascimento;
    private String cpf;
    private Endereco endereco;

    // Construtor
    public Funcionario() {}

    // Getters e Setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Date getNascimento() {
        return nascimento;
    }

    public void setNascimento(Date nascimento) {
        this.nascimento = nascimento;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public Endereco getEndereco() {
        return endereco;
    }

    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }

    // Método para exibir os dados do funcionário
    public void exibirDados() {
        System.out.println("Nome: " + nome);
        System.out.println("Data de Nascimento: " + nascimento);
        System.out.println("CPF: " + cpf);
        System.out.println("Endereço: " + endereco.exibirEndereco());
    }
}
