public class Pessoa {
    // Atributos comuns que podem ser herdados
    private String nome;

    // Construtor da classe Pessoa
    public Pessoa(String nome) {
        this.nome = nome;
    }

    // Método que retorna o nome (esse método vai para Contato)
    public String getNome() {
        return nome;
    }
}