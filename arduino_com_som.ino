/**
 * Projetos Arduino
 * 
 * @author diego patriota
 * @link https://github.com/diegopatriota
 * 19/05/2016 
 */

//inclusão de biblioteca
#include <TMRpcm.h> // também é necessário incluir essa biblioteca...

TMRpcm tmrpcm;   // cria um objeto para usar neste sketch
char mychar;

void setup(){

  tmrpcm.speakerPin = 9; //11 no Mega, 9 no Uno, Nano, etc

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  // vê se o cartão está presente e pode ser inicializado:
    Serial.println("SD fail");  
    return;   // não faz nada então/senão
  }
  tmrpcm.play("musica.wav"); //o arquivo de som "música" vai tocar cada vez que o arduino ligar, ou reiniciar
}

void loop(){  

  if(Serial.available()){   
    mychar = Serial.read();

    if(mychar == 'o'){ //envia a letra 'o' para o monitor serial e começa a reproduzir
      tmrpcm.play("musica.wav");
    } else if(mychar == 'r'){ //envia a letra 'r' para o monitor serial e começa a reproduzir
      tmrpcm.play("chortle.wav");
    }  
  }

}
