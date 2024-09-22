class Mulher extends PessoaIMC {

    // Construtor da classe Mulher
    public Mulher(String nome, double peso, double altura) {
        super(nome, peso, altura);
    }

    // Implementação do método que verifica o resultado do IMC
    @Override
    public String resultadoIMC() {
        double imc = calculaIMC();
        if (imc < 19) {
            return "Mulher abaixo do peso ideal";
        } else if (imc >= 19 && imc <= 25.8) {
            return "Mulher está no peso ideal";
        } else {
            return "Mulher acima do peso ideal";
        }
    }
}
