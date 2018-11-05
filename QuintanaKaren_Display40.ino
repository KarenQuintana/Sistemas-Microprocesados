/*UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA/CIERCOM
 * Nombre:Karen Quintana
 * Fecha:02/11/2018
 * Realizar un programa que medienta un pulsador se aumente el valor de un contador (1 al 40) 
 *  y mediante otro pulsador se reste ese valor.
 */
 //Declarar Variales
 int A=5;//plantea una variable de salida para en 7447 en el pin 2 del arduino como entero
 int B=4;//plantea una variable de salida para en 7447 en el pin 4 del arduino como entero
 int C=3;//plantea una variable de salida para en 7447 en el pin 3 del arduino como entero
 int D=2;//plantea una variable de salida para en 7447 en el pin 2 del arduino como entero
 int b1=6;//variable de boton aumento
 int b11=7;//variable de boton decremento
 int i =0;// inicializa variable de conteo
 int dec=9;// variable de decenas en el pin 9
 int uni=8;// variable de unidades en el pin 8
 int decenas;// variable decenas
 int unidades;// variable unidades


void setup() {
 
  pinMode(A,OUTPUT);// definir A como salida
  pinMode(B,OUTPUT);// definir B como salida
  pinMode(C,OUTPUT);// definir C como salida
  pinMode(D,OUTPUT);//definir D como salida
  pinMode(dec,OUTPUT);//definir dec como salida
  pinMode(uni,OUTPUT);//definir uni como salida
}
void loop() {
 if(digitalRead(b1)==HIGH){// si el botón de aumento esta en alto cuenta 
  delay(200);// espera
  if(i<40){// si la variable de conteo es menor a 40
    i++;// esta aumenta de uno en uno
    decenas=i/10;//división entera para obtener el numero en decenas
    unidades=i-(decenas*10);// a la variable de conteo y se le quita las decenas debido a sus 2 cifras
  }
 else{
 i=0;// se reinicia en 0
 }
 }
  if(digitalRead(b11)==HIGH){// si el boton de decremento esta en alto cuenta 
  delay(200);// espera
  if(i>=0){// la variable de conteo es mayor a 0
    i--;//se disminuye en uno por cada pulso
    decenas=i/10;//división entera para el conteo
    unidades=i-(decenas*10);// variable de conteo y se le quita las decenas en las unidades para el conteo
  }
 else{
 i=40;// una vez 0 continua en 40
 }
 }
 
  digitalWrite(uni,HIGH);// se activa unidades 
  digitalWrite(dec,LOW);//mientras el contador sea de unidades el display de decenas pasa apagado
 contador (unidades);//se llama la función de contador en función de los parámetros de unidades
 delay(100);// espero
 digitalWrite(uni,LOW);//el display de unidades de mantiene en bajo
  digitalWrite(dec,HIGH);// se activa o cambia el display de decenas
 contador (decenas);//se llama la función de contador en función de los parámetros de decenas
 delay(100);// espero
 
}
void contador (int j){//se plantea la función de contador de todos los números posibles de 0-9
  switch(j){
    // número 0
  case 0:
   digitalWrite(A,LOW);//1
 digitalWrite(B,LOW);//2
 digitalWrite(C,LOW);//4
 digitalWrite(D,LOW);//8
break;
//  número 1
case 1:
digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 break;
 // número 2 
 case 2:
digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 break;
// número 3 
case 3:
digitalWrite(A,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 break;
 // número 4 
 case 4:
digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
 break;
// número 5 
case 5:
digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
break;
 // número 6 
 case 6:
digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
 break;
 // número 7 
 case 7:
digitalWrite(A,HIGH);
 digitalWrite(B,HIGH);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
 break;
 // número 8 
 case 8:
digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
break;
 // número 9 
 case 9:
digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
break;
 }
}
