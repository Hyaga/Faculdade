public class PessoaFisica extends Pessoa {

	private long cpf;
	
	public PessoaFisica(String nome, long cpf) {
	
		super(nome); // responsavel por chamar o construtor da classe pesspa
		this.cpf = cpf;
	}
	
	public String getNome() {
		
		return "Pessoa Fisica:" + super.getNome() + "- CPF:" + cpf; 
		// Do mesmo jeito que o super e chamado para atribuir o construtor de outra classe ele tambem e precisa ser chamado para chamar os metodos de outra classe
		
	}
}
