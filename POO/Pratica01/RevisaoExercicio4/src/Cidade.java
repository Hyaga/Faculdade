public class Cidade {
    private String nome;
    private Estado estado;

    // Construtor
    public Cidade(String nome, Estado estado) {
        this.nome = nome;
        this.estado = estado;
    }

    // Getters e Setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Estado getEstado() {
        return estado;
    }

    public void setEstado(Estado estado) {
        this.estado = estado;
    }
}
