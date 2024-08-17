
public class RegistroAcademico {

		private String NomeAluno;	//Nome do Aluno
		private int numeroDeMatricula;
		private int codigoDoCurso; // Codigo de 1 a 4
		private double Cobranca;
		
		RegistroAcademico(String numero, int matricula,int codigo , double cobranca)
		{
			NomeAluno = numero;
			numeroDeMatricula = matricula;
			codigoDoCurso = codigo;
			Cobranca = cobranca;
		}
		
		public double calcularMensalidade() 
		{
			double mensalidade = 0;
			
			if(codigoDoCurso == 1)
				mensalidade = 450.00;
			if(codigoDoCurso == 2)
				mensalidade = 500.00;
			if(codigoDoCurso == 3)
				mensalidade = 550.00;
			if(codigoDoCurso == 4)
				mensalidade = 380.00;
			
			if(Cobranca ==1)
				mensalidade = 450.00;
			else mensalidade = mensalidade * 100 / Cobranca;
			
			return mensalidade;
		}
		
}
