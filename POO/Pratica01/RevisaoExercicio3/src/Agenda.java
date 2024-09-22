import java.util.ArrayList;

public class Agenda {
    private ArrayList<Contato> listaContatos;

    public Agenda() {
        listaContatos = new ArrayList<>();
    }

    // Método para cadastrar um novo contato
    public void cadastrarContato(String nome, String telefone) {
        Contato contato = new Contato(nome, telefone);
        listaContatos.add(contato);
        System.out.println("Contato cadastrado com sucesso!");
    }

    // Método para buscar um contato pelo nome
    public void buscarContato(String nomeBusca) {
        boolean encontrado = false;
        for (Contato c : listaContatos) {
            if (c.getNome().equalsIgnoreCase(nomeBusca)) {
                System.out.println("Telefone de " + c.getNome() + ": " + c.getTelefone());
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            System.out.println("Contato inexistente.");
        }
    }

    // Método para imprimir todos os contatos na agenda
    public void imprimirAgenda() {
        if (listaContatos.isEmpty()) {
            System.out.println("A agenda está vazia.");
        } else {
            System.out.println("\n--- CONTATOS NA AGENDA ---");
            for (Contato c : listaContatos) {
                System.out.println("Nome: " + c.getNome() + ", Telefone: " + c.getTelefone());
            }
        }
    }
}
