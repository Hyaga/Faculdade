public class Pessoa {
    // Atributos privados
    private String nome;
    private String cpf;

    // Construtor
    public Pessoa(String nome, String cpf) {
        this.nome = nome;
        this.cpf = cpf;
    }

    // Método para obter o nome
    public String getNome() {
        return nome;
    }

    // Método para obter o CPF
    public String getCpf() {
        return cpf;
    }

    // Método para imprimir as informações básicas
    public void imprime() {
        System.out.println("Nome: " + nome);
        System.out.println("CPF: " + cpf);
    }
}
