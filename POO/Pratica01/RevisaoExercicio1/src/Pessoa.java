import java.time.Year;

public class Pessoa extends Faculdade{
    // Atributos privados
    private String nome;
    private int diaNascimento;
    private int mesNascimento;
    private int anoNascimento;
    private int idadeAtual;
    

    // Construtor
    public Pessoa(String nomeFaculdade,String nome, int diaNascimento, int mesNascimento, int anoNascimento) {
    	super(nomeFaculdade);
        this.nome = nome;
        this.diaNascimento = diaNascimento;
        this.mesNascimento = mesNascimento;
        this.anoNascimento = anoNascimento;
        this.idadeAtual = calcularIdade(); //Calculo idade
    }

    // Método para calcular a idade da pessoa (considerando apenas o ano de nascimento)
    public int calcularIdade() {
        int anoAtual = Year.now().getValue(); 
        return anoAtual - anoNascimento; 
    }

    // Método para retornar a idade
    public int getIdadeAtual() {
        return idadeAtual;
    }

    // Método para retornar o nome
    public String getNome() {
        return nome;
    }

}
