/*primeira pratica com java e programalçao orientada a objetos
*/

/*Classe da pratica 01 */


public class Triangulo {

    //Atributos da Classe
    float lado1;
    float lado2;
    float lado3;

    //Construtor da Classe
    Triangulo(float primeiro, float segundo, float terceiro){
        // Aqui foi criado um construtor para receber os atributos da classe
        lado1 = primeiro;
        lado2 = segundo;
        lado3 = terceiro;
    }

    //Metodos da classe
    boolean verificarEquilatero(){ // Este metodo calculara se o triangulo sera Equilatero
        boolean resultado;
            if((lado1 == lado2) && (lado2 == lado3)){
                resultado = true;
            }else resultado = false;
        return resultado;
    }

    float calcularPerimetro(){ // Este metodo calculara o perimetro do triangulo
        float resultado = lado1 + lado2 + lado3;
        return resultado;
    }

}