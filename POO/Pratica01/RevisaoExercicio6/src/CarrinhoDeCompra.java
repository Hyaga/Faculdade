import java.util.ArrayList;

public class CarrinhoDeCompra {
    private ArrayList<Produto> produtos;

    // Construtor
    public CarrinhoDeCompra() {
        this.produtos = new ArrayList<>();
    }

    // Adicionar produto ao carrinho
    public void adicionarProduto(Produto produto, int quantidade) {
        if (produto.getEstoque() >= quantidade) {
            produto.reduzirEstoque(quantidade);
            produtos.add(produto);
            System.out.println(quantidade + " unidade(s) de " + produto.getNome() + " adicionada(s) ao carrinho.");
        } else {
            System.out.println("Estoque insuficiente para o produto " + produto.getNome());
        }
    }

    // Remover produto do carrinho
    public void removerProduto(Produto produto) {
        if (produtos.remove(produto)) {
            System.out.println(produto.getNome() + " removido do carrinho.");
        } else {
            System.out.println("Produto não encontrado no carrinho.");
        }
    }

    // Exibir os produtos no carrinho
    public void exibirProdutos() {
        if (produtos.isEmpty()) {
            System.out.println("O carrinho está vazio.");
        } else {
            System.out.println("Produtos no carrinho:");
            for (Produto p : produtos) {
                System.out.println("- " + p.getNome() + " | Preço: R$ " + p.getPreco());
            }
        }
    }

    // Calcular o total do carrinho
    public double calcularTotal() {
        double total = 0;
        for (Produto p : produtos) {
            total += p.getPreco();
        }
        return total;
    }

    public ArrayList<Produto> getProdutos() {
        return produtos;
    }
}
