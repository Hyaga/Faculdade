import java.util.ArrayList;

public class RevistaCientifica {
	
		private int Numero;
		private String Titulo;
		private ArrayList<Edicao> Array_Edicao = new ArrayList<Edicao>();

		
		public RevistaCientifica(int Numero,String Titulo) {
			
			this.Numero = Numero;
			this.Titulo = Titulo;
			
		}
		
		public void InserirEdicao(Edicao objEdicao) {
			Array_Edicao.add(objEdicao);
		}
		
		public ArrayList<Edicao> getArray_Edicao(){
			return Array_Edicao;
		}
}
