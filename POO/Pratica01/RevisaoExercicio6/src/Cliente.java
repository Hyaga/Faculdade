import java.util.ArrayList;

public class Cliente {
    private String nome;
    private String email;
    private ArrayList<Pedido> pedidos;

    // Construtor
    public Cliente(String nome, String email) {
        this.nome = nome;
        this.email = email;
        this.pedidos = new ArrayList<>();
    }

    // Adicionar pedido à lista de pedidos do cliente
    public void adicionarPedido(Pedido pedido) {
        pedidos.add(pedido);
    }

    // Exibir todos os pedidos do cliente
    public void exibirPedidos() {
        System.out.println("Pedidos do cliente " + nome + ":");
        for (Pedido p : pedidos) {
            p.exibirPedido();
        }
    }

    // Getters e Setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
