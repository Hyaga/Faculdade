import java.time.LocalDate;

public class Audiencia {
    private LocalDate data;
    private String recomendacao;

    public Audiencia(LocalDate data, String recomendacao) {
        this.data = data;
        this.recomendacao = recomendacao;
    }

    public LocalDate getData() {
        return data;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }

    public String getRecomendacao() {
        return recomendacao;
    }

    public void setRecomendacao(String recomendacao) {
        this.recomendacao = recomendacao;
    }
}
