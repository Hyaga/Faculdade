public class Jogador {

	private String nome;
	private int idade;
	private float altura;
	
	public Jogador(String n , int i, float altur) {
		
		nome = n;
		idade = i;
		altura = altur;
	}
	
	public String RetornaNome() {
		return nome;
	}
	
	public float RetornaAltura() {
		return altura;
	}
	
	public int RetornaIdade() {
		return idade;
	}
	

	
	
}
	
