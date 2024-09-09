
public class Main {

	public static void main(String[] args) {
		
		PessoaFisica objetoPessoaFisica = new PessoaFisica("Ana Santos", 0145241632);
		PessoaJuridica objetoPessoaJuridica = new PessoaJuridica("Maria Eduarda", 888888);
		
		System.out.println("***** " + objetoPessoaFisica.getNome());
		System.out.println("***** " + objetoPessoaJuridica.getNome());
	}
	
}
