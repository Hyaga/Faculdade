import java.util.Scanner;
public class MainExercicio03 {

	public static void main(String[] args)
	{
		RegistroAcademico objetoCarla = new RegistroAcademico("Carla Silva",3360,4,50.00);
		RegistroAcademico objetoPaula = new RegistroAcademico("Paula Castro",8250,2,30.00);

		System.out.println("A mensalidade da Carla e: " + objetoCarla.calcularMensalidade());
		System.out.println("A mensalidade da Paula e: " + objetoPaula.calcularMensalidade());

	}
}
