import java.util.ArrayList;

public class CarrinhoDeCompra {
    private ArrayList<ItemCarrinho> itensCarrinho;

    // Construtor
    public CarrinhoDeCompra() {
        this.itensCarrinho = new ArrayList<>();
    }

    // Adicionar produto ao carrinho com a quantidade
    public void adicionarProduto(Produto produto, int quantidade) {
        if (produto.getEstoque() >= quantidade) {
            produto.reduzirEstoque(quantidade);
            ItemCarrinho item = new ItemCarrinho(produto, quantidade);
            itensCarrinho.add(item);
            System.out.println(quantidade + " unidade(s) de " + produto.getNome() + " adicionada(s) ao carrinho.");
        } else {
            System.out.println("Estoque insuficiente para o produto " + produto.getNome());
        }
    }

    // Remover produto do carrinho
    public void removerProduto(Produto produto) {
        for (ItemCarrinho item : itensCarrinho) {
            if (item.getProduto().equals(produto)) {
                itensCarrinho.remove(item);
                System.out.println(produto.getNome() + " removido do carrinho.");
                return;
            }
        }
        System.out.println("Produto não encontrado no carrinho.");
    }

    // Exibir os produtos no carrinho
    public void exibirProdutos() {
        if (itensCarrinho.isEmpty()) {
            System.out.println("O carrinho está vazio.");
        } else {
            System.out.println("Produtos no carrinho:");
            for (ItemCarrinho item : itensCarrinho) {
                System.out.println("- " + item.getProduto().getNome() + " | Preço: R$ " + item.getProduto().getPreco() 
                + " | Quantidade: " + item.getQuantidade());
            }
        }
    }

    // Calcular o total do carrinho com a quantidade de cada item
    public double calcularTotal() {
        double total = 0;
        for (ItemCarrinho item : itensCarrinho) {
            total += item.calcularTotalItem();
        }
        return total;
    }

    public ArrayList<ItemCarrinho> getItensCarrinho() {
        return itensCarrinho;
    }
}
