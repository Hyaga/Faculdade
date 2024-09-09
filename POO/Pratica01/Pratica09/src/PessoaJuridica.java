
public class PessoaJuridica extends Pessoa {
	
	private long cnpj;
	
	public PessoaJuridica(String nome, long cnpj) {
		
		super(nome);
		this.cnpj = cnpj;
	}

	public String getNome() {
		
		return "Pessoa Juridica" + super.getNome() + " - CNPJ: " + cnpj;
	}
	
	
	
}
