
public class Aluno {
	
	private String Nome;
	private float Nota1;
	private float Nota2;
	private float Nota3;
	private float Media;
	
	
	public Aluno(String nome, float primeiraNota, float segundaNota, float terceiraNota){
		
		Nome = nome;
		Nota1 = primeiraNota;		
		Nota2 = segundaNota;
		Nota3 = terceiraNota;
		Media = 0;
		
	}
	
	String ImprimirNomeAluno(){
		return Nome;
	}
	
	private float Soma() {
		
		float soma = Nota1 + Nota2 + Nota3;
		return soma;
		
	}
	
	private float CalcularMedia() {
		 Media = Soma()/3;
		return Media;
	}
	
	public String imprimirResultadoFinal() {
		
		String resultado = "";
		float media = CalcularMedia();
		if(media >= 6)
			resultado = "Aluno esta Aprovado";
		else if(media >= 4 && (media <6))
			resultado ="Aluno esta de Recuperação";
		else resultado = "Aluno esta reprovado";
		
		return resultado;
		
	}
}
