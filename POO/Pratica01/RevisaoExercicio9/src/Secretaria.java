public class Secretaria extends Usuario {
    private String carteiraTrabalho;

    public Secretaria(String login, String senha, String carteiraTrabalho) {
        super(login, senha);
        this.carteiraTrabalho = carteiraTrabalho;
    }

    public String getCarteiraTrabalho() {
        return carteiraTrabalho;
    }

    public void setCarteiraTrabalho(String carteiraTrabalho) {
        this.carteiraTrabalho = carteiraTrabalho;
    }
}
