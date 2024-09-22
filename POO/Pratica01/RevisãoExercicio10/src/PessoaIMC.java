class PessoaIMC extends Pessoa {

    // Construtor da classe PessoaIMC
    public PessoaIMC(String nome, double peso, double altura) {
        super(nome, peso, altura);
    }

    // Método para calcular o IMC
    public double calculaIMC() {
        return getPeso() / (getAltura() * getAltura());
    }

    // Método para retornar a descrição do IMC - será sobrescrito em classes filhas
    public String resultadoIMC() {
        return "";
    }
}