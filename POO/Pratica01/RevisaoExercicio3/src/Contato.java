public class Contato {

    private String nome;
    private String telefone;

    // Construtor
    public Contato(String nome, String telefone) {
        this.nome = nome;
        this.telefone = telefone;
    }

    // Método get para o nome
    public String getNome() {
        return nome;
    }

    // Método set para o nome
    public void setNome(String nome) {
        this.nome = nome;
    }

    // Método get para o telefone
    public String getTelefone() {
        return telefone;
    }

    // Método set para o telefone
    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
}
