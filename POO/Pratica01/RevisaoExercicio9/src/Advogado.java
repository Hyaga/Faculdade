public class Advogado extends Usuario {
    private String registroOAB;

    public Advogado(String login, String senha, String registroOAB) {
        super(login, senha);
        this.registroOAB = registroOAB;
    }

    public String getRegistroOAB() {
        return registroOAB;
    }

    public void setRegistroOAB(String registroOAB) {
        this.registroOAB = registroOAB;
    }
}
