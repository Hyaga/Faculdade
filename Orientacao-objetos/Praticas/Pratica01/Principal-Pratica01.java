/*Aqui sera o documento principal da pratica 01*/

import java.util.Scanner;

public class Principal{

    public static void main(String[] args){

        float lado1,lado2,lado3; // Declaração dos atributos
        Triangulo objeto1; // Declaração do objeto da classe Triangulo

        Scanner teclado = new Scanner(System.in); // Metodo para a utilização da leitura do teclado

        System.out.println("Digite o lado 1 do Triangulo:"); // Forma de imprimir dados na tela em java
        lado1 = teclado.nextFloat(); // Forma de inserir dados e diferentes tipos em java
        System.out.println("Digite o lado 2 do Triangulo:"); // Forma de imprimir dados na tela em java
        lado2 = teclado.nextFloat(); // Forma de inserir dados e diferentes tipos em java
        System.out.println("Digite o lado 3 do Triangulo:"); // Forma de imprimir dados na tela em java
        lado3 = teclado.nextFloat(); // Forma de inserir dados e diferentes tipos em java

        objeto1 = new Triangulo(lado1,lado2,lado3); // Intancia do objeto triangulo , com os atributos digitados a cima 
        
        System.out.println("\n O perimeto do Triangulo e " + objeto1.calcularPerimetro());
    }

}