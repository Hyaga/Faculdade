public class Main {
    public static void main(String[] args) {
        // Instanciar um objeto da classe Livros
        Livro meuLivro = new Livro("O Senhor dos Anéis", 1000, 450);

        // Exibir os dados iniciais do livro
        meuLivro.exibirInfo();
        meuLivro.verificarProcesso();

        // Alterar o título do livro e a quantidade de páginas lidas
        meuLivro.setTitulo("O Hobbit");
        meuLivro.setPaginasLidas(300);

        // Exibir os dados atualizados do livro
        System.out.println("\nApós as alterações:");
        meuLivro.exibirInfo();
        meuLivro.verificarProcesso();
    }
}
