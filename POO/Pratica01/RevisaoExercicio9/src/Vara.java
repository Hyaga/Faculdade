import java.util.ArrayList;

public class Vara {
    private String nome;
    private Tribunal tribunal;
    private ArrayList<Processo> processos;

    public Vara(String nome, Tribunal tribunal) {
        this.nome = nome;
        this.tribunal = tribunal;
        this.processos = new ArrayList<>();
    }

    public String getNome() {
        return nome;
    }

    public Tribunal getTribunal() {
        return tribunal;
    }

    public void adicionarProcesso(Processo processo) {
        this.processos.add(processo);
    }

    public ArrayList<Processo> getProcessos() {
        return processos;
    }
}
