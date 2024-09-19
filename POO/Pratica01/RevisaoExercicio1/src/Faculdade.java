public class Faculdade {
    // Atributo privado
    private String nomeFaculdade;

    // Construtor 
    public Faculdade(String nomeFaculdade) {
        this.nomeFaculdade = nomeFaculdade;
    }

    // Método para retornar o nome 
    public String getNomeFaculdade() {
        return nomeFaculdade;
    }

    // Método para alterar o nome da faculdade
    public void setNomeFaculdade(String nomeFaculdade) {
        this.nomeFaculdade = nomeFaculdade;
    }
}