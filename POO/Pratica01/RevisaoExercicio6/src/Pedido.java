public class Pedido {
    private CarrinhoDeCompra carrinho;
    private double valorTotal;

    // Construtor
    public Pedido(CarrinhoDeCompra carrinho) {
        this.carrinho = carrinho;
        this.valorTotal = carrinho.calcularTotal();
    }

    // Exibir os detalhes do pedido
    public void exibirPedido() {
        System.out.println("Detalhes do Pedido:");
        carrinho.exibirProdutos();
        System.out.println("Valor Total: R$ " + valorTotal);
    }

    public double getValorTotal() {
        return valorTotal;
    }
}
