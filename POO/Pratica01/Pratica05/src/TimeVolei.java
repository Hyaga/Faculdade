public class TimeVolei {
	
	private Jogador[]VetorJogadores;
	private  int totalJogadores;
	
	public TimeVolei() {
		VetorJogadores = new Jogador[6];
		totalJogadores = 0;
		
	}
	
	public void InsereJogado(String n, int i, float d) {
		if(totalJogadores < 6 ) 
		{
			VetorJogadores[totalJogadores] = new Jogador(n,i,d);
			totalJogadores++;
		}
		return;
	}
	
	
	public String NomeJogadorMenorAltura() {
		
		float MenorAltura = 999999;
		String NomeJogador ="";
		
		for(int i = 0; i < totalJogadores; i++) {
			if(VetorJogadores[i].RetornaAltura() < MenorAltura) {
				MenorAltura = VetorJogadores[i].RetornaAltura();
				NomeJogador = VetorJogadores[i].RetornaNome();
			}
		}
		
		return NomeJogador;
		
	}
	
}
