class Homem extends PessoaIMC {

    // Construtor da classe Homem
    public Homem(String nome, double peso, double altura) {
        super(nome, peso, altura);
    }

    // Implementação do método que verifica o resultado do IMC
    @Override
    public String resultadoIMC() {
        double imc = calculaIMC();
        if (imc < 20.7) {
            return "Homem abaixo do peso ideal";
        } else if (imc >= 20.7 && imc <= 26.4) {
            return "Homem está no peso ideal";
        } else {
            return "Homem acima do peso ideal";
        }
    }
}