public class Disciplina {
    // Atributos privados
    private int quantidadeDeAlunos;
    private double[][] notasDosAlunos; // Matriz para armazenar as  notas de cada aluno
    private int alunosReprovados;

    // Construtor para inicializar a quantidade de alunos e alocar memória para as notas
    public Disciplina(int quantidadeDeAlunos) {
        this.quantidadeDeAlunos = quantidadeDeAlunos;
        this.notasDosAlunos = new double[quantidadeDeAlunos][4]; // Definição de quantidade de notas que os alunos terao
        this.alunosReprovados = 0;
    }

    // Método para inserir notas dos alunos
    public void inserirNotas(int indiceAluno, double nota1, double nota2, double nota3,double nota4) {
        if (indiceAluno >= 0 && indiceAluno < quantidadeDeAlunos) {
            notasDosAlunos[indiceAluno][0] = nota1;
            notasDosAlunos[indiceAluno][1] = nota2;
            notasDosAlunos[indiceAluno][2] = nota3;
            notasDosAlunos[indiceAluno][3] = nota4;
        } else {
            System.out.println("Índice do aluno fora do limite!");
        }
    }

    // Método para calcular a média de um aluno específico
    public double calcularMedia(int indiceAluno) {
        if (indiceAluno >= 0 && indiceAluno < quantidadeDeAlunos) {
            double soma = 0;
            for (int i = 0; i < 4; i++) {
                soma += notasDosAlunos[indiceAluno][i];
            }
            return soma / 4;
        }
        System.out.println("Índice do aluno fora do limite!");
        return 0;
    }

    // Método para calcular a média de todos os alunos e verificar quantos foram reprovados
    public void calcularMediaGeral() {
        alunosReprovados = 0;
        for (int i = 0; i < quantidadeDeAlunos; i++) {
            double media = calcularMedia(i);
            if (media < 4) {
                alunosReprovados++;
            }
        }
        System.out.println("Número de alunos reprovados: " + alunosReprovados);
    }
}
