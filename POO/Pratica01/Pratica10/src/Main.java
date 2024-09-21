import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		RevistaCientifica objetoRevista = new RevistaCientifica(533,"Ciencia e tecnologia");
		
		int numero = 0;
		String titulo;
		Scanner LeituraTeclado = new Scanner(System.in);
	
	
		while(numero != -1) {
			
			System.out.print(" \n*** Cadastro de Edicao *** \n");
			System.out.print("*** Digite o numero da Edicao *** \n");
			numero = LeituraTeclado.nextInt();
			
			if(LeituraTeclado.hasNextLine()) // Limpa o conteudo que possa ter ficado no teclado
				LeituraTeclado.nextLine();
			
			if(numero == -1)
				break;
			
			Edicao objetoEdicao = new Edicao(numero); // Criacao do objeto edicao
			
			System.out.print("*** Cadastro dos Artigos *** \n");
			
			for(int i =0; i< 5 ; i++) {
				System.out.print("Digite o titulo do artigo" + (i+1) + ":");
				titulo = LeituraTeclado.nextLine();
				objetoEdicao.InsereArtigo(titulo);
				
			}
			objetoRevista.InserirEdicao(objetoEdicao);
			
			System.out.print(" \n*** Conteudo da Revista ***");
			
			for(Edicao edicao : objetoRevista.getArray_Edicao()) {
			
				System.out.print("*** \n Edicao : ***" + edicao.getNumero());
				
				for(Artigo artigo: edicao.getArray_Artigo()) {
					
					System.out.print("*** \n Artigo ***" + artigo.getTitulo());

				}
			}
			
			
		}
	
	}
	
}
