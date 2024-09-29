class Contato extends Pessoa {

    // Construtor da classe Contato
    public Contato(String nome, String telefone, Endereco endereco, Cidade cidade, Estado estado) {
        super(nome, telefone, endereco, cidade, estado); // Chama o construtor da classe Pessoa
    }

}