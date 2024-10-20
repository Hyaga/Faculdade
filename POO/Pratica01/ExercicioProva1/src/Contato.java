// Classe Contato, que herda de Pessoa
public class Contato extends Pessoa {
    private String telefone;
    private Endereco endereco;
    private Cidade cidade;
    private Estado estado;

    // Construtor da classe Contato
    public Contato(String nome, String telefone, Endereco endereco, Cidade cidade, Estado estado) {
        super(nome); // Inicializa o nome usando o construtor de Pessoa
        this.telefone = telefone;
        this.endereco = endereco;
        this.cidade = cidade;
        this.estado = estado;
    }

    // Método que retorna o telefone
    public String getTelefone() {
        return telefone;
    }

    // Método que retorna o endereço completo
    public String getEnderecoCompleto() {
        return endereco.getRuaNumero() + ", " + cidade.getNomeCidade() + ", " + estado.getNome();
    }
}
