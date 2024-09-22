public class ItemCarrinho {
    private Produto produto;
    private int quantidade;

    // Construtor
    public ItemCarrinho(Produto produto, int quantidade) {
        this.produto = produto;
        this.quantidade = quantidade;
    }

    // Getters
    public Produto getProduto() {
        return produto;
    }

    public int getQuantidade() {
        return quantidade;
    }

    // Retorna o preço total do item baseado na quantidade
    public double calcularTotalItem() {
        return produto.getPreco() * quantidade;
    }
}
