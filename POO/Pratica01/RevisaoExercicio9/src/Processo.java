import java.util.ArrayList;

public class Processo {
    private String codigoProcesso;
    private Tribunal tribunal;
    private Vara vara;
    private Pessoa cliente;
    private Pessoa parteContraria;
    private String descricao;
    private Secretaria secretaria;
    private Advogado advogadoResponsavel;
    private ArrayList<Audiencia> audiencias;
    private ArrayList<Custa> custas;

    public Processo(String codigoProcesso, Tribunal tribunal, Vara vara, Pessoa cliente, Pessoa parteContraria, String descricao, Secretaria secretaria, Advogado advogadoResponsavel) {
        this.codigoProcesso = codigoProcesso;
        this.tribunal = tribunal;
        this.vara = vara;
        this.cliente = cliente;
        this.parteContraria = parteContraria;
        this.descricao = descricao;
        this.secretaria = secretaria;
        this.advogadoResponsavel = advogadoResponsavel;
        this.audiencias = new ArrayList<>();
        this.custas = new ArrayList<>();
    }

    public void adicionarAudiencia(Audiencia audiencia) {
        this.audiencias.add(audiencia);
    }

    public void adicionarCusta(Custa custa) {
        this.custas.add(custa);
    }
}
