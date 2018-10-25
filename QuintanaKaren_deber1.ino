/* Deber #01:
 *  Nombre:Karen Quintana
 *  Sistemas microporcesados
 *1.- Realizar un juego de lueces que se prendan secuencialmente los leds impartes (1,3,5).
 *2.- Realizar un programa que se enciendan uno por uno los leds pares (0,2,4). 
 *3.- Realizar un juego que se enciendan y apaguen los leds de forma aleatoria.
 */
 // Parte 1
 
 int leds[6]={8,9,10,11,12,13};//defino vector para configurar leds pares
int i=0;//variable de recorrido del vector
 void setup() {
  for(;i<6;i++){ // establecemos variables de conteo
  pinMode(leds[i],OUTPUT);//definir i como pin de salida 
}
 i=0;//resetea variable de conteo
 }
 
  void loop() {
     for(;i<3;++i){
  digitalWrite(leds[(i*2)+1],HIGH);// enciendo posicion i del vector
   delay(200);// espero
      }  
      
      for(;i>=0;--i){
    digitalWrite(leds[(i*2)+1],LOW);// apago posicion i del vector
  delay(200);// espero
      }
      i=0;//resetea variable de conteo
// Parte 2

for(;i<6;++i){
  digitalWrite(leds[i*2],HIGH);// enciendo posicion i delvector
  delay(200);
  digitalWrite(leds[i*2],LOW);// apago posicion i delvector
  delay(200);// espero
  }  
  i=0;//resetea variable de conteo

//PARTE 3

   i=random(6);       // ocupamos la función aleatoria genera números aleatorios con el número maximo de las aleaciones que me puede dar.
 digitalWrite (leds[i],HIGH);// prendo la posición k del vector
 delay (300);//espero
 digitalWrite (leds[i],LOW);// apago posicion k delvecto
 delay (300);//espero
 i=0;//resetea variable de conteo
  }  
  
 
