/* ============================================================================

    Arduino
    Porta Serial
    Conectar dois arduinos pela porta serial - MASTER
    
    Autor: Wilson Brancaglioni da Silva
    Data: 27/08/2023

============================================================================ */

#define pinLed 9


void setup(){
  
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
}


void loop(){
  
  
  //Avalia se há alguma informação recebida
  if (Serial.available() ){
    char valorLido;
    valorLido = Serial.read();//Recebe os dados e armazena na variável Valor Lido
    
    analogWrite(pinLed, valorLido);//O Led irá variar sua luminosidade de acordo com a variação do potenciometro
  }
  }








/* ============================================================================  
                                                              
                                       _                      
                                      / \                     
                                     |oo >                    
                                     _\=/_                    
                    ___         #   /  _  \   #               
                   /<> \         \\//|/.\|\\//                
                 _|_____|_        \/  \_/  \/                 
                | | === | |          |\ /|                    
                |_|  0  |_|          \_ _/                    
                 ||  0  ||           | | |                    
                 ||__*__||           | | |                    
                |* \___/ *|          []|[]                    
                /=\ /=\ /=\          | | |                    
________________[_]_[_]_[_]_________/_]_[_\_______________________________
                                                              
                                                              
============================================================================ */
/* --- Final do Programa --- */
