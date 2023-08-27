/* ============================================================================

    Arduino
    Porta Serial
    Conectar dois arduinos pela porta serial - SLAVE
    
    Autor: Wilson Brancaglioni da Silva
    Data: 27/08/2023

============================================================================ */

#define pinPot A0
char valorAnterior;

void setup(){
  
  Serial.begin(9600);
}

void loop(){
  
  char valorLidoPot;
  valorLidoPot = map(analogRead(pinPot),0,1023,0,255);//Função map para converter o valor lido do potenciometro
  
  if (valorLidoPot != valorAnterior){//Caso o valor lido seja diferente do valor anterior o valor é mostrado
    Serial.print(valorLidoPot);
   	valorAnterior = valorLidoPot;//O valor lido é armazenado na variável valorAnterior para comparar com o valorLidoPot e evitar o envio de dados desnecessários

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
