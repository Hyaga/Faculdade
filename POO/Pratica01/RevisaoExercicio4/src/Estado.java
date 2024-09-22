public class Estado {
    private String nome;
    private String sigla;

    // Construtor
    public Estado(String nome, String sigla) {
        this.nome = nome;
        this.sigla = sigla;
    }

    // Getters e Setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSigla() {
        return sigla;
    }

    public void setSigla(String sigla) {
        this.sigla = sigla;
    }
}
