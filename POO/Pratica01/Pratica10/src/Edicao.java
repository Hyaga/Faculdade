import java.util.ArrayList;

public class Edicao {
	
	private int Numero;
	
	private ArrayList<Artigo> Array_Artigo = new ArrayList<Artigo>(); // Criação de um arraylist dos objetos da classe artigo

	public Edicao(int Numero) {
		this.Numero = Numero;
	}
	
	
	public void InsereArtigo(String Titulo) {
		Artigo objArtigo = new Artigo(Titulo);
		Array_Artigo.add(objArtigo);
	}
	
	public ArrayList<Artigo> getArray_Artigo(){
		return Array_Artigo;
	}
	
	public int getNumero() {
		return Numero;
	}
}
