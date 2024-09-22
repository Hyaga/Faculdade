public class Endereco {
    private String rua;
    private int numero;
    private String bairro;
    private String cep;
    private Cidade cidade;

    // Construtor
    public Endereco(String rua, int numero, String bairro, String cep, Cidade cidade) {
        this.rua = rua;
        this.numero = numero;
        this.bairro = bairro;
        this.cep = cep;
        this.cidade = cidade;
    }

    // Getters e Setters
    public String getRua() {
        return rua;
    }

    public void setRua(String rua) {
        this.rua = rua;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getBairro() {
        return bairro;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public String getCep() {
        return cep;
    }

    public void setCep(String cep) {
        this.cep = cep;
    }

    public Cidade getCidade() {
        return cidade;
    }

    public void setCidade(Cidade cidade) {
        this.cidade = cidade;
    }

    // Método para exibir o endereço completo
    public String exibirEndereco() {
        return rua + ", " + numero + " - " + bairro + ", CEP: " + cep + ", " + cidade.getNome() + " - " + cidade.getEstado().getSigla();
    }
}
