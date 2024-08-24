import java.util.Scanner;

public class Main {

	
	public static void main(String[]args) {
		
	TimeVolei objetoTime = new TimeVolei();
	
	objetoTime.InsereJogado("Anderson",34, (float) 1.98);
	objetoTime.InsereJogado("Anderson2",24, (float) 1.28);
		
	System.out.println("O jogador com a menor altura eh " + objetoTime.NomeJogadorMenorAltura());
	}
	
}
