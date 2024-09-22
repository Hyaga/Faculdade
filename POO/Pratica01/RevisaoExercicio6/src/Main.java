import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Criação de produtos
        Produto produto1 = new Produto("Laptop", 3500.0, 10);
        Produto produto2 = new Produto("Mouse", 50.0, 100);
        Produto produto3 = new Produto("Teclado", 150.0, 50);

        // Criação de um carrinho e um cliente
        CarrinhoDeCompra carrinho = new CarrinhoDeCompra();
        Cliente cliente = new Cliente("João", "joao@example.com");

        int opcao;
        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Adicionar produto ao carrinho");
            System.out.println("2. Remover produto do carrinho");
            System.out.println("3. Exibir carrinho");
            System.out.println("4. Finalizar compra");
            System.out.println("5. Exibir pedidos");
            System.out.println("6. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine(); // Consumir a linha

            switch (opcao) {
                case 1:
                    System.out.println("1. Laptop - R$3500");
                    System.out.println("2. Mouse - R$50");
                    System.out.println("3. Teclado - R$150");
                    System.out.print("Escolha o produto: ");
                    int escolhaProduto = scanner.nextInt();
                    System.out.print("Quantidade: ");
                    int quantidade = scanner.nextInt();

                    switch (escolhaProduto) {
                        case 1:
                            carrinho.adicionarProduto(produto1, quantidade);
                            break;
                        case 2:
                            carrinho.adicionarProduto(produto2, quantidade);
                            break;
                        case 3:
                            carrinho.adicionarProduto(produto3, quantidade);
                            break;
                        default:
                            System.out.println("Opção inválida.");
                    }
                    break;

                case 2:
                    System.out.println("1. Laptop");
                    System.out.println("2. Mouse");
                    System.out.println("3. Teclado");
                    System.out.print("Escolha o produto para remover: ");
                    escolhaProduto = scanner.nextInt();

                    switch (escolhaProduto) {
                        case 1:
                            carrinho.removerProduto(produto1);
                            break;
                        case 2:
                            carrinho.removerProduto(produto2);
                            break;
                        case 3:
                            carrinho.removerProduto(produto3);
                            break;
                        default:
                            System.out.println("Opção inválida.");
                    }
                    break;

                case 3:
                    carrinho.exibirProdutos();
                    break;

                case 4:
                    Pedido pedido = new Pedido(carrinho);
                    cliente.adicionarPedido(pedido);
                    System.out.println("Compra finalizada com sucesso.");
                    carrinho = new CarrinhoDeCompra(); // Criar um novo carrinho para o cliente
                    break;

                case 5:
                    cliente.exibirPedidos();
                    break;

                case 6:
                    System.out.println("Saindo...");
                    break;

                default:
                    System.out.println("Opção inválida.");
            }

        } while (opcao != 6);

        scanner.close();
    }
}
