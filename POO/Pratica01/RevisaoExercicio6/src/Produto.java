public class Produto {
    private String nome;
    private double preco;
    private int estoque;

    // Construtor
    public Produto(String nome, double preco, int estoque) {
        this.nome = nome;
        this.preco = preco;
        this.estoque = estoque;
    }

    // Getters e Setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public int getEstoque() {
        return estoque;
    }

    public void setEstoque(int estoque) {
        this.estoque = estoque;
    }

    // Reduz o estoque do produto
    public void reduzirEstoque(int quantidade) {
        if (estoque >= quantidade) {
            estoque -= quantidade;
        } else {
            System.out.println("Estoque insuficiente.");
        }
    }
}
