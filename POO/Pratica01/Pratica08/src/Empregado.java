
public class Empregado {

		private String nome;
		private float salario;
		private String cpf;
		
		public Empregado(String nome, float salario, String cpf) {
		
			this.nome = nome;
			this.salario = salario;
			this.cpf = cpf;
			
		}
		
		public String getNome() {
			
			return nome;
			
		}
		
		public void setNome(String nome) {
			
			this.nome = nome;
			
		}
		
		public float getSalario() {
			
			return salario;
		}
		
		public void setSalario(float salario){
			
			this.salario = salario;
		}
		
		public String cpf() {
			
			return cpf;
		}
		
		public void setcpf(String cpf) {
			
			this.cpf = cpf;
		}


	    // Método para exibir os dados do empregado
	    public void exibirDados() {
	        System.out.println("Nome: " + nome);
	        System.out.println("CPF: " + cpf);
	        System.out.println("Salário: R$ " + salario);
	    }
}
