class Pessoa {
    private String nome;
    private String telefone;
    private Endereco endereco;
    private Cidade cidade;
    private Estado estado;

    // Construtor da classe Pessoa
    public Pessoa(String nome, String telefone, Endereco endereco, Cidade cidade, Estado estado) {
        this.nome = nome;
        this.telefone = telefone;
        this.endereco = endereco;
        this.cidade = cidade;
        this.estado = estado;
    }

    // Métodos Getters
    public String getNome() {
        return nome;
    }

    public String getTelefone() {
        return telefone;
    }

    public String getEnderecoCompleto() {
        return endereco.getRuaNumero() + ", " + cidade.getNomeCidade() + ", " + estado.getNome();
    }
}