public class Livro {
    // Atributos privados
    private String titulo;
    private int quantidadeDePaginas;
    private int paginasLidas;

    // Construtor da classe
    public Livro(String titulo, int quantidadeDePaginas, int paginasLidas) {
        this.titulo = titulo;
        this.quantidadeDePaginas = quantidadeDePaginas;
        this.paginasLidas = paginasLidas;
    }

    // Métodos getters e setters

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public int getQuantidadeDePaginas() {
        return quantidadeDePaginas;
    }

    public void setQuantidadeDePaginas(int quantidadeDePaginas) {
        this.quantidadeDePaginas = quantidadeDePaginas;
    }

    public int getPaginasLidas() {
        return paginasLidas;
    }

    public void setPaginasLidas(int paginasLidas) {
        this.paginasLidas = paginasLidas;
    }

    // Método para calcular o progresso do livro
    public double calcularProgresso() {
        return ((double) paginasLidas / quantidadeDePaginas) * 100;
    }

    // Novo método verificarProcesso
    public void verificarProcesso() {
        double porcentagem = (paginasLidas * 100.0) / quantidadeDePaginas;
        System.out.println("Você já leu " + String.format("%.2f", porcentagem) + "% do livro " + titulo);
    }

    // Método para exibir informações do livro
    public void exibirInfo() {
        System.out.println("Título: " + titulo);
        System.out.println("Total de Páginas: " + quantidadeDePaginas);
        System.out.println("Páginas Lidas: " + paginasLidas);
        System.out.println("Progresso: " + calcularProgresso() + "%");
    }
}
