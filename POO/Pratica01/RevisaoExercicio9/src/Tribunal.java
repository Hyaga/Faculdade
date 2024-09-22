import java.util.ArrayList;

public class Tribunal {
    private String nome;
    private ArrayList<Vara> varas;

    public Tribunal(String nome) {
        this.nome = nome;
        this.varas = new ArrayList<>();
    }

    public String getNome() {
        return nome;
    }

    public void adicionarVara(Vara vara) {
        this.varas.add(vara);
    }

    public ArrayList<Vara> getVaras() {
        return varas;
    }
}
